#include <stdio.h>
#include <stdlib.h>


//Structure of Doubly Linked List
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;	
}DNode;




//Function for printing all the nodes of the list in asscending order.
void print_list(DNode *head){
	DNode *current = head;
	
	int i = 1;
	while (current != NULL){
		printf("Value in Node %d is equal to %d\n", i, current -> data);
		i++;
		current = current -> next;
	}
}




//Function for inserting new node at the beginning of the list.
DNode *insert_at_end(DNode *head){
	DNode *new_node, *current = head;

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
		while(current -> next != NULL) current = current -> next;
		current -> next = new_node;
		new_node -> prev = current;
		new_node -> next = NULL;
	}
	return head;
}




//Function for deleting the first node from the list.
DNode *delete_at_beg(DNode *head){
	if (head == NULL) return NULL;
	DNode *current = head;
	head = head -> next;
	head -> prev = NULL;
	free(current);
	return head;
}

//Main funtion
void main(){
	DNode *head = NULL;
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	

	//printing the list
	printf("\n\nList before: \n");
	print_list(head);	

	printf("\n\nList after: \n");
	head = delete_at_beg(head);
	print_list(head);
}
