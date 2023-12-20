#include<stdio.h>
#define max 10
void mergesort(int array[],int beg,int end);
void merge(int array[],int beg,int mid,int end);
void quicksort(int array[],int beg,int end);
int partition(int array[],int beg,int end);
void main(){
    int choice,len,array[max];
    printf("\nEnter size:");
    scanf("%d",&len);
    printf("\nEnter values:");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&array[i]);
    }
    do
    {
        printf("\n1.merge sort");
        printf("\n2.quick sort");
        printf("\n3.redefine array");
        printf("\n4.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
             mergesort(array,0,len-1);
             for (int i = 0; i < len; i++)
             {
                printf("%d\t",array[i]);
             }
              break;
        case 2:
            quicksort(array,0,len-1);
            for (int i = 0; i < len; i++)
            {
                printf("%d\t",array[i]);
            }
            break;
        case 3:
           for (int i = 0; i < len; i++)
           {
             scanf("%d",&array[i]);
           }
           break;
        case 4:
            printf("\nexiting..");
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice != 4);
}
void mergesort(int array[], int beg, int end) {
    int mid;
    if (beg < end) {
        mid = (beg + end) / 2;
        mergesort(array, beg, mid);
        mergesort(array, mid + 1, end);
        merge(array, beg, mid, end);
    }
}

void merge(int array[],int beg,int mid,int end){
    int i=beg,j=mid+1,k=0,temp[end],indexes=beg;
    while ((i<=mid) && (j<=end))
    {
        if (array[i] < array[j])
        {
            temp[indexes] = array[i];
            i++;
        }
        else
        {
            temp[indexes] =array[j];
            j++;
        }
        indexes++;
    }
    if (i>mid)
    {
        while (j<=end)
        {
            temp[indexes] = array[j];
            j++;
            indexes++;
        }
    }
    else
    {
        while (i<=mid)
        {
            temp[indexes] = array[i];
            i++;
            indexes++;
        }
        
    }
    while (k<indexes)
    {
        array[k] = temp[k];
        k++;
    }
}
void quicksort(int array[],int beg,int end){
    int pos;
    if (beg<end)
    {
        pos = partition(array,beg,end);
        quicksort(array,beg,pos-1);
        quicksort(array,pos+1,end);
    }
}
int partition(int array[],int beg,int end){
    int left ,right,loc,flag,temp;
    left = loc = beg;
    right = end;
    flag = 1;
    if (flag != 0)
    {
        while ((array[loc] < array[right] ) && (right != loc))
        {
            right--;
            if (loc == right)
            {
                flag = 0;
            }
            else if (array[right] < array[loc])
            {
                temp = array[right];
                array[right] = array[loc];
                array[loc] = temp;
                loc = right;
            }
        }
        if (flag != 0)
        {
            while ((array[loc]> array[left]) && (left != loc))
            {
                left++;
                if (loc == left)
                {
                    flag = 0;
                }
                else if (array[left] > array[loc])
                {
                    temp = array[left];
                    array[left] = array[loc];
                    array[loc]  = temp;
                    loc = left;
                }
            }
        }
    }
    return loc;
    
}