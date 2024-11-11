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
    int jumlah = 0, total = 0, bilangan;
    float rataRata;
    while (1)
    {
        printf("\nMasukkan bilangan bulat (masukkan angka negatif untuk berhenti): ");
        if (scanf("%d", &bilangan) != 1)
        {
            printf(RED "Inputan tidak valid. Mohon masukkan angka!" RESET);
            clearInputBuffer();
            continue;
        }

        if (bilangan < 0)
        {
            break;
        }

        total += bilangan;
        jumlah++;
    }

    if (jumlah > 0)
    {
        rataRata = (float)total / jumlah;
        printf(GREEN "\nTotal bilangan: %d\nRata-rata bilangan: %.2f\n\n" RESET, total, rataRata);
    }
    else
    {
        printf(RED "\nTidak ada bilangan yang dimasukkan\n\n" RESET);
    }
    
    printf("\n\n=== Code Execution Successful ===\n");
    return 0;
}