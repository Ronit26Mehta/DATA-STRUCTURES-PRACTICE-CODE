#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *next;
};
struct node* start = NULL;
struct node* create_insert(struct node *start,int val,int priority);
struct node* delete(struct node *start);
void display(struct node *start);
int peek(struct node *start);
void main(){
    int choice,val,priority;
    do
    {
        printf("\n1.create Insert queue");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.peek");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data:");
            scanf("%d",&val);
            printf("\nEnter the priority:");
            scanf("%d",&priority);
            start =  create_insert(start,val,priority);
            break;
        case 2:
            start = delete(start);
            break;
        case 3:
             display(start);
             break;
        case 4:
             val = peek(start);
             if (val == -1)
             {
                printf("\nEmpty");
             }
             else
             {
                printf("\nThe data is:%d",val);
             }
             break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);
}
struct node *create_insert(struct node *start,int val,int pri){
    struct node *ptr,*pp;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->priority = pri;
    if (start == NULL || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        pp=start;
        while (pp->next!= NULL  && pri >= pp->priority)
        {
            pp=pp->next;
        }
        ptr->next = pp->next;
        pp->next = ptr;
    }
    return start;
}
struct node *delete(struct node *start){
   struct node * ptr = start;
   if (ptr == NULL)
   {
       printf("\nEmpty or underflow");
   }
   else
   {
      start = start->next;
      printf("\nThe data to be deleted is:%d",ptr->data);
      free(ptr);
   }
   return start;
}
void display(struct node *start){
    struct node *ptr = start;
    if (ptr == NULL)
    {
        printf("\nEmpty queue or underflow");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d[%d]\t",ptr->data,ptr->priority);
            ptr = ptr->next;
        }
    }
}
int peek(struct node *start){
    if(start == NULL){
        return -1;
    }
    else
    {
        return start->data;
    }
}
