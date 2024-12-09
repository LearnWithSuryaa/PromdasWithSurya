#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

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

int validasiNamaBuah(const char *nama)
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

void swapStrings(char *str1, char *str2)
{
    char temp[MAKSIMAL_NAMA_BUAH];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
