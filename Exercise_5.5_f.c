#include <stdio.h>

int main() {
    double fact = 1;
    double prev = 1;
    int n = 1;

    while (1) {
        n++;
        fact = fact * n;

        if (fact <= prev)
            break;

        prev = fact;
    }

    printf("Largest n for int: %d\n", n - 1);
    return 0;
}