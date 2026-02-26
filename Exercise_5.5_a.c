#include <stdio.h>

int main() {
    short fact = 1;
    short prev = 1;
    int n = 1;

    while (1) {
        n++;
        fact = fact * n;

        if (fact <= prev)  // overflow happened
            break;

        prev = fact;
    }

    printf("Largest n for short: %d\n", n - 1);
    return 0;
}