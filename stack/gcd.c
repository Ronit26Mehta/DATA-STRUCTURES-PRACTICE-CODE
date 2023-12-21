#include<stdio.h>
int gcd(int num1,int num2);
int exponents(int num1,int num2);
void main(){
    int num1,num2,res;
    printf("\nEnter num1 and num2:");
    scanf("%d %d",&num1,&num2);
    res = gcd(num1,num2);
    printf("\nthe result is:%d",res);
}
int gcd(int num1 , int num2){
    int rem;
    rem = num1 % num2;
    if (rem == 0)
    {
        return num2;
    }
    else{
        return gcd(num2,rem);
    }
}
int exponents(int num1,int num2){
    if (num2 == 0)
    {
        return 1;
    }
    else{
        return(num1*exponents(num1,num2-1));
    }
}