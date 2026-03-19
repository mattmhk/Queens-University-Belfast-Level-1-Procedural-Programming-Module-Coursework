#include <stdio.h>

int main()
{
    char Days[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; i++) {
        printf("%s\n", Days[i]);
    }
}
