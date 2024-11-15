#include <stdio.h>
#include <string.h>
#include "fungsi.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#define MAX_TRANSAKSI 100

int riwayat[MAX_TRANSAKSI] = {0};
int indexRiwayat = 0;
int totalKeseluruhan = 0;
int jumlahTransaksi = 0;
int batasMin = 1, batasMax = 10000;
int modeBerkala = 0;

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void formatRupiah(int harga)
{
    int bagianUtama = harga;
    char buffer[50], formatted[50] = "";
    int len, count = 0;

    sprintf(buffer, "%d", bagianUtama);
    len = strlen(buffer);

    for (int i = len - 1; i >= 0; i--)
    {
        formatted[count++] = buffer[i];
        if ((len - i) % 3 == 0 && i != 0)
        {
            formatted[count++] = '.';
        }
    }

    for (int i = 0; i < count / 2; i++)
    {
        char temp = formatted[i];
        formatted[i] = formatted[count - i - 1];
        formatted[count - i - 1] = temp;
    }
    printf("Rp%s", formatted);
}

void tampilkanMenu()
{
    printf(GREEN "\n===== MENU PILIHAN FITUR =====\n" RESET);
    printf(BLUE "1. Tambah transaksi\n");
    printf("2. Lihat riwayat transaksi\n");
    printf("3. Hitung rata-rata transaksi\n");
    printf("4. Atur batasan nilai transaksi\n");
    printf("5. Tampilkan total sementara\n");
    printf("6. Tampilkan jumlah transaksi\n");
    printf("7. Reset riwayat transaksi\n");
    printf("0. Keluar\n" RESET);
    printf("Pilih fitur dengan memasukkan angka: ");
}

void tambahTransaksi()
{
    int bilangan, total = 0, jumlah = 0;

    printf("\nMasukkan transaksi (gunakan 0 untuk menyelesaikan):\n");
    while (1)
    {
        if (scanf("%d", &bilangan) != 1)
        {
            printf(RED "\nInput tidak valid. Mohon masukkan angka\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (bilangan == 0)
            break;

        if (bilangan < batasMin || bilangan > batasMax)
        {
            printf(RED "Nilai transaksi harus antara %d dan %d.\n" RESET, batasMin, batasMax);
            continue;
        }

        total += bilangan;
        jumlah++;
    }

    if (total > 0 && indexRiwayat < MAX_TRANSAKSI)
    {
        riwayat[indexRiwayat++] = total;
        totalKeseluruhan += total;
        jumlahTransaksi++;
        printf(GREEN "Transaksi berhasil dicatat.\n" RESET);
    }
    else if (total == 0)
    {
        printf(RED "Tidak ada transaksi yang dicatat.\n" RESET);
    }
    else
    {
        printf(RED "Riwayat transaksi penuh. Tidak bisa menambah transaksi baru.\n" RESET);
    }
}

void lihatRiwayatTransaksi()
{
    printf(GREEN "\nRiwayat Transaksi:\n" RESET);
    if (indexRiwayat > 0)
    {
        for (int i = 0; i < indexRiwayat; i++)
        {
            printf(BLUE "Transaksi %d: ", i + 1);
            formatRupiah(riwayat[i]);
            printf("\n" RESET);
        }
    }
    else
    {
        printf(RED "Tidak ada transaksi yang dicatat.\n" RESET);
    }
}

void hitungRataRataTransaksi()
{
    if (jumlahTransaksi > 0)
    {
        printf(GREEN "\nRata-rata transaksi: ");
        formatRupiah(totalKeseluruhan / jumlahTransaksi);
        printf("\n" RESET);
    }
    else
    {
        printf(RED "\nTidak ada transaksi yang dicatat.\n" RESET);
    }
}

void aturBatasTransaksi()
{
    printf(GREEN "Masukkan batas bawah transaksi: " RESET);
    scanf("%d", &batasMin);
    printf(GREEN "Masukkan batas atas transaksi: " RESET);
    scanf("%d", &batasMax);
    printf(GREEN "Batas transaksi diatur antara %d dan %d.\n" RESET, batasMin, batasMax);
}

void tampilkanTotalSementara()
{
    printf(GREEN "\nTotal transaksi sementara: ");
    formatRupiah(totalKeseluruhan);
    printf(" dari %d transaksi\n" RESET, jumlahTransaksi);
}

void tampilkanJumlahTransaksi()
{
    printf(GREEN "\nJumlah transaksi yang dicatat: %d\n" RESET, jumlahTransaksi);
}

void resetRiwayatTransaksi()
{
    indexRiwayat = 0;
    totalKeseluruhan = 0;
    jumlahTransaksi = 0;
    printf(GREEN "\nRiwayat transaksi berhasil direset.\n" RESET);
}
