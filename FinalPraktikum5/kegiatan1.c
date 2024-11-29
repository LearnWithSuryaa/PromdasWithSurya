#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKSIMAL_BUAH 10 
#define MAKSIMAL_NAMA_BUAH 20

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define KUNING "\033[33m"
#define CYAN "\033[36m"
#define BIRU "\033[34m"

void cetakGaris(const char *warna) {
    printf("%s===============================================================%s\n", warna, RESET);
}

int validasiNamaBuah(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            return 0; 
        }
    }
    return 1;
}

int validasiAngka(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1;
}

void urutkanNamaBuah(char **namaBuah, int jumlah) {
    char sementara[MAKSIMAL_NAMA_BUAH];
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (strcmp(namaBuah[i], namaBuah[j]) > 0) {
                strcpy(sementara, namaBuah[i]);
                strcpy(namaBuah[i], namaBuah[j]);
                strcpy(namaBuah[j], sementara);
            }
        }
    }
}

int main() {
    int jumlahBuah;
    char input[10]; 

    cetakGaris(HIJAU);
    printf(HIJAU "            Selamat datang di Program Input Buah!\n" RESET);
    cetakGaris(HIJAU);

    while (1) {
        printf(KUNING "Berapa banyak buah yang ingin Anda masukkan? (maksimal %d): " RESET, MAKSIMAL_BUAH);
        scanf("%s", input);

        if (validasiAngka(input)) {
            jumlahBuah = atoi(input);
            if (jumlahBuah > MAKSIMAL_BUAH) {
                cetakGaris(MERAH);
                printf(MERAH "PERINGATAN: Anda hanya dapat memasukkan maksimal %d buah.\n" RESET, MAKSIMAL_BUAH);
                jumlahBuah = MAKSIMAL_BUAH;
                break;
            } else if (jumlahBuah <= 0) {
                cetakGaris(MERAH);
                printf(MERAH "PERINGATAN: Jumlah buah harus lebih dari 0.\n" RESET);
            } else {
                break;
            }
        } else {
            cetakGaris(MERAH);
            printf(MERAH "ERROR: Masukkan angka yang valid!\n\a" RESET);
            cetakGaris(MERAH);
        }
    }

    char **namaBuah = (char **)malloc(jumlahBuah * sizeof(char *));
    
    cetakGaris(CYAN);
    printf(CYAN "Silakan masukkan nama buah:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        namaBuah[i] = (char *)malloc(MAKSIMAL_NAMA_BUAH * sizeof(char)); 

        while (1) {
            printf(BIRU "  - Nama buah ke-%d: " RESET, i + 1);
            scanf(" %s", namaBuah[i]);

            if (strlen(namaBuah[i]) == 0) {
                printf(MERAH "  ERROR: Nama buah tidak boleh kosong!\n" RESET);
            } else if (strlen(namaBuah[i]) > MAKSIMAL_NAMA_BUAH - 1) {
                printf(MERAH "  ERROR: Nama buah terlalu panjang (maksimal %d karakter)!\n" RESET, MAKSIMAL_NAMA_BUAH - 1);
            } else if (!validasiNamaBuah(namaBuah[i])) {
                printf(MERAH "  ERROR: Nama buah hanya boleh berisi huruf dan spasi!\n" RESET);
            } else {
                break; 
            }
        }
    }

    cetakGaris(HIJAU);
    printf(HIJAU "Berikut daftar buah yang Anda masukkan:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        printf(KUNING "  %d. %s\n" RESET, i + 1, namaBuah[i]);
    }

    urutkanNamaBuah(namaBuah, jumlahBuah);

    cetakGaris(CYAN);
    printf(CYAN "Nama buah dalam urutan abjad:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        printf(KUNING "  %d. %s\n" RESET, i + 1, namaBuah[i]);
        free(namaBuah[i]);
    }

    cetakGaris(HIJAU);
    printf(HIJAU "         Terima kasih telah menggunakan program ini!\n" RESET);
    cetakGaris(HIJAU);

    free(namaBuah); 

    return 0;
}
