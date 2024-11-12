#include <stdio.h>
#include <string.h>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main()
{
    char str[100];
    int i, j, unik, valid;

    printf("\nMasukkan sebuah string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nKarakter unik dalam string:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
            continue;

        unik = 1;

        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                unik = 0;
                break;
            }
        }

        if (unik)
        {
            printf(GREEN "%c" RESET, str[i]);
        }
    }

    printf("\n\n=== Code Execution Successful ===\n");
    return 0;
}