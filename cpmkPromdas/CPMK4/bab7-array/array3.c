// soal nomor 6 dan 7
#include <stdio.h>

void header()
{
    printf("\n------------------------------- Program Pencari Array -------------------------------\n");
    printf("Program ini akan mencari karakter yang diinputkan oleh user apakah ada di dalam string.\n\n");
}

void footer()
{
    printf("\n------------------------------ Program Selesai di Jalankan ------------------------------\n\n");
}

int main()
{
    char negara[10] = {'i', 'n', 'd', 'o', 'n', 'e', 's', 'i', 'a', '\0'}, tujuan, choice;
    int found, i, legth = sizeof(negara) / sizeof(negara[0]);

    do
    {
        header();

        for (i = 0; i < legth; i++)
        {
            printf("%c ", negara[i]);
        }

        printf("\nMasukkan huruf yang ingin dicari: ");
        scanf(" %c", &tujuan);

        found = 0;

        for (int i = 0; negara[i] != '\0'; i++)
        {
            if (negara[i] == tujuan)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("Karakter '%c' ada dalam array.\n", tujuan);
        }
        else
        {
            printf("Karakter '%c' tidak ada dalam array.\n", tujuan);
        }

        printf("\nApakah Anda Ingin Mengulang Program (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            footer();
        }

        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    return 0;
}