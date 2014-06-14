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