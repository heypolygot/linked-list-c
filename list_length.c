#include <stdio.h>

// Creating a Node structure.
typedef struct node{
	int value;
	struct node *next;
}Node;
 

//Function to print the lenght of linked list.
int length(Node *head){
	Node *current;
	current = head;
	int len=0;
	while (current != NULL){
		len++;
		current = current -> next;
	}
	return len;
}

void main() {
	Node a,b,c;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=NULL;	
	
	printf("Linked List's Length is %d\n",length(&a));	

}


