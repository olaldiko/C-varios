#ifndef EGITURAK_H
#define EGITURAK_H
typedef struct JAIO{
	int eguna;
	int hilabetea;
	int urtea;
}JAIO_t;
typedef struct HELBIDE{
	char kalea[70];
	int zenbakia;
	char pisua[20];
	char herria[40];
	int postakodea;
    char telefonoa[12];
}HELBIDE_t;
typedef struct IKASGAI{
	char izena[50];
	float nota;
	struct ERABILTZAILE *irakaslea;
	struct IKASGAI *hurrengoa;
}IKASGAI_t;
typedef struct IKASLE{
	char izena[50];
	char abizenak[50];
	int idal;
	struct HELBIDE helbidea;
	struct JAIO jaiotza;
	struct IKASGAI *ikasgaiak;
	struct IKASLE *hurrengoa;
}IKASLE_t;

typedef struct GELA{
	char maila[50];
	int ikasle_kop;
	struct IKASLE *ikasleak;
	char gelafisikoa[20];
	char tutorea[50];
	struct GELA *hurrengoa;
	struct IKASGAI *stdikasgaiak;
}GELA_t;
typedef struct ERABILTZAILE{
    char izena[50];
    char abizena[50];
    char pasahitza[50];
    int sartuda;
    char ida[20];
    int mota;
    struct ERABILTZAILE *hurrengoa;
}ERABILTZAILE_t;
typedef struct ESKOLA{
	int idesk;
	struct GELA *gelak;
	char izena[50];
	int idikasle;
    struct ERABILTZAILE *erabiltzaileak;
    int iderabil;
	struct ESKOLA *hurrengoa;
}ESKOLA_t;
typedef struct INDIZEA{
    char fitxategia[100];
    char izena[50];
    int idesk;
    struct INDIZEA *hurrengoa;
}INDIZEA_t;
typedef struct POSI{
	struct GELA *gelaikas;
	struct IKASLE *ikaslea;
}POSI_t;
#endif