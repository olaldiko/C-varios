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
void indizeagorde(INDIZEA_t *indizea, int *idesk){
    FILE *index;
    index = fopen("indizea.txt", "w");
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
    for (eskolaux = eskola; eskolaux != NULL; eskolaux = eskolaux->hurrengoa) {
        sprintf(fitxategia, "./e%ie.txt", idesk);
        eskolafitx = fopen(fitxategia, "w");
        fprintf(eskolafitx, "%s;%i;%i\n", eskolaux->izena, eskolaux->idikasle, eskolaux->iderabil);
        fclose(eskolafitx);
        sprintf(fitxategia, "./e%ie", eskola->idesk);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
    }
}
void erabiltzaileakgorde(ESKOLA_t *eskola){
    ERABILTZAILE_t *erabiltzailea;
    FILE *erabilfitx;
    char fitxategia[50];
    sprintf(fitxategia, "./e%ie/e%ierabil.txt", eskola->idesk, eskola->idesk);
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
    sprintf(fitxategia, "./e%ie/e%igelak.txt", eskola->idesk, eskola->idesk);
    gelafitx = fopen(fitxategia, "w");
    fprintf(gelafitx, "IDa\tMaila\tIKop\tGela Fisikoa\tTutorea\n");
    for (gela = eskola->gelak; gela != NULL; gela = gela->hurrengoa) {
        fprintf(gelafitx, "%i;%s;%i;%s;%s\n", gela->idgela, gela->maila, gela->ikasle_kop, gela->gelafisikoa, gela->tutorea);
        sprintf(fitxategia, "./e%ie/g%ig", eskola->idesk, gela->idgela);
        if(stat(fitxategia, &st) == -1){
            mkdir(fitxategia, 0770);
        }
    }
    fclose(gelafitx);
}
void ikasleakgorde(GELA_t *gela, int idesk){
    struct stat st = {0};
    IKASLE_t *ikaslea;
    FILE *ikaslefitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%iikasleak.txt", idesk, gela->idgela, gela->idgela);
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
    }
    fclose(ikaslefitx);
}
void stdikasgaiakgorde(GELA_t *gela, int idesk){
    IKASGAI_t *ikasgaia;
    FILE *ikasgaifitx;
    char fitxategia[70];
    sprintf(fitxategia, "./e%ie/g%ig/g%istdikas.txt", idesk, gela->idgela, gela->idgela);
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
    sprintf(fitxategia, "./e%ie/g%ig/i%ii/i%iiikasgaiak.txt", idesk, idgela, ikaslea->idal, ikaslea->idal);
    ikasgaifitx = fopen(fitxategia, "w");
    fprintf(ikasgaifitx, "Izena\tNota\tIrakaslea\n");
    for (ikasgaia = ikaslea->ikasgaiak; ikasgaia != NULL; ikasgaia = ikasgaia->hurrengoa) {
        fprintf(ikasgaifitx, "%s;%f;%s\n", ikasgaia->izena, ikasgaia->nota, ikasgaia->irakaslea->ida);
    }
    fclose(ikasgaifitx);
}

#endif