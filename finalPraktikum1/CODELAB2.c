#include <stdio.h>
int main()
{
	char nama [50];
	int umur;
	float gaji_pokok, tunjangan, total_gaji;
	printf("Masukkan Nama: ");
	fgets(nama, 50, stdin); //menggunakan fgets untuk input string yang lebih aman
	
	printf("Masukkan Umur: ");
	scanf("%d", &umur);
	
	printf("Masukkan Gaji Pokok: ");
	scanf("%f", &gaji_pokok);
	
    tunjangan = gaji_pokok*0.1;
	total_gaji = gaji_pokok+tunjangan; //memperbaiki perhitungan total gaji yang sebelumnya dikali menjadi ditambah
	
	printf("Nama: %s\n", nama);
	printf("Umur: %d\n", umur);
	printf("Gaji Pokok: %.2f\n", gaji_pokok);
	printf("Tunjangan: %.2f\n", tunjangan);
	printf("Total Gaji: %.2f\n", total_gaji);
	return 0;
}