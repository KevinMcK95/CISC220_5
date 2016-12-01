#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "udll.h"
/* indexes and lengths/ data in head (overwritting values in insert)
how to pass/ use head and last
special index cases (index within length)
remove is a name taken by stdio.h
printing a union for testing
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
	if (head.next == NULL){ //then last should also be NULL
		head.next = insertNode;
		last.previous = insertNode;
		free(insertNode);
		head.data.i = 1; //length 1 
		return;
	}
	if (index == 0){
		Node* temp = head.next;
		temp->previous = insertNode;
		insertNode->next = temp;
		head.next = insertNode;
	}
	else if (index == (len-1)){
		Node* temp = last.previous;
		temp->next = insertNode;
		insertNode->previous = temp;
		last.previous = insertNode;
	}
	else{
		int count;
		if(index <= len/2){
			Node* temp = head.next;
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
			Node* temp = last.previous;
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
	head.data.i = head.data.i+1;
	free(insertNode);
}


void removes(int index)
{
	int len = length();
	if (index == 0){
		Node* temp = head.next;
		head.next = temp->next;
		head.previous = NULL;
	}
	else if (index == (len-1)){
		Node* temp = last.previous;
		temp = temp->previous;
		last.previous = temp;
		temp->next = NULL;
		last.next = NULL;
	}
	else{
		int count;
		if (index <= len/2){
			Node* temp = head.next;
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
			Node* temp = last.previous;
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
	head.data.i = head.data.i-1;
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
		temp = head.next;
		int count = 0;
		while (count < index){
			temp = temp->next;
			count++;
		}
		return temp->data;
	}
	else{
		temp = last.previous;
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
	return head.data.i;
}
