#include "jucator_si_lista_jucatori.h"
#include "echipa_si_lista_echipe.h"
#include "meci_si_coada_de_meciuri.h"
#include "arbore.h"
#include "biblioteci_si_define.h"
char *alocare_text(char *text,int dim);
void afisare_lista_jucatori(lista_jucatori *lista);
void afisare_lista_echipe(lista_echipe *lista);
void afisare_lista_echipe_pt_fisier(lista_echipe *lista,char *nume_fisier);
lista_jucatori *creare_jucator(char *nume,char *prenume,int puncte);
void inserare_jucator(lista_jucatori **lista,char *numme,char *prenume,int puncte);
lista_echipe *creare_echipa(char *nume_echipa,float medie,int nr_jucatori,lista_jucatori *lista);
void inserare_echipa(lista_echipe **lista,char *nume_echipa,float medie,int nr_jucatori,lista_jucatori *player_list);
void stergere_lista_jucatori(lista_jucatori **lista);
void stergere_lista_echipe(lista_echipe **lista);
void stergere_lista_echipe_fara_lista_de_jucatori(lista_echipe **lista);
void citire_taskuri(int *taskuri, char *nume_fisier);
void taskul1(lista_echipe **lista_cu_echipe,int *nr_echipe,char *nume_fisier);
void eliminare_caractere_ascunse_de_final(lista_echipe **lista);
int suma_punctaje(lista_jucatori *aux);
void punctaj_minim(lista_echipe *lista,float *minim);
void eliminare_echipe_cu_punctaj_minim_din_stiva(lista_echipe **lista,lista_echipe *adresa);
void taskul2(lista_echipe **lista,int dif,char *nume_fisier);
coada_meciuri *creaza_coada();
head_to_head *creare_meci(echipa t1,echipa t2);
void adaugare_meci_in_coada(coada_meciuri *program,echipa t1,echipa t2);
int puterea_maxima_a_lui_doi(int nr_echipe);
void afisare_lista_echipe_castigatoare_pt_fisier(lista_echipe *lista,int nr,char *nume_fisier_out);
void afisare_program_meciuri_pt_fisier(coada_meciuri *program,int nr, char *nume_fisier_out);
void taskul3(lista_echipe **lista,int *nr_echipe, char *nume_fisier_out);
void iordine(Nod *root);
Nod* creare_nod_arbore(echipa team);
Nod *inserare_in_BST(Nod *root,int inaltime,echipa team);
void lista_descrescatoare(lista_echipe **noua_lista_cu_echipe,Nod *root);
void taskul4(lista_echipe *lista_cu_echipe,char *nume_fisier_out);
int inaltime_arbore(Nod *root);
Nod *inserare_nod_in_AVL(Nod *root,echipa team);
int maximul_dintre_doi_intregi(int a,int b);
Nod* rotatie_la_dreapta(Nod *z);
Nod* rotatie_la_stanga(Nod *z);
Nod *rotatie_la_stanga_dreapta(Nod *z);
Nod *rotatie_la_dreapta_stanga(Nod *z);
Nod* echilibrare_arbore(Nod *root);
void stergere_arbore(Nod *root);
void iordine_modificata(Nod *root);
void afisare_echipe_de_pe_nivelul_2(FILE *f,Nod *root);
void taskul5(lista_echipe *lista_cu_echipe,char *nume_fisier_out);
