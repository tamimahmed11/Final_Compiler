#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char* word) {
    const char* keywords[] = {
        "int", "float", "if", "else", "while", "for", "return", "break"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/=<>%&|!^";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) return 1;
    }
    return 0;
}

int isNumber(const char* str) {
    int dot = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            if (str[i] == '.' && dot == 0) {
                dot = 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

void analyzeToken(const char* token) {
    if (isKeyword(token)) {
        printf("Token: %s -> Keyword\n", token);
    } else if (isalpha(token[0]) || token[0] == '_') {
        printf("Token: %s -> Identifier\n", token);
    } else if (isNumber(token)) {
        printf("Token: %s -> Number\n", token);
    }
}

void analyzeLine(char* line) {
    char token[100];
    int i = 0, j = 0;
    while (line[i] != '\0') {
        if (isalpha(line[i]) || isdigit(line[i]) || line[i] == '.' || line[i] == '_') {
            token[j++] = line[i];
        } else {
            if (j > 0) {
                token[j] = '\0';
                analyzeToken(token);
                j = 0;
            }
            if (isOperator(line[i])) {
                printf("Token: %c -> Operator\n", line[i]);
            }
        }
        i++;
    }
    if (j > 0) {
        token[j] = '\0';
        analyzeToken(token);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        analyzeLine(line);
    }

    fclose(file);
    return 0;
}
