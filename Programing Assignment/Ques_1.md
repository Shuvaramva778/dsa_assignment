md
# Balanced Parentheses Using Stack

## (a) Data Structure Definition
A stack is implemented using a character array and an integer variable `top`.  
The stack stores opening brackets `(`, `{`, `[` and is used to verify balance.

## (b) Functions Implemented
- `push(char c)` – Inserts an element into the stack.
- `pop()` – Removes and returns the top element of the stack.
- `isMatchingPair(char open, char close)` – Checks matching parentheses.
- `areParenthesesBalanced(char expr[])` – Determines whether the expression is balanced.

## (c) main() Overview
The `main()` function accepts a mathematical expression as input and checks if the parentheses are balanced using stack operations.

## (d) Sample Output
Input: a + (b − c)  
Output: Balanced Parentheses  

Input: m + [a − b ∗ (c + d ∗ {m)]  
Output: Unbalanced Parentheses


---