#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
char stack[max];
int top = -1;
void push(char stack[],char val);
void reverse(char str[]);
void InfixtoPostfix(char source[],char target[]);
char pop(char stack[]);
int getPriority(char exp);
char source[max],target[max],temp[max];
void main(){
  
    printf("\nEnter infix expression:");
    fgets(source,max,stdin);
    source[strcspn(source,"\n")] = '\0';
    reverse(source);
    strcpy(target,"");
    InfixtoPostfix(temp,target);
    printf("\nThe corresponding postfix expression is:");
    puts(target);
    strcpy(temp,"");
    reverse(target);
    printf("\nthe corresponding prefix expression is:");
    puts(temp);
}
void InfixtoPostfix(char source[],char target[]){
    char temp;
    int i =0 , j =0;
    strcpy(target,"");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(stack,source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while (top != -1 && (stack[top] != '('))
            {
                target[j] = pop(stack);
                j++;
            }
            if (top == -1)
            {
                printf("\nInvalid expression");
                exit(1);
            }
            temp = pop(stack);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '/' || source[i] == '*' || source[i] == '%' )
        {
            while (top!=-1 && (stack[top] != '(') && (getPriority(stack[top]) > getPriority(source[i])))
            {
                target[j] = pop(stack);
                j++;
            }
            push(stack,source[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Expression..");
            exit(1);
        }
        i++;
    }
    
    while (top != -1 && stack[top] != '(')
    {
       target[j] = pop(stack);
       j++;
    }
    target[j] = '\0';
}
void push(char stack[],char exp){
    if (top == max -1)
    {
        printf("\nOverflow");
    }
    else
    {
        stack[++top] = exp;
    }
}
char pop(char stack[]){
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        return stack[top--];
    }
}
int getPriority(char exp){
    if (exp == '*' || exp == '/' || exp == '%')
    {
        return 2;
    }
    else
    {
        return 1;
    }
    
    
}
void reverse(char str[]){
    int len,i=0,j=0;
    len = strlen(str);
    j = len -1;
    while (j>=0)
    {
        if (str[j] == '(')
        {
            temp[i] = ')';
        }
        else if (str[j] == ')')
        {
            temp[i] = '(';
        }
        else
        {
            temp[i] = str[j];
        }
        i++;
        j -- ;
    }
    temp[i] = '\0';
}