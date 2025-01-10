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



//Function for inserting new nodes between 2 nodes.
Node *insert_after(Node *head, int new_value, int after_value){
	Node *new_node = calloc(1, sizeof(Node));
	new_node -> value = new_value;
	
	if (head == NULL) return new_node;
	else{
		Node *current = head;
		while (current -> next != NULL){
			if (current -> value == after_value){
				new_node -> next = current -> next;
				current -> next = new_node;
				return head;
			}else current = current -> next;
		}
		new_node -> next = current -> next;
		current -> next = new_node;
		return head;
	}

}


void main(){
	Node *head = NULL;
	
	head = insert_at_tail(head, 2);
	head = insert_at_tail(head, 4);
        head = insert_at_tail(head, 6);
        head = insert_at_tail(head, 8);
        head = insert_at_tail(head, 10);
        head = insert_at_tail(head, 12);	
		
	printf("List before insertion:");
	print_node(head);
	
	printf("List after insertion:");
	insert_after(head, 20, 6);
	print_node(head);
}
