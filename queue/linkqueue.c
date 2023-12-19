#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct queue{
    struct node *front;
    struct node *rear;
};
struct queue *q;
void create_queue(struct queue *q);
struct queue *insert(struct queue *q,int);
struct queue *delete(struct queue *q);
int peek(struct queue *q);
struct queue *display(struct queue *q);
void main(){
    int val,choice;
    q = (struct queue*)malloc(sizeof(struct queue));
    create_queue(q);
    do
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.peek");
        printf("\n4.display");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter val:");
            scanf("%d",&val);
            q = insert(q,val);
            break;
        case 2:
             q = delete(q);
             break;
        case 3:
             val = peek(q);
             if (val == -1)
             {
                printf("\nEmpty");
             }
             else
             {
                printf("\n the top element is:%d",val);
             }
             break;
        case 4:
             q = display(q);
             break;
        default:
             printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);   
}
void create_queue(struct queue *q){
    q->front = NULL;
    q->rear = NULL;
}
struct queue *insert(struct queue *q,int val){
struct node *ptr;
ptr = (struct node *) malloc(sizeof(struct node));
ptr->data = val;
if (q->front == NULL)
{
    q->front=ptr;
    q->rear = ptr;
    q->front->next = q->rear->next = NULL;
}
else
{
    q->rear->next=ptr;
    q->rear=ptr;
    q->rear->next =NULL;
}
return q;
}
struct queue *display(struct queue *q){
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        while (ptr!=q->rear)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    return q;
}
struct queue *delete(struct queue *q){
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
    {
        printf("\nEmpty Queue or underflow");
    }
    else
    {
        q->front = q->front->next;
        printf("\nValue deleted is  %d",ptr->data);
        free(ptr);
    }
    return q;
}
int peek(struct queue *q){
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
    {
        return -1;
    }
    else
    {
        return ptr->data;
    }
}