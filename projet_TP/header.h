
struct produit
{ int codebar;
int qte;
float prix;
char nom;
}; typedef struct produit PRODUIT;
//**************************************
int saisie();
PRODUIT* allocation_rempissage(int);
void affichage(PRODUIT*,int);
void ajout(int,PRODUIT**);
void supprimer(int,PRODUIT**);
void consulter1(int, PRODUIT*); // affichage d'un produit 
void consultaion(int,PRODUIT*); //consultation d'un produit => si le produit disponible il affiche le qte el le nom du produit si non il afiche " le produit est indisponible"
void modifier(int,PRODUIT**);// modification du prix 
void tri(int , PRODUIT**); //tri
//**************************************
