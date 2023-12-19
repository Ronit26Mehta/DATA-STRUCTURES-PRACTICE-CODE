#include<stdio.h>
#define max 10
int queue[max];
int frontA = -1,rearA = -1,frontB = max,rearB=max;
void pushA(int val);
void pushB(int val);
int deleteA();
int deleteB();
int peekA();
int peekB();
void displayA();
void displayB();
void pushA(int val){
    if (rearA == rearB -1)
    {
        printf("\nOverflow");
    }
    else if (frontA== -1  &&  rearA == -1)
    {
        frontA = rearA = 0;
        queue[rearA] = val;
    }
    else
    {
        rearA++;
        queue[rearA] = val;
    }
}
int deleteA(){
    int val;
    if (frontA == -1)
    {
        return -1;
    }
    else if (frontA == rearA)
    {
        val = queue[rearA];
        frontA = rearA = -1;
        return val;
    }
    else
    {
        val = queue[rearA];
        frontA--;
        return val;
    }    
}
int peekA(){
    int val;
    if (frontA == -1)
    {
        val = -1;
    }
    else
    {
        val = queue[frontA];
    }
    return val;
}
void displayA(){
if (frontA == -1)
{
    printf("\nEmpty or underflow");
}
else
{
    for (int i = frontA; i <= rearA; i++)
    {
        printf("%d\t",queue[i]);
    }
}
}
void pushB(int val){
    if (frontA == frontB -1)
    {
        printf("\noverflow");
    }
    else if (frontB == max   && rearB == max)
    {
        rearB = frontB = max -1;
        queue[rearB] = val;
    }
    else
    {
        rearB--;
        queue[rearB] = val;
    }
}
int peekB(){
    if (frontB == -1)
    {
        printf("\nunderflow");
    }
    else
    {
        return queue[frontB];
    }
}
int deleteB(){
    int val;
    if (frontB == -1)
    {
        printf("\nUnderflow");
        return -1;
    }
    else if (frontB == rearB)
    {
        val = queue[frontB];
        frontB = rearB = max;
        return val;
    }
    else
    {
        val = queue[frontB];
        frontB++;
        return val;
    }
}
void displayB(){
    if (frontB == -1)
    {
        printf("\n underflow or empty");
    }
    else
    {
        for (int i = frontB; i >= rearB; i--)
        {
            printf("%d\t",queue[i]);
        }
    }
}