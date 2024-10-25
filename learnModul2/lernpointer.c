#include <stdio.h>

/*int main(){
    int num=15;
    int *ptr;//DEKLARASI POINTER BERTIPE INTEGER

    //MENGISI POINTER DENGAN ALAMAT MEMORI VARIABEL NUM
    ptr=&num;

    printf("Nilai dari num: %d\n", num);
    printf("Alamat memori dari num: %p\n", &num);//MENGGUNAKAN %p UNTUK MENAMPILKAN ALAMAT MEMORI
    printf("Nilai yang diakses melalui pointer ptr: %d\n", *ptr);
    printf("Alamat memori yang disimpan dalam pointer ptr: %p\n", ptr);//MEMILIKI OUTPUT YANG SAMA DENGAN BARIS NO 11 KARENA POINTER *ptr TELAH DIISI DENGAN ALAMAT num

    //MENGUBAH NILAI VARIABEL NUM MEMLALUI POINTER PTR
    *ptr=25;
    printf("Nilai baru dari num setelah diubah melalui pointer: %d\n", num);//BERFUNGSI UNTUK MENCETAK NILAI TERBARU DARI VARIABEL num SETELAH DIUBAH MELALUI POINTER *ptr

    return 0;
}*/

void tukar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 10, y =20;
    tukar(&x, &y);
    printf("Nilai x yang setelah ditukar: %d\n", x);
    printf("Nilai y yang setelah ditukar: %d\n",y);

    return 0;
}