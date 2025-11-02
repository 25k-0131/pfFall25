#include <stdio.h>
void push(int stack[], int* top, int maxSize);
void pop(int stack[], int* top);
void peek(int stack[], int top);
void display(int stack[], int top);


int main (void)
{
	int top=-1, n, capacity = 5;
	int stack[capacity];
	
	do{
		
	
        printf("\n===== STACK MENU =====\n");

		printf("1. PUSH: Insert an element into the stack\n2. POP: Remove the top element from the stack\n3. PEEK: Display the top element without removing it\n4. DISPLAY: Show all elements currently in the stack\n5. EXIT: Terminate the program\n");
		printf("Select any one: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				push(stack, &top, capacity);
				break;
			case 2:
				pop(stack, &top);
				break;
			case 3:
				peek(stack, top);
				break;
			case 4:
				display(stack,top);
				break;
			case 5:
				printf("Exiting...");
				break;
			default:
				printf("Enter correct number: \n");
				break;
		}
    }while(n!=5);
    
    return 0;
}

void push(int stack[], int* top, int maxSize)
{
	int p;
	if (*top == maxSize - 1)
	{
		printf("Stack is full");
		return;
	}
	printf("Enter number to push: ");
	scanf("%d", &p);
	(*top)++;
	stack[*top] = p;
	printf("%d pushed into stack.\n", p);
	return;
}

void pop(int stack[], int* top)
{
	if (*top == -1)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("%d popped from stack.\n", stack[*top]);
	(*top)--;
	return; 
}
void peek(int stack[], int top)
{
	if (top == -1)
	{
		printf("Stack is empty\n");
		return;
	}
	else{
		
		printf("Top element is: %d\n", stack[top]);
		return;
	}
	
}
void display(int stack[], int top)
{
	int i;
	
	if (top == -1)
	{
		printf("Stack is empty\n");
		return;
	}
	else{
		for(i = top; i>=0; i--)
		{
		printf("%d ", stack[i]);
        printf("\n");
		
		}
	return;
	}
	
}
