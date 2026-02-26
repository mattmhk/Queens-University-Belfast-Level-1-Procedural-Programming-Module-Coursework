#include <stdio.h>
main()
{
    int numchar = 0;
    while (getchar()!='\n') numchar++;
    printf("\n\nLength of text is %d characters\n",numchar);
}
