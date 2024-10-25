#include <stdio.h>
#include <stdbool.h>

bool prima(int num){
    if(num<=1){
        return false; //BILANGAN KURANG DARI ATAU SAMA DENGAN 1 BUKAN BILANGAN PRIMA
    }
    for (int i=2; i*i<=num; i++){
        if (num % i == 0){
            return false; //JIKA HABIS DIBAGI BILANGAN SELAIN 1 DAN DIRINYA SENDIRI, BUKAN PRIMA
        }
    }
 return true; // Jika tidak ada pembagi selain 1 dan dirinya sendiri, maka bilangan tersebut prima
}

int main() {
    int number;

    printf("Masukkan sebuah bilangan: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("%d adalah bilangan prima.\n", number);
    } else {
        printf("%d bukan bilangan prima.\n", number);
    }

    return 0;
}

/*Header <stdbool.h>: Header ini menyediakan definisi untuk tipe data Boolean (bool) dan nilai-nilai true dan false.
Fungsi isPrime:
Parameter: Menerima sebuah bilangan integer num sebagai input.
Return type: Mengembalikan nilai Boolean (bool).
Logika:
Bilangan kurang dari atau sama dengan 1: Bukan bilangan prima, langsung mengembalikan false.
Loop pengecekan: Melakukan perulangan untuk memeriksa apakah num habis dibagi oleh bilangan bulat dari 2 hingga akar kuadrat dari num. Jika ada pembagi yang ditemukan, maka num bukan bilangan prima dan fungsi mengembalikan false.
Jika tidak ada pembagi: Berarti num adalah bilangan prima, maka fungsi mengembalikan true.
Fungsi main:
Meminta pengguna untuk memasukkan sebuah bilangan.
Memanggil fungsi isPrime untuk memeriksa apakah bilangan tersebut prima.
Mencetak hasil pemeriksaan ke layar.
Mengapa menggunakan Boolean di sini?

Kemudahan membaca: Menggunakan true dan false membuat kode lebih mudah dibaca dan dipahami.
Kejelasan logika: Tipe data Boolean secara eksplisit mewakili konsep benar atau salah, sehingga logika program menjadi lebih jelas.
Pengembalian nilai: Fungsi isPrime hanya perlu mengembalikan satu dari dua kemungkinan: bilangan prima atau bukan. Tipe data Boolean sangat cocok untuk mewakili hasil seperti ini.
Contoh lain penggunaan Boolean:

Kondisi dalam perulangan: while (kondisi == true)
Pengambilan keputusan: if (flag == true)
Mengembalikan status keberhasilan fungsi: Misalnya, fungsi untuk membuka file bisa mengembalikan true jika berhasil dan false jika gagal.
Keuntungan menggunakan Boolean:

Membuat kode lebih jelas dan mudah dibaca.
Memudahkan dalam pengambilan keputusan.
Meningkatkan efisiensi dalam beberapa kasus.
Intinya, tipe data Boolean sangat berguna dalam pemrograman untuk mewakili nilai kebenaran (benar atau salah). Dengan menggunakan Boolean, kita dapat membuat kode yang lebih terstruktur, mudah dibaca, dan lebih mudah untuk dipelihara.*/