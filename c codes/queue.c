#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int value[10], 
 front = -1, 
  rear = -1, 
   MAX = 10; 
int i;

void queue(int num) {
	if (front == -1 && rear == -1) {
		front = 0; rear = 0;
		
	}
	
	if(rear == MAX) {
		printf("OVERFLOW!\n\n");
		
	}
	
	else {
		value[rear] = num; 
		rear++; 
	}
	
}

void dequeue() {
	value[front] = 0;
	front++;
	
}

void print() {
	for(i = 0; i < MAX; i++) {
		printf("%d ", value[i]);
		
	}
}

int main(int argc, char *argv[]) {
	queue(1);
	queue(2);
	queue(3);
	queue(4);
	queue(5);
	queue(6);
	queue(7);
	queue(8);
	queue(9);
	queue(10);

	print();
	return 0;
}
