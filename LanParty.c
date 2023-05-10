#include "meci_si_coada_de_meciuri.h"
#include "arbore.h"
#include "biblioteci_si_define.h"
#include "prototipul_functiilor.h"
int main()
{
    int *taskuri;
    taskuri=(int*)malloc(5*sizeof(int));
    citire_taskuri(taskuri);
    /*int i;
    for(i=0;i<5;i++)
     printf("%d ",taskuri[i]);
    printf("\n");
    */
    lista_echipe *lista_cu_echipe=NULL;
    Nod *root;
    int nr_echipe=0;
    if(taskuri[0]==1)
    {
          taskul1(&lista_cu_echipe,&nr_echipe);
          ///afisare_lista_echipe(lista_cu_echipe);
    }
    if(taskuri[1]==1)
    {
        taskul2(&lista_cu_echipe,nr_echipe-puterea_maxima_a_lui_doi(nr_echipe));
        ///afisare_lista_echipe(lista_cu_echipe);
        nr_echipe=puterea_maxima_a_lui_doi(nr_echipe);
    }
    if(taskuri[2]==1)
    {
        taskul3(&lista_cu_echipe,&nr_echipe);
        ///afisare_lista_echipe(lista_cu_echipe);
    }
    if(taskuri[3]==1)
      root=taskul4(lista_cu_echipe);
    if(taskuri[4]==1)
      root=taskul5(root);
    printf("A trecut aici!\n");
    /*float minim;
    punctaj_minim(lista_cu_echipe,&minim);
    printf("Puntajul minim de-a lungul echipelor este:%f\n",minim);
    printf("%d\n",nr_echipe);
    printf("%d\n",puterea_maxima_a_lui_doi(nr_echipe));
    */
    stergere_lista_echipe(&lista_cu_echipe);
    free(taskuri);
    return 0;
}
