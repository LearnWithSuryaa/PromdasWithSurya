#include <stdio.h>

#define HARGA_NORMAL 1000000

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void formatRupiah(long harga)
{
    if (harga >= 1000)
    {
        formatRupiah(harga / 1000);
        printf(BLUE ".%03ld" RESET, harga % 1000);
    }
    else
    {
        printf(BLUE "%ld" RESET, harga);
    }
}

void bersihkanBufferInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    int umur;
    float hargaTiket = 1, diskon = 1.0;

    while (1)
    {
        printf("Masukkan umur penumpang: ");

        if (scanf("%d", &umur) != 1 || umur < 0 || umur > 120)
        {
            bersihkanBufferInput();
            printf(RED "ERROR: Masukkan umur yang valid.\n" RESET);
        }
        else
        {
            printf("Umur yang dimasukkan: %d\n", umur);
            break;
        }
    }

    if (umur >= 0 && umur <= 120)
    {
        if (umur < 2)
        {
            hargaTiket = 0;
            printf(GREEN "Penumpang mendapatkan tiket gratis.\n" RESET);
        }
        else if (umur >= 2 && umur <= 12)
        {
            diskon = 0.5;
        }
        else if (umur > 12 && umur <= 60)
        {
            diskon = 1.0;
        }
        else
        {
            diskon = 0.75;
        }
        if (hargaTiket != 0)
        {
            hargaTiket = HARGA_NORMAL * diskon;
            printf(BLUE "Harga tiket setelah diskon adalah: Rp." RESET);
            formatRupiah((long)hargaTiket);
            printf("\n");
        }
    }
    else
    {
        printf(RED "Input tidak valid. Umur harus berada dalam rentang 0 hingga 120.\n" RESET);
    }

    return 0;
}