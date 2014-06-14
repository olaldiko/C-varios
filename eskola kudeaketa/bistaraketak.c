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

void bistaratuGelak(ESKOLA_t *eskola){
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
	printf("Izena\t\tAbizenak\t\tNota\n");
	printf("-----------------------------------------------------------------------------");
	for (aux = gela->ikasleak; aux != NULL; aux = aux->hurrengoa){
		printf("%s\t\t%s\t\t%f\n", aux->izena, aux->abizenak, notakbatazbesteko(aux->ikasgaiak));
	}
	printf("-----------------------------------------------------------------------------");
}

void bistaratunotakikasle(IKASLE_t *ikasle){
	IKASGAI_t *ikasgai;
    printf("-----------------------------%s %s Notak:------------------------------\n", ikasle->izena,ikasle->abizenak);
	printf("Ikasgaia\tNota:\n");
    for (ikasgai = ikasle->ikasgaiak; ikasgai != NULL; ikasgai = ikasgai->hurrengoa) {
        printf("%s\t%f\n", ikasgai->izena, ikasgai->nota);
    }
    printf("--------------------------------------------------------------------------");
}

#endif