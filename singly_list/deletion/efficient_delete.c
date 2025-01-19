#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Node Structure
typedef struct node{
	int value;
	struct node *next;
}Node;


//Function Declarations
Node *insert_at_head(Node *head,int new_value);
void print_Node (Node *head);
Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted);


//Function for inserting new node at the starting of the list.
Node *insert_at_head(Node *head,int new_value){
	Node *newnode = calloc(1,sizeof(Node));	
	newnode -> value = new_value;
	
	if (head == NULL) return newnode;
	else{
		newnode -> next = head;
		return newnode;
	}
}




//Function for printing a Node.
void print_Node (Node *head){
	Node *current;
	current = head;
	
	int i = 1;
	
	while (current != NULL){
		printf("Node %d = %d\n", i,current->value);
		i++;
		current = current -> next;
	}
}



//Function for efficiently Deleting all matching Nodes.
Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted){
	*num_deleted = 0;
	if (head ==  NULL)  return NULL;

	Node *current, *temp, *new_head;
	current = head;
	
	while (current -> value == delete_value){

		temp = current;
		current = current -> next;

		free(temp);
		*num_deleted += 1;
		if (current == NULL) return NULL;
	}

	new_head = current;

	while (current -> next != NULL){
		
		if (current -> next -> value == delete_value){
			temp = current -> next;
			current -> next = current -> next -> next;
			free(temp);
			*num_deleted += 1;
		}
		else current = current -> next;	
	}
	return new_head;
}




void main() {
	Node *head = NULL;

	head = insert_at_head(head, 7);	
        head = insert_at_head(head, 5);
        head = insert_at_head(head, 3);
        head = insert_at_head(head, 6);
        head = insert_at_head(head, 1);
        head = insert_at_head(head, 3);
        head = insert_at_head(head, 2);
        head = insert_at_head(head, 8);

	int num_to_del;
	printf("enter number to delete:");
	scanf("%d",&num_to_del);

	printf("List before Deletion\n");
	print_Node(head);
	
	int num_deleted;
	head = efficient_delete_matches(head,num_to_del,&num_deleted);
	
	printf("%d number of %d's are deleted\n",num_deleted,num_to_del);
	printf("List after Deletion:\n");
	print_Node(head);
	
}
