#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
}

void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}

int main()
{
	/*-------------------------*/
	int a,b;
	Pile *maPile = initialiser();
	while(a!=4){
	
	    printf("chois un ici,\n\n1- empiler.\n2- depiler.\n3- afficher la pile.\n");
    scanf("%d",&a);
    
     switch(a){
     	case 1:{
     		system("cls");
     		printf("donne la valeur empiler");
     		scanf("%d",&b);
     		empiler(maPile, b);
			break;
		 }
		 case 2:{
		 	system("cls");
		 	printf("Je depile %d\n", depiler(maPile));
			break;
		 }
		 case 3:{
		    system("cls");
		 	printf("\nEtat de la pile :\n");
		 	afficherPile(maPile);
			break;
		 }
	 }
	 
   }
	return 0;
}
