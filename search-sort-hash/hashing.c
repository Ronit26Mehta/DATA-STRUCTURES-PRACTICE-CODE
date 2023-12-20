#include<stdio.h>
#define max 10
int hashtable[max];
void insert(int hashtable[],int key);
void delete(int hashtable[],int key);
int search(int hashtable[],int key);
void display(int hashtable[]);
void insert(int hashtable[],int key){
    int div,result,i=0;
    div = key % max;
    while (i<max)
    {
        result = (div + i ) % max;
        if (hashtable[result] == -1)
        {
            hashtable[result] = key;
            break;
        }
       
        i++;
    }
      if ( i == max)
        {
        printf("\nhastable is full");
        }
}
void display(int hashtable[]){
    printf("index\tkey\n");
    for (int i = 0; i < max; i++)
    {
        printf("%d\t%d\n",i,hashtable[i]);
    }
}
int search(int hashtable[],int key){
    int div,result,i=0;
    div = key % max;
    while (i<=max)
    {
        result = (div+i) % max;
        if (hashtable[result]  == key)
        {
            return result;
            break;
        }
        else if (i == max)
        {
          return -1;
        }
        i++;
    }
}
void delete(int hashtable[],int key){
    int result;
    result = search(hashtable,key);
    if (result == -1)
    {
        printf("\n value not found");
    }
    else if (hashtable[result] == key)
    {
        hashtable[result] = -1;
        printf("\n%d deleted",key);
    }
}
void main(){
    int key,choice,result;
    for (int i = 0; i < max; i++)
    {
        hashtable[i] = -1;
    }
    do
    {
        printf("\n1.insert");
        printf("\n2.display");
        printf("\n3.search");
        printf("\n4.delete");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nenter key:");
            scanf("%d",&key);
            insert(hashtable,key);
            break;
        case 2:
            display(hashtable);
            break;
        case 3: 
            printf("\nenter key:");
            scanf("%d",&key);
            result = search(hashtable,key);
            if (result == -1)
            {
                printf("\nkey not found");
            }
            else
            {
                printf("\nkey found");
            }
            break;
        case 4:
            printf("\nenter key:");
            scanf("%d",&key);
            delete(hashtable,key);
            break;
        case 5:
             printf("\nexiting..");
             break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice != 5);
}