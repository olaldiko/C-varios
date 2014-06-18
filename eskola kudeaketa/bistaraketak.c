//
//  bistaraketak.c
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 14/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//
#ifndef BISTARAKETAK_C
#define BISTARAKETAK_C

#include <stdio.h>
#include <stdlib.h>
#include "egiturak.h"
#include "bestelakoak.h"

void bistaratugelak(ESKOLA_t *eskola){
	GELA_t *hasiera;
	GELA_t *gela;
	int kont = 0;
	gela = eskola->gelak;
	hasiera = gela;
	if (gela == NULL){
		printf("------------------------------Ez daude Gelarik----------------------------");
	}
	else{
		for (gela = hasiera; gela != NULL; gela = gela->hurrengoa){
			printf("%i. %s\t", kont, gela->gelafisikoa);
			if (kont % 3 == 0)
				printf("\n");
            kont++;
		}
	}
}

void bistaratunotakgela(GELA_t *gela){
	IKASLE_t *aux;
	printf("IDa\t\tIzena\t\tAbizenak\t\tNota\n");
	printf("-----------------------------------------------------------------------------\n");
	for (aux = gela->ikasleak; aux != NULL; aux = aux->hurrengoa){
		printf("%i\t\t%s\t\t%s\t\t%f\n", aux->idal ,aux->izena, aux->abizenak, notakbatazbesteko(aux->ikasgaiak));
	}
	printf("-----------------------------------------------------------------------------\n");
    printf("Sakatu tekla bat jarraitzeko\n");
    getchar();
    fpurge(stdin);
}

void bistaratunotakikasle(IKASLE_t *ikasle){
	IKASGAI_t *ikasgai;
    printf("-----------------------------%s %s Notak:------------------------------\n", ikasle->izena,ikasle->abizenak);
	printf("Ikasgaia\tNota:\n");
    for (ikasgai = ikasle->ikasgaiak; ikasgai != NULL; ikasgai = ikasgai->hurrengoa) {
        printf("%s\t%f\n", ikasgai->izena, ikasgai->nota);
    }
    printf("--------------------------------------------------------------------------\n");
    printf("Sakatu tekla bat jarraitzeko\n");
    getchar();
    fpurge(stdin);
}
void bistaratuikasle(ESKOLA_t *eskola){
    int idal = 0;
    POSI_t pos;
    system("clear");
    printf("Mesedez, sartu ikaslearen IDALa:\n");
    scanf("%i", &idal);
    fpurge(stdin);
    pos = aurkituikasle(idal, eskola);
    if (pos.ikaslea != NULL) {
        printf("Izena: %s\n",pos.ikaslea->izena);
        printf("Abizena: %s\n", pos.ikaslea->abizenak);
        printf("Jaiotza: %i/%i/%i\n", pos.ikaslea->jaiotza.eguna, pos.ikaslea->jaiotza.hilabetea, pos.ikaslea->jaiotza.urtea);
        printf("Helbidea:\n");
        printf("\tKalea ,zenbakia eta pisua: %s %i, %s\n", pos.ikaslea->helbidea.kalea, pos.ikaslea->helbidea.zenbakia, pos.ikaslea->helbidea.pisua);
        printf("\tHerria: %s\n", pos.ikaslea->helbidea.herria);
        printf("\tPosta Kodea: %i\n", pos.ikaslea->helbidea.postakodea);
        printf("\tTelefonoa: %s\n", pos.ikaslea->helbidea.telefonoa);
        printf("Gela: %s\n", pos.gelaikas->gelafisikoa);
        printf("Maila: %s\n", pos.gelaikas->maila);
        printf("Tutorea: %s\n", pos.gelaikas->tutorea);

    }else{
        printf("Ikaslea ez da aurkitu\n");
    }
    printf("Sakau tekla bat jarraitzeko\n");
    getchar();
    fpurge(stdin);
}
void bistaratunotakirakas(IKASLE_t *ikaslea, ERABILTZAILE_t *irakaslea){
    IKASGAI_t *ikasgaia;
    printf("Izen abizenak: %s %s\t", ikaslea->izena, ikaslea->abizenak);
    for (ikasgaia = ikaslea->ikasgaiak; ikasgaia!= NULL; ikasgaia = ikasgaia->hurrengoa) {
        if (ikasgaia->irakaslea == irakaslea) {
            printf("\tIkasgaia: %s\tNota: %f\n", ikasgaia->izena, ikasgaia->nota);
        }
        printf("\n");
    }
    getchar();
    fpurge(stdin);
}
void bistaratunotakirakasgela(ESKOLA_t *eskola, ERABILTZAILE_t *irakaslea){
    IKASLE_t *ikasleak;
    ikasleak = aukeratugela(eskola)->ikasleak;
    for (; ikasleak != NULL; ikasleak = ikasleak->hurrengoa) {
        bistaratunotakirakas(ikasleak, irakaslea);
    }
}

#endif