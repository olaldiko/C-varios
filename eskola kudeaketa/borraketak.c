#ifndef BORRAKETAK_C
#define BORRAKETAK_C
#include <stdio.h>
#include <stdlib.h>
#include "borraketak.h"
#include "egiturak.h"
#include "bestelakoak.h"
#include "datuak.h"

void borratugela(ESKOLA_t *eskola){
	GELA_t *gela;
	GELA_t *hasiera;
	GELA_t *gelaux;
	GELA_t *temp;
	hasiera = eskola->gelak;
	gelaux = hasiera;
	gela = aukeratugela(eskola);
	if (gela != NULL){
		if (gelaux == gela){
			temp = gelaux;
			gelaux = gelaux->hurrengoa;
			free(temp);
			eskola->gelak = gelaux;
		}
		else{
			while ((gelaux->hurrengoa != gela) || (gelaux->hurrengoa != NULL)){
				gelaux = gelaux->hurrengoa;
			}
			if (gelaux->hurrengoa == gela){
				temp = gelaux->hurrengoa;
				gelaux->hurrengoa = gelaux->hurrengoa->hurrengoa;
				free(temp);
			}
		}
	}
}

void borratuikasle(ESKOLA_t *eskola){
	IKASLE_t *ikasleaux;
	POSI_t pos;
	int id;
	printf("\nSartu bilatu nahi duzun ikaslearen id-a :  ");
	scanf("%i", &id);
    pos = aurkituikasle(id, eskola);
    if (pos.ikaslea == NULL) {
        printf("Ikaslea ez da aurkitu\n");
    }else{
        if (pos.ikaslea == pos.gelaikas->ikasleak) {
            pos.gelaikas->ikasleak = pos.ikaslea->hurrengoa;
        }else{
            for (ikasleaux = pos.gelaikas->ikasleak; ikasleaux->hurrengoa != pos.ikaslea; ikasleaux = ikasleaux->hurrengoa);
            if(pos.ikaslea->hurrengoa!= NULL){
                ikasleaux->hurrengoa = pos.ikaslea->hurrengoa;
            }else{
                ikasleaux->hurrengoa = NULL;
            }
        }
        free(pos.ikaslea);
        pos.gelaikas->ikasle_kop--;
    }
}
void borratueskola(INDIZEA_t **indizea, int *idesk){
    INDIZEA_t *eskolaind;
    INDIZEA_t *hasiera;
    char fitxategia[50];
    eskolaind = aukeratueskola((*indizea));
    if (eskolaind != NULL) {
    if  (eskolaind == (*indizea)){
        (*indizea) = (*indizea)->hurrengoa;
    }else{
        for (hasiera = (*indizea); hasiera->hurrengoa != eskolaind; hasiera = hasiera ->hurrengoa);
        hasiera->hurrengoa = eskolaind->hurrengoa;
    }
    sprintf(fitxategia, "rm ./e%ie.csv", eskolaind->idesk);
    system("fitxategia");
    sprintf(fitxategia, "rm -r \"./e%ie\"", eskolaind->idesk); //Utilizar system y rm es una guarrada, lo se... con mas tiempo hago una recursiva con remove();
    system(fitxategia);
    free(eskolaind);
    indizeagorde((*indizea), idesk);
    }
    printf("\nSakatu tekla bat jarraitzeko");
    getchar();
    fpurge(stdin);
}
#endif
