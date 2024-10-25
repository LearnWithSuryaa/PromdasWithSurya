#include <stdio.h>

int main()
{
    int a = 5;
    int b = 2; // digunakna pada oprasi increment a++ dan b++

    int hasil_a = 2 + 3 * 5;
    int hasil_b = 10 - 7 + 3 % 6;
    int hasil_c = 3 % 7 / 2 - 1;
    int hasil_d = ++a * 3 / 6 % 7;
    int hasil_e = b++ * 3 - 4 * 7;
    int hasil_f = 6 << 2;
    int hasil_g = 12 >> 3;

    printf("\na. 2 + 3 * 5 = %d\n", hasil_a);
    printf("b. 10 - 7 + 3 %% 6 = %d\n", hasil_b);
    printf("c. 3 %% 7 / 2 - 1 = %d\n", hasil_c);
    printf("d. ++a * 3 / 6 %% 7 = %d\n", hasil_d);
    printf("e. b++ * 3 - 4 * 7 = %d\n", hasil_e);
    printf("f. 6 << 2 = %d\n", hasil_f);
    printf("g. 12 >> 3 = %d\n\n", hasil_g);

    return 0;
}