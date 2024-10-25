Berapakah hasil ekspresi berikut :

    a. 2 + 3 * 5=17
    Oprasi dilakukan sesuai dengan urutan prioritas yakni oprator perkalian didahulukan
    3*5=15
    15+2=17

    b. 10 – 7 + 3 % 6=6
    Urutan oprasi dilakukan mulai dari modulus terlebih dahulu kemudian penjumlahan dan pengurangan dari kiri ke kanan yakni:
    3%6= 3(nilai 3 ini merupakan nilai sisa dari pembagian 3 dan 6)
    10-7=3
    3+3=6

    c. 3 % 7 / 2 – 1 =0
    Urutan oprasi dilakukan mulai dari modulus terlebih dahulu kemudian dilanjutkan dengan pembagian lalu yang terakhir pengurangan:
    3%7=3 (sisa pembagian 3 dan 7)
    3/2=1 (karena pembagian bilangan bulat menghasilkan bilangan bulat)
    1-1=0

    d. ++5 * 3 / 6 % 7 = 3
    Ekspresi ini tidak valid di C karena kita tidak bisa menggunakan operasi increment pada literal (angka konstan seperti 5).
    Jadi ekspresi ini tidak bisa dievaluasi sebagaimana adanya

    e. 3 * 2++ - 4 * 7 = -22
    Sama seperti pada contoh d, kita tidak bisa menggunakan 2++ karena 2 adalah literal dan bukan variabel, 
    sehingga increment tidak bisa diterapkan pada konstanta. Ekspresi ini juga tidak valid.

    f. 6 << 2 = 24
    Operator << adalah operator bitwise shift ke kiri.
    6 dalam biner adalah 00000110.
    Menggeser ke kiri sebanyak 2 posisi:
    00000110 menjadi 00011000 (ini sama dengan 24 dalam desimal).

    g. 12 >> 3 = 1
    Operator >> adalah operator bitwise shift ke kanan.
    12 dalam biner adalah 00001100.
    Menggeser ke kanan sebanyak 3 posisi:
    00001100 menjadi 00000001 (ini sama dengan 1 dalam desimal).