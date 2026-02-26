#include <stdio.h>
int main()
{
    char alphanumeric;
    int i=0;
    printf("Enter phone number :");
    while ((alphanumeric=getchar())!='\n')
    {
        if (i==0) printf("The phone number is :");
        i++;
        switch (alphanumeric)
        {
            case 'A': case 'a': case 'B': case 'b': case 'C': case 'c':
                putchar('2');
                break;
            case 'D': case 'd': case 'E': case 'e': case 'F': case 'f':
                putchar('3');
                break;
            case 'G': case 'g': case 'H': case 'h': case 'I': case 'i':
                putchar('4');
                break;
            case 'J': case 'j': case 'K': case 'k': case 'L': case 'l':
                putchar('5');
                break;
            case 'M': case 'm': case 'N': case 'n': case 'O': case 'o':
                putchar('6');
                break;
            case 'P': case 'p': case 'Q': case 'q': case 'R': case 'r': case
            'S': case 's':
                putchar('7');
                break;
            case 'T': case 't': case 'U': case 'u': case 'V': case 'v':
                putchar('8');
                break;
            case 'W': case 'w': case 'X': case 'x': case 'Y': case 'y': case
            'Z': case 'z':
                putchar('9');
                break;
                default:
                putchar(alphanumeric);
        }
    }
}
