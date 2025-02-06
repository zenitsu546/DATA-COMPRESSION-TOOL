#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100

char keywords[][10] = {"int", "float", "if", "else", "while", "return"};

int isKeyword(char* str) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char c) {
    char operators[] = "+-*/%=";
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char* str) {
    if (isalpha(str[0]) || str[0] == '_') {
        for (int i = 1; i < strlen(str); i++) {
            if (!isalnum(str[i]) && str[i] != '_') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void analyze(char* str) {
    char token[MAX_TOKEN_SIZE];
    int j = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i]) || isOperator(str[i])) {
            if (j > 0) {
                token[j] = '\0';
                if (isKeyword(token)) {
                    printf("Keyword: %s\n", token);
                } else if (isIdentifier(token)) {
                    printf("Identifier: %s\n", token);
                }
                j = 0;
            }
            if (isOperator(str[i])) {
                printf("Operator: %c\n", str[i]);
            }
        } else {
            token[j++] = str[i];
        }
    }
    if (j > 0) {
        token[j] = '\0';
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isIdentifier(token)) {
            printf("Identifier: %s\n", token);
        }
    }
}

int main() {
    char code[] = "int x = 10; if (x > 5) { return x; }";

    printf("Lexical Analysis of the Code:\n");
    analyze(code);

    return 0;
}
