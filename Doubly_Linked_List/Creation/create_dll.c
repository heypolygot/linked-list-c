#include <stdio.h>
#include <stdlib.h>


//Structure of a Doubly Linked List
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}DNode;
 


//Function declarations
DNode  *create_dll(DNode *head);




//Function for creating a Doubly Linked List.
DNode  *create_dll(DNode *head){
	DNode *new_node, *current;
	
	int num;
	printf("Enter the value:");
	scanf("%d",&num);
	
	new_node = (DNode *)malloc(sizeof(DNode));
	new_node -> data = num;
	
	if (head == NULL){
		new_node -> next = new_node;
		new_node -> prev = new_node;
		head = new_node;
	}else{
		current = head;
		while(current -> next != NULL) 	current = current -> next;
		current -> next = new_node;
		new_node -> prev = current;
		new_node -> next = NULL;
	}
	return head;
}




//Main function
void main(){
	DNode *head = NULL;
	head = create_dll(head);	

}
