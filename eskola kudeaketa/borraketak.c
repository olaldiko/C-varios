#ifndef BORRAKETAK_C
#define BORRAKETAK_C
#include <stdio.h>
#include <stdlib.h>
#include "borraketak.h"
#include "egiturak.h"
#include "bestelakoak.h"

void borratuGela(ESKOLA_t *eskola){
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

void borratuIkasle(ESKOLA_t *eskola){
	IKASLE_t *hasiera;
	IKASLE_t *ikasleaux;
	IKASLE_t *temp;
	POSI_t pos;
	int id;
	printf("\nSartu bilatu nahi duzun ikaslearen id-a :  ");
	scanf("%i", &id);
	pos.gelaikas = aukeratugela(eskola);                        //Esto hay que tocarlo, esta mal
	if (pos.gelaikas != NULL){
		hasiera = pos.gelaikas->ikasleak;
		ikasleaux = hasiera;
		if (ikasleaux == pos.ikaslea){
			temp = ikasleaux;
			ikasleaux = ikasleaux->hurrengoa;
			free(temp);
			pos.gelaikas->ikasleak = ikasleaux;
		}
		else{
			while (ikasleaux->hurrengoa != pos.ikaslea || ikasleaux->hurrengoa != NULL){
				ikasleaux = ikasleaux->hurrengoa;
			}
			if (ikasleaux->hurrengoa == pos.ikaslea){
				temp = ikasleaux->hurrengoa;
				ikasleaux->hurrengoa = ikasleaux->hurrengoa->hurrengoa;
				free(temp);
			}
		}
	}
}
#endif
