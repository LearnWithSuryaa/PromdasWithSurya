#include <stdio.h>
#include <string.h>

int main() {
    char gender[10];
    int height;
    int isAboveAverage = 0;  // Variabel untuk menentukan apakah tinggi di atas rata-rata

    // Input jenis kelamin
    printf("Masukkan jenis kelamin (Male atau Female): ");
    scanf("%s", gender);

    // Cek apakah input jenis kelamin valid
    if (strcasecmp(gender, "male") == 0 || strcasecmp(gender, "female") == 0) {
        // Input tinggi badan setelah jenis kelamin
        printf("Masukkan tinggi badan: ");
        scanf("%d", &height);

        // Proses pengecekan tinggi badan
        if (strcasecmp(gender, "male") == 0) {
            // Jika Male, cek apakah tinggi > 165
            if (height > 165) {
                isAboveAverage = 1;
            }
        } else if (strcasecmp(gender, "female") == 0) {
            // Jika Female, cek apakah tinggi > 155
            if (height > 155) {
                isAboveAverage = 1;
            }
        }

        // Tampilan akhir setelah semua input dan proses selesai
        printf("\nJenis kelamin: %s\n", gender);
        printf("Tinggi badan: %d cm\n", height);

        // Menampilkan hasil "above average" atau "average"
        if (isAboveAverage) {
            printf("Status: You are above average\n");
        } else {
            printf("Status: You are average\n");
        }

    } else {
        // Jika input jenis kelamin tidak valid
        printf("Input tidak valid\n");
    }

    return 0;
}
