#include <stdio.h>

void cetakArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d", arr[i];)
    }
    printf("\n");
}

int main(){
    int angka[5]={5, 6, 7, 8, 9};
    cetakArray(angka 5);
    return 0;
}
/*Fungsi cetakArray:

void cetakArray(int arr[], int size): Fungsi ini menerima dua parameter:
int arr[]: Parameter ini sebenarnya adalah pointer ke integer. Ketika kita mengirimkan nama array ke sebuah fungsi, yang sebenarnya kita kirimkan adalah alamat memori dari elemen pertama array tersebut. Jadi, di dalam fungsi, arr akan diperlakukan sebagai pointer.
int size: Parameter ini menyimpan ukuran array, sehingga fungsi tahu berapa banyak elemen yang harus dicetak.
for loop: Loop ini digunakan untuk mengiterasi setiap elemen dalam array. Indeks i akan dimulai dari 0 dan berjalan hingga size-1.
printf("%d ", arr[i]);: Setiap elemen array akan dicetak ke layar, diikuti oleh spasi.
printf("\n");: Setelah semua elemen dicetak, baris baru akan dibuat.
Fungsi main:

Deklarasi array: int angka[5] = {10, 20, 30, 40, 50}; Deklarasi sebuah array dengan nama angka yang berisi 5 elemen.
Pemanggilan fungsi: cetakArray(angka, 5); Fungsi cetakArray dipanggil dengan mengirimkan array angka dan ukurannya (5) sebagai argumen.
Kenapa kita tidak perlu mendeklarasikan pointer secara eksplisit di dalam fungsi cetakArray?

Karena ketika kita mengirimkan nama array ke sebuah fungsi, secara otomatis array tersebut akan "decay" menjadi pointer ke elemen pertamanya. Jadi, di dalam fungsi, arr akan dianggap sebagai pointer ke integer.

Mengapa kita perlu mengirimkan ukuran array sebagai parameter terpisah?

Karena array tidak menyimpan informasi tentang ukurannya sendiri. Jika kita hanya mengirimkan nama array, fungsi tidak akan tahu berapa banyak elemen yang harus diproses. Oleh karena itu, kita perlu mengirimkan ukuran array secara terpisah.

Konsep Penting:

Array sebagai pointer: Nama array sebenarnya adalah pointer ke elemen pertamanya.
Passing by reference: Ketika kita mengirimkan array ke sebuah fungsi, yang sebenarnya kita kirimkan adalah alamat memorinya. Ini berarti perubahan yang dilakukan di dalam fungsi akan memengaruhi array asli.
Keuntungan menggunakan pointer dengan array:

Efisiensi: Mengakses elemen array menggunakan pointer umumnya lebih efisien dibandingkan dengan metode lain.
Fleksibelitas: Pointer memungkinkan kita melakukan manipulasi data yang lebih kompleks pada array.
Contoh lain penggunaan pointer dengan array:

Mengurutkan array: Kita bisa menggunakan pointer untuk mengimplementasikan berbagai algoritma pengurutan seperti bubble sort, insertion sort, atau quicksort.
Mencari elemen dalam array: Kita bisa menggunakan pointer untuk melakukan pencarian linear atau binary search.
Memanipulasi string: String dalam C sebenarnya adalah array of char, sehingga kita bisa menggunakan pointer untuk memanipulasi string.*/