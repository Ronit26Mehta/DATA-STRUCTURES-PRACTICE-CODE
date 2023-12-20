#include<stdio.h>
#define size 10
int array[size],temp[size];
void bubble_sort(int array[],int len);
void insertion_sort(int array[],int len);
void selection_sort(int array[],int len);
void radix_sort(int array[],int len);
/*void restoreHeapUp(int *,int);
void restoreHeapDown(int *,int,int);*/
void main(){
int len,choice;

do
{
    printf("\n-------SORTING VISUALIZER-------\n");
    printf("\nEnter the lenght of the array:");
    scanf("%d",&len);
    printf("\nEnter the elements:");
    for (int i = 0; i < len; i++)
    {
    scanf("%d",&array[i]);
    }
    printf("\nlist of sorting algorithm:");
    printf("\n1.Bubble sort");
    printf("\n2.insertion sort");
    printf("\n3.selection sort");
    printf("\n4.radix sort");
    printf("\n5.heap sort");
    printf("\n6.exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        bubble_sort(array,len);
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        break;
    case 2:
        insertion_sort(array,len);
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        break;
    case 3:
         selection_sort(array,len);
         for (int i = 0; i < len; i++)
         {
            printf("%d\t",array[i]);
         }
         break;
    case 4:
        radix_sort(array,len);
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        break;
   /* case 5:
        for (int i = 1; i <= len; i++)
        {
            array[i] = array[i-1];
            restoreHeapUp(array,i);
        }
        int j = len;
        int temp;
        for (int i = 1; i <= j; i++)
        {
            temp;
            temp = array[1];
            array[1] = array[len];
            array[len] = temp;
            len = len -1;
           restoreHeapDown(array,1,len); 
        }
        len = j;
        printf("\nthe sorted array:");
        for (int i = 1; i <= len; i++)
        {
            printf("%4d\t",array[i]);
        }
        
        */
    default:
        printf("\nInvalid Choice");
        break;
    }
    
} while (choice != 6);
}
void bubble_sort(int array[],int len){
int i,j,temp;
for ( i = 0 ; i < len - 1 ; i++)
{
    for ( j = 0; j < len - 1 - i; j++)
    {
        if (array[j]>array[j+1])
        {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
    for (int k= 0; k < len; k++)
    {
        printf("%d\t",array[k]);
    }
    printf("\n");
    
}
}
void insertion_sort(int array[],int len){
    int i,j,temp;
    for (int i = 1; i < len; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((temp<array[j]) && (j>=0))
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
        for (int k = 0; k < len; k++)
        {
            printf("%d\t",array[k]);
        }
        printf("\n");
    }
    
}
int smallest(int array[],int k, int len){
    int pos = k,small = array[k],i;
    for (int i = k+1; i < len; i++)
    {
        if (array[i]<small)
        {
            small = array[i];
            pos = i;
            
        }
        
    }
    return pos;
}
void selection_sort(int array[],int len){
int k,pos,temp;
for (int k = 0; k < len; k++)
{
    pos = smallest(array,k,len);
    temp = array[k];
    array[k] = array[pos];
    array[pos] = temp;
    for (int h = 0; h < len; h++)
    {
        printf("%d\t",array[h]);
    }
    printf("\n");
}
}
int largest(int array[],int len){
    int large = array[0],i;
    for ( i = 1; i < len; i++)
    {
        if (array[i]>large)
        {
            large = array[i];
        }
        
    }
 return large;   
}
void radix_sort(int array[],int len){
    int bucket[size][size],bucket_count[size];
    int i,j,k,remainder,NOP = 0, divisor = 1,large,pass;
    large = largest(array,len);
    while (large>0)
    {
        NOP ++;
        large/=size;
    }
    for ( pass = 0; pass < NOP; pass++)
    {
        for (int i = 0; i < size; i++)
        {
            bucket_count[i] = 0;
        }
        for (int i = 0; i < len; i++)
        {
            remainder = (array[i]/divisor) % size;
            bucket[remainder][bucket_count[remainder]]= array[i];
            bucket_count[remainder]+=1;
        }
        i = 0;
        printf("\n");
        for ( k = 0; k < size; k++)
        {
            for ( j = 0; j < bucket_count[k]; j++)
            {
                array[i] = bucket[k][j];
                i++;
            }
        }
        printf("\nthe iteration:\n");
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        printf("\n");
        divisor *= size;
    }
    

}
/*
void restoreHeapUp(int *Heap,int index){
    int val = Heap[index];
    while ((index>1) && (Heap[index/2]<val))
    {
        Heap[index]=Heap[index/2];
        index/=2;
    }
    Heap[index]=val;
}
void restoreHeapDown(int *Heap,int index,int len){
    int val = Heap[index];
    int j = index*2;
    while (j<=len)
    {
        if ((j<len) && (Heap[j]<Heap[j+1]))
        {
            j++;
        }
        if (Heap[j]<Heap[j/2])
        {
            break;
        }
        Heap[j/2]=Heap[j];
        j = j * 2;
    }
    Heap[j/2] = val;
}
*/