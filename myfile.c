#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};


File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}


void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}


int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}

void afficherFile(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;

    while (element != NULL)
    {
        printf("%d\n", element->nombre);
        element = element->suivant;
    }

    printf("\n");
}

int main()
{
	int a,b,c,d;
	File *maFile = initialiser();
	while(a!=4){
	
	    printf("\n\nchois un ici,\n\n1- enfiler.\n2- defiler.\n3- afficher File.\n4- exit\n\n");
        scanf("%d",&a);
    
     switch(a){
     	case 1:{
     		system("cls");
     		printf("donne la valeur enfiler\n");
     		scanf("%d",&b);
     		enfiler(maFile, b);
     		system("cls");
     		printf("\nEtat de la file :\n");
            afficherFile(maFile);
			break;
		 }
		 case 2:{
		 	system("cls");
		 	printf("Je defile \n_![%d]!\n", defiler(maFile));
		 	printf("\nEtat de la file :\n");
            afficherFile(maFile);
			break;
		 }
		 case 3:{
		    system("cls");
		 	printf("\nEtat de la file :\n");
            afficherFile(maFile);
			break;
	     }
	 }
	 
   }
	return 0;
}
