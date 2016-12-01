#include <stdio.h>
#include "udll.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
	head.data.i = 0; head.next = NULL; head.previous = NULL;
	last.data.i = 0; last.next = NULL; last.previous = NULL;

	float val = 19.1234, *ptr = &val, val2 = 7.5, *ptr2 = &val2;

	Node n4; n4.data.f = val; n4.next = NULL; n4.previous = NULL; last.previous = &n4;
	Node n3; n3.data.f = val2; n3.next = &n4; n3.previous = NULL; n4.previous = &n3;
	Node n2; n2.data.f = val; n2.next = &n3; n2.previous = NULL; n3.previous = &n2;
	Node n1; n1.data.f = val2; n1.next = &n2; n1.previous = NULL; n2.previous = &n1;
	head.next = &n1; head.data.i = 4;
	union Data test; test.f = 3.14;
	union Data test2;
	test2 = get(3);
	removes(3);
	int len=length();
	printf("%d %f\n",len, test2.f);	
	for(Node* i = head.next; i!=NULL; i=i->next){
		printf("element = %f\n",i->data.f);
	}
	return 0;
}
