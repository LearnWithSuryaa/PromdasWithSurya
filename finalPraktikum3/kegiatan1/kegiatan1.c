#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

enum Film
{
    SPIDERMAN,
    BATMAN,
    SUPERMAN,
    AVENGERS,
    JOKER
};
enum JenisTiket
{
    REGULER,
    VIP,
    VVIP
};

const int hargaFilm[] = {50000, 55000, 60000, 70000, 45000};
const int hargaTiket[] = {30000, 100000, 150000};

void header()
{
    printf("\n----------------------------------- Bioskop -----------------------------------\n");
}

void line()
{
    printf("-------------------------------------------------------------------------------\n");
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

bool validasiTanggal(int hari, int bulan, int tahun)
{

    if (bulan < 1 || bulan > 12)
    {
        return false;
    }

    if (hari < 1 || hari > 31)
    {
        return false;
    }

    if ((bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) && hari > 30)
    {
        return false;
    }

    if (bulan == 2)
    {
        if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0))
        {
            if (hari > 29)
            {
                return false;
            }
        }
        else
        {
            if (hari > 28)
            {
                return false;
            }
        }
    }

    return true;
}

int hitungHariDariTanggal(int hari, int bulan, int tahun)
{
    if (bulan < 3)
    {
        bulan += 12;
        bulan -= 2;
    }

    int k = tahun % 100;
    int j = tahun / 100;

    int h = (hari + (13 * (bulan + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7; // implementasi algoritma Zeller's Congruence

    return h;
}

bool isWeekday(int h)
{
    return (h >= 2 && h <= 6);
}

int pilihFilm()
{
    int choice;
    while (1)
    {
        printf("Pilih film:\n1. Spiderman - Rp.%.0d\n2. Batman - Rp.%.0d\n3. Superman - Rp.%.0d\n4. Avengers - Rp.%.0d\n5. Joker - Rp.%.0d\n",
               hargaFilm[0], hargaFilm[BATMAN], hargaFilm[SUPERMAN], hargaFilm[AVENGERS], hargaFilm[JOKER]);
        printf("Masukkan pilihan Anda (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Inputan tidak valid. Harap masukkan angka dari 1 sampai 5!!\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (choice < 1 || choice > 5)
        {
            printf(RED "Inputan tidak valid. Harap pilih angka dari 1 sampai 5!!\n" RESET);
        }
        else
        {
            break;
        }
    }
    return choice - 1;
}

int pilihTiket()
{
    int choice;
    while (1)
    {
        printf("Pilih jenis tiket:\n1. Reguler - Rp.%.0d\n2. VIP - Rp.%.0d\n3. VVIP - Rp.%.0d\n",
               hargaTiket[REGULER], hargaTiket[VIP], hargaTiket[VVIP]);
        printf("Masukkan pilihan Anda (1-3): ");

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Inputan tidak valid. Harap pilih angka dari 1 sampai 3!!\n" RESET);
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        if (choice < 1 || choice > 3)
        {
            printf(RED "Inputan tidak valid. Harap pilih angka dari 1 sampai 3!!\n" RESET);
        }
        else
        {
            break;
        }
    }
    return choice - 1;
}

int pilihMember()
{
    int member;
    while (1)
    {
        printf("Apakah Anda member? (1 untuk Ya, 0 untuk Tidak): ");

        if (scanf("%d", &member) != 1)
        {
            printf(RED "Inputan tidak valid! Harap masukkan 1 (Ya) atau 0 (Tidak).\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (member != 1 && member != 0)
        {
            printf(RED "Inputan tidak valid! Harap masukkan 1 (Ya) atau 0 (Tidak).\n" RESET);
        }
        else
        {
            break;
        }
    }
    return member;
}

float hitungTotalHarga(int pilihanFilm, int pilihanTiket)
{
    return hargaFilm[pilihanFilm] + hargaTiket[pilihanTiket];
}

// Fungsi untuk format rupiah dengan desimal dan pemisah ribuan
void formatRupiah(float harga)
{
    int bagianUtama = (int)harga;                           // Ambil bagian utama (sebelum desimal)
    int bagianDesimal = (int)((harga - bagianUtama) * 100); // Ambil bagian desimal
    char buffer[50], formatted[50] = "";                    // Buffer dan string akhir
    int len, count = 0;

    // Ubah bagian utama ke string
    sprintf(buffer, "%d", bagianUtama);
    len = strlen(buffer);

    // Tambahkan pemisah titik setiap tiga digit
    for (int i = len - 1; i >= 0; i--)
    {
        formatted[count++] = buffer[i];
        if ((len - i) % 3 == 0 && i != 0)
            formatted[count++] = '.';
    }
    formatted[count] = '\0';

    // Balik string agar benar
    for (int i = 0; i < count / 2; i++)
    {
        char temp = formatted[i];
        formatted[i] = formatted[count - i - 1];
        formatted[count - i - 1] = temp;
    }

    // Tambahkan desimal di akhir
    printf(GREEN "Rp%s,%02d" RESET, formatted, bagianDesimal);
}
 

int main()
{
    int pilihanFilm, pilihanTiket, member, hari, bulan, tahun, hariDalamMinggu;
    char input[100];
    float totalHarga, pembayaran, kembalian;
    float diskonMember = 0.10, diskonWeekday = 0.15;
    bool valid = false;

    header();
    pilihanFilm = pilihFilm();
    line();
    pilihanTiket = pilihTiket();
    line();
    do
    {
        printf("Masukkan tanggal pemesanan (format DD-MM-YYYY): ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d-%d-%d", &hari, &bulan, &tahun) == 3)
        {
            if (tahun >= 1000 && tahun <= 9999)
            {
                if (validasiTanggal(hari, bulan, tahun))
                {
                    valid = true;
                }
                else
                {
                    printf(RED "\nTanggal tidak valid!\n" RESET);
                    valid = false;
                }
            }
            else
            {
                printf(RED "\nTahun harus dalam format YYYY!\n" RESET);
                valid = false;
            }
        }
        else
        {
            printf(RED "\nInput tidak valid! Pastikan menggunakan format DD-MM-YYYY.\n" RESET);
            valid = false;
        }
    } while (!valid);

    member = pilihMember();
    line();

    hariDalamMinggu = hitungHariDariTanggal(hari, bulan, tahun);
    totalHarga = hitungTotalHarga(pilihanFilm, pilihanTiket);

    if (isWeekday(hariDalamMinggu))
    {
        totalHarga -= totalHarga * diskonWeekday;
        printf(GREEN "Diskon weekday 15%% berhasil diterapkan!\n" RESET);
    }
    else
    {
        printf(GREEN "Weekend, harga normal diterapkan!\n" RESET);
    }

    if (member == 1)
    {
        totalHarga -= totalHarga * diskonMember;
        printf(GREEN "Diskon member 10%% berhasil diterapkan!\n" RESET);
    }

    line();
    printf("Total harga: ");
    formatRupiah(totalHarga);
    printf("\n");
    printf("Alamat memori variabel total: %p\n", (void *)&totalHarga);
    line();

    // Input pembayaran
    do
    {
        printf("Masukkan jumlah uang yang dibayarkan: ");
        if (scanf("%f", &pembayaran) != 1)
        {
            printf(RED "Inputan tidak valid! Harap masukkan jumlah uang yang benar.\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (pembayaran < totalHarga)
        {
            printf(RED "Uang yang Anda masukkan kurang! Silahkan masukkan sesuai nominal" RESET);
            formatRupiah(totalHarga);
            printf("\n");
        }
    } while (pembayaran < totalHarga);
    line();

    if (pembayaran > totalHarga)
    {
        kembalian = pembayaran - totalHarga;
        printf("Kembalian Anda: ");
        formatRupiah(kembalian);
        printf("\n");
    }
    else
    {
        printf(GREEN "Terima kasih, pembayaran Anda sudah pas.\n" RESET);
    }
    line();
    return 0;
}