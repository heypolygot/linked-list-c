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




//Function for Deleting the first node.
CNode *delete_at_beg(CNode *head){
	if (head == NULL) return NULL;
 
	CNode *current;
	current = head;
	
	while (current -> next != head) current = current -> next;
	current -> next = head -> next;
	free(head);
	head = current -> next;		
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
	head = delete_at_beg(head);
	print_node(head);
}
