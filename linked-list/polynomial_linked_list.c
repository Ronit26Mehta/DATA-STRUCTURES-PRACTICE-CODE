#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int num;
    int coeff;
    struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;
struct node *last3 = NULL;
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node*,struct node*,struct node*);
struct node *sub_poly(struct node*,struct node*,struct node*);
struct node *add_node(struct node*,int,int);
void main()
{
    int choice;
    do
    {
        printf("\n1.Enter first polynomial\n2.Enter second polynomial\n3.display polynomial 1 \n4. display ploynomial 2\n5.add the polynomial\n6.display result\n7.subtract the polynomial\n8.display the result");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start1 = create_poly(start1);
            break;
        case 2:
             start2 = create_poly(start2);
             break;
        case 3:
            start1 = display_poly(start1);
            break;
        case 4:
             start2 = display_poly(start2);
             break;
        case 5:
             start3 = add_poly(start1,start2,start3);
             break;
        case 6:
              start3 = display_poly(start3);
              break;
        case 7:
             start4 = sub_poly(start1,start2,start4);
             break;
        case 8:
             start4 = display_poly(start4);
             break;
        case 9:
            printf("\nExiting...");
            break;
        default:
             printf("\nInvalid choice");
            break;
        }
    } while (choice != 9);   
}
struct node *create_poly(struct node *start){
    struct node *nn,*ptr;
    int n,c;
    printf("\nEnter the number :");
    scanf("%d",&n);
    printf("\nEnter the coeffecient:");
    scanf("%d",&c);
    while (n != -1)
    {
        nn  = (struct node *)malloc(sizeof(struct node));
        nn->num = n;
        nn->coeff = c;
        if (start == NULL)
        {
            start = nn;
            nn->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                 ptr = ptr->next;
            }
            ptr->next = nn;
            nn->next = NULL;
        }
        printf("\nEnter the number:");
        scanf("%d",&n);
        printf("\nEnter the coeffecient:");
        scanf("%d",&c);
    }
    return start;
}
struct node *display_poly(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("%d x^%d \t",ptr->num,ptr->coeff);
         ptr = ptr->next;
    }
    return start;
}
struct node *add_poly(struct node *start1,struct node *start2,struct node *start3){
    struct node *ptr1,*ptr2;
    int sum_num,c;
    ptr1 = start1;
    ptr2 = start2;
    while (ptr1!= NULL && ptr2!= NULL)
    {
        if (ptr1->coeff== ptr2->coeff)
        {
            sum_num = ptr1->num + ptr2->num;
            start3 = add_node(start3,sum_num,ptr1->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            start3 = add_node(start3,ptr1->num,ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            start3 = add_node(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
        
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start3 = add_node(start3,ptr2->num,ptr2->coeff);
            ptr2 = ptr2 ->next;
        }
        
    }
    else if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start3  = add_node(start3,ptr1->num,ptr1->coeff);
            ptr1 = ptr1 ->next;
        }
    }
    return start3;
}
struct node *sub_poly(struct node *start1,struct node *start2,struct node *start4){
    struct node *ptr1,*ptr2;
    int sum_num;
    ptr1 = start1 , ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->coeff == ptr2->coeff)
        {
            sum_num = ptr1->num - ptr2->num;
            start4 = add_node(start4,sum_num,ptr1->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->coeff > ptr2 ->coeff)
        {
            start4 = add_node(start4,ptr1->num,ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->coeff<ptr2->coeff)
        {
            start4 = add_node(start4,ptr2->num,ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
  if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start4 = add_node(start4,ptr2->num,ptr2->coeff);
            ptr2 = ptr2 ->next;
        }
        
    }
  else if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start4  = add_node(start4,ptr1->num,ptr1->coeff);
            ptr1 = ptr1 ->next;
        }
    }
    return  start4;
}
struct node *add_node(struct node *start,int num,int coeff){
    struct node *nn,*ptr;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->num = num;
    nn->coeff = coeff;
    if (start == NULL)
    {
          nn->next = NULL;
          start = nn;
    }
    else
    {
        ptr  = start;
        while (ptr->next !=NULL)
        {
             ptr = ptr->next;
        }
        ptr->next = nn;
        nn->next = NULL;
    }
    
    return start;
}