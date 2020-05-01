#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}


void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}



int main()
{
    Liste *maListe = initialisation();
    
    /*----------------------------*/
    int a,b;
    while(a!=4){
        printf("1- insertion.\n2- suppression.\n3- afficher Liste.\n\n- votre chois =");
    scanf("%d",&a);
     switch(a){
     	case 1:{
     		system("cls");
     		printf("donne le nombre d'insertion");
     		scanf("%d",&b);
     		insertion(maListe, b);
			break;
		 }
		 case 2:{
		 	 system("cls");
		     suppression(maListe);
			break;
		 }
		 case 3:{
		 	system("cls");
		 	afficherListe(maListe);
			break;
		 }
		 
	 }
 }
    /*----------------------------*/
  return 0;
}
