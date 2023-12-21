#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top = -1;
void push(char exp);
char pop();
void main(){
    char exp[max],temp;
    int flag = 1;
    printf("\nEnter expression:");
    fgets(exp,max,stdin);
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')'  || exp[i] == ']' || exp[i] == '}')
        {
            if (top == -1)
            {
                flag = 0;
                break;
            }
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '{'  || temp == '['))
                {
                    flag =0;
                }
                if (exp[i] == '}' && (temp == '[' || temp == '('))
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '(' || temp == '{'))
                {
                    flag = 0;
                }
            }
            
        }
        
    }
    if (top>=0)
    {
        flag = 0;
    }
    if (flag == 1)
    {
        printf("\nvalid expression");
    }
    else
    {
        printf("\ninvalid expression");
    }
}
void push(char exp){
if (top == max-1)
{
    printf("\nfull");
}
else
{
    top++;
    stack[top]= exp;
}
}
char pop(){
    return stack[top--];
}