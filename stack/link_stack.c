#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack*,int val);
struct stack *pop(struct stack*);
int peek(struct stack*);
struct stack *display(struct stack*);
void main(){
    int val,choice;
    do
    {
        printf("\n1.push\n2.pop\n3.peek\n4.display");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value:");
            scanf("%d",&val);
            top = push(top,val);
            break;
        case 2:
            top = pop(top);
        break;
        case 3:
            val = peek(top);
            if (val != -1)
            {
                printf("\nData at the top is:%d",val);
            }
            else
            {
               printf("\nUnderflow");   
            }
            break;
        case 4:
             top = display(top);
             break;
        case 5:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice!=5);
}

struct stack *push(struct stack *top,int val){
    struct stack *nn;
    nn = (struct stack*)malloc(sizeof(struct stack));
    nn->data = val;
    if (top == NULL)
    {
        nn->next = NULL;
        top = nn;
    }
    else
    {
        nn->next = top;
        top  = nn;
    }
    return top;
}
struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (ptr == NULL)
    {
        printf("\nEmpty stack..");
    }
    else
    {
        top = top->next;
        printf("\n%d is poped out",ptr->data);
        free(ptr);
    }
    return top;
}
struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("\nEmpty Stack...");
    }
    else
    {
        while (ptr!=NULL)
        {
            printf("%d->\t",ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}
int peek(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (ptr == NULL)
    {
        return -1;
    }
    else
    {
        return ptr->data;
    }
}