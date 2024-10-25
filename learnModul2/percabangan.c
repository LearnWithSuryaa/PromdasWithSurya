#include <stdio.h>

/*int main(){
    int num1, num2;
    printf("Masukkan angka pertama: ");
    scanf("%d", &num1);
    printf("Masukkan angka kedua: ");
    scanf("%d", &num2);

    if(num1>num2){
        printf("Bilangan terbesar adalah: %d\n", num1);
    }else if(num2>num1){
        printf("Biangan terbesar adalah: %d\n", num2);
    }else{
        printf("Kedua bilangan sama: %d\n",num1);
    }

    return 0;
}*/
	
	int main(){
		int saklar;
		do{
		  printf("\nMasukkan Status Saklar (1=ON, 0=OFF): ");
		  scanf("%d", &saklar);
	   	  if(saklar == 1){
			printf("ON\n");
		  }else if(saklar == 0){
			printf("OFF\n");			
		  }else{
			printf("Error input tidak valid, masukkan nilai 1 atau 0\n");
          }
		}while(saklar !=0 && saklar !=1);
		
		return 0;
	}