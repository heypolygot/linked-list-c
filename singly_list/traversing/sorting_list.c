#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Structure of Linked list.
typedef struct node{
	int value;
	struct node *next;
}Node;


//Function declarations
void print_node(Node *head);
Node *insert_at_tail(Node *head,int new_value);
void sort_list (Node *head);



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



void sort_list (Node *head){
	if (head == NULL || head -> next == NULL) return;
	
	bool swapped = false;
	
	do{
		swapped = false;	
		Node *current = head;
		Node *prev = NULL;

		while (current -> next != NULL){
			prev = current;
			current = current -> next;
			
			if (current != NULL){
				if (current -> value < prev -> value){
					int temp;
					temp = prev -> value;
					prev -> value = current -> value;
					current -> value = temp;
					swapped = true;
				}	
			}
		}
	}while (swapped);
}


void main(){
	Node *head = NULL;
	
	head = insert_at_tail(head, 2);
	head = insert_at_tail(head, 10);
        head = insert_at_tail(head, 1);
        head = insert_at_tail(head, 8);
        head = insert_at_tail(head, 0);
        head = insert_at_tail(head, 3);	
	
	printf("List before sorting:-\n");
	print_node(head);
	printf("\nList after sorting\n");
	sort_list(head);
	print_node(head);
}
