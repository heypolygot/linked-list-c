#include <stdio.h>
#include <stdlib.h>

//Structure of Linked list.
typedef struct node{
	int value;
	struct node *next;
}Node;

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


//Function for inserting new node at the starting of the list.
Node *insert_at_head(Node *head,int new_value){
	Node *newnode = calloc(1,sizeof(Node));	
	newnode -> value = new_value;
	
	if (head == NULL) return newnode;
	else{
		newnode -> next = head;
		return newnode;
	}
}

void main(){
	Node *list1_head = NULL;
	
	list1_head = insert_at_head(list1_head, 2);
	
	print_node(list1_head);
}
