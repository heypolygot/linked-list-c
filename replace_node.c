#include <stdio.h>

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


//Function for replacing Node value.
void replace_matches(Node *node, int find_value, int replace_value){
	if (node != NULL){
		if (node -> value == find_value){
			node -> value = replace_value;
		}
		replace_matches(node->next,find_value,replace_value);		
	}
}


void main() {
	Node a,b,c,d,e,f,g,h;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=&d;	
	
        d.value=3;
        d.next=&e;

        e.value=21;
        e.next=&f;

        f.value=13;
        f.next=&g;

        g.value=3;
        g.next=&h;

	h.value=3;
        h.next=NULL;
	
	printf("List before Replacement:\n");
	print_Node(&a);

	replace_matches(&a,3,7);
	printf("List after Replacement:\n");
	print_Node(&a);
}
