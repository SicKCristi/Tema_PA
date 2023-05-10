struct jucator
{
    char *nume,*prenume;
    int punctaj;
};
typedef struct jucator jucator;
struct lista_jucatori
{
    jucator informatii_jucator;
    struct lista_jucatori *next;
};
typedef struct lista_jucatori lista_jucatori;
