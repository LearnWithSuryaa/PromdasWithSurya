#include <stdio.h>
#include <ctype.h>
#include "utility.h"

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void cetakGaris(const char *warna, const char *karakter, int panjang)
{
    printf("%s", warna);
    for (int i = 0; i < panjang; i++)
    {
        printf("%s", karakter);
    }
    printf("%s\n", RESET);
}

void cetakHeader(const char *judul)
{
    cetakGaris(BIRU, "=", 76);
    printf("%s%s%-40s%s\n", CYAN, TEBAL, judul, RESET);
    cetakGaris(BIRU, "=", 76);
}

int validasiNama(const char *nama)
{
    for (int i = 0; nama[i] != '\0'; i++)
    {
        if (!isalpha(nama[i]) && nama[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}
