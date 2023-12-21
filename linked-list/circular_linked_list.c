#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_cli(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
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
        printf("\n\t press 5 to delete at beginning of linked list \t\n");
        printf("\n\t press 6 to delete at end of linked list \t\n");
        printf("\n\t press 7 to delete after an element of linked list \t\n");
        printf("\n\t press 8 to delete a whole linked list\t\n");
        printf("\n\t enter -1 to exit \t\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
             start = create_cli(start);
             printf("\n circular linked list created \n");       
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
             start = delete_beg(start);
             break;
        case 6:
             start = delete_end(start);
             break;
        case 7:
             start = delete_after(start);
             break;
        case 8:
             start = delete_list(start);
             break;
        case 9:
             printf("\n\t Exiting...\t\n");
             break;
        default:
           printf("\ninvalid choice\n");
            break;
        }
    } while (choice!=-1);   
}
struct node *create_cli(struct node *start){
      struct node *nn, *ptr;
      int num;
      printf("\n\t Enter -1 to exit \t\n");
      printf("\n Enter the data:\n");
      scanf("%d",&num);
      while (num != -1)
      {
        nn = (struct node*)malloc(sizeof(struct node));
        nn->data = num;
        if (start == NULL)
        {
            nn->next=nn;
            start = nn;
        }
        else{
            ptr = start;
            while (ptr->next!=start)
            {
                ptr = ptr->next;
            }
            ptr->next = nn;
            nn->next = start; 
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
      }
      return start;     
}
struct node *display(struct node *start){
     struct node *ptr;
     ptr = start;
     printf("\n the data for circular linked list:\n");
     while(ptr->next!=start){
        printf("\t %d",ptr->data);
        ptr = ptr ->next;
     }
     printf("\t %d",ptr->data);
     return start;
}
struct  node *insert_beg(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\nEnter the data:");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next=nn;
    nn->next=start;
    start=nn;
    return start;   
}
struct node *insert_end(struct node *start){
    struct node *ptr,*nn;
    int num;
    printf("\n Enter the data");
    scanf("%d",&num);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = num;
    ptr = start;
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=start;
    return start;
}
struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(ptr);
    start = ptr->next;
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*pp;
    ptr = start;
 
    while (ptr->next!=start)
    {
        pp=ptr;
        ptr=ptr->next;

    }
    pp->next=ptr->next;
    free(ptr);
    return start;   
}
struct node *delete_after(struct node *start){
    struct node *pp,*ptr;
    int val;
    printf("\nEnter the value to be deleted:");
    scanf("%d",&val);
    ptr = start;
    pp = ptr;
    while (pp->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    if (ptr == start)
    {
        start=pp->next;
    }
    free(ptr);
    return start;
}
struct node *delete_list(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr->next !=start)
    {
        start=delete_end(start);
    }
     free(start);
     return start;
}           