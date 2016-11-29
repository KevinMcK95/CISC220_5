#include <stdio.h>
#include "udll.h"
#include <stdlib.h>
#include <string.h>

Node* head = NULL;
Node* last = NULL;
Node n4 = malloc(sizeof(Node));
Node n3 = malloc(sizeof(Node));
Node n2 = malloc(sizeof(Node));
Node n1 = malloc(sizeof(Node));

int main(void)
{
	float val = 19.1234, *ptr = &val, val2 = 7.5, *ptr2 = &val2;
	n4.data.f = val; n4.next = NULL; n4.previous = NULL; head = &n4; last = &n4;
	n3.data.f = val2; n3.next = &n4; n3.previous = NULL; head = &n3; n4.previous = &n3;
	n2.data.f = val; n2.next = &n3; n2.previous = NULL; head = &n2; n3.previous = &n2;
	n1.data.i = 4; n1.next = &n2; n1.previous = NULL; head = &n1; n2.previous = &n1;
	float pi=3.14;
	insert(2,pi);
	
	for(Node *i = head; i!=NULL; i=i->next){
		printf("element = %f\n",i->data.f);
	}
	return 0;
}
