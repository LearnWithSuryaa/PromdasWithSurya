#include <stdio.h>
#include "fungsi.h"

// luas lingkaran
/*int main(){
    printf("Luas Lingkaran: %.2f\n", luasLingkaran(5.0));
}*/

// menulis mundur
/*int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum dibalik: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }

    tulisMundur(arr, size);

    printf("\nArray setelah dibalik: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;
}*/

// mencari nilai terbesar
/*int main()
{
    int num1, num2, num3;

    printf("\nMasukkan angka pertama: ");
    scanf("%d", &num1);
    printf("Masukkan angka kedua: ");
    scanf("%d", &num2);
    printf("Masukkan angka ketiga: ");
    scanf("%d", &num3);

    printf("\nNilai yang terbesar adalah: %d\n\n", findMax(num1, num2, num3));

    return 0;
}*/

// menampilkan jam dengan format J:M:D
/*int main()
{
    int jam, menit, detik;

    printf("Masukkan jam (0-23): ");
    scanf("%d", &jam);
    printf("Masukkan menit (0-59): ");
    scanf("%d", &menit);
    printf("Masukkan detik (0-59): ");
    scanf("%d", &detik);

    tulisJam(jam, menit, detik);
}*/

// menentukan bilangan genap atau ganjil
/*int main()
{
    int bilangan;
    printf("Masukkan bilangan: ");
    scanf("%d", &bilangan);

    if (isEvent(bilangan))
    {
        printf("%d adalah bilangan genap\n", bilangan);
    }
    else
    {
        printf("%d adalah bilangan ganjil\n", bilangan);
    }

    return 0;
}*/

// menentukan bilangan positif atau negatif
/*int main()
{
    int bilangan;
    printf("Masukkan bilangan: ");
    scanf("%d", &bilangan);

    if (isPositif(bilangan))
    {
        printf("%d adalah bilangan positif\n", bilangan);
    }
    else
    {
        printf("%d adalah bilangan negatif\n", bilangan);
    }

    return 0;
}*/

// mencari karakter pada string
/*int main()
{
    char str[100], karakter, posisi;
    printf("Masukkan sebuah kalimat: ");
    fgets(str, sizeof(str), stdin);

    printf("Masukkan karakter yang ingin dicari: ");
    scanf("%c", &karakter);

    posisi = findPos(str, karakter);

    if (posisi != -1)
    {
        printf("Karakter '%c' ditemukan pada posisi %d\n", karakter, posisi);
    }
    else
    {
        printf("Karakter '%c' tidak ditemukan dalam kalimat\n", karakter);
    }

    return 0;
}*/

// nilai absolut
/*int main()
{
    float nilai;
    int hasil;
    printf("Masukkan bilangan: ");
    scanf("%f", &nilai);

    hasil = absolut(nilai);

    printf("Nilai absolut dari %.2f adalah %d\n", nilai, hasil);

    return 0;
}*/

// menentukan bilangan prima
/*int main()
{
    int num;
    printf("Masukkan bilangan: ");
    scanf("%d", &num);

    if (isPrima(num))
    {
        printf("%d adalah bilangan prima\n", num);
    }
    else
    {
        printf("%d bukan bilangan prima\n", num);
    }

    return 0;
}*/

// deret fibonancci
int main()
{
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Deret fibonancci: ");
    for (int i = 1; i < n; i++)
    {
        printf("%d ", fibonancci(i));
    }

    printf("\n");

    return 0;
}