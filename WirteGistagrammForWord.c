/*Пишем гистограмму длин вводимых слов*/
#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
    int c, i, nc, state;
    int wl[10]; /*wl - word lengths*/
    for (i = 0; i < 10; ++i)
        wl[i] = 0;
    state = OUT;
    nc = 0; 
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > 0 && nc < 10)
                ++wl[nc];
            nc = 0;
        }
        else
        {
            state = IN;
            ++nc;
        }
    }
    printf("\nГистограмма длин слов:\n");
    for (i = 1; i < 10; ++i)
    {
        printf("%d-буквенные: ", i);
        for (int j = 0; j < wl[i]; ++j)
            printf("*");
        printf("\n");
    }

    return 0; 
}