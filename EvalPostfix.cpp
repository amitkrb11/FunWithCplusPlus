//#include<cstdio>
//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//typedef struct stack{
//	int top;
//	int capacity;
//	int* arr;
//}stack;
//stack* createStack(int d){
//	stack* t = (stack*)malloc(sizeof(stack));
//	t->top = -1;
//	t->capacity = d;
//	t->arr = (int*)malloc(t->capacity * sizeof(int));
//	return t;
//}
//int IsEmpty(stack* s){
//	return s->top == -1;
//}
//int IsFull(stack* s){
//	return s->top == s->capacity - 1;
//}
//void push(stack* s, int d){
//	if (!IsFull(s))
//		s->arr[++s->top] = d;
//	return;
//}
//int pop(stack* s){
//	if (!IsEmpty(s))
//		return s->arr[s->top--];
//
//	return 0;
//}
//int peek(stack* s){
//	return s->arr[s->top];
//}
//int IsOperand(char c){
//	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//		return 1;
//	return 0;
//}
//int Prec(char c){
//	switch (c){
//
//	case '+':
//	case '-':
//		return 1;
//
//	case '*':
//	case '%':
//		return 2;
//
//	case '^':
//		return 3;
//
//	}
//	return -1;
//}
//int PretoPostFix(char* str){
//	int i, k;
//	 stack* stack = createStack(strlen(str));
//
//	 // loop through all characters
//	 for (i = 0, k = -1; str[i]; i++){
//
//		 // we got operand
//		 if (IsOperand(str[i]))
//			 str[++k] = str[i];
//
//		 // when '(' is encountered push it on stack
//		 else if (str[i] == '(')
//				 push(stack, str[i]);
//
//		 //when ')' is encountered check whether top is its counterpart, 
//		 //if not traverse through stack and pop all element to str[]
//		 else if (str[i] == ')')
//		 {
//					 while (!IsEmpty(stack) && peek(stack) != '(')
//						 str[++k] = pop(stack);
//					 if (!IsEmpty(stack) && peek(stack) != '(')
//						 return -1;
//					 else
//						 pop(stack);
//		 }
//		 else{
//			 // now here we got an operator
//			 if (Prec(str[i]) >= Prec(peek(stack))){
//				 push(stack, str[i]);
//			 }
//			 else{
//				 //pop elements from stack until str char is <= stack element
//				 while (!IsEmpty(stack) && Prec(str[i]) <= Prec(str[i]))
//					 str[++k] = pop(stack);
//			 }
//		 }
//	 }
//
//	 while (!IsEmpty(stack))
//		 str[++k] = pop(stack);
//
//	 str[++k] = '\0';
//
//	 cout << str << '\n';
//	 return 0;
//}
//
//int EvalPostFix(char* str){
//
//	stack* stack = createStack(strlen(str));
//
//	if (!stack) return -1;
//
//	for(int i = 0; str[i]; i++){
//
//		//if number push to stack
//		if (isdigit(str[i]))
//			push(stack, str[i]);
//
//		else{
//			int s1 = pop(stack);
//			int s2 = pop(stack);
//
//			switch (str[i]){
//			case '+': push(stack, s2 + s1); break;
//			case '-': push(stack, s2 - s1); break;
//			case '*': push(stack, s2 * s1); break;
//			case '%': push(stack, s2 % s1); break;
//			}
//		}
//	}
//	cout << pop(stack) << endl;
//	return 0;
//}
//int main(){
//	char str[] = "1+2*(3^4-8)^(7+6*5)-10";
//	cout << str << '\n';
//	PretoPostFix(str);
//	EvalPostFix(str);
//	return 0;
//}