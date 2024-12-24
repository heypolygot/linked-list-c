#include <stdio.h>

typedef struct node{
	int value;
	struct node *next;
}Node;


//Function for Counting Matches.
int count_matches(Node *node,int count_value){
	if (node == NULL) return 0;
	else if (node -> value == count_value) return 1 + count_matches(node->next,count_value);
	else return count_matches(node->next,count_value);
}


void main() {
	Node a,b,c,d,e,f,g,h;

	a.value=5;
	a.next=&b;

	b.value=10;
	b.next=&c;

	c.value=15;
	c.next=&d;	
	
        d.value=3;
        d.next=&e;

        e.value=21;
        e.next=&f;

        f.value=13;
        f.next=&g;

        g.value=3;
        g.next=&h;

        h.value=3;
        h.next=NULL;

	printf("Total count = %d\n",count_matches(&a,3));
}
