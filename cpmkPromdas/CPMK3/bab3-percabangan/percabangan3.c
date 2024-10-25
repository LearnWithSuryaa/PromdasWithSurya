#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void cetakNamaBulan(int bulan)
{
    switch (bulan)
    {
    case 1:
        printf("Januari");
        break;
    case 2:
        printf("Februari");
        break;
    case 3:
        printf("Maret");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("Mei");
        break;
    case 6:
        printf("Juni");
        break;
    case 7:
        printf("Juli");
        break;
    case 8:
        printf("Agustus");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("Oktober");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("Desember");
        break;
    default:
        printf("Bulan tidak valid");
        break;
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

bool validasiJam(int jam, int menit, int detik, const char *period)
{
    if (jam < 0 || jam > 23)
    {
        return false;
    }

    if (menit < 0 || menit > 59)
    {
        return false;
    }

    if (detik < 0 || detik > 59)
    {
        return false;
    }

    if (strcmp(period, "PM") == 0 && jam < 12)
    {
        jam += 12;
    }
    else if (strcmp(period, "AM") == 0 && jam == 12)
    {
        jam = 0;
    }

    if (jam < 0 || jam > 23)
    {
        return false;
    }

    return true;
}

void bersihkanBufferInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// program input tanggal sesuai format (DD-MM-YYYY)
/*int main() {
    int hari, bulan, tahun;
    char input[100];
    char choice;
    bool valid = false;

    do {
        do {
            printf("\nMasukkan tanggal (format DD-MM-YYYY): ");
            fgets(input, sizeof(input), stdin);

            if (sscanf(input, "%d-%d-%d", &hari, &bulan, &tahun) == 3) {
                if (tahun >= 1000 && tahun <= 9999) {
                    if (validasiTanggal(hari, bulan, tahun)) {
                        valid = true;
                    } else {
                        printf(RED "\nTanggal tidak valid!\n" RESET);
                        valid = false;
                    }
                } else {
                    printf(RED "\nTahun harus dalam format YYYY!\n" RESET);
                    valid = false;
                }
            } else {
                printf(RED "\nInput tidak valid! Pastikan menggunakan format DD-MM-YYYY.\n" RESET);
                valid = false;
            }

        } while (!valid);
        printf(BLUE "\n%d ", hari);
        cetakNamaBulan(bulan);
        printf(" %d\n" RESET, tahun);

        bool pilihanValid = false;
        do {
            printf("\nApakah Anda ingin mengulang program? (y/n): ");
            scanf(" %c", &choice);

            bersihkanBufferInput();

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                pilihanValid = true;
            } else {
                printf(RED "Input tidak valid! Masukkan 'y' untuk ya atau 'n' untuk tidak.\n" RESET);
            }

        } while (!pilihanValid);

    } while (choice == 'y' || choice == 'Y');

    printf(GREEN "Program selesai.\n" RESET);

    return 0;
}*/

// program menentukan kelipatan 4 dan 5
/*int main()
{
    int angka, attempt = 0;

    while (1)
    {
        printf("Masukkan 4 digit angka: ");
        scanf("%d", &angka);

        if (angka < 1000 || angka > 9999)
        {
            attempt++;
            if (attempt == 2)
            {
                printf(RED "\nMasukkan 4 Digit Angka!!\n\n" RESET);
            }
            else
            {
                printf(RED "\nAngka tidak valid.\n\n" RESET);
            }
        }
        else
        {
            if (angka % 4 == 0 && angka % 5 == 0)
            {
                printf(GREEN "\nAngka valid.\n\n" RESET);
            }
            else
            {
                printf(RED "\nAngka tidak valid karena tidak habis dibagi 4 dan 5.\n\n" RESET);
            }
            break;
        }
    }
    return 0;
}*/

// program input jam sesuai format
/*int main()
{
    int jam, menit, detik;
    char input[20], period[3], choice;
    bool valid = false;

    do
    {
        do
        {
            printf("Masukkan Jam (format JJ:MM:DD AM/PM): ");
            fgets(input, sizeof(input), stdin);

            if (sscanf(input, "%d:%d:%d %2s", &jam, &menit, &detik, period) == 4)
            {
                if (strcasecmp(period, "AM") != 0 && strcasecmp(period, "PM") != 0)
                {
                    printf(RED "\nINPUT TIDAK VALID: Periode harus AM atau PM!\n\n" RESET);
                    valid = false;
                }

                else if (validasiJam(jam, menit, detik, period))
                {
                    valid = true;
                    printf(GREEN "\n%02d:%02d:%02d %s\n" RESET, jam, menit, detik, period);
                }
                else
                {
                    printf(RED "\nINPUT TIDAK VALID: jam, menit, detik, atau periode salah!\n\n" RESET);
                }
            }
            else
            {
                printf(RED "\nPastikan input dalam format JJ:MM:DD AM/PM!\n\n" RESET);
            }
        } while (!valid);

        bool pilihanValid = false;
        do
        {
            printf("\nApakah Anda ingin mengulang program? (y/n): ");
            scanf(" %c", &choice);

            bersihkanBufferInput();

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                pilihanValid = true;
            }
            else
            {
                printf(RED "\nInput tidak valid! Masukkan 'y' untuk ya atau 'n' untuk tidak.\n" RESET);
            }

        } while (!pilihanValid);
    } while (choice == 'y' || choice == 'Y');
    printf(GREEN "Program selesai.\n" RESET);
    return 0;
}*/

// program menghitung harga barang
/*int main()
{
    int harga1, harga2, harga3;
    float total, diskon;
    int validInput;

    do
    {
        printf("\nMasukkan harga barang pertama: ");
        validInput = scanf("%d", &harga1);
        bersihkanBufferInput();

        if (!validInput)
        {
            printf(RED "\nInputan tidak valid. Harap masukkan angka yang benar!\n" RESET);
        }
    } while (!validInput);

    do
    {
        validInput = 0;
        printf("Masukkan harga barang kedua: ");
        validInput = scanf("%d", &harga2);
        bersihkanBufferInput();

        if (!validInput)
        {
            printf(RED "\nInputan tidak valid. Harap masukkan angka yang benar!\n\n" RESET);
        }
    } while (!validInput);

    do
    {
        validInput = 0;
        printf("Masukkan harga barang ketiga: ");
        validInput = scanf("%d", &harga3);
        bersihkanBufferInput();

        if (!validInput)
        {
            printf(RED "\nInputan tidak valid. Harap masukkan angka yang benar!\n\n" RESET);
        }
    } while (!validInput);

    total = harga1 + harga2 + harga3;

    if (total > 100000)
    {
        diskon = total * 0.10;
        total -= diskon;
        printf(GREEN "\nAnda mendapatkan diskon 10%%!" RESET);
    }
    else
    {
        printf(RED "\nAnda tidak mendapatkan diskon.\n" RESET);
    }

    printf(GREEN "\nTotal harga yang harus dibayarkan: %.2f\n\n" RESET, total);

    return 0;
}*/

// program validasi input user
/*int main()
{
    char code[5];
    while (1)
    {
        printf("\nMasukkan 4 karakter: ");
        scanf("%4s", code);

        if (strcasecmp(code, "abcd") == 0)
        {
            printf(GREEN "Succsessfull process\n" RESET);
            break;
        }
        else
        {
            printf(RED "Masukkan kode lagi!" RESET);
            continue;
        }
    }
    return 0;
}*/

// program validasi input
/*int main()
{
    char code[4]; //buffer 4 menyediakan kapasitas untuk new line dan null terminator
    while (1)
    {
        printf("\nMasukkan 2 karakter: ");
        fgets(code, sizeof(code), stdin);

        if (code[strlen(code) - 1] != '\n')//memastikan inputan hanya 2 karakter
        {
            printf(RED "\nInput terlalu panjang. Masukkan maksimal 2 karakter!\n" RESET);
            bersihkanBufferInput();
            continue;
        }

        code[strcspn(code, "\n")] = '\0';

        if (strcasecmp(code, "AB") == 0 || strcasecmp(code, "BA") == 0)
        {
            printf(GREEN "Silahkan Masuk.\n" RESET);
            break;
        }
        else
        {
            printf(RED "\nIdentifikasi gagal. Harap masukkan ulang kode!\n" RESET);
            continue;
        }
    }
    return 0;
}*/

//program validasi 2 input
int hanyaHuruf(char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isalpha(input[i]))
        {
            return 0; 
        }
    }
    return 1;
}

