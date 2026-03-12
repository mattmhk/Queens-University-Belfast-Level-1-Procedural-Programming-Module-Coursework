#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int counts[26][26] = {{0}};  
    printf("Enter your sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int len = strlen(sentence);
    for (int i = 0; i < len - 1; i++) {
        char c1 = tolower(sentence[i]);
        char c2 = tolower(sentence[i + 1]);
        if (c1 == c2) {
            counts[c1 - 'a'][c2 - 'a']++;
        }
    }

    printf("\nDouble letter patterns and number of occurrences are:\n");
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (counts[i][j] > 0) {
                printf("%c%c : %d\n", i + 'a', j + 'a', counts[i][j]);
            }
        }
    }

    return 0;
}