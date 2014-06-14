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
void modifikatuikasle(ESKOLA_t **eskola, int idal, int idesk){
	POSI_t posi;
	int aukera = 0;
	IKASLE_t *ikaslea;
	posi = aurkituikasle(idesk, *eskola);
	if(posi.ikaslea !=NULL){
        ikaslea = posi.ikaslea;
		while(aukera != 5){
            system("CLS");
            printf("Ze datu modifikatu nahi duzu?\n");
            printf("1. Izena\n");
            printf("2. Abizenak\n");
            printf("3. Helbidea\n");
            printf("4. Jaiotza data");
            printf("5. Irten");
            printf(">");
            scanf("%i", &aukera);
            fflush(stdin);
            switch(aukera){
                case 1:
                    printf("Sartu izena mesedez:\n>");
                    gets(ikaslea -> izena);
                    fflush(stdin);
                    break;
                case 2:
                    printf("Sartu abizenak mesedez:\n>");
                    gets(ikaslea -> abizenak);
                    fflush(stdin);
                    break;
                case 3:
                    ikaslea -> helbidea =
                    modifikatuhelbidea(ikaslea -> helbidea);
                    break;
                case 4:
                    ikaslea -> jaiotza = 
                    modifikatujaiotza(ikaslea -> jaiotza);
                    break;
            }
        }
	}else{
		printf("\nIkaslea ez da aurkitu\n");
		getchar();
		fflush(stdin);
	}
}
JAIO_t modifikatujaiotza(JAIO_t jaiotza){
	system("CLS");
	printf("Sartu eguna mesedez:\n>");
	scanf("%i", &jaiotza.eguna);
	fflush(stdin);
	printf("\nSartu hilabetea:\n>");
	scanf("%i", &jaiotza.hilabetea);
	fflush(stdin);
	printf("\nSartu urtea:\n>");
	scanf("%i", &jaiotza.urtea);
	fflush(stdin);
	return jaiotza;
}
HELBIDE_t modifikatuhelbidea(HELBIDE_t helbidea){
	int aukera = 0;
	while (aukera != 6){
		system("CLS");
		printf("Ze datu modifikatu nahi duzu?\n");
		printf("1. Kalea\n");
		printf("2. Zenbakia\n");
		printf("3. Pisua\n");
		printf("4. Herria\n");
		printf("5. Posta kodea\n");
		printf("6. Irten\n");
		printf(">");
		scanf("%i", &aukera);
		fflush(stdin);
		switch(aukera){
            case 1:
                printf("Sartu kalea mesedez\n");
                gets(helbidea.kalea);
                break;
            case 2:
                printf("Sartu zenbakia mesedez:\n>");
                scanf("%i", &helbidea.zenbakia);
                fflush(stdin);
                break;
            case 3:
                printf("Sartu pisua mesedez:\n>");
                gets(helbidea.pisua);
                fflush(stdin);
                break;
            case 4:
                printf("Sartu herria mesedez:\n>");
                gets(helbidea.herria);
                fflush(stdin);
                break;
            case 5:
                printf("Sartu posta kodea mesedez:\n>");
                scanf("%i", &helbidea.postakodea);
                fflush(stdin);
                break;
		}
	}
	return helbidea;
}
void modifikatugela(ESKOLA_t **eskola, int idesk){
	int aukera = 0;
	GELA_t *gela;
	gela = aukeratugela(*eskola);
	while (aukera != 3){
		system("CLS");
		printf("Ze datu aldatu nahi duzu?\n");
		printf("1. Gelaren maila\n");
		printf("2. Tutorea\n");
		printf("3. Irten\n>");
		scanf("%i", &aukera);
		fflush(stdin);
		switch(aukera){
			case 1:
				printf("Sartu gelaren maila:\n");
                gets(gela->maila);
				break;
			case 2:
				printf("Sartu tutorearen izena mesedez:\n>");
				gets(gela -> tutorea);
				fflush(stdin);
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