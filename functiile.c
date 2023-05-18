#include "meci_si_coada_de_meciuri.h"
#include "arbore.h"
#include "biblioteci_si_define.h"
char *alocare_text(char *text,int dim)
{
    text=(char*)malloc((dim+1)*sizeof(char));
    return text;
}
void afisare_lista_jucatori(lista_jucatori *lista)
{
    printf("Lista cu jucatori este urmatoarea:\n");
    while(lista!=NULL)
    {
        printf("%s %s %d\n",lista->informatii_jucator.nume,lista->informatii_jucator.prenume,lista->informatii_jucator.punctaj);
        lista=lista->next;
    }
    printf("\n");
}
void afisare_lista_echipe(lista_echipe *lista)
{
    printf("Lista cu echipele este urmatoarea:\n");
    while(lista!=NULL)
    {
        printf("%d %s ",lista->informatii_echipa.nr_membrii,lista->informatii_echipa.nume_echipa);
        printf("%f\n",lista->informatii_echipa.punctaj_mediu);
        afisare_lista_jucatori(lista->informatii_echipa.jucatori_din_echipa);
        lista=lista->next;
    }
}
void afisare_lista_echipe_pt_fisier(lista_echipe *lista,char *nume_fisier)
{
    FILE *f;
    f=fopen(nume_fisier,"wt");
    if(f==NULL)
    {
        printf("FIsierul de output nu a putut fi deschis!\n");
        exit(1);
    }
    while(lista!=NULL)
    {
        fprintf(f,"%s\n",lista->informatii_echipa.nume_echipa);
        lista=lista->next;
    }
    fclose(f);
}
lista_jucatori *creare_jucator(char *nume,char *prenume,int puncte)
{
    lista_jucatori *aux=(lista_jucatori*)malloc(sizeof(lista_jucatori));
    aux->informatii_jucator.nume=alocare_text(aux->informatii_jucator.nume,strlen(nume));
    strcpy(aux->informatii_jucator.nume,nume);
    aux->informatii_jucator.prenume=alocare_text(aux->informatii_jucator.prenume,strlen(prenume));
    strcpy(aux->informatii_jucator.prenume,prenume);
    aux->informatii_jucator.punctaj=puncte;
    aux->next=NULL;
    return aux;
}
void inserare_jucator(lista_jucatori **lista,char *nume,char *prenume,int puncte)
{
    lista_jucatori *aux=creare_jucator(nume,prenume,puncte);
    if(*lista==NULL)
    {
        *lista=aux;
        return;
    }
    aux->next=*lista;
    *lista=aux;
}
lista_echipe *creare_echipa(char *nume_echipa,float medie,int nr_jucatori,lista_jucatori *lista)
{
    lista_echipe *aux=(lista_echipe*)malloc(sizeof(lista_echipe));
    aux->informatii_echipa.nume_echipa=alocare_text(aux->informatii_echipa.nume_echipa,strlen(nume_echipa));
    strcpy(aux->informatii_echipa.nume_echipa,nume_echipa);
    aux->informatii_echipa.punctaj_mediu=medie;
    aux->informatii_echipa.nr_membrii=nr_jucatori;
    aux->informatii_echipa.jucatori_din_echipa=lista;
    aux->next=NULL;
    return aux;
}
void inserare_echipa(lista_echipe **lista,char *nume_echipa,float medie,int nr_jucatori,lista_jucatori *player_list)
{
    lista_echipe *aux=creare_echipa(nume_echipa,medie,nr_jucatori,player_list);
    if(*lista==NULL)
    {
        *lista=aux;
        return;
    }
    aux->next=*lista;
    *lista=aux;
}
void inserare_echipa_deja_existenta(lista_echipe **lista,lista_echipe *aux)
{
    if(*lista==NULL)
    {
        *lista=aux;
        return;
    }
    aux->next=*lista;
    *lista=aux;
}
void stergere_lista_jucatori(lista_jucatori **lista)
{
    lista_jucatori *aux1,*aux2;
    aux1=*lista;
    while(aux1!=NULL)
    {
        aux2=aux1->next;
        free(aux1->informatii_jucator.nume);
        free(aux1->informatii_jucator.prenume);
        free(aux1);
        aux1=aux2;
    }
    *lista=NULL;
}
void stergere_lista_echipe(lista_echipe **lista)
{
    lista_echipe *aux1,*aux2;
    aux1=*lista;
    while(aux1!=NULL)
    {
        aux2=aux1->next;
        free(aux1->informatii_echipa.nume_echipa);
        stergere_lista_jucatori(&aux1->informatii_echipa.jucatori_din_echipa);
        free(aux1);
        aux1=aux2;
    }
    *lista=NULL;
}
void stergere_lista_echipe_fara_lista_de_jucatori(lista_echipe **lista)
{
   lista_echipe *aux1,*aux2;
   aux1=*lista;
   while(aux1!=NULL)
   {
       aux2=aux1->next;
       free(aux1->informatii_echipa.nume_echipa);
       free(aux1);
       aux1=aux2;
   }
}
void citire_taskuri(int *taskuri, char *nume_fisier)
{
    FILE *f;
    f=fopen(nume_fisier,"rt");
    if(!f)
    {
        printf("Fisierul pentru checker nu poate fi deschis!\n");
        exit(1);
    }
    int i;
    for(i=0;i<5;i++)
     fscanf(f,"%d",&taskuri[i]);
    fclose(f);
}
int suma_punctaje(lista_jucatori *aux)
{
    int suma=0;
    while(aux!=NULL)
    {
        suma+=aux->informatii_jucator.punctaj;
        aux=aux->next;
    }
    return suma;
}
void fmm_backslash_n_la_final(lista_echipe **lista)
{
    lista_echipe *aux=*lista;
    while(aux!=NULL)
    {
        if(aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]=='\n')
            aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]='\0';
        if(aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]=='\r')
            aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]='\0';
        if(aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]==' ')
            aux->informatii_echipa.nume_echipa[strlen(aux->informatii_echipa.nume_echipa)-1]='\0';
        aux=aux->next;
    }
}
void taskul1(lista_echipe **lista_cu_echipe,int *nr_echipe, char *nume_fisier, char *nume_fisier_out)
{
    FILE *f;
    f=fopen(nume_fisier,"rt");
    if(!f)
    {
        printf("Fisierul cu datele de intrare nu poate fi deschis!\n");
        exit(1);
    }
    char buffer[LMAX];
    char *aux,*nume,*prenume,*p;
    int nr_participanti,puncte;
    lista_jucatori *head=NULL;
    fgets(buffer,LMAX,f);
    *nr_echipe=atoi(buffer);
    int i;
    for(i=0;i<*nr_echipe;i++)
    {
        fgets(buffer,LMAX,f);
        aux=alocare_text(aux,LMAX);
        head=NULL;
        p=strtok(buffer," ");
        nr_participanti=atoi(p);
        p=strtok(NULL," ");
        aux[0]='\0';
        while(p)
        {
            strcat(aux,p);
            strcat(aux," ");
            p=strtok(NULL," ");
        }
        aux[strlen(aux)-1]='\0';
        int j;
        for(j=0;j<nr_participanti;j++)
        {
            fgets(buffer,LMAX,f);
            p=strtok(buffer," ");
            nume=alocare_text(nume,strlen(p));
            strcpy(nume,p);
            p=strtok(NULL," ");
            prenume=alocare_text(prenume,strlen(p));
            strcpy(prenume,p);
            p=strtok(NULL," ");
            puncte=atoi(p);
            inserare_jucator(&head,nume,prenume,puncte);
            free(nume);
            free(prenume);
        }
         fgets(buffer,LMAX,f);
         float medie=(float)suma_punctaje(head)/nr_participanti;
         inserare_echipa(lista_cu_echipe,aux,medie,nr_participanti,head);
         free(aux);
    }
    fclose(f);
    fmm_backslash_n_la_final(lista_cu_echipe);
    afisare_lista_echipe_pt_fisier(*lista_cu_echipe,nume_fisier_out);
}
int puterea_maxima_a_lui_doi(int nr_echipe)
{
    int aux=1;
    while(2*aux<=nr_echipe)
     aux*=2;
    return aux;
}
void punctaj_minim(lista_echipe *lista,float *minim)
{
    *minim=FLT_MAX;
    while(lista!=NULL)
    {
        if(lista->informatii_echipa.punctaj_mediu<*minim)
         *minim=lista->informatii_echipa.punctaj_mediu;
        lista=lista->next;
    }
}
void eliminare_echipe_cu_punctaj_minim_din_stiva(lista_echipe **lista,lista_echipe *adresa)
{
    lista_echipe *aux;
    if(adresa==*lista)
    {
        aux=*lista;
        *lista=(*lista)->next;
        free(aux->informatii_echipa.nume_echipa);
        stergere_lista_jucatori(&aux->informatii_echipa.jucatori_din_echipa);
        free(aux);
        return;
    }
    aux=*lista;
    while(aux->next!=adresa && aux->next!=NULL)
     aux=aux->next;
    lista_echipe *aux2=adresa;
    aux->next=aux2->next;
    free(aux2->informatii_echipa.nume_echipa);
    stergere_lista_jucatori(&aux2->informatii_echipa.jucatori_din_echipa);
    free(aux2);
}
void taskul2(lista_echipe **lista,int dif, char *nume_fisier)
{
    lista_echipe *aux;
    float minim;
    int nr;
    while(dif>0)
    {
        nr=0;
        punctaj_minim(*lista,&minim);
        aux=*lista;
        while(aux!=NULL && dif>0)
        {
            if(dif==0)
                return;
            if(fabs(aux->informatii_echipa.punctaj_mediu-minim)<0.000001 && dif>0)
            {
                eliminare_echipe_cu_punctaj_minim_din_stiva(lista,aux);
                dif--;
                aux=*lista;
            }
            else
             if(dif>0)
              aux=aux->next;
            nr++;
        }
    }
    afisare_lista_echipe_pt_fisier(*lista, nume_fisier);
}
coada_meciuri *creaza_coada()
{
    coada_meciuri *aux;
    aux=(coada_meciuri*)malloc(sizeof(coada_meciuri));
    if(aux==NULL)
    {
        puts("Alocare dinamica esuata!");
        exit(1);
    }
    aux->front=aux->rear=NULL;
    return aux;
}
void stergere_coada(coada_meciuri *coada)
{
    head_to_head *aux1=coada->front,*aux2;
    while(aux1!=NULL)
    {
        aux2=aux1->next;
        free(aux1->team1.nume_echipa);
        free(aux1->team2.nume_echipa);
        free(aux1);
        aux1=aux2;
    }
    free(coada);
}
head_to_head *creare_meci(echipa t1,echipa t2)
{
    head_to_head *aux=(head_to_head*)malloc(sizeof(head_to_head));
    aux->team1=t1;
    aux->team2=t2;
    aux->next=NULL;
    return aux;
}
void adaugare_meci_in_coada(coada_meciuri *program,echipa t1,echipa t2)
{
    head_to_head *aux=creare_meci(t1,t2);
    if(program->rear==NULL)
      program->rear=aux;
    else
    {
        (program->rear)->next=aux;
         program->rear=aux;
    }
    if(program->front==NULL)
     program->front=program->rear;
}
void afisare_program_meciuri_pt_fisier(coada_meciuri *program,int nr, char *nume_fisier_out)
{
    FILE *f;
    f=fopen(nume_fisier_out,"at");
    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    fprintf(f,"\n--- ROUND NO:%d\n",nr);
    head_to_head *aux=program->front;
    while(aux!=NULL)
    {
        fprintf(f,"%-32s - %32s\n",aux->team1.nume_echipa,aux->team2.nume_echipa);
        aux=aux->next;
    }
    fprintf(f,"\n");
    fclose(f);
}
void afisare_lista_echipe_castigatoare_pt_fisier(lista_echipe *lista,int nr,char *nume_fisier_out)
{
    FILE *f;
    f=fopen(nume_fisier_out,"at");
    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    fprintf(f,"WINNERS OF ROUND NO:%d\n",nr);
    while(lista!=NULL)
    {
        fprintf(f,"%-33s -  %.2f\n",lista->informatii_echipa.nume_echipa,lista->informatii_echipa.punctaj_mediu);
        lista=lista->next;
    }
    fclose(f);
}
void taskul3(lista_echipe **lista,int *nr_echipe, char *nume_fisier_out)
{
    lista_echipe *aux=*lista;
    lista_echipe *ultimii_opt=NULL;
    coada_meciuri *program=creaza_coada();
    while(aux!=NULL)
    {
        adaugare_meci_in_coada(program,aux->informatii_echipa,aux->next->informatii_echipa);
        aux=aux->next->next;
    }
    int nr_runda=1;
    while(*nr_echipe>=2)
    {
        afisare_program_meciuri_pt_fisier(program,nr_runda,nume_fisier_out);
        head_to_head *aux1=program->front;
        if(*nr_echipe==8)
        {
            aux1=program->front;
            while(aux1!=NULL)
            {
                inserare_echipa(&ultimii_opt,aux1->team1.nume_echipa,aux1->team1.punctaj_mediu,aux1->team1.nr_membrii,aux1->team1.jucatori_din_echipa);
                inserare_echipa(&ultimii_opt,aux1->team2.nume_echipa,aux1->team2.punctaj_mediu,aux1->team2.nr_membrii,aux1->team2.jucatori_din_echipa);
                aux1=aux1->next;
            }
        }
        aux1=program->front;
        lista_echipe *castigatori=NULL;
        lista_echipe *invinsi=NULL;
        while(aux1!=NULL)
        {
            if(aux1->team1.punctaj_mediu>aux1->team2.punctaj_mediu)
            {
                inserare_echipa(&castigatori,aux1->team1.nume_echipa,aux1->team1.punctaj_mediu+1,aux1->team1.nr_membrii,aux1->team1.jucatori_din_echipa);
                inserare_echipa(&invinsi,aux1->team2.nume_echipa,aux1->team2.punctaj_mediu,aux1->team2.nr_membrii,aux1->team2.jucatori_din_echipa);
            }
            else
            {
                inserare_echipa(&castigatori,aux1->team2.nume_echipa,aux1->team2.punctaj_mediu+1,aux1->team2.nr_membrii,aux1->team2.jucatori_din_echipa);
                inserare_echipa(&invinsi,aux1->team1.nume_echipa,aux1->team1.punctaj_mediu,aux1->team1.nr_membrii,aux1->team1.jucatori_din_echipa);
            }
            aux1=aux1->next;
        }
        afisare_lista_echipe_castigatoare_pt_fisier(castigatori,nr_runda,nume_fisier_out);
        if(*nr_echipe>8)
         stergere_lista_echipe(&invinsi);
        else
         if(*nr_echipe<=8)
          stergere_lista_echipe_fara_lista_de_jucatori(&invinsi);
        stergere_coada(program);
        program=creaza_coada(program);
        aux=castigatori;
        if(*nr_echipe>2)
          while(aux!=NULL)
          {
             adaugare_meci_in_coada(program,aux->informatii_echipa,aux->next->informatii_echipa);
             aux=aux->next->next;
          }
        *nr_echipe=(*nr_echipe)/2;
        nr_runda++;
    }
    *nr_echipe=8;
    *lista=ultimii_opt;
}
void iordine(FILE *f,Nod *root)
{
    if(root!=NULL)
    {
        iordine(f,root->right);
        fprintf(f,"%-33s -  %.2f\n",root->data.nume_echipa,root->data.punctaj_mediu);
        iordine(f,root->left);
    }
}
Nod* creare_nod_arbore(echipa team,int inaltime)
{
    Nod *root=(Nod*)malloc(sizeof(Nod));
    root->data=team;
    root->height=inaltime;
    root->left=NULL;
    root->right=NULL;
    return root;
}
Nod *inserare_in_BST(Nod *root,int inaltime,echipa team)
{
    if(root==NULL)
      return creare_nod_arbore(team,inaltime);
    if(fabs(root->data.punctaj_mediu-team.punctaj_mediu)<0.000001 && strcmp(root->data.nume_echipa,team.nume_echipa)>0)
    {
        echipa aux=root->data;
        root->data=team;
        root->right=inserare_in_BST(root->right,inaltime+1,aux);
    }
    else
     if(team.punctaj_mediu<root->data.punctaj_mediu)
       root->left=inserare_in_BST(root->left,inaltime+1,team);
     else
       root->right=inserare_in_BST(root->right,inaltime+1,team);
    return root;
}
void stergere_arbore(Nod *root)
{
    if(root==NULL)
     return;
    stergere_arbore(root->left);
    stergere_arbore(root->right);
    free(root->data.nume_echipa);
    free(root);
}
Nod *taskul4(lista_echipe *lista_cu_echipe,char *nume_fisier_out)
{
    Nod *root=NULL;
    int inaltime=0;
    root=inserare_in_BST(root,inaltime,lista_cu_echipe->informatii_echipa);
    lista_cu_echipe=lista_cu_echipe->next;
    int nr=2;
    while(lista_cu_echipe!=NULL)
    {
        inaltime=0;
        inserare_in_BST(root,inaltime,lista_cu_echipe->informatii_echipa);
        lista_cu_echipe=lista_cu_echipe->next;
        nr++;
    }
    FILE *f;
    if((f=fopen(nume_fisier_out,"at"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    fprintf(f,"\nTOP 8 TEAMS:\n");
    iordine(f,root);
    fclose(f);
    return root;
}
int inaltime_arbore(Nod *root)
{
    int inaltime_stanga,inaltime_dreapta;
    if(root==NULL)
     return 0;
    inaltime_stanga=inaltime_arbore(root->left);
    inaltime_dreapta=inaltime_arbore(root->right);
    return 1+ ((inaltime_stanga>inaltime_dreapta) ? inaltime_stanga:inaltime_dreapta);
}
int indice_de_echilibru(Nod *root)
{
    if(root==NULL)
     return 0;
    return inaltime_arbore(root->left)-inaltime_arbore(root->right);
}
int maximul_dintre_doi_intregi(int a,int b)
{
    return (a>b ? a : b);
}
Nod *rotatie_la_dreapta(Nod *z)
{
    Nod *y=z->left;
    Nod *T3=y->right;
    y->right=z;
    y->left=T3;
    z->height=1+maximul_dintre_doi_intregi(inaltime_arbore(z->left),inaltime_arbore(z->right));
    y->height= 1+ maximul_dintre_doi_intregi(inaltime_arbore(y->left),inaltime_arbore(y->right));
    return y;
}
Nod *rotatie_la_stanga(Nod *z)
{
    Nod *y=z->right;
    Nod *T3=y->left;
    y->left=z;
    y->right=T3;
    z->height=1+maximul_dintre_doi_intregi(inaltime_arbore(z->left),inaltime_arbore(z->right));
    y->height= 1+ maximul_dintre_doi_intregi(inaltime_arbore(y->left),inaltime_arbore(y->right));
    return y;
}
Nod *rotatie_la_stanga_dreapta(Nod *z)
{
    z->left=rotatie_la_stanga(z->left);
    return rotatie_la_dreapta(z);
}
Nod *rotatie_la_dreapta_stanga(Nod *z)
{
    z->right=rotatie_la_dreapta(z->right);
    return rotatie_la_stanga(z);
}
Nod *inserare_nod_in_AVL(Nod *root,echipa team)
{
     if(root==NULL)
     {
        root=(Nod*)malloc(sizeof(Nod));
        root->data=team;
        root->height=0;
        root->left=root->right=NULL;
        return root;
     }
    if(team.punctaj_mediu<root->data.punctaj_mediu)
     root->left=inserare_nod_in_AVL(root->left,team);
    else
     if(team.punctaj_mediu>root->data.punctaj_mediu)
      root->right=inserare_nod_in_AVL(root->right,team);
    else
      return root;
    root->height=1+maximul_dintre_doi_intregi(inaltime_arbore(root->left),inaltime_arbore(root->right));
    int indicele_de_echilibru=inaltime_arbore(root->left)-inaltime_arbore(root->right);
    if(indicele_de_echilibru>1 && team.punctaj_mediu<root->left->data.punctaj_mediu)
      return rotatie_la_dreapta(root);
    if(indicele_de_echilibru<-1 && team.punctaj_mediu>root->right->data.punctaj_mediu)
      return rotatie_la_dreapta(root);
    if(indicele_de_echilibru<1 && team.punctaj_mediu>root->left->data.punctaj_mediu)
      return rotatie_la_dreapta_stanga(root);
    if(indicele_de_echilibru<-1 && team.punctaj_mediu<root->right->data.punctaj_mediu)
       return rotatie_la_stanga_dreapta(root);
    return root;
}
/*Nod *balansare_BST(Nod *root)
{
    int indicele_de_echilibru=inaltime_arbore(root->left)-inaltime_arbore(root->right);
    if(root!=NULL)
    {
        if(indicele_de_echilibru>1 && team.punctaj_mediu<root->left->data.punctaj_mediu)
            return rotatie_la_dreapta(root);
        if(indicele_de_echilibru<-1 && team.punctaj_mediu>root->right->data.punctaj_mediu)
            return rotatie_la_dreapta(root);
        if(indicele_de_echilibru<1 && team.punctaj_mediu>root->left->data.punctaj_mediu)
            return rotatie_la_dreapta_stanga(root);
        if(indicele_de_echilibru<-1 && team.punctaj_mediu<root->right->data.punctaj_mediu)
            return rotatie_la_stanga_dreapta(root);
        balansare_BST(root->left);
        balansare_BST(root->rght);
    }
    return root;
}*/
void iordine_modificata(Nod *root)
{
    if(root!=NULL)
    {
        iordine_modificata(root->right);
        ///printf("%d\n",root->height);
        iordine_modificata(root->left);
    }
}
void afisare_echipe_de_pe_nivelul_2(FILE *f,Nod *root)
{
    if(root!=NULL)
    {
        afisare_echipe_de_pe_nivelul_2(f,root->left);
        if(root->height==2)
            fprintf(f,"%s\n",root->data.nume_echipa);
        ///printf("%d\n",root->height);
        afisare_echipe_de_pe_nivelul_2(f,root->right);
    }
}
void taskul5(lista_echipe *lista_cu_echipe,char *nume_fisier_out)
{
     lista_echipe *aux=lista_cu_echipe;
     Nod *root=NULL;
     while(aux!=NULL)
     {
         root=inserare_nod_in_AVL(root,lista_cu_echipe->informatii_echipa);
         aux=aux->next;
     }
     FILE *f;
     f=fopen(nume_fisier_out,"at");
     if(f==NULL)
     {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
     }
     fprintf(f,"\n");
     fprintf(f,"THE LEVEL 2 TEAMS ARE:\n");
     afisare_echipe_de_pe_nivelul_2(f,root);
     fclose(f);
     stergere_arbore(root);
}
