#include <stdio.h>

/*int main()
{
    int num[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // mendefinisikan array bilangan bulat
    char huruf[6] = {'a', 'i', 'u', 'e', 'o'};     // mendefinisikan array huruf atau string
    float desimal[6] = {1.2, 3.4, 5.6, 7.8, 9.0};  // mendefinisikan array desimal
    int fenita[6][3] = {{1,70},{2,85},{3,90},{4,75},{5,85}};// mendefinisikan array 2D
}*/
;

// program menampilkan bilangan ganjil dari 1-50
/*int main()
{
    int num[51];
    for (num = 0; num <= 50; num++)
    {
        if (num % 2 != 0)
        {
            printf("%d adalah angka ganjil\n", num);
        }
    }
    return 0;
}*/
;

// implementasi string(array huruf)
/*int main()
{
    char negara[10] = {'i', 'n', 'd', 'o', 'n', 'e', 's', 'i', 'a'};
    int i, length = sizeof(negara) / sizeof(negara[0]);

    for (i = 0; i < length; i++)
    {
        printf("%c", negara[i]);//jika ingin menampilkan output dengan spasi printf("%c ", negara[i]);
    }
    printf("\n\n");
    return 0;
}*/
;

//membuat program untuk menentukan suatu karakter apakah berada didalam string(array huruf)
void header() {
    printf("\n------------------------------- Program Pencari Array -------------------------------\n");
    printf("Program ini akan mencari karakter yang diinputkan oleh user apakah ada di dalam string.\n\n");
}

void footer() {
    printf("\n------------------------------ Program Selesai di Jalankan ------------------------------\n\n");
}

int main() {
    char negara[10] = {'i', 'n', 'd', 'o', 'n', 'e', 's', 'i', 'a', '\0'}, tujuan, choice;
    int found;

    do {
        header();
        
        printf("Masukkan huruf yang ingin dicari: ");
        scanf(" %c", &tujuan);
        
        found = 0;

        // Mencari karakter dalam array
        for (int i = 0; negara[i] != '\0'; i++) {
            if (negara[i] == tujuan) {
                found = 1;
                break;
            }
        }

        // Menampilkan hasil pencarian
        if (found) {
            printf("Karakter '%c' ada dalam array.\n", tujuan);
        } else {
            printf("Karakter '%c' tidak ada dalam array.\n", tujuan);
        }

        // Menanyakan apakah pengguna ingin mengulang
        printf("\nApakah Anda Ingin Mengulang Program (y/n): ");
        scanf(" %c", &choice);  // Tambahkan spasi sebelum %c untuk mengabaikan whitespace

        // Jika pilihan adalah 'n', tampilkan footer
        if (choice == 'n' || choice == 'N') {
            footer();
        }

        printf("\n");

    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
