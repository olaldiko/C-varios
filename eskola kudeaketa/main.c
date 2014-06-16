#include <stdio.h>
#include <stdlib.h>
#include "egiturak.h"
#include "menuak.h"
#include "datuak.h"

int main(void){
    INDIZEA_t *indizea = NULL;
    int idesk = 0;
    indizeairakurri(&indizea, &idesk);
    menunagusia(indizea, &idesk);
}