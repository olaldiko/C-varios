//
//  datuak.c
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 14/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//
#ifndef DATUAK_C
#define DATUAK_C
#define TOK ";\n"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egiturak.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "datuak.h"
#include "bestelakoak.h"
void indizeagorde(INDIZEA_t *indizea, int *idesk){
    FILE *index;
    index = fopen("indizea.csv", "w");
    fprintf(index, "%i\n", *idesk);
    for(;indizea != NULL; indizea = indizea->hurrengoa){
        fprintf(index, "%s;%i\n", indizea->izena, indizea->idesk);
    }
    fclose(index);
}
void eskolagorde(ESKOLA_t *eskola, int idesk){
    struct stat st = {0};
    FILE *eskolafitx;
    char fitxategia[50];
        sprintf(fitxategia, "./e%ie.csv", eskola->idesk);
        eskolafitx = fopen(fitxategia, "w");
        fprintf(eskolafitx, "%s;%i;%i;%i\n", eskola->izena, eskola->idikasle, eskola->iderabil, eskola->idgela);
        fclose(eskolafitx);
        sprintf(fitxategia, "./e%ie", eskola->idesk);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
    if (eskola->erabiltzaileak != NULL) {
        erabiltzaileakgorde(eskola);
    }
    if (eskola->gelak != NULL) {
        gelakgorde(eskola);
    }
}
void erabiltzaileakgorde(ESKOLA_t *eskola){
    ERABILTZAILE_t *erabiltzailea;
    FILE *erabilfitx;
    char fitxategia[50];
    sprintf(fitxategia, "./e%ie/e%ierabil.csv", eskola->idesk, eskola->idesk);
    erabilfitx = fopen(fitxategia, "w");
    fprintf(erabilfitx, "Izena\tAbizena\tPasahitza\tSartuta\tIDa\tMota\n");
    for(erabiltzailea = eskola->erabiltzaileak; erabiltzailea!= NULL; erabiltzailea = erabiltzailea->hurrengoa){
        fprintf(erabilfitx, "%s;%s;%s;%i;%s;%i\n", erabiltzailea->izena, erabiltzailea->abizena, erabiltzailea->pasahitza, erabiltzailea->sartuda, erabiltzailea->ida, erabiltzailea->mota);
    }
    fclose(erabilfitx);
}
void gelakgorde(ESKOLA_t *eskola){
    struct stat st = {0};
    GELA_t *gela;
    FILE *gelafitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/e%igelak.csv", eskola->idesk, eskola->idesk);
    gelafitx = fopen(fitxategia, "w");
    fprintf(gelafitx, "IDa\tMaila\tIKop\tGela Fisikoa\tTutorea\n");
    for (gela = eskola->gelak; gela != NULL; gela = gela->hurrengoa) {
        fprintf(gelafitx, "%i;%s;%i;%s;%s\n", gela->idgela, gela->maila, gela->ikasle_kop, gela->gelafisikoa, gela->tutorea);
        sprintf(fitxategia, "./e%ie/g%ig", eskola->idesk, gela->idgela);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
        if (gela->ikasleak != NULL){
            ikasleakgorde(gela, eskola->idesk);
        }
        if (gela->stdikasgaiak != NULL){
            stdikasgaiakgorde(gela, eskola->idesk);
        }
    }
    fclose(gelafitx);
}
void ikasleakgorde(GELA_t *gela, int idesk){
    struct stat st = {0};
    IKASLE_t *ikaslea;
    FILE *ikaslefitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%iikasleak.csv", idesk, gela->idgela, gela->idgela);
    ikaslefitx = fopen(fitxategia, "w");
    fprintf(ikaslefitx,"IDa\tIzena\tAbizena\tHelbidea\tJaiotza\n");
    for (ikaslea = gela->ikasleak; ikaslea != NULL; ikaslea = ikaslea->hurrengoa) {
        fprintf(ikaslefitx, "%i;%s;%s;", ikaslea->idal, ikaslea->izena, ikaslea->abizenak);
        fprintf(ikaslefitx, "%s;%i;%s;%s;%i;%s;", ikaslea->helbidea.kalea, ikaslea->helbidea.zenbakia, ikaslea->helbidea.pisua, ikaslea->helbidea.herria, ikaslea->helbidea.postakodea, ikaslea->helbidea.telefonoa);
        fprintf(ikaslefitx, "%i;%i;%i\n", ikaslea->jaiotza.eguna, ikaslea->jaiotza.hilabetea, ikaslea->jaiotza.urtea);
        sprintf(fitxategia, "./e%ie/g%ig/i%ii", idesk, gela->idgela, ikaslea->idal);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
        if (ikaslea->ikasgaiak != NULL){
        ikasgaiakgorde(ikaslea, idesk, gela->idgela);
        }
    }
    fclose(ikaslefitx);
}
void stdikasgaiakgorde(GELA_t *gela, int idesk){
    IKASGAI_t *ikasgaia;
    FILE *ikasgaifitx;
    char fitxategia[70];
    char irakasid[20];
    sprintf(fitxategia, "./e%ie/g%ig/g%istdikas.csv", idesk, gela->idgela, gela->idgela);
    ikasgaifitx = fopen(fitxategia, "w");
    fprintf(ikasgaifitx, "Izena\tIrakaslea\n");
    for (ikasgaia = gela->stdikasgaiak; ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa) {
        if (ikasgaia->irakaslea == NULL) {
            strcpy(irakasid, "--");
        }else{
            strcpy(irakasid, ikasgaia->irakaslea->ida);
        }
        fprintf(ikasgaifitx, "%s;%s\n", ikasgaia->izena, irakasid);
    }
    fclose(ikasgaifitx);
}
void ikasgaiakgorde(IKASLE_t *ikaslea, int idesk, int idgela){
    IKASGAI_t *ikasgaia;
    FILE *ikasgaifitx;
    char fitxategia[70];
    char irakasid[20];
    sprintf(fitxategia, "./e%ie/g%ig/i%ii/i%iiikasgaiak.csv", idesk, idgela, ikaslea->idal, ikaslea->idal);
    ikasgaifitx = fopen(fitxategia, "w");
    fprintf(ikasgaifitx, "Izena\tNota\tIrakaslea\n");
    for (ikasgaia = ikaslea->ikasgaiak; ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa) {
        if (ikasgaia->irakaslea == NULL) {
            strcpy(irakasid, "--");
        }else{
            strcpy(irakasid, ikasgaia->irakaslea->ida);
        }
        fprintf(ikasgaifitx, "%s;%f;%s\n", ikasgaia->izena, ikasgaia->nota, irakasid);
    }
    fclose(ikasgaifitx);
}

