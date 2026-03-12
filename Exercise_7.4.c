#include <stdio.h>
#include <string.h>

int main()
{
    char text[] = "The licenses for most software are designed to take away your freedom to share and change it";
    for (int i = 0; i < strlen(text) - 1; i++){
        if (text[i] == ' '){
            text[i] = '_';
        }
    }
    printf("%s\n", text);
}
