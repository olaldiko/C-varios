#ifndef MENUAK_C
#define MENUAK_C
#include <stdio.h>
#include <stdlib.h>
#include "egiturak.h"
#include "bestelakoak.h"
#include "sorketak.h"
#include "menuak.h"
void menusortuikasgai(IKASGAI_t **ikasgaiak){
	int aukera = 0;
	system("CLS");
	while(aukera != 2){
	printf("---------------------IKASGAIAK SORTZEKO MENUA------------------------\n");
	printf("1.\t Ikasgai bat sortu:\n");
	printf("2.\t Amaitu dut, irten:\n");
	scanf("%i", &aukera);
	if(aukera == 1){
		sortuikasgai(ikasgaiak);
	}
	}
}
void sartunotakmenu(IKASGAI_t **ikasgaiak, int idirak){
	int kont = 1;
	int aukera = 1;
	IKASGAI_t *ikasgaia;
	printf("-------------------AUKERATU IKASGAI BAT----------------------\n");
	for (ikasgaia = (*ikasgaiak);ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa, kont++){
		if(ikasgaia->ida == idirak){
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
#endif