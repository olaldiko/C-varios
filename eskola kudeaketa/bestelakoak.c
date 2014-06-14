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
		printf("------------------------------Ez daude Gelarik----------------------------\n");
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
	}while((aukera < 0)&&(aukera > kont));
	for(i = 0, gela = eskola->gelak ; i <= kont ; gela = gela->hurrengoa , i++);
	return gela;
}
}
ERABILTZAILE_t *aukeratuirakasle(ERABILTZAILE_t *erabiltzaileak){
	ERABILTZAILE_t *irakaslea;
	int i = 0;
	int kont = 0;
	int aukera = 0;
	irakaslea = erabiltzaileak;
	if(irakaslea == NULL){
		printf("------------------------------Ez daude erabiltzailerik----------------------------\n");
		return NULL;
	}else{
        do{
            for(;irakaslea !=NULL; irakaslea = irakaslea->hurrengoa, kont++){
                printf("%i. %s %s\t", kont, irakaslea->izena, irakaslea->abizena);
                if(kont %3 == 0)
                    printf("\n");
            }
            printf("\nAukeratu irakaslea mesedez:\n");
            scanf("%i", &aukera);
            fflush(stdin);
        }while((aukera < 0)&&(aukera > kont));
        for(i = 0, irakaslea = erabiltzaileak ; i <= kont ; irakaslea = irakaslea->hurrengoa , i++);
        return irakaslea;
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
ERABILTZAILE_t *loginmenu(ERABILTZAILE_t *erabiltzaileak){
    char ida[30];
    char pasahitza[50];
    ERABILTZAILE_t *erabiltzailea;
    do{
    system("CLS");
    printf("--------------------------ONGI ETORRI GESTIO SISTEMARA----------------------\n");
    printf("Sartu zure erabiltzaile IDa:\n>");
    gets(ida);
    fflush(stdin);
    printf("Sartu zure pasahitza:\n>");
    gets(pasahitza);
    for(erabiltzailea = erabiltzaileak; (((strcmp(erabiltzailea->ida,ida) != 0)||(strcmp(erabiltzailea->pasahitza, pasahitza) != 0))&&(erabiltzailea != NULL)); erabiltzailea = erabiltzailea->hurrengoa);
    if(erabiltzailea == NULL){
        printf("Erabiltzailea ez da aurkitu\n");
        getchar();
        fflush(stdin);
    }else{
        if(erabiltzailea->sartuda == 0){
            printf("sartzen zaren lehenengo aldia da, mesedez, sartu pasahitz berri bat(minimo 8 karaktere)\n");
            gets(erabiltzailea->pasahitza);
            fflush(stdin);
            while(strlen(pasahitza)< 8){
                printf("Pasahitzak ez ditu minimoak betetzen, saiatu berriz\n");
                gets(erabiltzailea->pasahitza);
            }
            printf("Pasahitza aldatu egin da\n");
            erabiltzailea->sartuda = 1;
        }
    }
    }while(erabiltzailea == NULL);
    return erabiltzailea;
}
INDIZEA_t *aukeratueskola(INDIZEA_t *indizea){
    INDIZEA_t *eskola;
	int i = 0;
	int kont = 0;
	int aukera = 0;
	eskola = indizea;
	if(indizea == NULL){
		printf("------------------------------Ez daude eskolarik----------------------------\n");
		return NULL;
	}else{
        do{
            for(;eskola !=NULL; eskola = eskola->hurrengoa, kont++){
                printf("%i. %s %i\t", kont, eskola->izena, eskola->idesk);
                if(kont %3 == 0)
                    printf("\n");
            }
            printf("\nAukeratu eskola mesedez:\n");
            scanf("%i", &aukera);
            fflush(stdin);
        }while((aukera < 0)&&(aukera > kont));
        for(i = 0, eskola = indizea ; i <= kont ; eskola = eskola->hurrengoa , i++);
        return eskola;
    }
    
}
#endif