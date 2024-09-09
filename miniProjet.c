#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 typedef   struct

{
    char nom[40];
    int num;
    char email[40];

}Contact;
int count = 0;


 Contact emp[12];

int chercher(char a[40] , int x){

    for(int i=0 ; i<count ; i++){
        char nom[40] ;
        char email[40] ;

        strcpy(nom, emp[i].nom);
        strcpy(email, emp[i].email);

      if (x==1)
      {
        if( strcmp(nom,a)==0)
        {


           return i;
        }
      }else
      {
        if( strcmp(email,a)==0)
        {


           return i;
        }
      }





    }

    return -1;

}


void insert(){
     Contact c;
            printf("Entrer le nom: ");
            scanf("%s", c.nom);

            printf("Entrer le numero tele \n ");
            scanf("%d", &c.num);

            printf("Entrer l'email: \n");
            scanf("%s", c.email);

             emp[count]=c;

            count++;




}
void ajouteM(){

    int x=1;

    while (x)
    {
        int n;
          insert();

          printf("0 . pour entrer fini la fonction\n");
          printf("1 . pour entrer un autre contact\n");


          scanf("%d" , &n);
          x=n;

    }




}



void modifier(){
   char y[40];
    int x;

   printf("1 .chercher le contact avec le nom  \n");
   printf("2 .chercher le contact avec le email  \n  ");
   scanf("%d" , &x);
   printf("enter le  contact ");
   scanf("%s" , y);

   int res =chercher(y , x);
     if(res==-1){
        printf(" le contact n'exist pas\n");
     }else{

        char e[30];
        printf("enter un nouveau adersse  email");
        scanf("%s" , e);
        int n;
        printf("enter un nouveau numéro");
        scanf("%d" , &n);


        strcpy(emp[res].email,e);

         emp[res].num=n;

        printf("les infrmation a ete modifier");

     }

}
void supprimer(){
     char y[40];
    int x;

   printf("1 .chercher le contact avec le nom  \n");
   printf("2 .chercher le contact avec le email  \n  ");
   scanf("%d" , &x);
   printf("enter le  contact ");
   scanf("%s" , y);

   int res =chercher(y , x);

    if (res==-1)
    {
        printf("ce contact n'exist pas \n");
    }else{
        for (int i = res; i < count-1; i++)
        {
           emp[i]=emp[i+1];
        }
        count--;

    }



}





void chercherContact(){
    char y[40];
    int x;

   printf("1 .chercher le contact avec le nom  \n");
   printf("2 .chercher le contact avec le email  \n  ");
   scanf("%d" , &x);
   printf("enter le  contact ");
   scanf("%s" , y);

   int res =chercher(y , x);

    if (res==-1)
    {
        printf("ce contact n'exist pas");

    }else{

         printf("le nom : %s , le num : %d , l'email : %s \n", emp[res].nom ,emp[res].num ,emp[res].email );


    }



}

 void  clone(Contact *list ){


      for (int  i = 0; i < 12; i++)
      {
        list[i]=emp[i];
      }

 }


// void afficheASC(){
//     Contact oper[12];
//      clone(oper);


//     for (int i = 0; i < count-1; i++)
//     {
//         for (int j = 0; j < count-i-1; j++)
//         {
//               Contact c;



//                if (strcmp (oper[j].nom,oper[j+1].nom)>0)
//             {

//                 c=oper[j];
//                 oper[j]=oper[j+1];
//                 oper[j+1]=c;
//             }






//         }

//     }


//         for (int i = 0; i < count; i++)
//         {
//            printf("nom: %s,num : %d , email: %s, \n",
//                     oper[i].nom, oper[i].num, oper[i].email);

//         }

// }

void affiche(int x){
    Contact oper[12];
     clone(oper);


    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
              Contact c;



               if (strcmp (oper[j].nom,oper[j+1].nom)<0)
            {

                c=oper[j];
                oper[j]=oper[j+1];
                oper[j+1]=c;
            }






        }

    }

             if(x==0){
        for (int i = 0; i < count; i++)
        {
           printf("nom: %s,num : %d , email: %s, \n",
                    oper[i].nom, oper[i].num, oper[i].email);

        }
    }else{


     for (int i = count -1; i >= 0; i--)
        {
           printf("nom: %s,num : %d , email: %s, \n",
                    oper[i].nom, oper[i].num, oper[i].email);

        }



    }





}


int main(){
int state=0;
while (state!=9)
{
        printf("Si vous voulez ajouter un contact, entrez [1]\n");
        printf("Si vous voulez afficher les contactes par ordre croissant, entrez [2]\n");
        printf("Si vous voulez afficher un contact, entrez [3]\n");
        printf("Si vous voulez mettre à jour un contact, entrez [4]\n");
        printf("Si vous voulez supprimer un contact, entrez [5]\n");
        printf("Si vous voulez ajouter plusieure  contact, entrez [6]\n");
        printf("Si vous vouler les contacts par ordre Décroissant., entrez [7]\n");

        printf("Pour quitter, entrez [9]\n");

       scanf("%d",&state);


       switch (state)
       {
       case 1:
         insert();
        break;
       case 2:

         printf("ASC \n");
         printf("DESC \n");
         int x;
         scanf("%d" , &x);


         affiche(x);
        break;
        case 3:


         chercherContact();
        break;
        case 4:
         modifier();
        break;
        case 5:

         supprimer();
        break;
        case 6:

         ajouteM();
        break;

       default:
        break;
       }




}



}