void indizeairakurri(INDIZEA_t **indizea, int *idesk){
    FILE *indexfitx;
    INDIZEA_t *berria;
    char bufferra[150];
    char *tokena;
    indexfitx = fopen("indizea.csv", "r");
    if (!indexfitx) {
        printf("Ezin izan da fitxategia irakurri");
    }else{
        fgets(bufferra, 150, indexfitx);
        tokena = strtok(bufferra, "\n");
        *idesk = atoi(tokena);
    while (fgets(bufferra, 150, indexfitx)) {
        if ((*indizea) == NULL) {
            berria = calloc(1, sizeof(INDIZEA_t));
            (*indizea) = berria;
        }else{
            berria->hurrengoa = calloc(1, sizeof(INDIZEA_t));
            berria = berria->hurrengoa;
        }
        tokena = strtok(bufferra, ";\n");
        strcpy(berria->izena, tokena);
        tokena = strtok(NULL, ";\n");
        berria->idesk = atoi(tokena);
        }
        fclose(indexfitx);
    }
}
void eskolairakurri(ESKOLA_t **eskola, int idesk){
    FILE *eskolafitx;
    ESKOLA_t *berria;
    char fitxategia[50];
    char bufferra[150];
    char *tokena;
    sprintf(fitxategia, "./e%ie.csv", idesk);
    eskolafitx = fopen(fitxategia, "r");
    if (eskolafitx != NULL) {
    berria = calloc(1, sizeof(ESKOLA_t));
        fgets(bufferra, 150, eskolafitx);
        tokena = strtok(bufferra, TOK);
        strcpy(berria->izena, tokena);
        tokena = strtok(NULL, TOK);
        berria->idikasle = atoi(tokena);
        tokena = strtok(NULL, TOK);
        berria->iderabil = atoi(tokena);
        tokena = strtok(NULL, TOK);
        berria->idgela = atoi(tokena);
        berria->idesk = idesk;
    fclose(eskolafitx);
        erabiltzaileakirakurri(berria);
        gelakirakurri(berria);
    (*eskola) = berria;
    }

}
void erabiltzaileakirakurri(ESKOLA_t *eskola){
    FILE *erabiltzailefitx;
    char fitxategia[50];
    char bufferra[200];
    char *tokena;
    ERABILTZAILE_t *erabiltzailea;
    sprintf(fitxategia, "./e%ie/e%ierabil.csv", eskola->idesk, eskola->idesk);
    erabiltzailefitx = fopen(fitxategia, "r");
    if (!erabiltzailefitx) {
        printf("--noera--\n");
    }else{
        fgets(bufferra, 200, erabiltzailefitx);
        while (fgets(bufferra, 200, erabiltzailefitx)){
            if (eskola->erabiltzaileak == NULL) {
                erabiltzailea = calloc(1, sizeof(ERABILTZAILE_t));
                eskola->erabiltzaileak = erabiltzailea;
            }else{
                erabiltzailea->hurrengoa = calloc(1, sizeof(ERABILTZAILE_t));
                erabiltzailea = erabiltzailea->hurrengoa;
            }
            tokena = strtok(bufferra, TOK);
            strcpy(erabiltzailea->izena, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(erabiltzailea->abizena, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(erabiltzailea->pasahitza, tokena);
            tokena = strtok(NULL, TOK);
            erabiltzailea->sartuda = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(erabiltzailea->ida, tokena);
            tokena = strtok(NULL, TOK);
            erabiltzailea->mota = atoi(tokena);
            //fscanf(erabiltzailefitx, "%s;%s;%s;%i;%s;%i%*[^\n]", erabiltzailea->izena, erabiltzailea->abizena, erabiltzailea->pasahitza, &erabiltzailea->sartuda, erabiltzailea->ida, &erabiltzailea->mota);
        }
        fclose(erabiltzailefitx);
    }
}
void gelakirakurri(ESKOLA_t *eskola){
    FILE *gelafitx;
    char fitxategia[70];
    GELA_t *gela;
    char bufferra[200];
    char *tokena;
    sprintf(fitxategia, "./e%ie/e%igelak.csv", eskola->idesk, eskola->idesk);
    gelafitx = fopen(fitxategia, "r");
    if (!gelafitx) {
        printf("--nogela--\n");
    }else{
        fgets(bufferra, 200, gelafitx);
        while (fgets(bufferra, 200, gelafitx)) {
            if (eskola->gelak == NULL) {
                gela = calloc(1, sizeof(GELA_t));
                eskola->gelak = gela;
            }else{
                gela->hurrengoa = calloc(1, sizeof(GELA_t));
                gela = gela->hurrengoa;
            }
            tokena = strtok(bufferra, TOK);
            gela->idgela = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(gela->maila, tokena);
            tokena = strtok(NULL, TOK);
            gela->ikasle_kop = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(gela->gelafisikoa, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(gela->tutorea, tokena);
            //fscanf(gelafitx, "%i;%s;%i;%s;%s%*[^\n]", &gela->idgela, gela->maila, &gela->ikasle_kop, gela->gelafisikoa, gela->tutorea);
            stdikasgaiakirakurri(gela, eskola->idesk, eskola->erabiltzaileak);
            ikasleakirakurri(gela, eskola->idesk, eskola->erabiltzaileak);
        }
    fclose(gelafitx);
    }
}
void ikasleakirakurri(GELA_t *gela, int idesk, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikaslefitx;
    IKASLE_t *ikaslea;
    char fitxategia[70];
    char bufferra[300];
    char *tokena;
    sprintf(fitxategia, "./e%ie/g%ig/g%iikasleak.csv", idesk, gela->idgela, gela->idgela);
    ikaslefitx = fopen(fitxategia, "r");
    if (!ikaslefitx) {
        printf("--noikas--\n");
    }else{
        fgets(bufferra, 300, ikaslefitx);
        while (fgets(bufferra, 300, ikaslefitx)) {
            if (gela->ikasleak == NULL) {
                ikaslea = calloc(1, sizeof(IKASLE_t));
                gela->ikasleak = ikaslea;
            }else{
                ikaslea->hurrengoa = calloc(1, sizeof(IKASLE_t));
                ikaslea = ikaslea->hurrengoa;
            }
            tokena = strtok(bufferra, TOK);
            ikaslea->idal = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->izena, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->abizenak, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->helbidea.kalea, tokena);
            tokena = strtok(NULL, TOK);
            ikaslea->helbidea.zenbakia = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->helbidea.pisua, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->helbidea.herria, tokena);
            tokena = strtok(NULL, TOK);
            ikaslea->helbidea.postakodea = atoi(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(ikaslea->helbidea.telefonoa, tokena);
            tokena = strtok(NULL, TOK);
            ikaslea->jaiotza.eguna = atoi(tokena);
            tokena = strtok(NULL, TOK);
            ikaslea->jaiotza.hilabetea = atoi(tokena);
            tokena = strtok(NULL, TOK);
            ikaslea->jaiotza.urtea = atoi(tokena);
            ikasgaiakirakurri(ikaslea, idesk, gela->idgela, erabiltzaileak);
            //fscanf(ikaslefitx, "%i;%s;%s;", &ikaslea->idal, ikaslea->izena, ikaslea->abizenak);
            //fscanf(ikaslefitx, "%s;%i;%s;%s;%i;%s;", ikaslea->helbidea.kalea, &ikaslea->helbidea.zenbakia, ikaslea->helbidea.pisua, ikaslea->helbidea.herria, &ikaslea->helbidea.postakodea, ikaslea->helbidea.telefonoa);
            //fscanf(ikaslefitx, "%i;%i;%i%*[^\n]", &ikaslea->jaiotza.eguna, &ikaslea->jaiotza.hilabetea, &ikaslea->jaiotza.urtea);
        }
        fclose(ikaslefitx);
    }
}
void stdikasgaiakirakurri(GELA_t *gela, int idesk, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikasgaifitx;
    IKASGAI_t *ikasgaia;
    char irakasid[20];
    char fitxategia[70];
    char bufferra[150];
    char *tokena;
    sprintf(fitxategia, "./e%ie/g%ig/g%istdikas.csv", idesk, gela->idgela, gela->idgela);
    ikasgaifitx = fopen(fitxategia, "r");
    if (!ikasgaifitx) {
        printf("--nostd--\n");
    }else{
        fgets(bufferra, 150, ikasgaifitx);
        while (fgets(bufferra, 150, ikasgaifitx)) {
            if (gela->stdikasgaiak == NULL) {
                ikasgaia = calloc(1, sizeof(IKASGAI_t));
                gela->stdikasgaiak = ikasgaia;
            }else{
                ikasgaia->hurrengoa = calloc(1, sizeof(IKASGAI_t));
                ikasgaia = ikasgaia->hurrengoa;
            }
            tokena = strtok(bufferra, TOK);
            strcpy(ikasgaia->izena, tokena);
            tokena = strtok(NULL, TOK);
            strcpy(irakasid, tokena);
            //fscanf(ikasgaifitx, "%s;%s%*[^\n]", ikasgaia->izena, irakasid);
            ikasgaia->irakaslea = aurkituerabiltzaile(erabiltzaileak, irakasid);
        }
        fclose(ikasgaifitx);
    }
}
void ikasgaiakirakurri(IKASLE_t *ikaslea, int idesk, int idgela, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikasgaifitx;
    char fitxategia[70];
    char bufferra[200];
    char *tokena;
    IKASGAI_t *ikasgaia;
    char irakasid[20];
    sprintf(fitxategia, "./e%ie/g%ig/i%ii/i%iiikasgaiak.csv", idesk, idgela, ikaslea->idal, ikaslea->idal);
    ikasgaifitx = fopen(fitxategia, "r");
    if (!ikasgaifitx) {
        printf("--noikg--\n");
    }else{
        fgets(bufferra, 200, ikasgaifitx);
        while (fgets(bufferra, 200, ikasgaifitx)) {
            if (ikaslea->ikasgaiak == NULL) {
                ikasgaia = calloc(1, sizeof(IKASGAI_t));
                ikaslea->ikasgaiak = ikasgaia;
            }else{
                ikasgaia->hurrengoa = calloc(1, sizeof(IKASGAI_t));
                ikasgaia = ikasgaia->hurrengoa;
            }
            tokena = strtok(bufferra, TOK);
            strcpy(ikasgaia->izena, tokena);
            tokena = strtok(NULL, TOK);
            ikasgaia->nota = atof(tokena);
            tokena = strtok(NULL, TOK);
            strcpy(irakasid, tokena);
            //fscanf(ikasgaifitx, "%s;%f;%s%*[^\n]", ikasgaia->izena, &ikasgaia->nota, irakasid);
            ikasgaia->irakaslea = aurkituerabiltzaile(erabiltzaileak, irakasid);
        }
        fclose(ikasgaifitx);
    }
}
#endif