int main()
{
    char input1[4], input2[4];// menambahkan space untuk new line dan null terminator
    int validInput1 = 0, validInput2 = 0;//variabel untuk looping

    while (1)
    {
        while (!validInput1)
        {
            printf("\nMasukkan input pertama (maksimal 2 huruf): ");
            fgets(input1, sizeof(input1), stdin);

            if (input1[strlen(input1) - 1] != '\n')
            {
                printf(RED "Input terlalu panjang. Masukkan maksimal 2 huruf!" RESET);
                bersihkanBufferInput();
                continue;
            }

            input1[strcspn(input1, "\n")] = '\0';

            if (!hanyaHuruf(input1))
            {
                printf(RED "Input tidak valid. Harus berupa huruf saja!" RESET);
            }
            else
            {
                validInput1 = 1;
            }
        }

        while (!validInput2)
        {
            printf("Masukkan input kedua (maksimal 2 huruf): ");
            fgets(input2, sizeof(input2), stdin);

            if (input2[strlen(input2) - 1] != '\n')
            {
                printf(RED "Input terlalu panjang. Masukkan maksimal 2 huruf!" RESET);
                bersihkanBufferInput();
                continue;
            }

            input2[strcspn(input2, "\n")] = '\0';

            if (!hanyaHuruf(input2))
            {
                printf(RED "Input tidak valid. Harus berupa huruf saja!" RESET);
            }
            else
            {
                validInput2 = 1;
            }
        }

        // Memeriksa apakah kedua input bernilai sama (case-insensitive)
        if (strcasecmp(input1, input2) == 0)
        {
            printf(GREEN "Dikenali\n\n" RESET);
        }
        else
        {
            printf(RED "Tidak dikenali\n\n" RESET);
        }

        break; // Mengakhiri program setelah proses selesai
    }

    return 0;
}