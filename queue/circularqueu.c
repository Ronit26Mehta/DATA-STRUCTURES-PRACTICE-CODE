#include <stdio.h>
#define max 10
int queue[max];
int front = -1,rear =-1;
void insert(int val);
int delete();
int peek();
void display();
void main(){
    int val,choice,result;
    do
    {
        printf("\n1.insert\n2.delete\n3.peek\n4.display");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            result = delete();
            if (result == -1)
            {
                printf("\nunderflow or empty");
            }
            else
            {
                printf("\nThe result is:%d",result);
            }
            break;
        case 3:
            result = peek();
            if (result == -1)
            {
                printf("\nEmpty of underflow");
            }
            else
            {
                printf("\nThe result is:%d",result);
            }
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
void insert(int val){
    if (front == 0 && rear == max - 1 )
    {
        printf("\nUnderflow condition");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if (front != 0 && rear == max -1)
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
      rear++;
      queue[rear] = val;   
    }
}
int delete(){
    int val;
    if (front == -1  && rear == -1)
    {
        val = -1;
    }
    else if (front == rear)
    {
        val = queue[front];
        front = rear = -1;

    }
    else if (front == max -1)
    {
        val  = queue[front];
        front = 0;
    }
    else
    {
        val = queue[front];
        front++;
    }
    return val;
}
int peek(){
    int val;
    if (front == -1 && rear == -1)
    {
        val = -1;
    }
    else
    {
        val = queue[front];
    }
    return val;
}
void display(){
    if (front == -1 && rear == -1)
    {
        printf("\nEmpty queue");
    }
    else if (front<rear)
    {
        for (int i = front; i <=rear; i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    else
    {
        for (int i = front; i <= max-1; i++)
        {
            printf("%d\t",queue[i]);
        }
        for (int i = 0; i < rear; i++)
        {
            printf("%d\t",queue[i]);
        }           
    }
}