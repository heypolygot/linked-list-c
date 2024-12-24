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

//Function for deleting the head of linked list.
Node *delete_head(Node *head){
	if (head == NULL) return NULL;
	else{
		Node *to_return = head -> next;
		free(head);
		return to_return;
	}
}

void main(){
	Node *list1_head = NULL;
	
	list1_head = insert_at_head(list1_head, 2);
	
	print_node(list1_head);
}
