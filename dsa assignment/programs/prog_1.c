#include <stdio.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char value) {
    if (top < MAX - 1) stack[++top] = value;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int balance(char exp[]) {
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0;
            char open = pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf(" %[^\n]", exp);  // <-- FIXED: read full line including spaces

    if (balance(exp))
        printf("The parentheses are balanced\n");
    else
        printf("The parentheses are not balanced\n");

    return 0;
}
