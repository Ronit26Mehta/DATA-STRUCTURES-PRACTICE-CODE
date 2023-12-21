#include<stdio.h>
int fib(int num);
void main(){
    int i,val,res;
    printf("\nEnter the number");
    scanf("%d",&val);
    for ( i = 0; i < val; i++)
    {
        res = fib(val);
        printf("\t%d",res); 
    }
    
}
int fib(int num){
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return (fib(num -1 ) +fib(num -2));
    }
}