#include "echipa_si_lista_echipe.h"
struct head_to_head
{
    echipa team1,team2;
    struct head_to_head *next;
};
typedef struct head_to_head head_to_head;
struct coada_meciuri
{
    head_to_head *front,*rear;
};
typedef struct coada_meciuri coada_meciuri;
