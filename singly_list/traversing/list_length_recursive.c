#include <stdio.h>

//Node structure.
typedef struct node{
	int value;
	struct node *next;
}Node;

//Recursive funstion to check length of linked list.
int recursive_length(Node *node){
	if (node=NULL){
		return 0;
	}else{
		return 1 + recursive_length(node->next);
	}
}


void main (){
	Node a,b,c;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=NULL;	

	Node *head = &a;
	recursive_length(head);
}
