#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100

int top = -1;
int stack[max];

void push(int exp);
int pop();
int gettype(char exp);

void main() {
    char exp[max];
    int val, result, len, op1, op2;
    printf("\nEnter expression: ");
    fgets(exp, max, stdin);
    len = strlen(exp);

    for (int i = len - 1; i >= 0; i--) {
        switch (gettype(exp[i])) {
            case 1:
                val = exp[i] - '0';
                push(val);
                break;
            case 2:
                op1 = pop();
                op2 = pop();
                switch (exp[i]) {
                    case '+':
                        result = op1 + op2;
                        break;
                    case '-':
                        result = op1 - op2;
                        break;
                    case '*':
                        result = op1 * op2;
                        break;
                    case '/':
                        result = op1 / op2;
                        break;
                }
                push(result);
                break;
        }
    }
    printf("\nStack contents: ");
    for (int i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\nResult is %d\n", stack[top]);
}

void push(int exp) {
    if (top == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = exp;
}

int pop() {
    return stack[top--];
}

int gettype(char exp) {
    if (exp == '+' || exp == '-' || exp == '*' || exp == '/') {
        return 2;
    } else {
        return 1;
    }
}
