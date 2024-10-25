#include <stdio.h>
#define PI 3.14159

void header (){
    printf("--------------------------- Program Menghitung Keliling dan Luas Lingkaran ---------------------------\n");
    printf("Program ini menghitung luas dan keliling lingkaran berdasarkan nilai radius yang diinputkan oleh user.\n\n");
}

void footer (){
    printf("------------------------------------- Program Selesai Dijalankan -------------------------------------\n");
}

float luasLingkaran (float radius){
    return PI*radius*radius;
}
float kelilingLingkaran (float radius){
    return 2*PI*radius;
}

int main(){
    char choice;
    float radius, luas, keliling;
    int validInput, errorCount;

    do{
      header();
      errorCount = 0;
        do{
          printf("Masukkan nilai radius: ");
          validInput = scanf("%f", &radius);//mendefinisikan bahwa valid input = inputan radius
          
           if(validInput != 1 || radius < 0){//memberikan kondisi dimana user harus memasukkan input yang tepat
             errorCount++;//menghitung jumlah error

             while((getchar()) != '\n');//membersihkan buffer input

             if(errorCount >= 2){//mengeluarkan user dari program dengan kode error setelah error terjadi lebih dari 2 kali
                printf("\nPROGRAM ERROR. MASUKKAN INPUT ANGKA!\n\n");
             }else{
               printf("\nProgram Error. Masukkan Input dengan Benar!\n\n");
             }
            }

        }while(validInput != 1 || radius < 0);//mengulang program jika user memberikan input bukan angka

      luas=luasLingkaran(radius);
      keliling=kelilingLingkaran(radius);
    
      printf("\nHasil luas lingkaran dengan menggunakan radius %.2f adalah: %.2f\n", radius, luas);
      printf("Hasil keliling lingkaran dengan menggunakan radius %.2f adalah: %.2f\n", radius, keliling);

     do{
         printf("\nApakah ANda ingin Mengulang Program? (y/n): ");

         while((getchar()) !='\n');//membersihkan buffer dari karakter newline
         scanf("%c", &choice);

         if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N'){//memberikan kondisi dimana user tidak memasukkan input yang tepat
            printf("\nERROR MASUKKAN INPUT DENGAN BENAR!\n");
         }
        }while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');//mengulang program jika user tidak memasukkan input yang benar

      if (choice != 'y' && choice != 'Y') {
            footer();
        }

        printf("\n");//memberikan gap new line

    }while (choice == 'y' || choice == 'Y');//jika user memilih 'y' maka program diulang

    return 0;
}