#include <stdio.h>
#include <stdlib.h>


//Structure of Doubly Linked List
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;	
}DNode;



//Function for inserting new node at the beginning of the list.
DNode *insert_at_beg(DNode *head){
	DNode *new_node;

	int num;
	printf("Enter value for the new node:");
	scanf("%d",&num);

	new_node = (DNode *)malloc(sizeof(DNode));
	new_node -> data = num;
	
	if (head == NULL){
		new_node -> next = NULL;
		new_node -> prev = NULL;
		head = new_node;
	}else{
		head -> prev = new_node;
		new_node -> next = head;
		new_node -> prev = NULL;
		head = new_node;
	}
	return head;
}



//Main funtion
void main(){
	DNode *head = NULL;
	head = insert_at_beg(head);	
}
