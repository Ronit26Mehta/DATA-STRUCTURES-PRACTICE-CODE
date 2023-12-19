#include<stdio.h>
#define max 10
int dequeue[max];
int left = -1,right = -1;
void input_dequeue(void);
void output_dequeue(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);
void main(){
    int choice;
    do
    {
        printf("\n1.Input Dequeue \n2.output Dequeue");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
             input_dequeue();
            break;
        case 2:
            output_dequeue();
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 3);
}
void input_dequeue(){
    int choice;
    do
    {
        printf("\n1.Insert right");
        printf("\n2.Delete left");
        printf("\n3.Delete right");
        printf("\n4.display");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
             delete_left();
             break;
        case 3:
             delete_right();
             break;
        case 4:
              display();
              break;
       default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);
    
}
void output_dequeue(){
    int choice;
    do
    {
        printf("\n1.Insert Right");
        printf("\n2.Insert Left");
        printf("\n3.delete_right");
        printf("\n4.Display");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
              insert_right();
            break;
        case 2:
             insert_left();
             break;
        case 3:
              delete_right();
              break;
        case 4:
             display();
             break;
        default:
             printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);   
}
void insert_right(){
    int val;
    printf("\nEnter the value:");
    scanf("%d",&val);
    if ((left == 0 && right == max-1) || (left == right+1))
    {
        printf("\nOverflow");
        return;
    }
    else if (left == -1)
    {
        left =0;
        right = 0;
        dequeue[right] = val;
    }
    else if(right == max -1)
    {
        right = 0;
        dequeue[right] = val;
    }
    else
    {
        right++;
        dequeue[right] = val;
    }
}
void insert_left(){
    int val;
    printf("\nEnter the value:");
    scanf("%d",&val);
    if ((left == 0 && right == max -1) || (left == right+1))
    {
         printf("\nOverflow");
         return;
    }
    else if (left == -1)
    {
        left = 0;
        right = 0;
        dequeue[left] = val;
    }
    else if(left == 0)
    {
        left = max-1;
        dequeue[left] = val;
    }
    else
    {
        left--;
        dequeue[left] = val;
    }
}
void delete_left(){
    if (left == -1)
    {
        printf("\nEmpty");
        return;
    }
    printf("\nThe value:%d",dequeue[left]);
    if (left == right)
    {
        left =-1;
        right = -1;
    }
    else if (left == max -1)
    {
        left = 0;
    }
    else
    {
        left++;
    }
    
}
void delete_right(){
    if (left == -1)
    {
        printf("\n Empty");
        return ;
    } 
    printf("\nthe value:%d",dequeue[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (right == 0 )
    {
        right = max -1;
    }
    else
    {
        right -- ;
    }
}
void display(){
    int front = left,rear = right;
    if (front == -1)
    {
        printf("\nEmpty queue");
    }
    else if(front<=rear){
        while (front<=rear)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
    }
    else
    {
        while (front<=max-1)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
        front = 0;
        while (front<=rear)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
    }   
}