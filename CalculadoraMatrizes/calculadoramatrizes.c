#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
typedef struct MB
{
 char nome_matriz[20];
 float **M;
 int totalL, totalC;
}Matriz;
typedef struct Lista_Encadeada
{
 Matriz MD;
 struct Lista_Encadeada *prox;
}ListaLinear;
void inicializa_lista(ListaLinear **N)
{
 *N = NULL;
}
ListaLinear * Cria_Nodo()
{
 ListaLinear *p;
 p = (ListaLinear *) malloc(sizeof(ListaLinear));
 if(!p)
 {
 printf("Problema de alocação");
 exit(0);
 }
 return p;
}
int Lista_vazia(ListaLinear *aux)
{
 if(aux==NULL)
 {
 //system("cls");
 printf("Lista Vazia");
 return 1;
 }
 return 0;

}
ListaLinear* verifica_matriz(ListaLinear **N,char nome_matriz[20])
{

 ListaLinear *aux;


 aux = *N;
 if(*N==NULL)
 {
 return NULL;
 }

 else
 {
 while(aux->prox != NULL)
 {
 if (!strcmp(nome_matriz,aux->MD.nome_matriz))
 {
 break;
 }
 aux = aux->prox;
 }
 if ((strcmp(nome_matriz,aux->MD.nome_matriz))&&aux->prox==NULL)
 {
 aux=NULL;
 }

 }
 return aux;
}
void mostra_matrizes(ListaLinear *aux)
{
 printf("Matrizes cadastradas:\n");
 do
 {
 printf("%s",aux->MD.nome_matriz);
 aux=aux->prox;
 }while (aux!=NULL);
}
void nova_matriz(Matriz *Mymatriz,char nome_matriz[20],int lin,int col)
{
 int i,j;
 for (i=0; i<lin; i++)
 {

 for (j=0; j<col; j++)
 {
 printf("Linha %d\n", i);
 printf("Elemento %d %d\n", i, j);
 scanf("%f", *(Mymatriz->M +i) +j);
 //system("cls");
 }
 }
 printf("\n");
 strcpy(Mymatriz->nome_matriz,nome_matriz);
 Mymatriz->totalL=lin;
 Mymatriz->totalC=col;


}
void Imprime_Matriz(ListaLinear *aux,int flag)
{
 int i,j;
 printf("Matriz %s\n",aux->MD.nome_matriz);
 for (i=0; i<aux->MD.totalL; i++)
 {
 for (j=0; j<aux->MD.totalC; j++)
 {
 printf("%.2f ", *(*(aux->MD.M +i) +j));
 }
 printf("\n");
 }
 if(flag==1)
 getchar();
}
ListaLinear* encontra_matriz(ListaLinear **N,int c)
{
 char nome_matriz[20];
 ListaLinear *aux;


 aux = *N;
 if(*N==NULL)
 {
 return aux;
 }

 else
 {
 setbuf(stdin,NULL);
 if (c==98)
 printf("\nInforme o nome da Matriz \n");
 else
 printf("\nInforme o nome da Matriz %d\n",c);
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 setbuf(stdin,NULL);
 while(aux->prox != NULL)
 {
 if (!strcmp(nome_matriz,aux->MD.nome_matriz))
 {
 break;
 }
 aux = aux->prox;
 }
 if ((strcmp(nome_matriz,aux->MD.nome_matriz))&&aux->prox==NULL)
 {
 printf("\nMatriz nao cadastrada\n\n");
 aux=NULL;
 }

 }
 return aux;
}
ListaLinear* insere_fim_lista(ListaLinear **N, Matriz matriz)
{

 ListaLinear *novo, * aux;
 novo = Cria_Nodo( );
 novo->MD = matriz;
 novo->prox = NULL;
 if(*N == NULL)
 {
 *N = novo;
 }
 else
 {
 aux = *N;
 while(aux->prox != NULL)
 aux = aux->prox;

 aux->prox = novo;
 }
 printf("\n\nOperacao realizada com sucesso\n\n");
 return novo;
 getchar();
}
float** criamatriz(int lin,int col)
{

 float **matriz;
 int i;
 //printf("Numero de linhas = %d\n", lin);
 matriz = (float **) malloc (lin * sizeof(float *));
 if (!matriz)
 {
 puts("Nao há espaço para alocar memória");
 exit(1);
 }
 //printf("Numero de colunas = %d\n", col);
 for (i=0; i<lin; i++)
 {
 *(matriz +i) = (float *) malloc(col * sizeof (float));
 if (! *(matriz+i) ){
 printf("Não há espaço para alocar a linha %d", i);
 exit(1);
 }
 }
 return matriz;
}
void soma_matriz(Matriz *Mymatriz,ListaLinear *aux,ListaLinear *aux2)
{
 int i,j;
 Mymatriz->totalL=aux->MD.totalL;
 Mymatriz->totalC=aux->MD.totalC;
 for (i=0; i< Mymatriz->totalL; i++)
 {
 for (j=0; j<Mymatriz->totalC; j++)
 {
 (*(*(Mymatriz->M +i)+j))=(*(*(aux->MD.M +i) +j))+(*(*(aux2->MD.M +i) +j));
 }
 }

}
void sub_matriz(Matriz *Mymatriz,ListaLinear *aux,ListaLinear *aux2)
{
 int i,j;
 Mymatriz->totalL=aux->MD.totalL;
 Mymatriz->totalC=aux->MD.totalC;
 for (i=0; i< Mymatriz->totalL; i++)
 {
 for (j=0; j<Mymatriz->totalC; j++)
 {
 (*(*(Mymatriz->M +i)+j))=(*(*(aux->MD.M +i) +j))-(*(*(aux2->MD.M +i) +j));
 }
 }

}
void multi_matriz(Matriz *Mymatriz,ListaLinear *aux,ListaLinear *aux2)
{
 int i,j,k;
 Mymatriz->totalL=aux->MD.totalL;
 Mymatriz->totalC=aux2->MD.totalC;
 for (i=0; i<aux->MD.totalC; i++)
 {
 for (j=0; j<Mymatriz->totalL; j++)
 {
 for(k=0;k<aux2->MD.totalC;k++)
 {
 (*(*(Mymatriz->M +j)+k))+=(*(*(aux->MD.M +j) +i))*(*(*(aux2->MD.M +i) +k));

 }

 }
 }

}
void div_matriz(Matriz *Mymatriz,ListaLinear *aux,ListaLinear *aux2)
{
 int i,j;
 Mymatriz->totalL=aux->MD.totalL;
 Mymatriz->totalC=aux->MD.totalC;
 for (i=0; i< Mymatriz->totalL; i++)
 {
 for (j=0; j<Mymatriz->totalC; j++)
 {
 (*(*(Mymatriz->M +i)+j))=(*(*(aux->MD.M +i) +j))/(*(*(aux2->MD.M +i) +j));
 }
 }

}
void transpo_matriz(Matriz *Mymatriz,ListaLinear *aux)
{


 int i,j;
 Mymatriz->totalC=aux->MD.totalL;
 Mymatriz->totalL=aux->MD.totalC;
 for (i=0; i< Mymatriz->totalL; i++)
 {
 for (j=0; j<Mymatriz->totalC; j++)
 {
 (*(*(Mymatriz->M +i)+j))=(*(*(aux->MD.M +j) +i));
 }

 }


}
void Diagon_matriz(ListaLinear *aux)
{
 int i,j;
 printf("Diagonal %s\n",aux->MD.nome_matriz);
 for (i=0; i<aux->MD.totalL; i++)
 {
 for (j=0; j<aux->MD.totalC; j++)
 {
 if(i==j)
 {
 printf("%.2f ", *(*(aux->MD.M +i) +j));
 }
 }
 printf("\n");
 }
 getchar();
}
int remove_fim_lista(ListaLinear **N,ListaLinear **aux3)
{
 ListaLinear *aux;
 if(*N == NULL)
 return 0;
 else
 {
 aux=*N;
 while(aux->prox!=*aux3)
 aux=aux->prox;
 aux->prox=NULL;
 free(*aux3);
 }

 return 1;
}
int remove_inicio_lista(ListaLinear **N)
{

 ListaLinear *aux;
 if(*N == NULL)
 return 0;


 else
 {

 aux = (*N)->prox;
 free(*N);
 *N = aux;
 }

 return 1;
}
int remove_meio_lista(ListaLinear **N,ListaLinear **aux3)
{
 ListaLinear *aux;


 if(*N == NULL)
 return 0;
 else
 {
 aux=*N;

 while(aux->prox!=*aux3)
 aux=aux->prox;

 aux->prox=(*aux3)->prox;
 free(*aux3);
 }

 return 1;
}
int main()
{
 int i,j,menu,lin,col,flag,check,checklist=0;
 char linha[80],nome_matriz[20];
 ListaLinear *MyList,*aux,*aux2,*aux3,*aux4;
 Matriz Mymatriz;


 inicializa_lista(&MyList);

 do{
 flag=1;
 printf("\n ---------------MENU----------------");
 printf("\n 1. Inserir nova matriz ");
 printf("\n 2. Imprimir Matriz ");
 printf("\n 3. Somar Matrizes ");
 printf("\n 4. Subtrair Matrizes ");
 printf("\n 5. Multiplicar Matrizes ");
 printf("\n 6. Dividir Matrizes ");
 printf("\n 7. Transpor Matriz ");
 printf("\n 8. Imprimir Diagonal da Matriz ");
 printf("\n 9. Destruir Matriz ");
 printf("\n 10. Sair ");
 printf("\n -----------------------------------\n");
 scanf("%d", &menu);
 switch(menu)
 {



 case 1:
 //system("cls");
 do{
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux=verifica_matriz(&MyList,nome_matriz);
 }while(aux!=NULL);
 //system("cls");
 do
 {
 printf("Informe o numero de linhas");
 setbuf(stdin,NULL);
 gets(linha);
 lin = atoi(linha);
 } while (lin<=0);
 //system("cls");
 do
 {
 puts("Informe o numero de colunas");
 setbuf(stdin,NULL);
 gets(linha);
 col = atoi(linha);
 } while (col<=0);
 // system("cls");
 Mymatriz.M=criamatriz(lin,col);
 nova_matriz(&Mymatriz,nome_matriz,lin,col);
 // system("cls");
 insere_fim_lista(&MyList, Mymatriz);
 getchar();
 // system("cls");

 break;



 case 2:
 if(Lista_vazia(MyList))
 break;
 // system("cls");
 mostra_matrizes(MyList);
 flag=98;
 do {
 // system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 flag=1;
 }while(aux==NULL);
 // system("cls");
 Imprime_Matriz(aux,flag);
 // system("cls");
 break;


 case 3:

 if(Lista_vazia(MyList))
 break;
 //system("cls");
 do {
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 flag++;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux2=encontra_matriz(&MyList,flag);
 }while(aux2==NULL);

 lin=aux->MD.totalL;
 col=aux->MD.totalC;
 if(aux->MD.totalL!=aux2->MD.totalL||aux->MD.totalC!=aux2->MD.totalC)
 {
 //system("cls");
 printf("\n\nMatrizes Incompativeis\n\n");
 break;
 }
 else
 {
 Mymatriz.M=criamatriz(lin,col);
 soma_matriz(&Mymatriz,aux,aux2);
 }
 printf("\n");
 do{
 //system("cls");
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux4=verifica_matriz(&MyList,nome_matriz);
 }while(aux4!=NULL);
 strcpy(Mymatriz.nome_matriz,nome_matriz);
 aux3=insere_fim_lista(&MyList, Mymatriz);
 Imprime_Matriz(aux,flag);
 printf("\n + \n\n");
 Imprime_Matriz(aux2,flag);
 printf("\n = \n\n");
 flag--;
 Imprime_Matriz(aux3,flag);
 //system("cls");
 break;



 case 4:

 if(Lista_vazia(MyList))
 break;
 //system("cls");
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 flag++;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux2=encontra_matriz(&MyList,flag);
 }while(aux2==NULL);

 lin=aux->MD.totalL;
 col=aux->MD.totalC;
 if(aux->MD.totalL!=aux2->MD.totalL||aux->MD.totalC!=aux2->MD.totalC)
 {
 //system("cls");
 printf("Matrizes Incompativeis");
 break;
 }
 else
 {
 Mymatriz.M=criamatriz(lin,col);
 sub_matriz(&Mymatriz,aux,aux2);
 }
 printf("\n");
 do{
 //system("cls");
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux4=verifica_matriz(&MyList,nome_matriz);
 }while(aux4!=NULL);
 strcpy(Mymatriz.nome_matriz,nome_matriz);
 aux3=insere_fim_lista(&MyList, Mymatriz);
 Imprime_Matriz(aux,flag);
 printf("\n - \n\n");
 Imprime_Matriz(aux2,flag);
 printf("\n = \n\n");
 flag--;
 Imprime_Matriz(aux3,flag);
 //system("cls");
 break;


 case 5:

 if(Lista_vazia(MyList))
 break;
 //system("cls");
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 flag++;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux2=encontra_matriz(&MyList,flag);
 }while(aux2==NULL);

 lin=aux->MD.totalL;
 col=aux2->MD.totalC;
 if(aux->MD.totalC!=aux2->MD.totalL)
 {
 //system("cls");
 printf("Matrizes Incompativeis");
 break;
 }
 else
 {
 Mymatriz.M=criamatriz(lin,col);
 multi_matriz(&Mymatriz,aux,aux2);
 }
 printf("\n");
 do{
 //system("cls");
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux4=verifica_matriz(&MyList,nome_matriz);
 }while(aux4!=NULL);
 strcpy(Mymatriz.nome_matriz,nome_matriz);
 aux3=insere_fim_lista(&MyList, Mymatriz);
 Imprime_Matriz(aux,flag);
 printf("\n * \n\n");
 Imprime_Matriz(aux2,flag);
 printf("\n = \n\n");
 flag--;
 Imprime_Matriz(aux3,flag);
 //system("cls");
 break;


 case 6:

 if(Lista_vazia(MyList))
 break;
 //system("cls");
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 flag++;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux2=encontra_matriz(&MyList,flag);
 }while(aux2==NULL);

 lin=aux->MD.totalL;
 col=aux->MD.totalC;
 for (i=0; i< aux2->MD.totalL; i++)
 {
 for (j=0; j<aux2->MD.totalC; j++)
 {
 if((*(*(aux2->MD.M +i)+j))==0)
 {
 //system("cls");
 printf("\nImpossivel divisao por 0 \n");
 check=98;
 break;
 }
 }
 }
 if(check==98)
 break;
 if(aux->MD.totalL!=aux2->MD.totalL||aux->MD.totalC!=aux2->MD.totalC)
 {
 //system("cls");
 printf("Matrizes Incompativeis");
 break;
 }
 else
 {
 Mymatriz.M=criamatriz(lin,col);
 div_matriz(&Mymatriz,aux,aux2);

 }
 printf("\n");
 do{
 //system("cls");
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux4=verifica_matriz(&MyList,nome_matriz);
 }while(aux4!=NULL);
 strcpy(Mymatriz.nome_matriz,nome_matriz);
 aux3=insere_fim_lista(&MyList, Mymatriz);
 Imprime_Matriz(aux,flag);
 printf("\n / \n\n");
 Imprime_Matriz(aux2,flag);
 printf("\n = \n\n");
 flag--;
 Imprime_Matriz(aux3,flag);
 //system("cls");
 break;


 case 7:

 if(Lista_vazia(MyList))
 break;
 //system("cls");
 flag=98;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 lin=aux->MD.totalC;
 col=aux->MD.totalL;
 {

 Mymatriz.M=criamatriz(lin,col);
 transpo_matriz(&Mymatriz,aux);

 }
 printf("\n");
 do{
 //system("cls");
 printf("Insira o nome da sua nova matriz:\n");
 setbuf(stdin,NULL);
 fgets(nome_matriz,20,stdin);
 aux=verifica_matriz(&MyList,nome_matriz);
 }while(aux!=NULL);
 strcpy(Mymatriz.nome_matriz,nome_matriz);
 aux=insere_fim_lista(&MyList, Mymatriz);
 printf("\nResultado:\n\n");
 Imprime_Matriz(aux,flag);
 //system("cls");
 break;



 case 8:
 if(Lista_vazia(MyList))
 break;
 //system("cls");
 flag=98;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 if(aux->MD.totalL==aux->MD.totalC)
 {
 //system("cls");
 Diagon_matriz(aux);
 //system("cls");
 }
 else
 {
 //system("cls");
 printf("Matriz nao Quadrada\n\n\n");
 getchar();
 }
 break;

 case 9:
 if(Lista_vazia(MyList))
 break;
 //system("cls");
 flag=98;
 do {
 //system("cls");
 mostra_matrizes(MyList);
 aux=encontra_matriz(&MyList,flag);
 }while(aux==NULL);
 strcpy(nome_matriz,aux->MD.nome_matriz);
 if(MyList==aux)
 {
 //system("cls");
 if(remove_inicio_lista(&MyList))
 printf("\n\nMatriz %s Destruida\n\n",nome_matriz);
 break;
 }
 else if(aux->prox==NULL)
 {
 //system("cls");
 if(remove_fim_lista(&MyList,&aux))
 printf("\n\nMatriz %s Destruida\n\n",nome_matriz);
 break;
 }
 else
 {
 //system("cls");
 if(remove_meio_lista(&MyList,&aux))
 printf("\n\nMatriz %s Destruida\n\n",nome_matriz);
 break;
 }

 case 10:

 //system("cls");
 printf("\n\n\nSaindo do programa!\n\n");
 if (checklist==0)
 break;
 else
 free(Mymatriz.M);
 while(MyList->prox != NULL)
 {
 MyList=MyList->prox;
 free(*MyList->MD.M);
 }
 MyList=MyList->prox;
 free(*MyList->MD.M);
 free(MyList);
 break;
 default:
 //system("cls");
 printf("\nOpcao Invalida");
 getchar();
 }
 }while(menu != 10);
 return 0;
}
