#include "jucator_si_lista_jucatori.h"
struct echipa
{
    int nr_membrii;
    float punctaj_mediu;
    char *nume_echipa;
    lista_jucatori *jucatori_din_echipa;
};
typedef struct echipa echipa;
struct lista_echipe
{
    echipa informatii_echipa;
    struct lista_echipe *next;
};
typedef struct lista_echipe lista_echipe;
