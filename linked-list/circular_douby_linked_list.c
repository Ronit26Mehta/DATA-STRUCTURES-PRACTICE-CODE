#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *create_cldi(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
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
        printf("\n\t enter 9 to exit \t\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = create_cldi(start);
            printf("\nThe circular doubly linked list is created");
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
             start = delete_node(start);
             break;
        case 8:
             start = delete_list(start);
             if (start == NULL)
             {
                printf("\nList is empty");
             }
             
             break;
        case 9:
             printf("\nExiting...");
             break;
        default:
             printf("\nInvalid choice");
            break;
        }
    } while (choice!=9);
    
}
struct node *create_cldi(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);

    while (num != -1 && ptr != NULL) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL) {
            new_node->prev = new_node;
            new_node->next = new_node;
            start = new_node; // Update start pointer here for the first element
        } else {
            ptr = start;
            while (ptr->next != start) {
                ptr = ptr->next;
            }

            new_node->prev = ptr;
            ptr->next = new_node;
            new_node->next = start;
            start->prev = new_node;
        }

        printf("Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}


struct node *display( struct node *start){
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return start;
}
struct node *insert_beg(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\n Enter data:");
    scanf("%d",&num);
    nn =(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr = start;
    while (ptr->next!=start)
    {
        ptr = ptr->next;
    }
    nn->prev=ptr;
    ptr->next=nn;
    nn->next=start;
    start->prev=nn;
    start = nn;
    return start;
}
struct node *insert_end(struct node *start){
    struct node *nn,*ptr;
    int num;
    printf("\nEnter data:");
    scanf("%d",&num);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = num;
    ptr = start;
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
     ptr->next=nn;
     nn->prev=ptr;
     nn->next=start;
     start->prev=nn;
     return start;
}
struct node *delete_beg(struct node *start){
    struct node *ptr,*temp;
    ptr= start;
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
    temp = start;
    ptr->next= start->next;
    start = start->next;
    start->prev=ptr;
    free(temp);
    return start;
}
struct node *delete_end(struct node *start){
      struct node *ptr,*temp;
      ptr=start;
      while (ptr->next!=start)
      {
        ptr=ptr->next;
      }
      ptr->prev->next=start;
      start->prev=ptr->prev;
      free(ptr);
      return start;
}
struct node *delete_node(struct node *start){
    struct node *ptr;
    int val;
    printf("\n Enter the value after which deletion happens:");
    scanf("%d",&val);
    ptr=start;
    if (ptr->data==val)
    {
        start = delete_beg(start);
        return start;
    }
    else{
        while (ptr->data!=val)
        {
            ptr=ptr->next;
        }
          ptr->prev->next=ptr->next;
          ptr->next->prev=ptr->prev;
          return start;
    }
}
struct node *delete_list(struct node *start){
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start)
    {
        start = delete_end(start);
    }
    free(start);
    return start;
     

}