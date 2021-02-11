#include <stdio.h>
#include <stdlib.h>

typedef struct element element; 
struct element
{
	int val;
	struct element *nxt; 
};

typedef element* llist;

llist header(llist liste, int valeur)
{
	/* On crée un nouvel élément */
	element* nouvelElement = malloc(sizeof(element));
	/* On assigne la valeur au nouvel élément */
	nouvelElement->val = valeur;
	/* On assigne l'adresse de l'élément suivant au nouvel élément*/
	nouvelElement->nxt = liste;
	/* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
	return nouvelElement; 
}


llist tail(llist liste, int valeur)
{
	/* On crée un nouvel élément */
	element* nouvelElement = malloc(sizeof(element));
	/* On assigne la valeur au nouvel élément */
	nouvelElement->val = valeur;
	/* On ajoute en fin, donc aucun élément ne va suivre */
	nouvelElement->nxt = NULL;

	if(liste == NULL)
	{
		/* Si la liste est videé il suffit de renvoyer l'élément créé */
		return nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		 * indique que le dernier élément de la liste est relié au nouvel élément */
		element* temp = liste; 
		while(temp->nxt != NULL)
		{
			temp = temp->nxt;
		}
		temp->nxt = nouvelElement; 
		return liste;
	}
}

void print(llist liste)
{
	element* temp=liste;// to not loose the header address
	printf("List is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->val);
		temp = temp->nxt;
	}
	printf("\n");
}

int main()
{
	/* Déclarons 3 listes chaînées de façons différentes mais équivalentes */
	llist ma_liste1 = NULL;

	//element *ma_liste2 = NULL;
	//struct element *ma_liste3 = NULL;

//	ma_liste1 = header(ma_liste1, 5);
//	ma_liste1 = header(ma_liste1, 6);
//	ma_liste1 = header(ma_liste1, 7);
//	ma_liste1 = header(ma_liste1, 8);
//	ma_liste1 = header(ma_liste1, 9);

	ma_liste1 = tail(ma_liste1, 5);	
	ma_liste1 = tail(ma_liste1, 6);
	ma_liste1 = tail(ma_liste1, 7);
	ma_liste1 = tail(ma_liste1, 8);

	print(ma_liste1);

	return 0; 
}


