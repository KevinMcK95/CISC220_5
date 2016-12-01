#include <stdio.h>
#include "udll.h"
#include <stdlib.h>
#include <string.h>

void printer(union Data inData, int type){
	if (type == 0){
		printf("%d\n",inData.i);
	}
	else if (type == 1){
		printf("%d\n",*(inData.iP));
	}
	else if (type == 2){
		printf("%f\n",inData.f);
	}
	else if (type == 3){
		printf("%f\n",*(inData.fP));
	}
	else if (type == 4){
		printf("%c\n",inData.c);
	}
	else if (type == 5){
		printf("%c\n",*(inData.cP));
	}
	else{
		printf("Not a valid type.\n");
	}
	return;
}

int main(void)
{
	head.data.i = 0; head.type = 0, head.next = NULL; head.previous = NULL;
	last.data.i = 0; last.type = 0; last.next = NULL; last.previous = NULL;
	
	//TYPES: int=0, intPtr=1, float=2, floatPtr=3, char=4, charPtr=5

	float val = 19.1234, *ptr = &val;
	char c = 'K', *cPtr = &c;
	int i = 42, *iPtr = &i;

	Node n4; n4.data.fP = ptr; n4.type = 3; n4.next = NULL; n4.previous = NULL; last.previous = &n4;
	Node n3; n3.data.f = val; n3.type = 2; n3.next = &n4; n3.previous = NULL; n4.previous = &n3;
	Node n2; n2.data.c = c; n2.type = 4; n2.next = &n3; n2.previous = NULL; n3.previous = &n2;
	Node n1; n1.data.cP = cPtr; n1.type = 5; n1.next = &n2; n1.previous = NULL; n2.previous = &n1;
	Node n0; n0.data.i = i; n0.type = 0; n0.next = &n1; n0.previous = NULL; n1.previous = &n0;
	Node n_1; n_1.data.iP = iPtr; n_1.type = 1; n_1.next = &n0; n_1.previous = NULL; n0.previous = &n_1;
	head.next = &n_1; head.data.i = 6;
	union Data test; test.c = 'm';
	union Data test2;
	
	test2 = get(0);
	int len=length();
	printf("Length = %d, Integer Pointer storing: %d\n\n",len, *test2.iP);	
	int count = 0;
	for(Node* i = head.next; i !=NULL ; i=i->next){ //print list forwards
		printf("element %d = ",count);
		printer(i->data,i->type);
		count++;
	}
	printf("\n");
	removeNode(4);
	len = length();
	count = len-1;

	for(Node* i = last.previous; i !=NULL ; i=i->previous){ //print new list backwards
		printf("element %d = ",count);
		printer(i->data,i->type);
		count--;
	}
	printf("\n");
	insert(3,test,4);
	count = 0;
	for(Node* i = head.next; i !=NULL ; i=i->next){ //print new list forwards
		printf("element %d = ",count);
		printer(i->data,i->type);
		count++;
	}

	return 0;
}
