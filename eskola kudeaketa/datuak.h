//
//  datuak.h
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 14/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//

#ifndef eskola_kudeaketa_datuak_h
#define eskola_kudeaketa_datuak_h
void indizeagorde(INDIZEA_t *, int *);
void eskolagorde(ESKOLA_t *, int);
void erabiltzaileakgorde(ESKOLA_t *);
void gelakgorde(ESKOLA_t *);
void ikasleakgorde(GELA_t *, int);
void stdikasgaiakgorde(GELA_t *, int);
void ikasgaiakgorde(IKASLE_t *, int, int);
void indizeairakurri(INDIZEA_t **, int *);
void eskolairakurri(ESKOLA_t **, int);
void erabiltzaileakirakurri(ESKOLA_t *);
void gelakirakurri(ESKOLA_t *);
void ikasleakirakurri(GELA_t *, int, ERABILTZAILE_t *);
void stdikasgaiakirakurri(GELA_t *, int, ERABILTZAILE_t *);
void ikasgaiakirakurri(IKASLE_t *, int, int, ERABILTZAILE_t *);
#endif
