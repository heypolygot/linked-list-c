#include <stdio.h>

typedef struct node{
	int value;
	struct node *next;
}Node;

void main() {
	Node a,b,c;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=NULL;	
}
