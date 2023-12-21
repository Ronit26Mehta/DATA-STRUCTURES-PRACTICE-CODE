#include<stdio.h>
#define max 10
int topA = -1,topB = max;
int stack[max];
void pushA(int stack[],int val);
void pushB(int stack[],int val);
int popA(int stack[]);
int popB(int stack[]);
int peekA(int stack[]);
int peekB(int stack[]);
void displayA(int stack[]);
void displayB(int stack[]);
void pushA(int stack[],int val){
    if (topA == topB-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        topA++;
        stack[topA] = val;
    }
}
int popA(int stack[])
{
    int val;
    if (topA == -1)
    {
        printf("\nstack underflow");
        return -1;
    }
    else{
        val = stack[topA];
        return val;
    }   
}
int peekA(int stack[]){
    int val;
    if (topA == -1)
    {
        printf("\nStack underflow");
        return -1;
    }
    else{
        val = stack[topA];
        return val;
    }
}
void displayA(int stack[]){
    int i;
    if (topA == -1)
    {
        printf("\nStack underflow");
    }
    else{
        for (i= topA; i > -1; i--)
        {
            printf("\t%d",stack[i]);
        }
    }
}
void pushB(int stack[],int val){
    if (topB-1 == topA)
    {
        printf("\nstack overflow");
    }
    else{
        topB--;
        stack[topB] = val;
    }
}
int peekB(int stack[]){
    if (topB == max)
    {
        printf("\nstack underflow");
        return -1;
    }
    else{
        return stack[topB];
    }
}
int popB(int stack[]){
    int val;
    if (topB == max)
    {
        printf("\nstack underflow");
        return -1;
    }
    else
    {
        val = stack[topB];
        topB++;
    }
}
void displayB(int stack[]){
    int i;
    if (topB == max)
    {
        printf("\nstack is empty");
    }
    else
    {
        for ( i = topB; i < max; i++)
        {
            printf("\t%d",stack[i]);
        }
    }
}