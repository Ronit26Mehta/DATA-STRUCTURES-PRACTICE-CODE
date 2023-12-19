#include<stdio.h>
#define max 10
int front = -1,rear = -1;
int queue[max];
void insert(int val);
int delete();
int peek();
void display();
void main(){
    int choice,val,result;
    do
    {
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.peek");
        printf("\n4.display");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
           result = delete();
           if (result == -1)
           {
             printf("\nEmpty queue/underflow");
           }
           else
           {
            printf("\n%d value was deleted",result);
           }
         break;
        case 3:
            result = peek();
            if (result == -1)
            {
                printf("\nEmpty queue/underflow");
            }
            else
            {
                printf("\n %d was at top",result);
            }
            break;
        case 4:
             display();
             break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice!=5);
    
}
void insert(int val){
    if (rear == max-1)
    {
        printf("\nQueue is full or overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}
void display(){
    if (front == -1 || front>rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for(int i = front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
int delete(){
    int val;
    if (front == -1 || front>rear)
    {
        return -1;
    }
    else if (front == rear)
    {
        val =queue[front];
        front = rear = -1;
        return val;
    }
    else
    {
        val = queue[front];
        front++;
       /* if (front > rear)
        {
            front = rear = -1;
        }*/
           return val;
        
    }
}
int peek(){
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        return queue[front];
    }
}
