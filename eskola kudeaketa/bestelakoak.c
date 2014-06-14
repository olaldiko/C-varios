#ifndef BESTELAKOAK_C
#define BESTELAKOAK_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
float notaksartu(){
	float nota = 0;
	printf("Mesedez, sartu ikasgaiaren nota:\n");
	scanf("%f", &nota);
	fflush(stdin);
	printf("%f", nota);
	getchar();
	fflush(stdin);
	return nota;
}
HELBIDE_t helbideasartu(){
	HELBIDE_t helbidea;
	printf("Helbidea:\n\n");
	printf("Kalea?\n>");
	gets(helbidea.kalea);
	fflush(stdin);
	printf("\nZenbakia?\n>");
	scanf("%i", &helbidea.zenbakia);
	fflush(stdin);
	printf("\nPisua?\n>");
	gets(helbidea.pisua);
	fflush(stdin);
	printf("\nHerria?\n>");
	gets(helbidea.herria);
	fflush(stdin);
	printf("\nPosta kodea?\n>");
	scanf("%i", &helbidea.postakodea);
	fflush(stdin);
	return helbidea;
}
JAIO_t jaiotzasartu(){
	JAIO_t jaiotza;
	printf("\nSartu jaioteguna:\n>");
	scanf("%i", &jaiotza.eguna);
	fflush(stdin);
	printf("\nSartu jaiotze hilabetea:\n>");
	scanf("%i", &jaiotza.hilabetea);
	fflush(stdin);
	printf("\nSartu jaiotze urtea:\n>");
	scanf("%i", &jaiotza.urtea);
	fflush(stdin);
	return jaiotza;
}
void kopiatuikasgai(GELA_t *gela, IKASGAI_t **ikasdest){
	IKASGAI_t *hasiera;
	IKASGAI_t *ikasgai;
	ikasgai = gela->stdikasgaiak;
	(*ikasdest) = (IKASGAI_t*)calloc(1, sizeof(IKASGAI_t));
	hasiera = (*ikasdest);
	do{
		memcpy(&(*ikasdest), &ikasgai, sizeof(IKASGAI_t));
		if(ikasgai->hurrengoa != NULL){
		(*ikasdest)->hurrengoa = (IKASGAI_t*)calloc(1, sizeof(IKASGAI_t));
		(*ikasdest) = (*ikasdest)->hurrengoa;
		}
		ikasgai = ikasgai->hurrengoa;
	}while(ikasgai != NULL);
	(*ikasdest) = hasiera;
}
GELA_t *aukeratugela(ESKOLA_t *eskola){
	GELA_t *gela;
	int i = 0;
	int kont = 0;
	int aukera = 0;
	gela = eskola->gelak;
	if(gela == NULL){
		printf("------------------------------Ez daude Gelarik----------------------------");
		return NULL;
	}else{
	do{
	for(gela = eskola->gelak;gela !=NULL; gela = gela->hurrengoa, kont++){
		printf("%i. %s\t", kont, gela->gelafisikoa);
		if(kont %3 == 0)
			printf("\n");

	}
	printf("\nAukeratu gela mesedez:\n");
	scanf("%i", &aukera);
	fflush(stdin);
	}while((aukera < 0)&&(aukera < kont));
	for(i = 0, gela = eskola->gelak ; i <= kont ; gela = gela->hurrengoa , i++);
	return gela;
}
}
POSI_t aurkituikasle(int idal, ESKOLA_t *eskola){
	POSI_t posizioa;
	int aurkitua = 0;
	posizioa.gelaikas = eskola->gelak;
	while ((posizioa.gelaikas != NULL)&&(aurkitua == 0)){
		posizioa.ikaslea = posizioa.gelaikas->ikasleak;
		while((posizioa.ikaslea != NULL)&&(aurkitua == 0)){
			if(posizioa.ikaslea->idal == idal){
				aurkitua = 1;
			}
			posizioa.ikaslea = posizioa.ikaslea->hurrengoa;
		}
		posizioa.gelaikas = posizioa.gelaikas->hurrengoa;
	}
	return posizioa;
}
float notakbatazbesteko(IKASGAI_t *ikasgaiak){
    IKASGAI_t *ikasgaia;
    float nota = 0;
    int i = 0;
    for(ikasgaia = ikasgaiak; ikasgaia != NULL;ikasgaia = ikasgaia->hurrengoa, i++){
        nota = nota + ikasgaiak->nota;
    }
	nota = nota/(i+1);
    return nota;
}
#endif