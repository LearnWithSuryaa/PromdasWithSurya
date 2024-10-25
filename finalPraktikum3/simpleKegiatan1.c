#include <stdio.h>

enum film
{
    SPIDERMAN,
    BATMAN,
    SUPERMAN,
    AVENGERS,
    JOKER
};

enum jenisTiket
{
    REGULER,
    VIP,
    VVIP
};

void header()
{
    printf("\n----------------------------------- Bioskop -----------------------------------\n");
}

void line()
{
    printf("\n-------------------------------------------------------------------------------\n");
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    const int hargaFilm[] = {50000, 55000, 60000, 70000, 45000};
    const int hargaTiket[] = {30000, 100000, 150000};
    int pilihanFilm, pilihanTiket, member, hari;
    float totalHarga, pembayaran, kembalian, diskonMember = 0.10, diskonWeekday = 0.15;

    header();

    while (1)
    {
        printf("Pilih film:\n1. Spiderman - Rp.%d\n2. Batman - Rp.%d\n3. Superman - Rp.%d\n4. Avengers - Rp.%d\n5. Joker - Rp.%d\n",
               hargaFilm[0], hargaFilm[1], hargaFilm[2], hargaFilm[3], hargaFilm[4]);
        printf("Masukkan pilihan Anda (1-5): ");

        if (scanf("%d", &pilihanFilm) != 1)
        {
            printf("Inputan tidak valid. Harap masukkan angka dari 1 sampai 5!\n");
            clearInputBuffer();
            continue;
        }

        if (pilihanFilm < 1 || pilihanFilm > 5)
        {
            printf("Inputan tidak valid. Harap masukkan angka dari 1 sampai 5!\n");
        }
        else
        {
            break;
        }
    }
    line();
    while (1)
    {
        printf("Pilih jenis tiket:\n1. Reguler - Rp%d\n2. VIP - Rp%d\n3. VVIP - Rp%d\n",
               hargaTiket[0], hargaTiket[1], hargaTiket[2]);
        printf("Masukkan pilihan Anda (1-3): ");

        if (scanf("%d", &pilihanTiket) != 1)
        {
            printf("Inputan tidak valid. Harap pilih angka dari 1 sampai 3!\n");
            clearInputBuffer();
            continue;
        }

        if (pilihanTiket < 1 || pilihanTiket > 3)
        {
            printf("Inputan tidak valid. Harap pilih angka dari 1 sampai 3!\n");
        }
        else
        {
            break;
        }
    }
    line();
    while (1)
    {
        printf("Pilih hari:\n1. Weekday (diskon 15%%)\n2. Weekend (Harga normal)\n");
        printf("Masukkan Pilihan Anda (1-2): ");

        if (scanf("%d", &hari) != 1)
        {
            printf("Inputan tidak valid. Harap pilih angka dari 1 atau 2!\n");
            clearInputBuffer();
            continue;
        }

        if (hari != 1 && hari != 2)
        {
            printf("Inputan tidak valid. Harap pilih angka dari 1 atau 2!\n");
        }
        else
        {
            break;
        }
    }
    line();
    while (1)
    {
        printf("Apakah Anda member? (1 untuk Ya, 0 untuk Tidak): ");
        if (scanf("%d", &member) != 1)
        {
            printf("Inputan tidak valid. Harap masukkan 1 (Ya) atau 0 (Tidak).\n");
            clearInputBuffer();
            continue;
        }

        if (member != 1 && member != 0)
        {
            printf("Inputan tidak valid. Harap masukkan 1 (Ya) atau 0 (Tidak).\n");
        }
        else
        {
            break;
        }
    }
    line();
    
    // Menghitung total harga berdasarkan pilihan film dan tiket
    totalHarga = hargaTiket[pilihanTiket-1] + hargaFilm[pilihanFilm-1];

    // Diskon weekday
    if (hari == 1)
    {
        totalHarga -= totalHarga * diskonWeekday;
        printf("Diskon weekday 15%% diterapkan!\n");
    }

    // Diskon member
    if (member == 1)
    {
        totalHarga -= totalHarga * diskonMember;
        printf("Diskon member 10%% diterapkan!\n");
    }

    printf("Total harga: Rp. %.2f\n", totalHarga);

    do
    {
        printf("Masukkan jumlah uang yang dibayarkan: ");
        if (scanf("%f", &pembayaran) != 1)
        {
            printf("Inputan tidak valid! Harap masukkan jumlah uang yang benar.\n");
            clearInputBuffer();
            continue;
        }

        if (pembayaran < totalHarga)
        {
            printf("Uang yang Anda masukkan kurang! Silahkan masukkan sesuai nominal.\n");
        }
    } while (pembayaran < totalHarga);
    line();
    if (pembayaran > totalHarga)
    {
        kembalian = pembayaran - totalHarga;
        printf("Kembalian Anda: Rp. %.2f\n", kembalian);
    }
    else
    {
        printf("Terima kasih, pembayaran Anda sudah pas.\n");
    }
    line();
    return 0;
}