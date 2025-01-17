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

void main() {
	CNode *head = create_cll(head);
}
