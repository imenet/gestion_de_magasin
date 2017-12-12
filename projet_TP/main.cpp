#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"
void main()

{
	printf("\n**************************************************************************************************************\n");
	printf("\n------------------------------------------------bienvenue-----------------------------------------------------\n");
	printf("\n**************************************************************************************************************\n");
	
	int n;
	PRODUIT *t;
	int exit=1;
	n=saisie(); //saisir le nombre de produits 
    t=allocation_rempissage(n);
	tri(n,&t);
	float caise;
	int fin=0;
	int code_bar;
	int qte;

	while(exit)
	{   
	    printf("si tu veut afficher les produits taper 2 \n si tu veut consulter un produit taper 3 \n si tu veut consulter1 un produit taper 4 \n si tu veut ajouter un produit taper 5 \n si tu veut supprimer un produit taper 6 \n si tu veut modifier un produit taper 7 \n si tu veut vendre taper 8 \n si tu ceut afficher la caise taper 9 \n si tu veut exit taper 1");
	  scanf("%d",&exit);
		switch(exit)
		{ case 2:
		  { 
			  printf("\n-------------------------------AFFICHAGE----------------------------------------------\n");
			  affichage(t,n);
		      printf("\n--------------------------------FIN AFFICHAGE------------------------------------------\n");
		  } // affichage des prodits 
	   break;
		case(3):
			{  printf("\n---------------------------CONSULTATION--------------------------------------------------\n");
			   consultaion(n,t);  
			   printf("\n--------------------------FIN CONSULTATION-----------------------------------------------\n");
			}// consutation il nous informer si le produit est disponible ou non 
		   break;
	   case(4):
		   {   
			   printf("\n---------------------------AFFICHAGE D'UN PRODUIT--------------------------------------------------\n");
			   consulter1(n,t);
		       printf("\n---------------------FIN AFFICHAGE D'UN PRODUIT----------------------------------------------------\n");
		   }
		       //afichage d'un produit en utilisant le code bar comme idantifiant : entre du code bar du produit en clavier et affichage du prix , nom el qte du prix
		   break;
	   case(5):
		   {
			   printf("\n----------------------------------------AJOUT D'UN PRODUIT---------------------------------------------------\n");
		       ajout(n,&t); n=n+1; tri(n,&t);
		       printf("\n---------------------------------------FIN AJOUT D'UN PRODUIT-------------------------------------------------\n");
		   } //ajout d'un produit
		   break;
	   case(6):
		   {
			   printf("\n---------------------------------SUPPRIMER UN PRODUIT--------------------------------------------------------\n");
			   supprimer(n,&t); n=n-1; tri(n,&t);
			   printf("\n--------------------------FIN DU SUPPRISSION D'UN PRODUIT---------------------------------------------------\n");}
		   // supprimer un produit 
		   break;
	   case(7):
		   {
			    printf("\n-----------------------------MODIFICATION D'UN PRIX D'UN¨PRODUIT----------------------------------------------\n");
			    modifier(n,&t); tri(n,&t);
			    printf("\n-----------------------------FIN MODIFICATION DU PRIX D'UN PRODUIT--------------------------------------------\n");
		   } // modifier le prix d'un produit en utilisant le code bar comme idantifiant  
		   break;
	   case(8):
		   {
			    printf("\n------------------------------------ACHAT----------------------------------------------\n");
			   do{
				   printf("si il ya vente d'un produit taper 0 sinon taper 100");
				   scanf("%d",&fin);
				   printf("doner le code bar du produit a acheter ");
				   scanf("%d",&code_bar);
				   printf("donner le qte");
				   scanf("%d",&qte);
				   for(int i=0;i<n;i++)
				   {
					   if(code_bar==(t+i)->codebar)
					   {
						   (t+i)->qte-=qte;
						   caise+=(((t+i)->prix)*qte);

						   break;
					   }
				   }
			   }while(fin==100);

			 printf("\n----------------------------------------FIN ACHAT-----------------------------------------------\n");
		   }
		   break;
	   case(9): 
		   {
			    printf("\n-------------------------------AFFICHAGE DE LE GAIN------------------------------------------\n");
			    printf("le qte d'achat est  %f",caise);
			    printf("\n-----------------------------FIN AFFICHAGE GAIN--------------------------------------------\n");
		   }
		   break;
		  
	   }
	}
	printf("\n**************************************************************************************************************\n");
	printf("\n----------------------------------------------AUREVOIR--------------------------------------------------------\n");
	printf("\n**************************************************************************************************************\n");
	getch();
}