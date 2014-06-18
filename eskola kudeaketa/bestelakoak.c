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
    printf("\nTelefonoa?\n>");
    gets(helbidea.telefonoa);
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
	IKASGAI_t *ikasgai;
    IKASGAI_t *dest;
	ikasgai = gela->stdikasgaiak;
	while (ikasgai != NULL) {
        if ((*ikasdest) == NULL) {
            (*ikasdest) = calloc(1, sizeof(IKASGAI_t));
            dest = (*ikasdest);
        }else{
            dest->hurrengoa = calloc(1, sizeof(IKASGAI_t));
            dest = dest->hurrengoa;
        }
        memcpy(dest, ikasgai, sizeof(IKASGAI_t));
        ikasgai = ikasgai->hurrengoa;
    }
    
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
	for(i = 0, gela = eskola->gelak ; (i <aukera)&&(gela != NULL) ; gela = gela->hurrengoa , i++);
	return gela;
}
}
ERABILTZAILE_t *aukeratuirakasle(ERABILTZAILE_t *erabiltzaileak){
	ERABILTZAILE_t *irakaslea;
	int i = 0;
	int kont = 0;
	int aukera = 0;
    int badaude = 0;
	irakaslea = erabiltzaileak;
	if(irakaslea == NULL){
		printf("------------------------------Ez daude erabiltzailerik----------------------------\n");
		return NULL;
	}else{
        do{
            for(;irakaslea !=NULL; irakaslea = irakaslea->hurrengoa, kont++){
                if (irakaslea->mota == 2){
                    badaude = 1;
                printf("%i. %s %s\t", kont, irakaslea->izena, irakaslea->abizena);
                if(kont %3 == 0)
                    printf("\n");
                }
            }
            if (badaude == 1){
            printf("\nAukeratu irakaslea mesedez:\n");
            scanf("%i", &aukera);
            fpurge(stdin);
            }
        }while((aukera < 0)&&(aukera > kont));
        if (badaude == 1){
            for(i = 0, irakaslea = erabiltzaileak ; (i < aukera)&&(irakaslea != NULL) ; irakaslea = irakaslea->hurrengoa , i++);
            return irakaslea;
        }else{
            return NULL;
        }
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
			}else{
			posizioa.ikaslea = posizioa.ikaslea->hurrengoa;
            }
		}
        if (aurkitua != 1) {
		posizioa.gelaikas = posizioa.gelaikas->hurrengoa;
        }
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
    printf("Aukeratu ikasgaia mesedez\n");
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
        getchar();
        fpurge(stdin);
        return NULL;
    }
    }while (((aukera < 0)||(aukera > kont))&&(badaude == 1));
    for (ikasgaia = ikasgaiak, i = 0; ((ikasgaia != NULL)&&(i < aukera)); ikasgaia = ikasgaia->hurrengoa, i++);
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
    for(erabiltzailea = erabiltzaileak; (((strcmp(erabiltzailea->ida,ida) != 0)||(strcmp(erabiltzailea->pasahitza, pasahitza) != 0))&&(erabiltzailea->hurrengoa != NULL)); erabiltzailea = erabiltzailea->hurrengoa);
    if(erabiltzailea == NULL){
        printf("Erabiltzailea ez da aurkitu\n");
        getchar();
        fpurge(stdin);
    }else{
        if (((strcmp(erabiltzailea->ida,ida) == 0)&&(strcmp(erabiltzailea->pasahitza, pasahitza) == 0))){
            if(erabiltzailea->sartuda == 0){
                printf("sartzen zaren lehenengo aldia da, mesedez, sartu pasahitz berri bat(minimo 8 karaktere)\n");
                gets(erabiltzailea->pasahitza);
                fpurge(stdin);
                while(strlen(erabiltzailea->pasahitza)< 8){
                    printf("Pasahitzak ez ditu minimoak betetzen, saiatu berriz\n");
                    gets(erabiltzailea->pasahitza);
                    fpurge(stdin);
                }
                printf("Pasahitza aldatu egin da\n");
                getchar();
                fpurge(stdin);
                erabiltzailea->sartuda = 1;
            }
        }else{
            printf("Pasahitza ez da zuzena, saiatu berriz\n");
            getchar();
            fpurge(stdin);
            erabiltzailea = NULL;
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
		printf("\n------------------------------Ez daude eskolarik----------------------------\n");
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
        }while((aukera < 0)||(aukera > kont));
        for(i = 0, eskola = indizea ; (i < aukera)&&(eskola->hurrengoa != NULL) ; eskola = eskola->hurrengoa , i++);
        return eskola;
    }
    
}
void sortuerabiltzaileid(ERABILTZAILE_t *erabiltzailea){
    char iderabil[50];
    strncat(iderabil, erabiltzailea->izena, 2);
    strncat(iderabil, erabiltzailea->abizena, 8);
    printf("Erabiltzaile ID berria ---%s--- da (Sakatu enter jarritzeko)\n", iderabil);
    getchar();
    fpurge(stdin);
    strcpy(erabiltzailea->ida, iderabil);
}
ERABILTZAILE_t *aurkituerabiltzaile(ERABILTZAILE_t *erabiltzaileak, char iderabil[]){
    if (strcmp(iderabil, "--")== 0) {
        return NULL;
    }else{
    for (; ((strcmp(erabiltzaileak->ida, iderabil)!= 0)&&(erabiltzaileak != NULL)); erabiltzaileak = erabiltzaileak->hurrengoa);
    return erabiltzaileak;
    }
    }
#endif