//
//  egiturak.h
//  eskola kudeaketa
//
//  Created by Gorka Olalde on 11/06/14.
//  Copyright (c) 2014 Gorka Olalde. All rights reserved.
//

#ifndef eskola_kudeaketa_egiturak_h
#define eskola_kudeaketa_egiturak_h

typedef struct JAIO{
	int eguna;
	int hilabetea;
	int urtea;
}JAIO;
typedef struct{
	char kalea[70];
	int zenbakia;
	char pisua[20];
	char herria[40];
	int postakodea;
}HELBIDE;
typedef struct IKASGAI{
	char izena[50];
	float nota;
	int ida;
	struct IKASGAI *hurrengoa;
}IKASGAI;
typedef struct{
	char izena[50];
	char abizenak[50];
	int idal;
	HELBIDE helbidea;
	JAIO jaiotza;
	IKASGAI *ikasgaiak;
	struct IKASLE *hurrengoa;
}IKASLE;

typedef struct{
	char maila[50];
	int ikasle_kop;
	IKASLE *ikasleak;
	char gelafisikoa[20];
	char tutorea[50];
	struct GELA *hurrengoa;
	IKASGAI *stdikasgaiak;
}GELA;

typedef struct{
	int idesk;
	GELA *gelak;
	char izena[50];
	int idikasle;
	struct ESKOLA *hurrengoa;
}ESKOLA;

typedef struct{
	GELA *gelaikas;
	IKASLE *ikaslea;
}POSI;

#endif
