# Checking Balanced Parentheses Using Stack in C

## a. How the data structures are defined
A stack data structure is used to check whether the parentheses in an expression are balanced.  
The stack is implemented using a character array, where each element stores an opening bracket such as `(`, `{`, or `[`.

### Explanation
- `stack[MAX]` is used to store the brackets.
- `top` keeps track of the current top position of the stack.
- When `top` is `-1`, the stack is empty.
- The stack works on the **First In, Last Out (FILO)** principle.

---

## b. Description of the functions used

### 1. `push(char value)`
- This function inserts an opening bracket into the stack.
- It first checks whether the stack is full.
- If free space is available, the bracket is added and `top` is increased.
- This function is called whenever an opening bracket is found in the expression.

### 2. `pop()`
- This function removes and returns the top element from the stack.
- It checks whether the stack is empty.
- If the stack is not empty, the top element is removed and returned.
- This function is called when a closing bracket is found in the expression.

### 3. `balance(char exp[])`
- This is the main logic function to check balanced parentheses.
- It scans the input expression one character at a time using a loop equal to the length of the expression.
- Opening brackets are pushed onto the stack using `push()`.
- When a closing bracket appears, `pop()` removes the top element and checks for a match.
- If a mismatch is found, the function returns `0`, indicating the expression is unbalanced.
- At the end, if the stack is empty, the expression is considered balanced.

---

## c. Overview of `main()`
The `main()` function manages the overall execution of the program. It performs the following steps:

1. Declares a character array to store the input expression  
2. Asks the user to enter the expression  
3. Calls the `balance()` function to check the parentheses  
4. Displays the result based on the returned value  

