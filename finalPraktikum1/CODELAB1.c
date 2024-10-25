#include <stdio.h>
int main()
{
	//ubah dengan memanggil variabel a, b satu persatu agar lebih jelas dalam penginputan data
    int a;
    int b;
    printf("-----Enter a: ");
    scanf("%d", &a);
    
    printf("-----Enter b: ");
    scanf("%d", &b);
    
    //oprasi penjumlahan
    int sum=a+b;
    printf("-----Penjumlahan: %d\n", sum);
    
    //oprasi pengurangan
    int fenita=a-b;
    printf("-----Pengurangan: %d\n", fenita);
    
    //oprasi perkalian
    int product=a*b;
    printf("-----Perkalian: %d\n", product);
    
    //oprasi pembagian dan pengecekan b!=0
    if (b !=0){
		float division= (float) a/b;// cast a atau b ke float
		printf("-----Pembagian: %.2f\n", division); // memberikan format dua angka dibelakang koma dengan %.2f
	}else
	{
		printf("-----Error: pembagian dengan nol\n");
	}
	return 0;
}