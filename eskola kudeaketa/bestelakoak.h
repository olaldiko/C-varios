#ifndef BESTELAKOAK_H
#define BESTELAKOAK_H
#include "egiturak.h"
float notaksartu();
HELBIDE_t helbideasartu();
JAIO_t jaiotzasartu();
void kopiatuikasgai(GELA_t *, IKASGAI_t **);
GELA_t *aukeratugela(ESKOLA_t *);
POSI_t aurkituikasle(int , ESKOLA_t *);
float notakbatazbesteko(IKASGAI_t *);
ERABILTZAILE_t *loginmenu(ERABILTZAILE_t *);
ERABILTZAILE_t *aukeratuirakasle(ERABILTZAILE_t *);
INDIZEA_t *aukeratueskola(INDIZEA_t *);
IKASGAI_t *aukeratuikasgai(IKASGAI_t *, ERABILTZAILE_t *);
void sortuerabiltzaileid(ERABILTZAILE_t *);
#endif