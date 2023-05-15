#include "functiile.c"
int main(int argc, char *argv[])
{
    int *taskuri;
    taskuri=(int*)malloc(5*sizeof(int));
    if(argc!=4)
     {
        printf("Numarul de argumente este incorect!\n");
        exit(1);
     }
    citire_taskuri(taskuri,argv[1]);
    lista_echipe *lista_cu_echipe=NULL;
    Nod *root=NULL;
    int nr_echipe=0;
    if(taskuri[0]==1)
    {
          taskul1(&lista_cu_echipe,&nr_echipe,argv[2],argv[3]);
          ///afisare_lista_echipe(lista_cu_echipe);
    }
    if(taskuri[1]==1)
    {
        taskul2(&lista_cu_echipe,nr_echipe-puterea_maxima_a_lui_doi(nr_echipe),argv[3]);
        ///afisare_lista_echipe(lista_cu_echipe);
        nr_echipe=puterea_maxima_a_lui_doi(nr_echipe);
    }
    if(taskuri[2]==1)
    {
        taskul3(&lista_cu_echipe,&nr_echipe,argv[3]);
        ///afisare_lista_echipe(lista_cu_echipe);
    }
    if(taskuri[3]==1)
      root=taskul4(lista_cu_echipe,argv[3]);
    if(taskuri[4]==1)
      taskul5(lista_cu_echipe,argv[3]);
    free(taskuri);
    return 0;
}
