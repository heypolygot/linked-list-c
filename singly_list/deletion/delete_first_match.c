#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int value;
	struct node *next;
}Node;

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

	int del_num;
	printf("Enter a number to delete:");
	scanf("%d",&del_num);

	printf("List before Deletion\n");
	print_Node(head);
	
	bool deleted;
	head = delete_first_match(head,del_num,&deleted);
	
	if (deleted){
		printf("List after Deletion:\n");
		print_Node(head);
	}else{
		printf("value not found:\n");
	}
}
