#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char c;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {  
            postfix[j++] = c;     // operand -> add to postfix
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (stack[top] != '(')  
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}