#include <stdio.h>
#include <stdlib.h> 

// Creating a Node structure.
typedef struct node{
	int value;
	struct node *next;
}Node;
 
//Function declarations
void print_Node (Node *head);
Node *delete_list(Node *node);
Node *insert_at_tail(Node *head,int new_value);



//Function for inserting new tail node.
Node *insert_at_tail(Node *head,int new_value){
	Node *new_node = calloc(1,sizeof(Node));	
	new_node -> value = new_value;
	
	if (head == NULL) return new_node;
	else{
		Node *current = head;
		while (current -> next != NULL) current = current -> next; 
		current -> next = new_node;
		return head;
	}
}




//Function for deleting whole list
Node *delete_list(Node *head){
	if (head == NULL) return NULL;

	delete_list(head -> next);
	free(head);
}


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
	Node *head = NULL;
	head = insert_at_tail(head, 2);
        head = insert_at_tail(head, 3);
        head = insert_at_tail(head, 4);
        head = insert_at_tail(head, 5);
        head = insert_at_tail(head, 6);
        head = insert_at_tail(head, 7);
        head = insert_at_tail(head, 8);
	
	printf("List before:\n");
	print_Node(head);
	
	delete_list(head);
	printf("List after:\n");
	print_Node(head);
}
