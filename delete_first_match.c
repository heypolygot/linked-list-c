#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


//Function for First Matching Node.
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted){
	if (head==NULL){
		*was_deleted = false;
		return NULL;
	}
	
	if (head->value == delete_value){
		Node *temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}
		
	Node *current = head->next;
	Node *prev = head;
	
	while (current != NULL){
		if (current -> value == delete_value){
			prev->next = current -> next;
			free(current);
			*was_deleted = true;
			return head;	
		}
		
		prev = current;
		current = current -> next;
	}
	*was_deleted = false;
	return head;
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
	
	printf("List before Deletion\n");
	print_Node(&a);
	
	bool deleted;
	delete_first_match(&a,3,&deleted);
	
	if (deleted){
		printf("List after Deletion:\n");
		print_Node(&a);
	}else{
		printf("value not found:\n");
	}
}
