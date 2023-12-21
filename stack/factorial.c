#include<stdio.h>
int fact(int);
void main(){
    int num,val;
    printf("\nEnter the value:");
    scanf("%d",&num);
    val = fact(num);
    printf("\nthe result is:%d",val);
}
int fact(int num){
    if (num == 0){
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else{
        return(num * fact(num -1));
    }
}







