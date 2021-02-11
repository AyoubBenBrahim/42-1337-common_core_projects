#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char data;
	struct Node *next;
} t_node;

t_node *head;

void insert(char x)
{
	t_node *temp = (t_node*)malloc(sizeof(t_node));
	temp->data = x;
	//temp->next = NULL; //if the list is empty
	temp->next = head;
	head = temp;
}

void print()
{
	t_node *temp = head;// to not loose the header address
	printf("List is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int i;
	//int j;
	char tab[] = {'1','2','3','4','5','6','\0'};

	head = NULL;
	for (i = 1; i < (int)strlen(tab); i++)
	{
		insert(tab[i]);
	}
	print();
}
