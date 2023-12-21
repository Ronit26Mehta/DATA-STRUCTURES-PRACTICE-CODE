#include<stdio.h>
#include<malloc.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_before(struct node *);
struct node *delete_list(struct node *);
void main(){
    int choice;
    do
    {
        printf("\n\t CIRCULAR LINKED LIST \t\n");
        printf("\n\t press 1 to create linked list \t\n");
        printf("\n\t press 2 to display linked list \t\n");
        printf("\n\t press 3 to insert at beginning of linked list \t\n");
        printf("\n\t press 4 to insert at end of linked list \t\n");
        printf("\n\t press 5 to insert before a node of linked list \t\n");
        printf("\n\t press 6 to insert after a node of linked list \t\n");
        printf("\n\t press 7 to delete at beginning of linked list \t\n");
        printf("\n\t press 8 to delete before a node of linked list \t\n");
        printf("\n\t press 9 to delete after a node of linked list \t\n");
        printf("\n\t press 10 to delete at end of linked list \t\n");
        printf("\n\t press 11 to delete a whole linked list\t\n");
        printf("\n\t press 12 to exit\t\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = create_ll(start);
            printf("\ndoubly linked list created");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
             start = insert_end(start);
             break;
        case 5:
             start = insert_before(start);
             break;
        case 6:
             start = insert_after(start);
             break;
        case 7:
             start = delete_beg(start);
             break;
        case 8:
             start = delete_before(start);
             break;
        case 9:
            start = delete_after(start);
            break;
        case 10:
             start = delete_end(start);
             break;
        case 11:
             start = delete_list(start);
             if (start == NULL) {
                 printf("\nLinked list is empty.");
              }
             break;
        case 12:
            printf("\nExiting...");
            break;
        default:
            break;
        }
    } while (choice!=12);
    
}
struct node *create_ll(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\nEnter -1 to exit:");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while (num !=-1)
    {
        if (start == NULL)
        {
            nn = (struct node*)malloc(sizeof(struct node));
            nn->prev=NULL;
            nn->next=NULL;
            nn->data=num;
            start=nn;
        }
        else
        {
            ptr=start;
            nn=(struct node*)malloc(sizeof(struct node));
            nn->data=num;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=nn;
            nn->prev=ptr;
            nn->next=NULL;
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start){
    struct node *nn;
    int num;
    printf("\nEnter the data:");
    scanf("%d",&num);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data=num;
    start->prev=nn;
    nn->next=start;
    nn->prev=NULL;
    start = nn;
    return start;
}
struct node *insert_before(struct node *start){
    struct node *nn,*ptr;
    int num,val;
    printf("\nEnter the val where data will be placed before:");
    scanf("%d",&val);
    printf("\nEnter the data:");
    scanf("%d",&num);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while (ptr->data!=val)
    {
        ptr=ptr->next;
    }
    nn->next=ptr;
    nn->prev=ptr->prev;
    ptr->prev->next=nn;
    ptr->prev=nn;
    return start;
}
struct node *insert_after(struct node *start){
    struct node *nn,*ptr;
    int num,val;
    printf("\nEnter the data:");
    scanf("%d",&num);
    printf("\nEnter the value after which node will be placed:");
    scanf("%d",&val);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while (ptr->data!=val)
    {
        ptr=ptr->next;
    }
    nn->prev=ptr;
    nn->next=ptr->next;
    ptr->next->prev=nn;
    ptr->next=nn;
    return start;
}
struct node *insert_end(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\nEnter the data:");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->prev=ptr;
    nn->next=NULL;
    return start;
}
struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    if (start == NULL)
    {
        printf("\nList is empty nothing to delete");
        return start;
    }
    
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start){
    struct node *temp,*ptr;
    int val;
    printf("\nEnter after which position data would be deleted:");
    scanf("%d",&val);
    ptr=start;
    while (ptr->data!=val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev=ptr;
    free(temp);
    return start;
}
struct node *delete_before(struct node *start){
    struct node *ptr,*temp;
    int val;
    printf("\nEnter the value before which data would be deleted");
    scanf("%d",&val);
    ptr=start;
    while (ptr->data!=val)
    {
        ptr=ptr->next;
    }
    temp=ptr->prev;
    if (temp==start)
    {
        start = delete_beg(start);
    }
    else
    {
        ptr->prev=temp->prev;
        temp->prev->next=ptr;
    }
    free(temp);
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr->next!= NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return start;
}
struct node *delete_list(struct node *start){
    struct node *ptr;
    while (start!=NULL)
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
    
}