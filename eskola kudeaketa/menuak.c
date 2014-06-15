#ifndef MENUAK_C
#define MENUAK_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "bistaraketak.h"
#include "borraketak.h"
#include "modifikazioak.h"
#include "sorketak.h"
#include "menuak.h"
#include "datuak.h"
#define ADMINUSER "scott"
#define ADMINPASS "tiger"
void menusortuikasgai(IKASGAI_t **ikasgaiak, ERABILTZAILE_t *erabiltzaileak){
	int aukera = 0;
	system("clear");
	while(aukera != 2){
	printf("---------------------IKASGAIAK SORTZEKO MENUA------------------------\n");
	printf("1.\t Ikasgai bat sortu:\n");
	printf("2.\t Amaitu dut, irten:\n");
	scanf("%i", &aukera);
	if(aukera == 1){
		sortuikasgai(ikasgaiak, erabiltzaileak);
	}
	}
}
void sartunotakmenu(IKASGAI_t **ikasgaiak, ERABILTZAILE_t *irakaslea){
	int kont = 1;
	int aukera = 1;
	IKASGAI_t *ikasgaia;
	printf("-------------------AUKERATU IKASGAI BAT----------------------\n");
	for (ikasgaia = (*ikasgaiak);ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa, kont++){
		if(ikasgaia->irakaslea == irakaslea){
			printf("%i\t %s", kont, ikasgaia->izena);
		}
	}
	scanf("%i", &aukera);
	for(ikasgaia = (*ikasgaiak); (ikasgaia != NULL)&&(aukera < kont);ikasgaia = ikasgaia->hurrengoa);
	if(ikasgaia == NULL){
		printf("Ez duzu ikasgaia ondo aukeratu\n");
	}else{
		ikasgaia->nota = notaksartu();
	}

}
void menueskolanagusia(ESKOLA_t *eskola){
    ERABILTZAILE_t *erabiltzailea;
    int aukera = 0;
    do{
        system("clear");
        printf("---------Ongi etorri %s eskolaren gestio programara-------------\n", eskola->izena);
        printf("1. Sartu erabiltzaile erregistratu batekin\n");
        printf("2. Sartu ikasle gisa\n");
        printf("0. Irten\n");
        printf("Aukera ");
        scanf("%i", &aukera);
    }while((aukera < 0)&&(aukera > 2));
    if(aukera == 1){
    erabiltzailea = loginmenu(eskola->erabiltzaileak);
    switch (erabiltzailea->mota) {
        case 1:
          //  menuidazkaria(eskola);
            break;
        case 2:
          //  menuirakasle(eskola);
            break;
    }
    }else{
        if (aukera == 2){
       //     menuikasle(eskola);
        }
    }
}
void menuidazk(ESKOLA_t **eskola){
	int aukera=0;
	GELA_t *gela;
	while(aukera != 8){
		system("clear");
		printf("******************************************\n");
		printf("** 1-Ikasle bat sartu                   **\n");
		printf("** 2-Ikasle baten datuak modifikatu     **\n");
		printf("** 3-Ikasle bat ikusi                   **\n");
		printf("** 4-Ikasle bat mugitu                  **\n");
		printf("** 5-Ikasle bat kendu                   **\n");
		printf("** 6-Gela bateko datuak modifikatu      **\n");
		printf("** 7-Gela bateko ikasle guztiak ikusi   **\n");
		printf("** 8-Irten                              **\n");
		printf("******************************************\n");
		scanf("%i", &aukera);
		fflush(stdin);
        
		switch(aukera){
			case 1:
				sortuikasle(eskola);
				break;
			case 2:
                modifikatuikasle(eskola);
				break;
                
			case 3:
				bistaratuikasle((*eskola));
				break;
			case 4:
				mugituikasle(eskola);
				break;
			case 5:
				borratuikasle((*eskola));
				break;
                
			case 6:
				modifikatugela(eskola);
				break;
                
			case 7:
				gela = aukeratugela((*eskola));
				bistaratunotakgela(gela);
				break;
			case 8:
				printf("Irtetzen...");
				break;
			default:
				printf("Zure aukera ez dago eskuragarri, saiatu berriz");
				break;
                
		}
	}
    
}
void menuadmin(INDIZEA_t **indizea, int *eskolakop){
    char erabiltzailea[50];
    char pasahitza[50];
    int aukera = 0;
    do{
    system("clear");
    printf("Sartu admin erabiltzailea:\n>");
    gets(erabiltzailea);
    fpurge(stdin);
    printf("Sartu pasahitza:\n>");
    gets(pasahitza);
    fpurge(stdin);
    }while((strcmp(erabiltzailea, ADMINUSER) != 0)||(strcmp(pasahitza, ADMINPASS) != 0));
    do{
        system("clear");
        printf("--------------------------ADMIN MENUA---------------------------\n");
        printf("1. Sortu eskola bat\n");
        printf("2. Ezabatu eskola bat\n");
        printf("0. Irten\n");
        printf("----------------------------------------------------------------\n");
        printf("Aukera: ");
        scanf("%i", &aukera);
        fpurge(stdin);
    }while((aukera < 0)&&(aukera > 2));
    switch (aukera) {
        case 1:
           sortueskola(indizea, eskolakop);
            break;
        case 2:
          //  borratueskola(indizea, eskolakop);
            break;
        default:
            break;
    }
}
void menunagusia(INDIZEA_t *indizea, int *eskolakop){
    int aukera = 0;
    INDIZEA_t *eskolaindex;
    ESKOLA_t *eskola;
    do{
        system("clear");
        printf("-------------------Ongi etorri eskola kudeaketa programara-----------------\n");
        printf("1. Sartu erabiltzaile normal gisa\n");
        printf("2. Sartu administratzaile gisa\n");
        printf("0. Irten");
        printf("---------------------------------------------------------------------------\n");
        printf("Aukera: ");
        scanf("%i", &aukera);
        fpurge(stdin);
    }while((aukera < 0)&&(aukera > 2));
    switch (aukera) {
        case 1:
            eskolaindex = aukeratueskola(indizea);
            //eskola = kargatueskola(eskolaindex);
            menueskolanagusia(eskola);
            break;
        case 2:
            menuadmin(&indizea, eskolakop);
        default:
            break;
    }
    
}
#endif