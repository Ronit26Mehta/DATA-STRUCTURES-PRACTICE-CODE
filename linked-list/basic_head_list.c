#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_hll(struct node*);
struct node *display(struct node*);
void main(){
    int choice;
    do
    {
        printf("\t---------Menu--------\n");
        printf("\t1:Create a list \n");
        printf("\t2:Display a list\n");
        printf("\nEnter a choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = create_hll(start);
            printf("\nLinked List created");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            printf("\nExiting");
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice!=3);
    
}
struct node *create_hll(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\nEnter -1 to stop");
    printf("\n Enter data:");
    scanf("%d",&num);
    while (num!=-1)
    {
        nn = (struct node*)malloc(sizeof(struct node));
        nn->data= num;
        nn->next=NULL;
        if (start == NULL)
        {
            start = (struct node*)malloc(sizeof(struct node));
            start->next=nn;
        }
        else{
            ptr=start;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=nn;
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
        
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while (ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr = ptr->next;
    }
    return start;
}