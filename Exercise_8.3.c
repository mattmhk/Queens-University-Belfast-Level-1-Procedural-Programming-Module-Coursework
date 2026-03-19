#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* titleFormat(char sentence[])
{
    sentence[0] = toupper(sentence[0]);

    for (int i = 0; i < strlen(sentence) - 1; i++){
        if (isspace(sentence[i])){
            sentence[i+1] = toupper(sentence[i+1]);
        }
    }
    return sentence;
}

int main()
{
    char sentence[1000];
    printf("Enter you sentence : ");
    scanf(" %[^\n]", sentence);

    titleFormat(sentence);

    printf("%s\n", sentence);
}