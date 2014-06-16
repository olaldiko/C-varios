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
	fpurge(stdin);
	printf("%f", nota);
	getchar();
	fpurge(stdin);
	return nota;
}
HELBIDE_t helbideasartu(){
	HELBIDE_t helbidea;
	printf("Helbidea:\n\n");
	printf("Kalea?\n>");
	gets(helbidea.kalea);
	fpurge(stdin);
	printf("\nZenbakia?\n>");
	scanf("%i", &helbidea.zenbakia);
	fpurge(stdin);
	printf("\nPisua?\n>");
	gets(helbidea.pisua);
	fpurge(stdin);
	printf("\nHerria?\n>");
	gets(helbidea.herria);
	fpurge(stdin);
	printf("\nPosta kodea?\n>");
	scanf("%i", &helbidea.postakodea);
	fpurge(stdin);
	return helbidea;
}
JAIO_t jaiotzasartu(){
	JAIO_t jaiotza;
	printf("\nSartu jaioteguna:\n>");
	scanf("%i", &jaiotza.eguna);
	fpurge(stdin);
	printf("\nSartu jaiotze hilabetea:\n>");
	scanf("%i", &jaiotza.hilabetea);
	fpurge(stdin);
	printf("\nSartu jaiotze urtea:\n>");
	scanf("%i", &jaiotza.urtea);
	fpurge(stdin);
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
	fpurge(stdin);
	}while((aukera < 0)&&(aukera > kont));
	for(i = 0, gela = eskola->gelak ; (i <= kont)&&(gela != NULL) ; gela = gela->hurrengoa , i++);
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
                if (irakaslea->mota == 2){
                printf("%i. %s %s\t", kont, irakaslea->izena, irakaslea->abizena);
                if(kont %3 == 0)
                    printf("\n");
                }
            }
            printf("\nAukeratu irakaslea mesedez:\n");
            scanf("%i", &aukera);
            fpurge(stdin);
        }while((aukera < 0)&&(aukera > kont));
        for(i = 0, irakaslea = erabiltzaileak ; (i <= kont)&&(irakaslea != NULL) ; irakaslea = irakaslea->hurrengoa , i++);
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
IKASGAI_t *aukeratuikasgai(IKASGAI_t *ikasgaiak, ERABILTZAILE_t *irakaslea){
    int kont = 0;
    int aukera = 0;
    int i = 0;
    int badaude = 0;
    IKASGAI_t *ikasgaia;
    
    do{
    printf("Aukeratu ikasgaia mesedez");
    for (ikasgaia = ikasgaiak; ikasgaia!= NULL; ikasgaia = ikasgaia->hurrengoa, kont++) {
        if (ikasgaia->irakaslea == irakaslea) {
            printf("%i. %s\n", kont, ikasgaia->izena);
            badaude = 1;
        }
    }
    if (badaude == 1) {
        printf("Aukera: ");
        scanf("%i", &aukera);
        fpurge(stdin);
    }else{
        printf("Ikasle honek ez ditu zuk emandako ikasgairik\n");
        return NULL;
    }
    }while (((aukera < 0)||(aukera > kont))&&(badaude == 1));
    for (ikasgaia = ikasgaiak, i = 0; ((ikasgaia != NULL)&&(i <= kont)); ikasgaia = ikasgaia->hurrengoa, i++);
    return ikasgaia;
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
    system("clear");
    printf("--------------------------ONGI ETORRI GESTIO SISTEMARA----------------------\n");
    printf("Sartu zure erabiltzaile IDa:\n>");
    gets(ida);
    fpurge(stdin);
    printf("Sartu zure pasahitza:\n>");
    gets(pasahitza);
    fpurge(stdin);
    for(erabiltzailea = erabiltzaileak; (((strcmp(erabiltzailea->ida,ida) != 0)||(strcmp(erabiltzailea->pasahitza, pasahitza) != 0))&&(erabiltzailea != NULL)); erabiltzailea = erabiltzailea->hurrengoa);
    if(erabiltzailea == NULL){
        printf("Erabiltzailea ez da aurkitu\n");
        getchar();
        fpurge(stdin);
    }else{
        if(erabiltzailea->sartuda == 0){
            printf("sartzen zaren lehenengo aldia da, mesedez, sartu pasahitz berri bat(minimo 8 karaktere)\n");
            gets(erabiltzailea->pasahitza);
            fpurge(stdin);
            while(strlen(pasahitza)< 8){
                printf("Pasahitzak ez ditu minimoak betetzen, saiatu berriz\n");
                gets(erabiltzailea->pasahitza);
                fpurge(stdin);
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
            fpurge(stdin);
        }while((aukera < 0)&&(aukera > kont));
        for(i = 0, eskola = indizea ; (i <= kont)&&(eskola != NULL) ; eskola = eskola->hurrengoa , i++);
        return eskola;
    }
    
}
void sortuerabiltzaileid(ERABILTZAILE_t *erabiltzailea){
    char iderabil[50];
    strncat(iderabil, erabiltzailea->izena, 6);
    strncat(iderabil, erabiltzailea->abizena, 8);
    printf("Erabiltzaile ID berria ---%s--- da (Sakatu enter jarritzeko)\n", iderabil);
    getchar();
    fpurge(stdin);
    strcpy(erabiltzailea->ida, iderabil);
}
#endif