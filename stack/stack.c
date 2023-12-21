#include<stdio.h>
#define max 10
int stack[max];
int top = -1;
void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);
 void main(){
    int choice,val;
    do
    {
        printf("\nStack Simulation\n");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peek");
        printf("\n4.display");
        printf("\n5.exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&val);
            push(stack,val);
            break;
        case 2:
            val = pop(stack);
            if (val == -1)
            {
                printf("\nunderflow");
            }
            else{
                printf("\nvalue poped=%d",val);
            }
            break;
        case 3:
            val = peek(stack);
            if (val == -1)
            {
                printf("\nunderflow");
            }
            else{
                printf("\nthe value is%d",val);
            }
            break;
        case 4:
            display(stack);
            break;
        case 5: 
            printf("\nexiting...");
            break;
        default:
             printf("\ninvalid choice");
            break;
        }
    } while (choice!=5);
    
 }
 void push(int stack[],int val){
    if (top == max -1 )
    {
        printf("\noveflow condition");
    }
    else
    {
        top++;
        stack[top] = val;
    }
 }
 int pop(int stack[]){
    int val;
    if (top == -1)
    {
        printf("\nunderflow condtion");
        return -1;
    }
    else{
        val = stack[top];
        top--;
        return val;
    }
 }
 int peek(int stack[]){
    int val;
    if (top == -1)
    {
        printf("\nstack is empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
 }
 void display(int stack[]){
    if (top == -1)
    {
        printf("\nstack is empty");
    }
    else{
        for (int i = top; i >= 0; i--)
        {
            printf("%d\t",stack[i]);
        }
    }
 }