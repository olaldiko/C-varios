#ifndef SORKETAK_C
#define SORKETAK_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "menuak.h"

void sortuikasle(ESKOLA_t **eskola){
	IKASLE_t *ikaslea;
	GELA_t *gela;
	gela = aukeratugela(*eskola);
	ikaslea = gela->ikasleak;
	while(ikaslea != NULL){
		ikaslea = ikaslea->hurrengoa;
	}
	ikaslea = (IKASLE_t*)calloc(1, sizeof(IKASLE_t));
	printf("Mesedez, sartu ikaslearen izena\n");
	gets(ikaslea->izena);
	fpurge(stdin);
	printf("Sartu ikaslearen abizenak");
	gets(ikaslea->abizenak);
    fpurge(stdin);
	ikaslea->helbidea = helbideasartu();
	ikaslea->jaiotza = jaiotzasartu();
	kopiatuikasgai(gela, &ikaslea->ikasgaiak);
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
		for(ikasgaiberri = (*ikasgaiak);ikasgaiberri ->hurrengoa != NULL; ikasgaiberri = ikasgaiberri->hurrengoa);
		ikasgaiberri->hurrengoa = (IKASGAI_t *)calloc(1, sizeof(IKASGAI_t));
		ikasgaiberri = ikasgaiberri->hurrengoa;
	}
		printf("Mesedez, sartu ikasgaiaren izena:\n");
		gets(ikasgaiberri->izena);
		fpurge(stdin);
    ikasgaiberri->irakaslea = aukeratuirakasle(erabiltzaileak);
}
void sortueskola(INDIZEA_t **indizea, int *eskolakop){
    INDIZEA_t *berria;
    FILE *eskolafitx;
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
    printf("Sartu eskolaren IDa:\n");
    scanf("%i", &berria->idesk);
    fpurge(stdin);
    eskolaberri->idesk = berria->idesk;
    printf("Sartu eskola berriaren fitxategiaren izena:\n");
    gets(berria->fitxategia);
    fpurge(stdin);
    eskolafitx = fopen(berria->fitxategia, "wb");
    fwrite(eskolaberri, sizeof(eskolaberri), 1, eskolafitx);
    (*eskolakop)++;
    
}
#endif
