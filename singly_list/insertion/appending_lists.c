#include <stdio.h>
#include <stdlib.h>




//Structure of Linked list.
typedef struct node{
	int value;
	struct node *next;
}Node;

//Function declarations	
Node *append_list(Node *head1, Node *head2);
void print_node(Node *head);
Node *insert_at_tail(Node *head,int new_value);






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


//Function for inserting new tail node.
Node *insert_at_tail(Node *head,int new_value){
	Node *new_node = calloc(1,sizeof(Node));	
	new_node -> value = new_value;
	
	if (head == NULL) return new_node;
	else{
		Node *current = head;
		while (current -> next != NULL) current = current -> next; 
		current -> next = new_node;
		return head;
	}
}


Node *append_list(Node *head1, Node *head2){
	if (head1 == NULL) return head2;
	Node *current = head1;

	while (current -> next != NULL) current = current -> next;
	current -> next = head2;
	return head1;
}


void main(){
	Node *head1 = NULL, *head2 = NULL;
	
	for (int i = 1; i<=3;i++){
		head1 = insert_at_tail(head1,i);
	}
	for (int i = 4; i<=10;i++){
		head2 = insert_at_tail(head2,i);
	}	
	
	printf("List 1 :-\n");
	print_node(head1);
	printf("\n\nList 2 :-\n");
	print_node(head2);
	
	head1 = append_list(head1, head2);	

	printf("\n\nList after appending list 2 into list 1 :- \n");
	print_node(head1);

}
