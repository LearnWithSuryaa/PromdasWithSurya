#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main()
{
    char str[100];
    int i, j, unik, valid;

    do
    {
        printf("\nMasukkan sebuah string (tanpa angka): ");
        fgets(str, sizeof(str), stdin);

        valid = 1;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (isdigit(str[i]))
            {
                printf(RED "\nError: Input tidak boleh mengandung angka.\n\n" RESET);
                valid = 0;
                break;
            }
        }
    } while (!valid);

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