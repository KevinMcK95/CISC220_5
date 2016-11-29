#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "udll.h"
/* indexes and lengths/ data in head (overwritting values in insert)
how to pass/ use head and last
special index cases (index within length)
remove is a name taken by stdio.h
*/

Node* makeNewNode(union Data data){
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	new->previous = NULL;
	return new;
}


void insert(int index, union Data data)
{
	int len = length();
	Node* insertNode;
	insertNode = makeNewNode(data);
	if (head == NULL){ //then last should also be NULL
		head = insertNode;
		last = insertNode;
		free(insertNode);
		head.data.i = 1; //length 1 
		return;
	}
	if (index == 0){
		head->previous = insertNode;
		insertNode->next = head;
		head = insertNode;
	}
	else if (index == (len-1)){
		last->next = insertNode;
		insertNode->previous = last;
		last = insertNode;
	}
	else{
		int count;
		if(index <= len/2){
			Node* temp = head;
			count = 0;
			while (count<index-1){
				count++;
				temp = temp->next;
			}
			insertNode->next = temp->next;
			insertNode->previous = temp;
			temp->next = insertNode;
			temp = insertNode->next;
			temp->previous = insertNode;
		}
		else{
			Node* temp = last;
			count = len-1;
			while (count>index){
				count--;
				temp = temp->previous;
			}
			insertNode->previous = temp->previous;
			insertNode->next = temp;
			temp->previous = insertNode;
			temp = insertNode->previous;
			temp->next = insertNode;

		}
	}
	head->data.i = head->data.i+1;
	free(insertNode);
}


void removes(int index)
{
	int len = length();
	if (index == 0){
		head = head->next;
		head->previous = NULL;
	}
	else if (index == (len-1)){
		last = last->previous;
		last->next = NULL;
	}
	else{
		int count;
		if (index <= len/2){
			Node* temp = head;
			count = 0;
			while (count<index-1){
				count++;
				temp = temp->next;
			}
			temp->next = temp->next->next;
			Node* nextTemp = temp->next;
			nextTemp->previous = temp;
		}
		else{
			Node* temp = last;
			count = len-1;
			while (count>index+1){
				count--;
				temp = temp->previous;
			}
			temp->previous = temp->previous->previous;
			Node* prevTemp = temp->previous;
			prevTemp->next = temp;
		}
	}
	head->data.i = head->data.i-1;
}

union Data get(int index)
{
	Node* temp;
	int len = length();
	if(index<0 || index>=len){
		printf("Index is out of range.\n");
		exit(-1);
	}
	else if (index <= len/2){
		temp = head;
		int count = 0;
		while (count < index){
			temp = temp->next;
			count++;
		}
		return temp->data;
	}
	else{
		temp = last;
		int count = len-1;
		while (count > index){
			temp = temp->previous;
			count--;
		}	
		return temp->data;
	}
	printf("ERROR! Something went wrong.\n");
	exit(-1);
}


int length()
{
	return head->data.i;
}
