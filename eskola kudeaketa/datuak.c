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
#include <string.h>
#include "egiturak.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "datuak.h"
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
    ESKOLA_t *eskolaux;
    FILE *eskolafitx;
    char fitxategia[50];
    eskola->idesk = idesk;
    for (eskolaux = eskola; eskolaux != NULL; eskolaux = eskolaux->hurrengoa) { //A revisar, solo habra cargada una en cada momento
        sprintf(fitxategia, "./e%ie.csv", idesk);
        eskolafitx = fopen(fitxategia, "w");
        fprintf(eskolafitx, "%s;%i;%i\n", eskolaux->izena, eskolaux->idikasle, eskolaux->iderabil);
        fclose(eskolafitx);
        sprintf(fitxategia, "./e%ie", eskola->idesk);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
        erabiltzaileakgorde(eskola);
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
        ikasleakgorde(gela, eskola->idesk);
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
        ikasgaiakgorde(ikaslea, idesk, gela->idgela);
    }
    fclose(ikaslefitx);
}
void stdikasgaiakgorde(GELA_t *gela, int idesk){
    IKASGAI_t *ikasgaia;
    FILE *ikasgaifitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%istdikas.csv", idesk, gela->idgela, gela->idgela);
    ikasgaifitx = fopen(fitxategia, "w");
    fprintf(ikasgaifitx, "Izena\tIrakaslea\n");
    for (ikasgaia = gela->stdikasgaiak; ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa) {
        fprintf(ikasgaifitx, "%s;%s\n", ikasgaia->izena, ikasgaia->irakaslea->ida);
    }
    fclose(ikasgaifitx);
}
void ikasgaiakgorde(IKASLE_t *ikaslea, int idesk, int idgela){
    IKASGAI_t *ikasgaia;
    FILE *ikasgaifitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/i%ii/i%iiikasgaiak.csv", idesk, idgela, ikaslea->idal, ikaslea->idal);
    ikasgaifitx = fopen(fitxategia, "w");
    fprintf(ikasgaifitx, "Izena\tNota\tIrakaslea\n");
    for (ikasgaia = ikaslea->ikasgaiak; ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa) {
        fprintf(ikasgaifitx, "%s;%f;%s\n", ikasgaia->izena, ikasgaia->nota, ikasgaia->irakaslea->ida);
    }
    fclose(ikasgaifitx);
}

