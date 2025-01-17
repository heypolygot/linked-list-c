#include <stdio.h>
#include <stdlib.h>

//Function Declarations




//Structure of the Circular Linked List [Its actually same as Singly ll]
typedef struct node{
	int data;
	struct node *next;
}CNode;


//Creating Circular linked list
CNode *create_cll(CNode *head){

	CNode *new_node, *ptr;
	int num;
	
	//Taking new node data from the user	
	printf("\nEnter the data:");
	scanf("%d",&num);

	//allocating memory for the new node 
	new_node = (CNode *)malloc(sizeof(CNode));
	new_node -> data = num;

	if (head == NULL){
		new_node -> next = new_node;
		head = new_node;
	}else{
		ptr = head;
		while (ptr  -> next != NULL)ptr = ptr -> next;
		ptr -> next =  new_node;
		new_node -> next = head;
	}

	return head;
	free(new_node);
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









void main() {
	CNode *head = NULL;
	head = insert_at_end(head);
	head = insert_at_end(head);
	head = insert_at_end(head);
}
