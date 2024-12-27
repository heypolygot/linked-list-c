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
void delete_duplicates(Node *head);


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


//Function for Deleting Duplicate Nodes.
void delete_duplicates(Node *head){
	if (head == NULL || head -> next == NULL) return;
	
	Node *current1, *current2, *duplicate;
	current1 = head;
	
	while (current1 != NULL && current1 -> next != NULL){
		current2 = current1;
		while (current2 -> next != NULL){
			if (current1 -> value == current2 -> next -> value){
				duplicate = current2 -> next;
				current2 -> next = current2 -> next -> next;
				free(duplicate);
			}else current2 = current2 -> next;
		}
		current1 = current1 -> next;
	}
}



void main(){
	Node *head = NULL;
	
	head = insert_at_tail(head, 2);
	head = insert_at_tail(head, 4);
        head = insert_at_tail(head, 2);
        head = insert_at_tail(head, 8);
        head = insert_at_tail(head, 10);
        head = insert_at_tail(head, 2);	
	
	printf("List before deleting duplicate values:\n");	
	print_node(head);

	delete_duplicates(head);
	printf("\nList after deleting duplicate values: \n");
	print_node(head);
}



















