#include <stdio.h>
#include <string.h> // Untuk fungsi strcpy

int main() {
    // Demonstrasi nilai Boolean
    int flagTrue = 1;   // 1 mewakili nilai true
    int flagFalse = 0;  // 0 mewakili nilai false

    printf("Boolean values demonstration:\n");
    printf("flagTrue: %d\n", flagTrue);
    printf("flagFalse: %d\n", flagFalse);

    // Operasi string
    char greeting[] = "Hello, World!";
    char copyGreeting[20];  // Ukuran harus cukup besar untuk menampung string yang akan disalin
    strcpy(copyGreeting, greeting);  // Menggunakan strcpy dari string.h

    printf("\nString operations:\n");
    printf("Original greeting: %s\n", greeting);
    printf("Copied greeting: %s\n", copyGreeting);

    // Demonstrasi pointer
    int number = 100;
    int *pointer = &number;

    printf("\nPointer demonstrations:\n");
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", (void*)&number);  // Cast ke (void*) untuk menampilkan alamat memori
    printf("Value of pointer: %p\n", (void*)pointer);   // Cast ke (void*) untuk menampilkan alamat memori
    printf("Value pointed by pointer: %d\n", *pointer);

    return 0;
}
    