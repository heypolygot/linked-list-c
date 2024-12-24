#include <stdio.h>
#include <stdbool.h>
// Creating a Node structure.
typedef struct node{
	int value;
	struct node *next;
}Node;
 
//Function for searching an element in a linked list.
bool is_member(Node *node, int find_value){
	if (node == NULL) return false;
	else if (node->value == find_value) return true;
	else return is_member(node->next,find_value);
}


void main() {
	Node a,b,c;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=NULL;	
	
	if (is_member(&a,10)) printf("No. is present\n");
	else printf("No. isn't present\n");
}
