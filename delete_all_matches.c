#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int value;
	struct node *next;
}Node;


//Function Declarations
Node *insert_at_head(Node *head,int new_value);
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted);
void print_Node (Node *head);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);




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


//Function for Deleting all matches.
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted){
	Node *current = head;
	bool deleted = false;
	*num_deleted = 0;

	do{
		current = delete_first_match(current,delete_value,&deleted);
		if (deleted) *num_deleted = *num_deleted + 1;
	}while(deleted);
	return current;
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


//Function for First Matching Node.
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted){
	if (head==NULL){
		*was_deleted = false;
		return NULL;
	}
	
	if (head->value == delete_value){
		Node *temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}
		
	Node *current = head->next;
	Node *prev = head;
	
	while (current != NULL){
		if (current -> value == delete_value){
			prev->next = current -> next;
			free(current);
			*was_deleted = true;
			return head;	
		}
		
		prev = current;
		current = current -> next;
	}
	*was_deleted = false;
	return head;
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
	head = delete_all_matches(head,num_to_del,&num_deleted);
	
	printf("%d number of %d's are deleted\n",num_deleted,num_to_del);
	printf("List after Deletion:\n");
	print_Node(head);
	
}
