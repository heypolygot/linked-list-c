#include <stdio.h>
#include <stdlib.h>


//Structure of the Circular Linked List [Its actually same as Singly ll]
typedef struct node{
	int data;
	struct node *next;
}CNode;



//Function Declarations
void print_node(CNode *head);
CNode *insert_at_beg(CNode *head);
CNode *delete_at_end(CNode *head);


//Function for printing the node data in order.
void print_node(CNode *head){
	CNode *current;
	current = head;

	int i = 1;

	do{
		printf("Node no. %d is Equal to %d\n", i, current -> data);
		i++;
		current = current -> next;
	}while (current != head);
}




//Function for inserting a node at the end.
CNode *insert_at_end(CNode *head){
	CNode *new_node, *ptr;
	int num;
	printf("Enter the Data:");
	scanf("%d",&num);
	
	new_node = (CNode *)malloc(sizeof(CNode));
	new_node -> data = num;

	if (head == NULL){
		new_node -> next = new_node;
		head = new_node;
	}else{
		ptr = head;
		while(ptr -> next != head) ptr = ptr -> next;
		ptr -> next = new_node;
		new_node ->  next = head;
		return head;
	}
}



//Function for deleting a node after a given node from the list.
CNode *delete_after(CNode *head){
	CNode *current = head, *prev = current;

	int num;
	printf("Enter the value after which the node hass to be deleted:");
	scanf("%d",&num);

	while (prev -> data != num){
		prev = current;
		current =  current -> next;
	}
	prev -> next = current -> next;
	if (current == head) head = prev -> next; 
	free(current);
	return head;
}


void main() {
	CNode *head = NULL;
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
	
	printf("List before:\n");
	print_node(head);
	printf("List after:\n");
	head = delete_after(head);
	print_node(head);
}
