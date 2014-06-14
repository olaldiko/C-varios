#ifndef MENUAK_C
#define MENUAK_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "sorketak.h"
#include "menuak.h"
#include "datuak.h"
#define ADMINUSER "scott"
#define ADMINPASS "tiger"
void menusortuikasgai(IKASGAI_t **ikasgaiak, ERABILTZAILE_t *erabiltzaileak){
	int aukera = 0;
	system("CLS");
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
        system("CLS");
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
void menuadmin(INDIZEA_t **indizea){
    char erabiltzailea[50];
    char pasahitza[50];
    int aukera = 0;
    do{
    system("CLS");
    printf("Sartu admin erabiltzailea:\n>");
    gets(erabiltzailea);
    fflush(stdin);
    printf("Sartu pasahitza:\n>");
    gets(pasahitza);
    }while((strcmp(erabiltzailea, ADMINUSER) != 0)&&(strcmp(pasahitza, ADMINPASS) != 0));
    do{
        system("CLS");
        printf("--------------------------ADMIN MENUA---------------------------\n");
        printf("1. Sortu eskola bat\n");
        printf("2. Ezabatu eskola bat\n");
        printf("0. Irten\n");
        printf("----------------------------------------------------------------\n");
        printf("Aukera: ");
        scanf("%i", &aukera);
        fflush(stdin);
    }while((aukera < 0)&&(aukera > 2));
    switch (aukera) {
        case 1:
           // sortueskola(indizea);
            break;
        case 2:
          //  borratueskola(indizea);
            break;
        default:
            break;
    }
}
void menunagusia(INDIZEA_t *indizea){
    int aukera = 0;
    FILE *eskolafitx;
    ESKOLA_t *eskola;
    do{
        system("CLS");
        printf("-------------------Ongi etorri eskola kudeaketa programara-----------------\n");
        printf("1. Sartu erabiltzaile normal gisa\n");
        printf("2. Sartu administratzaile gisa\n");
        printf("0. Irten");
        printf("---------------------------------------------------------------------------\n");
        printf("Aukera: ");
        scanf("%i", &aukera);
    }while((aukera < 0)&&(aukera > 2));
    switch (aukera) {
        case 1:
            eskolafitx = aukeratueskola(indizea);
            //eskola = kargatueskola(eskolafitx);
            break;
            
        default:
            break;
    }
    
}
#endif