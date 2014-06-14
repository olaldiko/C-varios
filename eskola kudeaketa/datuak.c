//
//  datuak.c
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 14/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//
#ifndef DATUAK_C
#define DATUAK_C
#include <stdio.h>
#include <stdlib.h>
#include "egiturak.h"
FILE *aukeratueskola(INDIZEA_t *indizesk){
    INDIZEA_t *indizea;
    int kont = 0;
    int aukera = 0;
    do{
        system("CLS");
        printf("------------------Aukeratu zure eskola mesedez--------------------\n");
        for(indizea = indizesk; indizea != NULL; indizea = indizea->hurrengoa, kont++){
            printf("%i. %s\n", kont, indizea->izena);
        }
        printf("--------------------------------------------------------------------");
    }while((aukera < 0)&&(aukera > kont));
    printf("Aukera: ");
    scanf("%i", &aukera);
    for (indizea = indizesk; aukera >= kont; indizea = indizea->hurrengoa);
    return fopen(indizea->fitxategia, "rb");
}
INDIZEA_t *kargatuindizea(char fitxategia[]){
    FILE *indizea;
    INDIZEA_t *indexa;
    INDIZEA_t *hasiera = NULL;
    indizea = fopen(fitxategia, "rb");
    if(indizea == NULL){
        printf("Ezin izan da fitxategia irakurri");
    }else{
        indexa = calloc(1, sizeof(indexa));
        hasiera = indexa;
        while(!feof(indizea)){
            fread(indexa, 1, sizeof(INDIZEA_t), indizea);
            indexa->hurrengoa = calloc(1, sizeof(INDIZEA_t));
            indexa = indexa->hurrengoa;
    }

}
    return hasiera;
}
#endif