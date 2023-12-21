#include<stdio.h>
void move(int n,char source,char sparse,char dest);
void main(){
    int n;
    printf("\nEnter the disks:");
    scanf("%d",&n);
    move(n,'A','B','C');
}

void move(int n,char source,char sparse,char dest){
    if (n == 1)
    {
        printf("\n%d from %d",source,dest);
    }
    else{
        move(n-1,source,sparse,dest);
        move(1,source,dest,sparse);
        move(n-1,sparse,dest,source);
    }
}