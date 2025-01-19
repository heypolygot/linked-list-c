#include <stdio.h>
#include <stdlib.h>

//Structure of Linked list.
typedef struct node{
	int value;
	struct node *next;
}Node;


//Function declarations
void print_node(Node *head);
Node *insert_at_tail(Node *head,int new_value);
Node *reverse_list(Node *head);



//Printing Nodes.
void print_node(Node *head){
	Node *current;
	current = head;
	
	int i=0;
	while (current!=NULL){
		printf("Node %d = %d\n",i,current->value);
		i++;
		current = current -> next;
	}
}


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



//Function for Reversing the linked List
Node *reverse_list(Node *head){
	Node *next, *current, *prev;
	prev = NULL;
	current = head;
	
	
	while ( current != NULL ){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	return prev;
}


void main(){
	Node *head = NULL;
	
	head = insert_at_tail(head, 2);
	head = insert_at_tail(head, 4);
        head = insert_at_tail(head, 6);
        head = insert_at_tail(head, 8);
        head = insert_at_tail(head, 10);
        head = insert_at_tail(head, 12);	
		
	printf("List before: \n");
	print_node(head);

	printf("List after: \n");
	head = reverse_list(head);
	print_node(head);
}
