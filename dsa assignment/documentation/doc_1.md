# Checking Balanced Parentheses Using Stack in C

## a. How the data structures are defined
A stack data structure is used to check whether the parentheses in an expression are balanced.  
The stack is implemented using a character array, where each element stores an opening bracket such as `(`, `{`, or `[`.

### Explanation
- `stack[MAX]` is used to store the brackets.  
- `top` keeps track of the current top position of the stack.  
- When `top = -1`, the stack is empty.  
- The stack works on the **First In, Last Out (FILO)** principle.

---

## b. Description of the functions used

### 1. `push(char value)`
- Inserts an opening bracket into the stack.  
- Checks if the stack is full before adding.  

### 2. `pop()`
- Removes and returns the top element from the stack.  
- Checks if the stack is empty before removing.  

### 3. `balance(char exp[])`
- Main function to check balanced parentheses:  
  - Scans the expression one character at a time.  
  - Pushes opening brackets onto the stack.  
  - Pops from the stack when a closing bracket appears and checks for a match.  
  - Returns `0` if unbalanced; otherwise, balanced if stack is empty at the end.

---

## c. Algorithm

**Step-by-step process:**

1. Initialize an empty stack (`top = -1`).  
2. Read the expression character by character:  
   - If opening bracket (`(`, `{`, `[`) → push onto stack.  
   - If closing bracket (`)`, `}`, `]`) → pop from stack and check if it matches the corresponding opening bracket.  
     - If mismatch or stack is empty → expression is unbalanced.  
3. After scanning the expression:  
   - If stack is empty → expression is balanced.  
   - If stack is not empty → expression is unbalanced.

---

## d. Overview of `main()`
1. Declare a character array to store the input expression.  
2. Ask the user to enter the expression.  
3. Call the `balance()` function to check parentheses.  
4. Display the result based on the returned value.
