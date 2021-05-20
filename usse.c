#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
#include <time.h>

void jajawab (); //pilihan selesai jawab
void sscore(int s,int s2); //score untuk jetak selesai sudah main
int main () {
    int i, count; // i untuk for loop , count untuk menghitung jawaban yang benar dan kirim ke score
    int soal[10] = {1, 2, 3, 4, 5,6,7,8,9,10}; //jumlah soal
    char choice;  //choice pilihan main menu
    mainhome:
    system("cls");
    printf("\n\t\t________________________________________");   //main menu
    printf("\n\t\t\t   WELCOME ");
    printf("\n\t\t\t      to ");
    printf("\n\t\t\t   THE GAME ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t   WHAT THE FUCK THIS GAME!    ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t > Press S to start the game");
    printf("\n\t\t > press C Credit        ");
    printf("\n\t\t > press Q to quit             ");
    printf("\n\t\t________________________________________\n\n");
    choice = toupper(getch());
    if (choice == 'C') {
        system("cls");
        printf("\n\t\tProgram ini disiapkan oleh\n\n"
               "1. Hadafee Mudo 2008107010101\n"               //untuk user di pilihan Credit
               "2. Muny Safitri\n"
               "3. Arif Munandar 2008107010016\n"
               "4. Rania Shafia Khuzai ");
        getch();
        goto mainhome;
    }else if (choice == 'Q')                                  //pilihan keluar program
        exit(1);
    else if (choice == 'S') {                                 //pilihan start game
        count=0;
        beforestart:
        system("cls");
        printf("\n\tketentuan Memainkan game\n"
               "\n1. Pemain hanya memiliki 1 nyawa"               //game rules
               "\n2. karena hanya memiliki satu nyawa, maka user akan dikasih pilihan untuk"
               "\n   tetap melanjutkan permainan atau tidak"
               "\n3. waktu yang disediakan untuk menjawab satu soal adalah 10 detik"
               "\n4. jika anda menjawab lebih dari 10 detik, maka anda kehilangan satu nyawa"
               "\n   alias game over"
               "\n5. Jika anda kalah, uang yang anda dapatkan tersebut tidak akan berkurang");
        printf("\n\n\n Press Y  to start the game");
        printf("\n Press N to return to the main menu!");
            if (toupper(getch()) == 'Y') {
                goto start;
            } else if (toupper(getch()) == 'N') {
                goto mainhome;
            }else{
                goto beforestart;
            }
        start:
        for (i = 0; i < 10; i++) { //for loop untuk ubah soal otomatis
            system("cls");
            switch (soal[i]) {                                    //soal 1- 10 adalah line 67- 254
                case 1:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.1000.000\n");//klo bisa jangan disingkat:)
                    printf("1. satu ton ada berapa kilogram ? \n");
                    printf("\ta. 100kg %20s","c. 1000kg\n");
                    printf("\tb. 10000kg %20s","d. 10kg\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'c') {
                       jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is c.1000kg");
                        getch();
                        goto score2;
                    }
                case 2:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.4000.000\n");//klo bisa jangan disingkat:)
                    printf("2.Senjata khas sukun aborigin adalah ? \n");
                    printf("\ta. Boomerang    c. Panah\n");
                    printf("\tb. Pedang       d. Salah semua\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'a') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is a. Boomerang");
                        getch();
                        goto score2;
                    }
                case 3:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.8000.000\n");//klo bisa jangan disingkat:)
                    printf("3. Berapa banyak kubus berukuran 1 inci yang bisa masuk ke dalam kotak\n "
                           "   berukuran panjang 5 inci, lebar 4 inci, dan tinggi 3 inci?\n");
                    printf("\ta. 60         c. 12\n");
                    printf("\tb. 23         d. 100\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'b') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is b. 23");
                        getch();
                        goto score2;
                    }
                case 4:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.16.000.000\n");//klo bisa jangan disingkat:)
                    printf("4. Manakah kata di bawah ini yang memiliki makna sama dengan \"caprice\"?\n");
                    printf("\ta. Whim           c. Capture\n");
                    printf("\tb. Acyion         d. Tact\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'c') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is c. Capture");
                        getch();
                        goto score2;
                    }
                case 5:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.32.000.000\n");//klo bisa jangan disingkat:)
                    printf("5. SEA Games diadakah setiap berapa tahun sekali ?\n");
                    printf("\ta. 2 tahun,     c. 5 tahun\n");
                    printf("\tb. 4 tahun,     d. 1 tahun\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'a') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is a. 2 tahun");
                        getch();
                        goto score2;
                    }
                case 6:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.64.000.000\n");//klo bisa jangan disingkat:)
                    printf("6. kabupaten/kota di provinsi aceh yang pernah menjadi ibukota indonesia adalah \n"
                           "\ta. Sabang     c. Banda Aceh\n"
                           "\tb. Bireun     d. Bukit Tinggi \n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'b') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is b. Bereun");
                        getch();
                        goto score2;
                    }
                case 7:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.150.000.000\n");//klo bisa jangan disingkat:)
                    printf("7. Di negara manakah letak terusan Suez  \n"
                           "\ta. Mesir     c. Saudi Arabia\n"
                           "\tb. India     d. Cina\n");

                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'a') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is a. Mesir");
                        getch();
                        goto score2;
                    }case 8:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.200.000.000\n");//klo bisa jangan disingkat:)
                    printf("8. Dimanakah letak monumen islam asia tenggara ( Monisa ) \n"
                           "\ta. Campa, kamboja      c. Padang, sumatera barat\n"
                           "\tb. Perlak, aceh        d. Jakarta\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'b') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is b. Perlak aceh");
                        getch();
                        goto score2;
                    }case 9:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.250.000.000\n");//klo bisa jangan disingkat:)
                    printf("9. Siapakah pengarang syair gout gout panyang iku\n"
                           "\ta. Abu Krueng Kalee             c. Syekh Nuruddin Ar-raniry\n"
                           "\tb. Syekh Abdurrauf As-Singkiy   d. Sultan Iskandar Muda\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'a') {
                        jajawab();
                        count++;
                        if (toupper(getch()) == 'N') {
                            goto score;
                        } else {
                            break;
                        }
                    } else {
                        printf("\n\nWrong!!! The correct answer is a. abu Kerueng Kalee");
                        getch();
                        goto score2;
                    }case 10:
                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.275.000.000\n");//klo bisa jangan disingkat:)
                    printf("10. Dari daerah manakah asal dari ceri sangkuriang ?\n"
                           "\ta. Padang, Sumatera Barat      c. Priangan, Jawa barat\n"
                           "\tb. Samosir, Sumatera Utara     d. Takengon, Aceh\n");
                    printf("Masukkan pilihan anda: ");
                    if (tolower(getch()) == 'c') {
                        count++;
                            break;

                    } else {
                        printf("\n\nWrong!!! The correct answer is c. Priangan, Jawa Tengah");
                        getch();
                        goto score2;
                    }
            }
        }
    }else{
        goto mainhome;
    }
    score:                // Hitungan semua score
    sscore(count,1);
    goto mainhome;
    score2:
    sscore(count,2);
    goto mainhome;
}
void jajawab () {
    printf("\n\nCorrect!!!\n");
    printf("\nDo you want to contine to the next question?");
    printf("\n Press Any key to continue "
           "\n Press N to Enough!");

}
void sscore(int s, int s2){
   int score;
    if (s2==1){
        system("cls");
        score=s*100000;
        printf("\n\n\t\t**************** CONGRATULATION *****************");
        printf("\n\n\t You won!!! Get reward  %d rupiah",score);
        printf(" \n\n\tPress any key if you want to go main menu");       // score untuk user win
        getch();
    } else if (s2==2){
        system("cls");
        printf("\n\n\t\t**************** GAME OVER *****************");
        printf("\n\n\t Anda hanya mendapatkan ""\n" //untuk user game over
               "\t Hahahahaha");
        printf(" \n\n\tPress any key if you want to go main menu");
        getch();
     }
}
