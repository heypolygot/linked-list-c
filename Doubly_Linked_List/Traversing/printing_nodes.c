#include <stdio.h>
#include <stdlib.h>


//structure of Doubly Linked List
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}DNode;



//Function for inserting new node at the end of the list 

