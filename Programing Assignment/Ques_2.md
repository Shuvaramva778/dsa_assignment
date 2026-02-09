md
# Infix to Postfix Conversion and Evaluation

## (a) Data Structure Definition
A stack is used to store operators during conversion and operands during postfix evaluation.

## (b) Functions Implemented
- `precedence(char op)` – Returns operator precedence.
- `infixToPostfix()` – Converts infix expression to postfix.
- `evaluatePostfix()` – Evaluates the postfix expression.
- `applyOperator()` – Performs arithmetic operations.

## (c) main() Overview
The `main()` function reads an infix expression, converts it to postfix notation, and evaluates the result.

## (d) Sample Output
Input: (3+5)*2  
Postfix: 35+2*  
Result: 16