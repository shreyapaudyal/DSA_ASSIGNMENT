#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

typedef struct {
    char data[MAX];
    int top;
} CharStack;

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void initCharStack(CharStack *s) { s->top = -1; }
void initIntStack(IntStack *s) { s->top = -1; }

void pushChar(CharStack *s, char x) { s->data[++s->top] = x; }
char popChar(CharStack *s) { return s->data[s->top--]; }
char peekChar(CharStack *s) { return s->data[s->top]; }

void pushInt(IntStack *s, int x) { s->data[++s->top] = x; }
int popInt(IntStack *s) { return s->data[s->top--]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    CharStack s;
    initCharStack(&s);

    int i = 0, k = 0;

    while (infix[i] != '\0') {

        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            pushChar(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (peekChar(&s) != '(')
                postfix[k++] = popChar(&s);
            popChar(&s);
        }
        else {
            while (s.top != -1 &&
                  (precedence(peekChar(&s)) > precedence(infix[i]) ||
                  (precedence(peekChar(&s)) == precedence(infix[i]) && infix[i] != '^'))) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, infix[i]);
        }
        i++;
    }

    while (s.top != -1)
        postfix[k++] = popChar(&s);

    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[]) {
    IntStack s;
    initIntStack(&s);

    int i = 0;

    while (postfix[i] != '\0') {

        if (postfix[i] >= '0' && postfix[i] <= '9') {
            pushInt(&s, postfix[i] - '0');
        }
        else {
            int b = popInt(&s);
            int a = popInt(&s);

            if (postfix[i] == '+') pushInt(&s, a + b);
            else if (postfix[i] == '-') pushInt(&s, a - b);
            else if (postfix[i] == '*') pushInt(&s, a * b);
            else if (postfix[i] == '/') pushInt(&s, a / b);
            else if (postfix[i] == '^') pushInt(&s, (int)pow(a, b));
        }
        i++;
    }
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Evaluated result: %d\n", evaluatePostfix(postfix));

    return 0;
}