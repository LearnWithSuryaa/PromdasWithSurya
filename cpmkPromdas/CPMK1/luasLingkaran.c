#include <stdio.h>
#define PI 3.14159

float luasLingkaran(float radius){
    return PI*radius*radius;
}

int main(){
    float radius;

    printf("Masukkan nilai radius: ");
    scanf("%f", &radius);

    printf("\nLuas lingkaran dengan radius %.2f adalah: %.2f\n\n", radius, luasLingkaran(radius));

    return 0;
}