/*
LinkedList
Struct Node
Head --> global variable
void insert(int x, int pos) --> x at position pos
void add() --> add at the end of the list
void reverse1() --> iterative 
void reverse2(Node* p) --> recursion, argument must be head
void print() --> print the list
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node* next;
};

//global pointer points at head node
Node* headptr;

//insert function, you have to be carefull because the linklist might have something already
void insert(int x, int pos){
	//creating node at memory in the heap
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = NULL;

	//if inset at the first position
	if(pos == 1){
		temp -> next = headptr;
		//why?
		//temp = head; //update temp
		headptr = temp; //update head
		return;
	}

	//start from head iterative to the n-1 position of the inset node
	Node* temp2 = headptr;
	//becasue you start at 1
	for(int i = 0; i<pos-2; i++){
		temp2 = temp2 -> next;
	}

	temp -> next = temp2 -> next;
	//update temp2s
	temp2 -> next = temp;
}
//add at the end of the linked list
void add(int x){
	Node* p = headptr;
	Node* newNode = new Node(); //creating a node, in heap
	while(p->next != NULL){
		p = p -> next;
	}

	p->next = newNode;
	newNode -> data = x;
	newNode -> next = NULL;
}

//iterative style
void reverse1(){
	Node *prev, *current, *next;
	current = headptr;
	prev = NULL;

	//the current pointer contain elements
	while(current!=NULL){
		//iterator
		next = current -> next;
		//change the link arrow direction
		current -> next = prev;

		prev = current;;
		current = next;
	}
	headptr = prev;
}
//recursion stype, traversal to the end, passing argument
void reverse2(Node* p){
	if(p->next == NULL){
		headptr = p;
		return;
	}
	reverse2(p->next);	

	Node* q = p-> next;
	q->next = p;
	p->next = NULL;
}

//print the list
void print(){
	Node* temp = headptr;

	printf("List is: " );
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//delete at x position
void del(int x){
	Node* p = headptr;
	if(x == 1){
		headptr = p->next;
		p->data = NULL;
		p->next = NULL;
		return;
	}

	for(int i=0; i<x-2; i++){
		p=p->next;
	}

	Node* q = p->next; 
	p->next = p->next->next;
	q->data = NULL;
	q->next = NULL;
	
}



int main(){
	headptr = NULL;
	insert(3,1);
	insert(4,2);
	add(5);
	insert(6,2);
	insert(7,1);
	add(8);

	print();

	reverse1();
	print();
	reverse1();
	print();
	reverse2(headptr);
	print();
	del(3);
	print();
}





