/*    AIM: To implement Producer-Consumer-Problem using shared memory  */
____________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#define size 10
int buffer[size], top=-1, data; 
int producer(){
	if (top==size)
		printf("Buffer is full!\n");
	else{
		printf("Enter the data: ");
		scanf("%d", &data);
		top++;
		buffer[top]=data;
}}
int consumer(){
	if (top==-1)
		printf("Buffer is empty!\n");
	else{
		printf("%d consumed\n",buffer[top]);
		top--;
}}
void display(){
	for(int i=top; i>=0; i--)
		printf("%d  ",buffer[i]);
	printf("\n");
}
void main(){
	int op;
	#pragma omp critical
	while(1){
		printf("1. Producer   2.Consumer   3.Display   4.Exit \nEnter the choice: ");
		scanf("%d", &op);
		switch(op){
			case 1: producer(); break;
			case 2: consumer(); break;
			case 3:	display(); break;
			case 4:	exit(0);
			default: printf("Invalid choice\n"); break;
}}}
