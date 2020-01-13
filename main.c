#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define taille 10

void affichtab (char monTableau[taille][taille]);
void remptab ( char monTableau[taille][taille]);
void selectionpla(char monTableau[taille][taille],int col, int l, char o);
void choixennemi(char monTableau[taille][taille],int cole, int le,int l,int col,int s);

int main()
{

    char monTableau[taille][taille];
    remptab (monTableau);
    affichtab(monTableau);
    int l;
    int col;
    char o;
    selectionpla( monTableau, col, l, o );
    int cole;
     int le;
     int s;
    choixennemi( monTableau,cole,  le, l, col, s);




    return 0;
}

//remplir le tab

void  remptab  ( char monTableau[taille][taille])
{
    int i;
    int j;

    for(i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            monTableau[i][j]='~';
        }
    }
}
//affiche le tab
void affichtab ( char monTableau[taille][taille])
{
    system("cls");
    int i;
    int j;

    for(i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            printf ("%c",monTableau[i][j]);
        }
        printf("\n");
    }
}
//selection de la ligne et colonne
void selectionpla(char monTableau[taille][taille], int col ,int l,char o )

{

   o = 'p' ;
   printf(" à toi joueur A selectionne ta colonne  \n" ) ;
   scanf(" %d",&col);
   printf(" maintenant, selectionne ta ligne  \n ");
   scanf(" %d",&l);
   monTableau[col][l]= o;
   affichtab(monTableau);
}


void choixennemi (char monTableau[taille][taille],int cole, int le,int l,int col , int s)
{


    int i;
    int j;

    printf(" à toi joueur B selectionne ta colonne  \n" ) ;
   scanf(" %d",&cole);
   printf(" maintenant, selectionne ta ligne  \n ");
   scanf(" %d",&le);


          if(monTableau[cole][le]=='~')  monTableau[cole][le]='?';
          if(monTableau[cole][le]=='p')  monTableau[cole][le]='X';

           affichtab(monTableau);

            if (monTableau[cole][le]=='X') s = 30;

 printf("ton score est de \n %d",s)  ;
}
void fscore(char monTableau[taille][taille] , int s){

    FILE* p_score_file = fopen("score.bin", "ab");


    if(p_score_file == NULL){
        printf("L'ouverture du fichier n'a pas fonctionnee\n");
    } else {

        fwrite(&s, sizeof (int), 1, p_score_file);
        fclose(p_score_file);
    }
}







