#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define KUNING "\033[33m"
#define CYAN "\033[36m"
#define BIRU "\033[34m"
#define TEBAL "\033[1m"

#define MAKSIMAL_BUAH 10
#define MAKSIMAL_NAMA_BUAH 50

void cetakGaris(const char *warna, const char *karakter)
{
    printf("%s", warna);
    for (int i = 0; i < 66; i++)
    {
        printf("%s", karakter);
    }
    printf("%s\n", RESET);
}

void cetakHeader(const char *judul)
{
    cetakGaris(BIRU, "=");
    printf("%s%s%-30s%s\n", CYAN, TEBAL, judul, RESET);
    cetakGaris(BIRU, "=");
}

int validasiNamaBuah(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ')
        {
            return 0; 
        }
    }
    return 1; 
}

int validasiAngka(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; 
        }
    }
    return 1; 
}

void urutkanNamaBuah(char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlah)
{
    char sementara[MAKSIMAL_NAMA_BUAH];
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if (strcmp(namaBuah[i], namaBuah[j]) > 0)
            {
                strcpy(sementara, namaBuah[i]);
                strcpy(namaBuah[i], namaBuah[j]);
                strcpy(namaBuah[j], sementara);
            }
        }
    }
}

int main()
{
    int jumlah;
    char input[10];
    int validInput = 0;

    cetakHeader("                    PROGRAM MANAJEMEN BUAH");

    while (!validInput)
    {
        printf("Masukkan jumlah nama buah yang ingin dimasukkan (maksimal %d): ", MAKSIMAL_BUAH);
        scanf("%s", input);

        if (validasiAngka(input))
        {
            jumlah = atoi(input);
            if (jumlah > 0 && jumlah <= MAKSIMAL_BUAH)
            {
                validInput = 1; 
            }
            else
            {
                printf("%sJumlah buah harus antara 1 dan %d.%s\n", MERAH, MAKSIMAL_BUAH, RESET);
            }
        }
        else
        {
            printf("%sInput tidak valid. Masukkan angka saja!%s\n", MERAH, RESET);
        }
    }

    char namaBuah[jumlah][MAKSIMAL_NAMA_BUAH];

    for (int i = 0; i < jumlah; i++)
    {
        int validNama = 0;
        while (!validNama)
        {
            printf("%sMasukkan nama buah ke-%d: %s", CYAN, i + 1, RESET);
            scanf(" %s", namaBuah[i]); 
            if (validasiNamaBuah(namaBuah[i]))
            {
                validNama = 1;
            }
            else
            {
                printf("%sNama buah hanya boleh berisi huruf dan spasi!%s\n", MERAH, RESET);
            }
        }
    }

    cetakHeader("                  NAMA BUAH SEBELUM DIURUTKAN");
    for (int i = 0; i < jumlah; i++)
    {
        printf("%s%d. %s%s%s\n", HIJAU, i + 1, KUNING, namaBuah[i], RESET);
    }

    urutkanNamaBuah(namaBuah, jumlah);

    cetakHeader("                  NAMA BUAH SETELAH DIURUTKAN");
    for (int i = 0; i < jumlah; i++)
    {
        printf("%s%d. %s%s%s\n", HIJAU, i + 1, KUNING, namaBuah[i], RESET);
    }

    cetakGaris(CYAN, "-");
    printf("%s           Terima kasih telah menggunakan program ini!%s\n", HIJAU, RESET);
    cetakGaris(CYAN, "-");

    return 0;
}
