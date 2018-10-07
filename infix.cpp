#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#define size 50

int is_full();
int is_empty();
void push(char a);
char pop();
int is_operand(char ch);
int is_operator(char b);
int pr(char e);


int top=-1;
char stack[size];

main(){
	char infix[size],postfix[size];
	int i=0,j=0;
	char token,b;
	printf("Enter infix Expression:");
	scanf("%s",infix);
	token=infix[i];
	while(token!='\0'){
	if(is_operand(token))
		postfix[j++]=token;
	else if(token=='(')
		push(token);
	else if(token==')'){
		while (stack[top]!='('){
		postfix[j++]=pop();
	}
		
	b=pop();
}
	else if(is_operator(token)){
		if(is_empty()){
			push(token);
		}
		
		while(pr(top)>=pr(token))
		postfix[j++]=pop();
		push(token);
	}
	i++;
	token=infix[i];
}
while (!is_empty()){
postfix[j++]=pop();
}
postfix[j]='\0';

	printf("\n\nInfix Expression:%s",infix);
	printf("\nPostfix Expression:%s",postfix);
	
}
int is_full(){
	if (top==size-1)
		return 1;
		else
		return 0;		
}

int is_empty(){
	if(top==-1)
		return 1;
	else
	return 0;
}

void push(char a){
	if(is_full()){
		printf("Stack Overflow");
	}
	else{
		stack[++top]=a;
	}
}

char pop(){
	if(is_empty())
	printf("Stack is empty");
else{
	return(stack[top--]);
}
}

int is_operand(char ch){
	if(ch>=0 && ch<=9)
		return 1;
	if(ch>='a' && ch <='z')
		return 1;
	
	if(ch>='A' && ch<='Z')
		return 1;
	
	
	else 
		return 0;
}

int is_operator(char b){
	if (b=='+')
	return 1;
	
	if(b=='-')
	return 1;
	
	if(b=='*')
	return 1;
	
	if(b=='/')
	return 1;
	
	if (b=='^')
	return 1;
	else 
	return 0;
}

int pr(char e){
	switch(e){
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	
}	
}


