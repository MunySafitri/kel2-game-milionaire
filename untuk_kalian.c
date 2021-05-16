#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
int main(){
	int uang=0;
	char jawaban;
	//char benar;
	printf("\nJika anda menjawab benar, maka anda mendapatkan rp.100k\n");//klo bisa jangan disingkat:)
	printf("berapa jumlah kuku ayam? \n");
	printf("a. 4 %20s","c.3\n");
	printf("b. 5 %20s","d.2\n");	
	printf("Masukkan pilihan anda: ");
	scanf("%c",&jawaban);
	//char benar= 'c';
	if(tolower(jawaban)=='c'){
		printf("selamat jawaban anda benar!\n");
		uang=uang+100000;
	}else{
		printf("jawaban anda salah!\nKlik enter menuju pertanyaan selanjutnya");
		getchar();	
	}
	system("cls");
	printf("\nJika anda menjawab benar, maka anda mendapatkan rp.150k\n");//klo bisa jangan disingkat:)
	printf("berapa jumlah kuku kucing? \n");
	printf("a. 4 %20s","c.3\n");
	printf("b. 5 %20s","d.2\n");	
	printf("Masukkan pilihan anda: ");
	//char benar='b';
	scanf("%c",&jawaban);
	if(tolower(jawaban)=='b'){
		printf("selamat jawaban anda benar!\n");
		uang=uang+150000;
	}else{
		printf("jawaban anda salah!\nKlik enter menuju pertanyaan selanjutnya");
		getchar();	
	}
	printf("uang yang anda peroleh sekarang adalah %d",uang);
	
	//dst
	return 0;	
}