void indizeairakurri(INDIZEA_t **indizea, int *idesk){
    FILE *indexfitx;
    INDIZEA_t *berria;
    indexfitx = fopen("indizea.csv", "r");
    if (!indexfitx) {
        printf("Ezin izan da fitxategia irakurri");
    }else{
    fscanf(indexfitx, "%i\n", idesk);
    berria = calloc(1, sizeof(INDIZEA_t));
    (*indizea) = berria;
    while (!feof(indexfitx)) {
        fscanf(indexfitx, "%s;%i\n", berria->izena, &berria->idesk);
        if (!feof(indexfitx)) {
        berria->hurrengoa = calloc(1, sizeof(INDIZEA_t));
        berria = berria->hurrengoa;
        }
    }
    }
}
void eskolairakurri(ESKOLA_t **eskola, int idesk){
    FILE *eskolafitx;
    ESKOLA_t *berria;
    char fitxategia[50];
    sprintf(fitxategia, "./e%ie.csv", idesk);
    eskolafitx = fopen(fitxategia, "r");
    berria = calloc(1, sizeof(ESKOLA_t));
    fscanf(eskolafitx, "%s;%i;%i\n", berria->izena, &berria->idikasle, &berria->iderabil);
    fclose(eskolafitx);
    (*eskola) = berria;

}
void erabiltzaileakirakurri(ESKOLA_t *eskola){
    FILE *erabiltzailefitx;
    char fitxategia[50];
    ERABILTZAILE_t *erabiltzailea;
    sprintf(fitxategia, "./e%ie/e%ierabil.csv", eskola->idesk, eskola->idesk);
    erabiltzailefitx = fopen(fitxategia, "r");
    if (!erabiltzailefitx) {
        printf("Ezin izan da fitxategia irakurri");
    }else{
        erabiltzailea = calloc(1, sizeof(ERABILTZAILE_t));
        eskola->erabiltzaileak = erabiltzailea;
        fscanf(erabiltzailefitx, "\n");
        while (!feof(erabiltzailefitx)){
            fscanf(erabiltzailefitx, "%s;%s;%s;%i;%s;%i\n", erabiltzailea->izena, erabiltzailea->abizena, erabiltzailea->pasahitza, &erabiltzailea->sartuda, erabiltzailea->ida, &erabiltzailea->mota);
            if (!feof(erabiltzailefitx)) {
                erabiltzailea->hurrengoa = calloc(1, sizeof(ERABILTZAILE_t));
                erabiltzailea = erabiltzailea->hurrengoa;
            }
        }
        fclose(erabiltzailefitx);
    }
}
void gelakirakurri(ESKOLA_t *eskola){
    FILE *gelafitx;
    char fitxategia[70];
    GELA_t *gela;
    sprintf(fitxategia, "./e%ie/e%igelak.csv", eskola->idesk, eskola->idesk);
    gelafitx = fopen(fitxategia, "r");
    if (!gelafitx) {
        printf("Ezin izan da gela irakurri");
    }else{
        gela = calloc(1, sizeof(GELA_t));
        eskola->gelak = gela;
        fscanf(gelafitx, "\n");
        while (!feof(gelafitx)) {
            fscanf(gelafitx, "%i;%s;%i;%s;%s\n", &gela->idgela, gela->maila, &gela->ikasle_kop, gela->gelafisikoa, gela->tutorea);
            if (!feof(gelafitx)) {
                gela->hurrengoa = calloc(1, sizeof(GELA_t));
                gela = gela->hurrengoa;
            }
        }
    fclose(gelafitx);
    }
}
void ikasleakirakurri(GELA_t *gela, int idesk, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikaslefitx;
    IKASLE_t *ikaslea;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%iikasleak.csv", idesk, gela->idgela, gela->idgela);
    ikaslefitx = fopen(fitxategia, "r");
    if (!ikaslefitx) {
        printf("Ez da fitxategia aurkitu\n");
    }else{
        fscanf(ikaslefitx, "\n");
        ikaslea = calloc(1, sizeof(IKASLE_t));
        gela->ikasleak = ikaslea;
        while (!feof(ikaslefitx)) {
            fscanf(ikaslefitx, "%i;%s;%s;", &ikaslea->idal, ikaslea->izena, ikaslea->abizenak);
            fscanf(ikaslefitx, "%s;%i;%s;%s;%i;%s;", ikaslea->helbidea.kalea, &ikaslea->helbidea.zenbakia, ikaslea->helbidea.pisua, ikaslea->helbidea.herria, &ikaslea->helbidea.postakodea, ikaslea->helbidea.telefonoa);
            fscanf(ikaslefitx, "%i;%i;%i\n", &ikaslea->jaiotza.eguna, &ikaslea->jaiotza.hilabetea, &ikaslea->jaiotza.urtea);
            if (!feof(ikaslefitx)) {
                ikaslea->hurrengoa = calloc(1, sizeof(IKASLE_t));
                ikaslea = ikaslea->hurrengoa;
            }
        }
        fclose(ikaslefitx);
    }
}
void stdikasgaiakirakurri(GELA_t *gela, int idesk, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikasgaifitx;
    IKASGAI_t *ikasgaia;
    char irakasid[20];
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%istdikas.csv", idesk, gela->idgela, gela->idgela);
    ikasgaifitx = fopen(fitxategia, "r");
    if (!ikasgaifitx) {
        printf("Ezin izan da fitxategia irakurri\n");
    }else{
        fscanf(ikasgaifitx, "\n");
        ikasgaia = calloc(1, sizeof(IKASGAI_t));
        gela->stdikasgaiak = ikasgaia;
        while (!feof(ikasgaifitx)) {
            fscanf(ikasgaifitx, "%s;%s\n", ikasgaia->izena, irakasid);
            //ikasgaia->irakaslea = aurkituerabiltzaile(erabiltzaileak, irakasid);
            if (!feof(ikasgaifitx)) {
                ikasgaia->hurrengoa = calloc(1, sizeof(IKASGAI_t));
                ikasgaia = ikasgaia->hurrengoa;
            }
        }
        fclose(ikasgaifitx);
    }
}
void ikasgaiakirakurri(IKASLE_t *ikaslea, int idesk, int idgela, ERABILTZAILE_t *erabiltzaileak){
    FILE *ikasgaifitx;
    char fitxategia[70];
    IKASGAI_t *ikasgaia;
    char irakasid[20];
    sprintf(fitxategia, "./e%ie/g%ig/i%ii/i%iiikasgaiak.csv", idesk, idgela, ikaslea->idal, ikaslea->idal);
    ikasgaifitx = fopen(fitxategia, "r");
    if (!ikasgaifitx) {
        printf("Ez da fitxategia aurkitu\n");
    }else{
        fscanf(ikasgaifitx, "\n");
        ikasgaia = calloc(1, sizeof(IKASGAI_t));
        ikaslea->ikasgaiak = ikasgaia;
        while (!feof(ikasgaifitx)) {
            fscanf(ikasgaifitx, "%s;%f;%s\n", ikasgaia->izena, &ikasgaia->nota, irakasid);
            //ikasgaia->irakaslea = aurkituerabiltzaile(erabiltzaileak, irakasid);
            if (!feof(ikasgaifitx)) {
                ikasgaia->hurrengoa = calloc(1, sizeof(IKASGAI_t));
                ikasgaia = ikasgaia->hurrengoa;
            }
        }
        fclose(ikasgaifitx);
    }
}
#endif