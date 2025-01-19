#include <stdio.h>
#include <stdlib.h>


//structure of Doubly Linked List
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



//Main Function
void main(){
	DNode *head = NULL;
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);

	printf("List: \n");
	print_list(head);
}
