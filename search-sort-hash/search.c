#include<stdio.h>
#define size 10
int array[size];
int val;
int pos;
int linear_search(int array[],int val,int len);
int binary_search(int array[],int val,int len);
int fibonacci_search(int array[],int val,int len);
int min(int val,int y);
void main(){
    int choice,len;
    printf("-----Welcome to search analyzer------");
    printf("\nEnter the size of array:");
    scanf("%d",&len);
    printf("\nEnter the content of the array:");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nThe content of array:");
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",array[i]);
    }
    do
    {
     printf("\nSelect from below");
     printf("\n1.linear search");
     printf("\n2.binary search");
     printf("\n3.fibonacci search");
     printf("\n4.exit");
     printf("\nYour choice of algorithm:");
     scanf("%d",&choice);
     switch (choice)
     {
     case 1:
        printf("\nEnter val:");
        scanf("%d",&val);
        pos = linear_search( array, val,len);
        if (array[pos] == val)
        {
            printf("%d found at index %d",val,pos);
        }
        else{
            printf("value not found");
        }
        break;
        case 2:
        printf("\nEnter val:");
        scanf("%d",&val);
        pos = binary_search( array, val, len);
        if (array[pos] == val)
        {
            printf("%d found at index %d",val,pos);
        }
        else{
            printf("value not found");
        }
        break;
       case 3:
       printf("\nEnter the value:");
       scanf("%d",&val);
       pos = fibonacci_search(array,val,len);
       if (array[pos] == val)
       {
         printf("\n %d found at %d index",val,pos);
       }
       else{
        printf("\nvalue not found");
       }
       break;

        
        case 4:
        printf("\nExiting...");
        break;
     default:
        printf("\n invalid choice");
        break;
     }
      
    } while (choice != 4);
    
}
int linear_search(int array[],int val,int len){
    for (int i = 0; i < len; i++)
    {
        if (array[i] == val)
        {
            pos = i;
            return pos;
        }
        
    }
}
int binary_search(int array[],int val,int len){
int mid,beg = 0,end = len - 1 ;
while (beg<=end)
{
    mid = (beg + end)/2;
    if (array[mid] == val)
    {
        pos = mid;
        return pos;
    }
    else if (array[mid]<val)
    {
        beg = mid +1;
    }
    else
    {
        end = mid - 1; 
    }
}
}
int min(int val,int y){
    return (val<=y)?val:y;
}
int fibonacci_search(int array[],int val,int len){
    int fibm2 = 0;
    int fibm1 = 1;
    int fib = fibm1 + fibm2;
    while (fib<len)
    {
        fibm2 = fibm1;
        fibm1 = fib;
        fib = fibm1 + fibm2;
    }
    int offset = -1;
    while (fib>1)
    {
        int i = min(offset+fibm2,len-1);
        if (array[i]<val)
        {
            fib = fibm1;
            fibm1 = fibm2;
            fibm2 = fib - fibm1;
            offset = i;
        }
        else if (array[i]>val)
        {
            fibm2 = fib;
            fibm1 = fibm1 - fibm2;
            fibm2 = fib - fibm1;
        }
        else{
            return i;
        }
    }
    if (fibm1 && array[offset+1]==val)
    {
        return offset + 1;
    }
    return -1;
}
