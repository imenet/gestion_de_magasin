#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"Header.h"
int saisie()
{
	int n ;
    printf("donner le nombre de types de produits");
    scanf("%d",&n);
return n;
}
PRODUIT * allocation_remplissage(int n)
{ PRODUIT* t;
t=((PRODUIT*)malloc(n*sizeof(PRODUIT)));
	if(!t) exit(-1);

	for(int i=0;i<n;i++)
	{ printf("donner le code bar");
	scanf("%d",&(t+i)->codebar);
	printf("donner le prinx");
	scanf("%f",&(t+i)->prix);
	printf("donner le prix");
	scanf("%d",&(t+i)->qte);
	printf("donner le nom");
	scanf("%s",&(t+i)->nom);
	}
	return t;
	
}
void affichage(PRODUIT* t,int n)
{  
	
	for(int i=0;i<n;i++)
	{
	printf("le codebar du produit est %d \t    le nom est %s      le prix est %d \t   le qte est %d \t",((t+i)->codebar),((t+i)->nom),((t+i)->prix),((t+i)->qte));
	}
}

void ajout(int n , PRODUIT **t)
{
	*t=(PRODUIT*)realloc(t,(n+1)*sizeof(PRODUIT));
        if(!t) exit(-2);
    printf("donner le nouveaux produit");
	 printf("donner le code a bar");
	scanf("%d",&(*t+n)->codebar);
	printf("donner le prix");
	scanf("%d",&(*t+n)->prix);
	printf("donner le prix");
	scanf("%d",&(*t+n)->qte);
	printf("donner le nom");
	scanf("%c",&(*t+n)->nom);
	
	
}
void supprimer(int n , PRODUIT ** t)
{ 
	int _code;
	printf("donner le code a bar du produit a suprimer");
    scanf("%d",&_code);
	for(int i=0;i<n;i++)
	{
		if(_code==(*t+i)->codebar)
			for (int j=i;i<n-1;i++)
			{
				(*t+j)->codebar=(*t+n-1)->codebar;
				(*t+i)->prix=(*t+n-1)->prix;
				(*t+i)->nom=(*t+n-1)->nom;
				(*t+i)->qte=(*t+n-1)->qte;
			}
			*t=(PRODUIT*)realloc(t,(n-1)*sizeof(PRODUIT));
			if(!t) exit(-3);


		

	}
}
void consulter1(int n, PRODUIT *t)
{
	int cod;
	printf("donner le code bar du produit a consulter");
	scanf("%d",&cod);
	for(int i=0;i<n;i++)
	{ if(cod==((t+i)->codebar))
	
	printf("**********************************************");
	printf("le codebar du produit  est %d \t le nom est %s le prix est %f \t le qte est %d \t",(t+i)->codebar,(t+i)->nom,(t+i)->prix,(t+i)->qte);
	}
}
void consultaion(int n,PRODUIT *t)
{
	int cod ;
	printf("donner le code bar du produit a consulter");
	scanf("%d",&cod);

	for(int i=0;i<n;i++)
	{ if((cod==((t+i)->codebar))&&((t+i)->qte!=0))
	
	{printf("**********************************************");
	printf("le produit existe et le codebar du produit  est %d \t le nom est %s le prix est %d \t le qte est %d \t",(t+i)->codebar,(t+i)->nom,(t+i)->prix,(t+i)->qte);
	}
	else printf("le produit est non disponible");
	}
}

void modifier(int n,PRODUIT **t)
{ int _codebar;
int _qte;
float _prix;
int m;
printf("donner le le codebar du produirt a modifier");
scanf("%d",&_codebar);
for(int i=0;i<n;i++)
  {
	  if(_codebar==((*t+i)->codebar))
	  {
		  printf("si tu veut modifier le prix taper 1 \n si tu veut modifier la qte taper 2 si tu veut modifier le deux taper 3");
		  scanf("%d",&m);
		  switch(m)
		  { 
		  case(1):
			  {
				 printf("\n----------------------modification du prix-----------------------------------\n");
                 printf("donner le nouveaux prix");
                 scanf("%f",&(*t+i)->prix);
				 printf("\n----------------------fin modification prix----------------------------------\n");
			  }
			  break;
		  case(2):
			  {
				  printf("\n------------------modification qte de produit ------------------------------\n");
				  printf("donner le nouveaux qte du produit");
				  scanf("%d",&(*t+i)->qte);
				  printf("\n-----------------fin modification qte de produit----------------------------\n");
			  }
			  break;
		  case(3):
			  {
				  printf("\n-------------------modiffication qte et prix de produit---------------------\n");
				  printf("\ndonner le nouveaux prix et qte du prix a modifier\n");
				  scanf("%f%d",&(*t+i)->prix,&(*t+i)->qte);
				  printf("\n-------------------fin modification qte et prix de produit-----------------\n");
			  }
			  break;
	  }

  }
}
}
void tri(int n ,PRODUIT **t)
{ int m=n;
bool tab_en_ordre=false;
PRODUIT e;
 while(!tab_en_ordre)
 {
	tab_en_ordre=true;
	for(int i=0;i<m;i++)
	{ 
		if(((*t+i)->prix)<(*t+i+1)->prix)
		{
			tab_en_ordre=false;
	
	        
			e.prix=(*t+i)->prix;
			e.qte=(*t+i)->qte;
			e.nom=(*t+i)->nom;
			e.codebar=(*t+i)->codebar;
			(*t+i)->prix=(*t+i+1)->prix;
			(*t+i)->qte=(*t+i+1)->qte;
			(*t+i)->nom=(*t+i+1)->nom;
			(*t+i)->codebar=(*t+i+1)->codebar;
			(*t+i+1)->prix=(e.prix);
			((*t+i+1)->nom)=(e.nom);
			(*t+i+1)->qte=(e.qte);
			(*t+i+1)->codebar=e.codebar;

		}
		m--;
	
	}
 }

}

