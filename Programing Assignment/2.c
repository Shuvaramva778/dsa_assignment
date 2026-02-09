#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    char opStack[100];
    int otop = -1;
int i;
    for ( i = 0; infix[i]; i++) {
        if (isdigit(infix[i]))
            postfix[k++] = infix[i];
        else if (infix[i] == '(')
            opStack[++otop] = '(';
        else if (infix[i] == ')') {
            while (opStack[otop] != '(')
                postfix[k++] = opStack[otop--];
            otop--;
        } else {
            while (otop != -1 && precedence(opStack[otop]) >= precedence(infix[i]))
                postfix[k++] = opStack[otop--];
            opStack[++otop] = infix[i];
        }
    }
    while (otop != -1)
        postfix[k++] = opStack[otop--];
    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[]) {
	int i;
    for ( i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i]))
            push(postfix[i] - '0');
        else {
            int b = pop();
            int a = pop();
            push(applyOperator(a, b, postfix[i]));
        }
    }
    return pop();
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}

