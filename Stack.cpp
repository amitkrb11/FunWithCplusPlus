#include<iostream>
#include<stdlib.h>
#include<limits.h>

typedef struct Stack{
	int top;
	unsigned int capacity;
	int* arr;
}stack;

//create stack of given capacity
stack *createStack(int c){
	stack* t = (stack*)malloc(sizeof(stack));
	t->capacity = c;
	t->top = -1;
	t->arr = (int*)malloc(t->capacity*sizeof(int));
	return t;
}
bool IsEmpty(stack* s){
	return s->top == -1;
}
bool IsFull(stack* s){
	return s->top == s->capacity-1;
}
//additem and increases top by 1
void push(stack* s, int item){
	if(IsFull(s)) return;
	s->arr[++s->top] = item;
	std::cout << "Pushed " << item << " to stack" << '\n';
}
//remove top item, decrement top by 1 and return 
int pop(stack* s){
	if (IsEmpty(s)) return INT_MIN;
	return s->arr[s->top--];
}
int peek(stack* s){
	if (IsEmpty(s)) return INT_MIN;
	return s->arr[s->top];
}
int main(){
	stack* s = createStack(5);
	push(s, 3);
	push(s, 5);
	push(s, 7); push(s, 9);

	return 0;
}