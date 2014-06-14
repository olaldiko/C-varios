#ifndef SORKETAK_C
#define SORKETAK_C
#include <stdio.h>
#include <stdlib.h>
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
	fflush(stdin);
	printf("Sartu ikaslearen abizenak");
	gets(ikaslea->abizenak);
	ikaslea->helbidea = helbideasartu();
	ikaslea->jaiotza = jaiotzasartu();
	kopiatuikasgai(gela, &ikaslea->ikasgaiak);
}
void sortugela(ESKOLA_t **eskola){
	GELA_t *gelaberri;
	GELA_t *gelak;
	gelaberri = (GELA_t *)calloc(1, sizeof(GELA_t));
	system("CLS");
	printf("Mesedez, sartu gelaren izena:\n");
	gets(gelaberri->gelafisikoa);
	fflush(stdin);
	printf("Sartu tutorearen izena:\n");
	gets(gelaberri->tutorea);
	printf("Sartu gelaren maila:\n");
	gets(gelaberri->maila);
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
		fflush(stdin);
    ikasgaiberri->irakaslea = aukeratuirakasle(erabiltzaileak);
}
#endif
