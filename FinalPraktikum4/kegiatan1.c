#include <stdio.h>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    int bilangan, choice, jumlah, total;

    do
    {
        jumlah = 0;
        total = 0;

        printf("\nMasukkan transaksi selanjutnya (gunakan 0 untuk menyelesaikan):\n");
        while (1)
        {
            if (scanf("%d", &bilangan) != 1)
            {
                printf(RED "\nInputan tidak valid. Mohon masukkan angka\n" RESET);
                clearInputBuffer();
                continue;
            }

            if (bilangan <= 0)
            {
                break;
            }

            total += bilangan;
            jumlah++;
        }

        if (total > 0)
        {
            printf(GREEN "\nTotal dari transaksi tersebut adalah: %d\n\n" RESET, total);
        }
        else
        {
            printf(RED "Mohon maaf. Tidak ada bilangan yang dijumlahkan\n" RESET);
        }

        printf("Apakah Anda ingin mencatat transaksi lagi (1=Ya, 0=Tidak): ");
        while (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1))
        {
            printf(RED "\nInput tidak valid. Mohon masukkan angka 1 atau 0!\n\n" RESET);
            clearInputBuffer();
            printf("Apakah Anda ingin mencatat transaksi lagi (1=Ya, 0=Tidak): ");
        }
    } while (choice == 1);

    printf(GREEN "\nTerima kasih telah menggunakan program ini!\n" RESET);

    return 0;
}
