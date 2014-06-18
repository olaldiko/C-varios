#ifndef SORKETAK_C
#define SORKETAK_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "menuak.h"
#include "sorketak.h"

void sortuikasle(ESKOLA_t **eskola){
	IKASLE_t *ikaslea;
	GELA_t *gela;
	gela = aukeratugela(*eskola);
    if (gela != NULL) {
        if (gela->ikasleak == NULL) {
            gela->ikasleak = calloc(1, sizeof(IKASLE_t));
            ikaslea = gela->ikasleak;
        }else{
            ikaslea = gela->ikasleak;
            while(ikaslea->hurrengoa != NULL){
                ikaslea = ikaslea->hurrengoa;
            }
            ikaslea->hurrengoa = calloc(1, sizeof(IKASLE_t));
            ikaslea = ikaslea->hurrengoa;
        }
    ikaslea->idal = (*eskola)->idikasle;
	printf("Mesedez, sartu ikaslearen izena\n");
	gets(ikaslea->izena);
	fpurge(stdin);
	printf("Sartu ikaslearen abizenak\n");
	gets(ikaslea->abizenak);
    fpurge(stdin);
	ikaslea->helbidea = helbideasartu();
	ikaslea->jaiotza = jaiotzasartu();
	kopiatuikasgai(gela, &ikaslea->ikasgaiak);
    (*eskola)->idikasle++;
    gela->ikasle_kop++;
    }
}
void sortugela(ESKOLA_t **eskola){
	GELA_t *gelaberri;
	GELA_t *gelak;
	gelaberri = (GELA_t *)calloc(1, sizeof(GELA_t));
	system("clear");
	printf("Mesedez, sartu gelaren izena:\n");
	gets(gelaberri->gelafisikoa);
	fpurge(stdin);
	printf("Sartu tutorearen izena:\n");
	gets(gelaberri->tutorea);
    fpurge(stdin);
	printf("Sartu gelaren maila:\n");
	gets(gelaberri->maila);
    fpurge(stdin);
    gelaberri->idgela = (*eskola)->idgela;
    (*eskola)->idgela++;
	menusortuikasgai(&gelaberri->stdikasgaiak, (*eskola)->erabiltzaileak);
	if((*eskola)->gelak == NULL){
		(*eskola)->gelak = gelaberri;
	}else{
		for(gelak = (*eskola)->gelak; gelak->hurrengoa != NULL; gelak = gelak->hurrengoa);
		gelak->hurrengoa = gelaberri;
	}
}
void sortuikasgai(IKASGAI_t **ikasgaiak, ERABILTZAILE_t *erabiltzaileak){
	IKASGAI_t *ikasgaiberri;
	if((*ikasgaiak) == NULL){
		(*ikasgaiak) = (IKASGAI_t *)calloc(1, sizeof(IKASGAI_t));
		ikasgaiberri = (*ikasgaiak);
	}else{
		for(ikasgaiberri = (*ikasgaiak);ikasgaiberri->hurrengoa != NULL; ikasgaiberri = ikasgaiberri->hurrengoa);
		ikasgaiberri->hurrengoa = (IKASGAI_t *)calloc(1, sizeof(IKASGAI_t));
		ikasgaiberri = ikasgaiberri->hurrengoa;
	}
		printf("Mesedez, sartu ikasgaiaren izena:\n");
		gets(ikasgaiberri->izena);
		fpurge(stdin);
    ikasgaiberri->irakaslea = aukeratuirakasle(erabiltzaileak);
}
void sortueskola(INDIZEA_t **indizea, ESKOLA_t **eskola, int *idesk){
    INDIZEA_t *berria;
    ESKOLA_t *eskolaberri;
    if ((*indizea) == NULL) {
        (*indizea) = calloc(1, sizeof(INDIZEA_t));
        berria = (*indizea);
    }else{
    for(berria = (*indizea); berria->hurrengoa != NULL; berria = berria ->hurrengoa);
    berria->hurrengoa = calloc(1, sizeof(INDIZEA_t));
    berria = berria->hurrengoa;
    }
    eskolaberri = calloc(1, sizeof(ESKOLA_t));
    system("clear");
    printf("Sartu eskolaren izena mesedez:\n");
    gets(berria->izena);
    fpurge(stdin);
    strcpy(eskolaberri->izena, berria->izena);
    berria->idesk = *idesk;
    eskolaberri->idesk = berria->idesk;
    printf("Eskola berriaren IDa %i da\n", *idesk);
    printf("Sakatu tekla bat jarraitzeko\n");
    getchar();
    fpurge(stdin);
    sortuerabiltzaile(&eskolaberri->erabiltzaileak);
    (*idesk)++;
    (*eskola) = eskolaberri;
    
}
void sortuerabiltzaile(ERABILTZAILE_t **erabiltzaileak){
    ERABILTZAILE_t *berria;
    int init = 0;
    int aukera = 0;
    if((*erabiltzaileak) == NULL){
        berria = calloc(1, sizeof(ERABILTZAILE_t));
        (*erabiltzaileak) = berria;
        init = 1;
    }else{
        for (berria = (*erabiltzaileak); berria->hurrengoa != NULL; berria = berria ->hurrengoa) {
        };
        berria->hurrengoa = calloc(1, sizeof(ERABILTZAILE_t));
        berria = berria->hurrengoa;
    }
    if (init == 1) {
        printf("Adi! Lehenengo erabiltzailea denez, hau idazkaria izango da\n");
        getchar();
        fpurge(stdin);
    }
    printf("Sartu erabiltzaile berriaren izena:\n");
    gets(berria->izena);
    printf("Sartu erabiltzaile berriaren abizena:\n");
    gets(berria->abizena);
    sortuerabiltzaileid(berria);
    do{
    printf("Sartu erabiltzailearen pasahitza(8 karaktere gutxienez:\n");
    gets(berria->pasahitza);
    }while (strlen(berria->pasahitza) < 8);
    if (init == 1) {
        berria->mota = 1;
    }else{
        do{
            printf("Aukeratu erabiltzailearen mota:\n1. Idazkaria\n2. Irakaslea\n");
            scanf("%i", &aukera);
            fpurge(stdin);
        }while((aukera < 1)||(aukera > 2));
        berria->mota = aukera;
    }
    printf("Erabiltzailea sortu da\n");
    getchar();
    fpurge(stdin);
}
#endif
