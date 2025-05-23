#include <stdio.h>

//defining the structure of the node
typedef struct node{
	int value;
	struct node *next;
}SNode;


//defining the structure of the list.
typedef struct list{
	SNode *head;
	int len;
}SList;

void main() {
	SList mylist;
	SNode a,b,c;

	mylist.head = &a;
	a.value=5;
	mylist.len++;
	a.next=&b;

	b.value=10;
	mylist.len++;
	b.next=&c;

	c.value=15;
	mylist.len++;
	c.next=NULL;

	printf("%d\n", mylist.len);
	printf("value of 2nd node = %d", mylist.head->next->value);
}
