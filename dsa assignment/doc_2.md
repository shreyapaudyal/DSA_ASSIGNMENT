# Infix to Postfix Conversion and Evaluation Using Stack in C

## a. How the data structures are defined
Two stacks are used in this program:  

1. **CharStack** – stores operators and parentheses while converting infix to postfix.  
2. **IntStack** – stores integer operands while evaluating postfix expression.  

### Explanation
- `CharStack data[MAX]` stores operators like `+`, `-`, `*`, `/`, `^`, and parentheses `(`, `)`.  
- `IntStack data[MAX]` stores integer operands.  
- `top` keeps track of the current top element of the stack.  
- When `top = -1`, the stack is empty.  
- Both stacks work on **FILO** principle.

---

## b. Description of the functions used

### 1. `initCharStack()` / `initIntStack()`
- Initializes the stack (`top = -1`).  

### 2. `pushChar()` / `pushInt()`
- Adds element to the top of the stack.  

### 3. `popChar()` / `popInt()`
- Removes and returns the top element of the stack.  

### 4. `peekChar()`
- Returns top element of `CharStack` without removing it.  

### 5. `precedence(char op)`
- Returns operator precedence: `^ = 3`, `* / = 2`, `+ - = 1`.  

### 6. `infixToPostfix(char infix[], char postfix[])`
- Converts infix to postfix using stack logic:  
  - Operand → append to postfix.  
  - `'('` → push onto stack.  
  - `')'` → pop until `'('`.  
  - Operator → pop higher/equal precedence, push current.  
  - Pop remaining operators at the end.  

### 7. `evaluatePostfix(char postfix[])`
- Evaluates postfix using integer stack:  
  - Operand → push onto stack.  
  - Operator → pop two operands, apply operation, push result.  
  - Final top of stack → result.

---

## c. Algorithm

**Infix to Postfix Conversion:**

1. Initialize empty CharStack.  
2. Read infix expression character by character:  
   - Operand → add to postfix.  
   - `'('` → push.  
   - `')'` → pop until `'('`.  
   - Operator → pop operators with higher/equal precedence, push current.  
3. Pop any remaining operators and append to postfix.

**Postfix Evaluation:**

1. Initialize empty IntStack.  
2. Read postfix expression character by character:  
   - Operand → push to stack.  
   - Operator → pop two operands, compute result, push back.  
3. Final value on stack → evaluated result.

---

## d. Overview of `main()`
1. Declare `infix` and `postfix` arrays.  
2. Ask user to enter infix expression.  
3. Call `infixToPostfix()` to convert expression.  
4. Print postfix expression.  
5. Call `evaluatePostfix()` to compute result.  
6. Print evaluated result.
