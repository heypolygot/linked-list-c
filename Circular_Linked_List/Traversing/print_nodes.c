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



//Function for inserting a node at beginning.
CNode *insert_at_beg(CNode *head){
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
		head = new_node;
		return head;
	}
}


void main() {
	CNode *head = NULL;
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	head = insert_at_beg(head);
	
	print_node(head);
}
