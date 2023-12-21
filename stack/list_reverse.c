#include<stdio.h>
#define max 10
int stack[max];
int top = -1;
int pop(int stack[]);
void push(int stack[],int val);
void main(){
    int val,i,n;
    int list[max];
    printf("\nEnter the lenght of list:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list[i]);
    }
    printf("\nthe list before reversal:");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d",list[i]);
    }
    for (int i = 0; i < n; i++)
    {
        push(stack,list[i]);
    }
    for (int i = 0; i < n; i++)
    {
        val = pop(stack);
        list[i] = val;
    }
    printf("\nlist after reversal:");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d",list[i]);
    }
}
void push(int stack[],int val){
    if (top == max - 1)
    {
        printf("\nstack is full");
    }
    else{
        stack[top] = val;
        top ++;
    }
}
int pop(int stack[]){
    if (top == -1)
    {
        printf("\nstack underflow");
        return -1;
    }
    else{
        return (stack[top--]);
    }
}