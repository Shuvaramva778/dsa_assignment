#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int areParenthesesBalanced(char expr[]) {
	int i;
    for ( i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1) return 0;
            if (!isMatchingPair(pop(), expr[i])) return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[100];

    printf("Enter expression: ");
    gets(expr);

    if (areParenthesesBalanced(expr))
        printf("Balanced Parentheses\n");
    else
        printf("Unbalanced Parentheses\n");

    return 0;
}
