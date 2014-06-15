//
//  modifikazioak.c
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 14/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//
#ifndef MODIFIKAZIOAK_C
#define MODIFIKAZIOAK_C
#include <stdio.h>
#include <stdlib.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "modifikazioak.h"
void modifikatuikasle(ESKOLA_t **eskola){
	POSI_t posi;
	int aukera = 0;
    int idal = 0;
	IKASLE_t *ikaslea;
    printf("Sartu ikaslearen IDALa mesedez");
    scanf("%i", &idal);
    fpurge(stdin);
	posi = aurkituikasle(idal, (*eskola));
	if(posi.ikaslea !=NULL){
        ikaslea = posi.ikaslea;
		while(aukera != 5){
            system("clear");
            printf("Ze datu modifikatu nahi duzu?\n");
            printf("1. Izena\n");
            printf("2. Abizenak\n");
            printf("3. Helbidea\n");
            printf("4. Jaiotza data");
            printf("5. Irten");
            printf(">");
            scanf("%i", &aukera);
            fpurge(stdin);
            switch(aukera){
                case 1:
                    printf("Sartu izena mesedez:\n>");
                    gets(ikaslea -> izena);
                    fpurge(stdin);
                    break;
                case 2:
                    printf("Sartu abizenak mesedez:\n>");
                    gets(ikaslea -> abizenak);
                    fpurge(stdin);
                    break;
                case 3:
                    ikaslea -> helbidea = modifikatuhelbidea();
                    break;
                case 4:
                    ikaslea -> jaiotza = modifikatujaiotza();
                    break;
            }
        }
        printf("\nIkaslearen modifikazioa gauzatu egin da\n");
		getchar();
		fpurge(stdin);
	}else{
		printf("\nIkaslea ez da aurkitu\n");
		getchar();
		fpurge(stdin);
	}
}
JAIO_t modifikatujaiotza(){
    JAIO_t jaiotza;
	system("clear");
	printf("Sartu eguna mesedez:\n>");
	scanf("%i", &jaiotza.eguna);
	fpurge(stdin);
	printf("\nSartu hilabetea:\n>");
	scanf("%i", &jaiotza.hilabetea);
	fpurge(stdin);
	printf("\nSartu urtea:\n>");
	scanf("%i", &jaiotza.urtea);
	fpurge(stdin);
	return jaiotza;
}
HELBIDE_t modifikatuhelbidea(HELBIDE_t helbidea){
	int aukera = 0;
	while (aukera != 6){
		system("clear");
		printf("Ze datu modifikatu nahi duzu?\n");
		printf("1. Kalea\n");
		printf("2. Zenbakia\n");
		printf("3. Pisua\n");
		printf("4. Herria\n");
		printf("5. Posta kodea\n");
		printf("6. Irten\n");
		printf(">");
		scanf("%i", &aukera);
		fpurge(stdin);
		switch(aukera){
            case 1:
                printf("Sartu kalea mesedez\n");
                gets(helbidea.kalea);
                fpurge(stdin);
                break;
            case 2:
                printf("Sartu zenbakia mesedez:\n>");
                scanf("%i", &helbidea.zenbakia);
                fpurge(stdin);
                break;
            case 3:
                printf("Sartu pisua mesedez:\n>");
                gets(helbidea.pisua);
                fpurge(stdin);
                break;
            case 4:
                printf("Sartu herria mesedez:\n>");
                gets(helbidea.herria);
                fpurge(stdin);
                break;
            case 5:
                printf("Sartu posta kodea mesedez:\n>");
                scanf("%i", &helbidea.postakodea);
                fpurge(stdin);
                break;
		}
	}
	return helbidea;
}
void modifikatugela(ESKOLA_t **eskola){
	int aukera = 0;
	GELA_t *gela;
	gela = aukeratugela((*eskola));
	while (aukera != 3){
		system("clear");
		printf("Ze datu aldatu nahi duzu?\n");
		printf("1. Gelaren maila\n");
		printf("2. Tutorea\n");
		printf("3. Irten\n>");
		scanf("%i", &aukera);
		fpurge(stdin);
		switch(aukera){
			case 1:
				printf("Sartu gelaren maila:\n");
                gets(gela->maila);
                fpurge(stdin);
				break;
			case 2:
				printf("Sartu tutorearen izena mesedez:\n>");
				gets(gela -> tutorea);
				fpurge(stdin);
				break;
		}
	}
}
void mugituikasle(ESKOLA_t **eskola){
    int idal;
    POSI_t posizioa;
    IKASLE_t *ikaslesrc;
    IKASLE_t *ikasledest;
    GELA_t *geladest;
    printf("Sartu ikaslearen IDa mesedez:\n");
    scanf("%i", &idal);
    posizioa = aurkituikasle(idal, *eskola);
    geladest = aukeratugela(*eskola);
    if((geladest != NULL)&&(posizioa.ikaslea != NULL)){
    for(ikaslesrc = posizioa.ikaslea; ikaslesrc->hurrengoa == posizioa.ikaslea; ikaslesrc = ikaslesrc->hurrengoa);
    ikaslesrc->hurrengoa = NULL;
        posizioa.gelaikas->ikasle_kop--;
        for(ikasledest = geladest->ikasleak;ikasledest->hurrengoa; ikasledest = ikasledest->hurrengoa);
        ikasledest->hurrengoa = posizioa.ikaslea;
        geladest->ikasle_kop++;
        
    }else{
        printf("errorea gertatu da, gela edo ikaslea ez duzu ondo aukeratu");
    }
}
#endif