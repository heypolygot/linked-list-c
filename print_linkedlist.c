#include <stdio.h>

// Creating a Node structure.
typedef struct node{
	int value;
	struct node *next;
}Node;
 

//Function for printing a Node.
void print_Node (Node *head){
	Node *current;
	current = head;
	
	int i = 1;
	
	while (current != NULL){
		printf("Node %d = %d\n", i,current->value);
		i++;
		current = current -> next;
	}
}

void main() {
	Node a,b,c;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=NULL;	
	
	print_Node(&a);
}
