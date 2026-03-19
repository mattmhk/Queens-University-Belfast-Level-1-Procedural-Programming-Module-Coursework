#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OPERANDS 10

int main() {
    char line[256];
    char command[10];
    char *token;
    int operands[MAX_OPERANDS];
    int count = 0;

    printf("Enter your command (sum/multiply) and numeric values:\n");

    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("Input error\n");
        return 1;
    }

    token = strtok(line, " \n");
    if (token == NULL) {
        printf("No command entered\n");
        return 1;
    }
    strcpy(command, token);

    count = 0;
    while ((token = strtok(NULL, " \n")) != NULL && count < MAX_OPERANDS) {
        int val = atoi(token);
        if (val < -999 || val > 999) {
            printf("Operand %d (%d) out of range [-999, 999]\n", count+1, val);
            return 1;
        }
        operands[count++] = val;
    }

    if (count == 0) {
        printf("No operands provided\n");
        return 1;
    }

    if (strcmp(command, "sum") == 0) {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += operands[i];
        }
        printf("sum");
        for (int i = 0; i < count; i++) {
            printf(" %d", operands[i]);
        }
        printf(" = %d\n", sum);
    } else if (strcmp(command, "multiply") == 0) {
        int product = 1;
        for (int i = 0; i < count; i++) {
            product *= operands[i];
        }
        printf("multiply");
        for (int i = 0; i < count; i++) {
            printf(" %d", operands[i]);
        }
        printf(" = %d\n", product);
    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}