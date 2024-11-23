#include <stdio.h>

int main()
{
    int penjualan[2][3] = {
        {5, 8, 6},
        {3, 7, 9}};

    int totalPenjualan[3] = {0};

    for (int produk = 0; produk < 3; produk++)
    {
        totalPenjualan[produk] = penjualan[0][produk] + penjualan[1][produk];
    }

    printf("\nTotal penjualan untuk setiap produk:\n");
    for (int produk = 0; produk < 3; produk++)
    {
        printf("Produk %c: %d\n", 'A' + produk, totalPenjualan[produk]);
    }
    
    printf("\n");

    return 0;
}
