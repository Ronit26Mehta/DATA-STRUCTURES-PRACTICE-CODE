#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define max 100
float st[max];
int top = -1;
void push(float st[],float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);
void main(){
    char exp[max];
    float val;
    printf("\nEnter the suitable postfix expression:");
    fgets(exp,max,stdin);
    val = evaluatePostfixExp(exp);
    printf("\nThe result is:%.2f",val);
}
float evaluatePostfixExp(char exp[]){
    float value,opr1,opr2;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st,(float)(exp[i] - '0'));
        }
        else
        {
            opr2 = pop(st);
            opr1 = pop(st);
            switch (exp[i])
            {
            case  '+':
                  value = opr1 + opr2;
                break;
            case '-':
                  value = opr1 - opr2;
                  break;
            case '/':
                   value  = opr1 /opr2;
                   break;
            case '%':
                   value = (int)opr1 % (int)opr2;
                   break;
            case '*':
                    value = opr1 * opr2;
                    break;
            default:
                  printf("\nInvalid choice");
                break;
            }
            push(st,value);
        }
        i++;
    }
    return(pop(st));
}
float pop(float st[]){
    return st[top--];
}
void push(float st[],float val){
    st[++top] = val;
}