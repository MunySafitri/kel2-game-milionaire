#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void pilihan (int a,int b,int j);
void jajawab (); //pilihan selesai jawab
void sscore(int s,int s2); //score untuk cetak selesai sudah main

int main(int arguments, char *argument[]){
    time_t start, end;
    int pil1,seconds,plus=0,i=0,count=0; // i untuk for loop , count untuk menghitung jawaban yang benar dan kirim ke score
    char usernameinput[50],passwordinput[50],c,d,f,choice;
    int soal[10] = {1, 2, 3, 4, 5,6,7,8,9,10}; //jumlah soal
    int fifty,timeradd;


    if(arguments>2){//jika user memasukkan arguments lebih dari 2
        printf("Command yang anda masukkan tidak benar!\n");
        return EXIT_FAILURE;
    }

    else if (arguments ==1){//jika user memasukkan satu argument
        system("cls");
        printf("WELCOME HUMAN!\n");

        mainmenu:
            system ("color 07") ;
            printf("1.Sign in\n2.Log-in\n3.Keluar\n\n");
            printf("masukkan pilihan anda: ");
            scanf("%i",&pil1);
            
            if(pil1 == 2){//program untuk menampilkan cara login
                system("cls");
                printf("Sudah sign-in??\nOke lanjut dengan commmand line berikut ini\n");
                printf("./namaprogram namauser@code\n");
                printf("\n^_^Silahkan Masuk!^_^\n");
                return EXIT_FAILURE;
            }else if(pil1 == 3){//program keluar
                system("cls");
                printf("TERIMAKASIH!!\n");
                return EXIT_FAILURE;
            }else if(pil1==1){//program untuk sign-in
                do{
                    system("cls");
                    if(c == ' ') {
                        printf("Username yang anda masukkan salah!\n");
                        printf("|Username tidak mengandung spasi|\n");
                    }
                    printf("Masukkan username anda: \n");
                    printf("|Contoh Mumun|\n->");
                    getchar();
                    scanf("%[^\n]s",usernameinput);
                    
                    do{
                        c=usernameinput[i++];
                        if (isalnum(c) == 0) {
                            break;
                        }
                        }while(isalnum(c) != 0);
                }while(c == ' ');
                do{
                    if(c == ' ') {
                        printf("Password yang anda masukkan salah!\n");
                        printf("|password tidak mengandung spasi|\n");
                    }
                    system("cls");
                    printf("Masukkan Password: \n");
                    printf("->");
                    getchar();
                    scanf("%[^\n]s",passwordinput);
                        while(isalnum(d) != 0){
                            d =passwordinput[i++];
                            if (isalnum(d) == 0) {
                                break;
                                }
                            printf("%c..",d);
                        }
                }while(d == ' ');
                
                strcat(usernameinput,"@");
                strcat(usernameinput,passwordinput);
                FILE* fip;

                char username[50];
                strcpy(username,usernameinput);
                strcat(usernameinput,".bin");
                
                getchar();
                if((fip=fopen(usernameinput,"r"))!=NULL){//jika username dan password sudah ada
                    system("cls");
                    system ("color 0c") ;
                    printf("\nMaaf, akun ini telah digunakan\nMohon gunakan username dan password yang berbeda\n");
                    printf("Klik enter untuk kembali ke menu utama\n");
                    getch();
                    system("cls");
                    goto mainmenu;
                }
                //program untuk menulis ke binary
                FILE* finp = fopen(usernameinput,"wb");
                fwrite(username, sizeof(char), sizeof(username)/sizeof(char), finp);
                
                fclose(finp);
                printf("\nAnda berhasil login!");
                printf("\nGunakan akun %s untuk login",username);
                getchar();
                system("cls");
                goto mainmenu;
            }
    }else if(arguments == 2){
        
        //program membaca file binary
        strcpy(usernameinput, argument[1]);
        char* user[3];
        user[0] = strtok(usernameinput, "@");
        
        int ctrl=0;
        while(user[ctrl++] != NULL)
        {
            user[ctrl] = strtok(NULL, "@");
        }
        
        FILE *fpr;
        char inp[100];
        strcpy(inp,argument[1]);
        strcat(inp,".bin");
        //program ketika user belum mendaftar
        if((fpr = fopen(inp, "rb")) == NULL)
        {
            printf("\nMaaf, Anda belum mendaftar\nSilahkan daftar terlebih dahulu..\n");
            return EXIT_FAILURE;
        }

        //program untuk membaca isi binary
        char account[100];
        fread(account, sizeof(char), sizeof(account)/sizeof(char), fpr);
        
        fclose(fpr);

        char *string[3];
        char username[50], password[50];
        //program untuk login
        string[0] = strtok(account, "@");
        ctrl=0;
        while(string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, "@");
        }
        
        strcpy(username, string[0]);
        strcpy(password, string[1]);
        
        if( (strcmp(user[0], username) == 0) && (strcmp(user[1], password) == 0) )
        {
            system("cls");
            system ("color 0a") ;
            printf("\nCONGRATULATIONS ON THOU REMEMBRENCE ENJOY YOUR STAY!\n");
            getchar();
        }else
        {
            system ("color 0c") ;
            printf("\nTHOU MIGHT HAVE BRAIN DAMAGE!");
            printf("\nMaaf, akun yang anda masukkan tidak terdaftar\nSilahkan daftar terlebih dahulu dengan menggunakan command ./namaprogram\n") ;
            return EXIT_FAILURE;
        }

        system("cls");
        system ("color 09") ;

        printf("\nWelcome %s!\n",username);
        getchar();
        //mulai permainan
        mainhome:
            system ("color 07");
            system("cls");
            printf("\n\t\t________________________________________");   //main menu
            printf("\n\t\t\t    WELCOME ");
            printf("\n\t\t\t       to ");
            printf("\n\t\t\t    THE GAME ");
            printf("\n\t\t________________________________________");
            printf("\n\t\t________________________________________");
            printf("\n\t\t\tWHO WANTS TO BE A" 
                "\n\t\t\t  MILLIONAIRE    ");
            printf("\n\t\t________________________________________");
            printf("\n\t\t________________________________________");
            printf("\n\t\t > Press S to start the game");
            printf("\n\t\t > press C Credit        ");
            printf("\n\t\t > press Q to quit             ");
            printf("\n\t\t________________________________________\n\n");
            choice = toupper(getch());
            if (choice == 'C') {//dibuat oleh
                system("cls");
                printf("\n\t\tProgram ini disiapkan oleh:\n\n"
                    "1. Hadafee Mudo 2008107010101\n"               //untuk user di pilihan Credit
                    "2. Muny Safitri 2008107010064\n"
                    "3. Arif Munandar 2008107010016\n"
                    "4. Rania Shafia Khuzai 200810t010051\n");
                getch();
                goto mainhome;
            }else if (choice == 'Q')                                  //pilihan keluar program
                exit(1);
            else if (choice == 'S') {                                 
                count=0,fifty = 1,timeradd = 1;
                beforestart:
                    system("cls");
                    printf("\n\tketentuan Memainkan game\n"
                        "\n1. Pemain hanya memiliki 1 nyawa."               //game rules
                        "\n2. karena hanya memiliki satu nyawa, maka user akan dikasih pilihan untuk"
                        "\n   tetap melanjutkan permainan atau tidak."
                        "\n3. waktu yang disediakan untuk menjawab satu soal adalah 10 detik."
                        "\n4. jika anda menjawab lebih dari 10 detik, maka anda kehilangan satu nyawa"
                        "\n   alias game over,waktu tidak ditampilkan, lebih cepat menjawab, itu lebih baik."
                        "\n5. Jika anda kalah, uang yang anda dapatkan akan hangus."
                        "\n6. Terdapat optional tambahan seperti 50:50 dan add 5 seconds, gunakan dengan baik.");
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
                            switch (soal[i]) {                                    //soal 1- 10 
                                case 1:
                                    start = time (NULL);//program menjalankan waktu
                                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.10.000\n");
                                    printf("1. satu ton ada berapa kilogram ? \n");
                                    printf("\ta. 100kg \t%10s","c. 1000kg\n");
                                    printf("\tb. 10000kg \t%10s","d. 10kg\n");

                                    pilihan(fifty,timeradd,plus);//fungsi pilihan tambhan

                                    fif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        
                                        if (seconds > 10+plus){//program ketika user lambat menjawab
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;
                                        }
                                        
                                        if (tolower(f) == 'c') {
                                        jajawab();
                                        count=count+10000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            }else{
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {  //program pilihan tambahan
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. 100kg\tc. 1000kg");
                                                fifty = 0;
                                                goto fif;
                                            }else {
                                                goto fif;
                                                }
                                        }
                                        else if(tolower(f)=='f'){//program pilihan tambahan
                                            if (timeradd== 1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto fif;
                                            }else{
                                                goto fif;
                                                }
                                        }
                                        else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is c.1000kg");
                                            getch();
                                            goto score2;
                                        }

                                case 2:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda akan mendapatkan uang sebesar Rp.400.000\n");
                                    printf("2.Senjata khas sukun aborigin adalah ? \n");
                                    printf("\ta. Boomerang    c. Panah\n");
                                    printf("\tb. Pedang       d. peluru\n");
                                    pilihan(fifty,timeradd,plus);

                                    gif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;
                                        }
                                        if (tolower(f) == 'a') {
                                            jajawab();
                                            count+=400000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (fifty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Boomerang\td. peluru");
                                                fifty = 0;
                                                goto gif;
                                            } else{ 
                                                goto gif;
                                                }
                                            }
                                        else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto gif;
                                            }else{
                                                goto gif;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is a. Boomerang");
                                            getch();
                                            goto score2;
                                        }
                                case 3:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp500.000\n\n");//klo bisa jangan disingkat:)
                                    printf("3. Berapa banyak kubus berukuran 2 inci yang bisa masuk ke dalam kotak\n "
                                        "   berukuran panjang 5 inci, lebar 4 inci, dan tinggi 3 inci?\n");
                                    printf("\ta. 60         c. 30\n");
                                    printf("\tb. 23         d. 100\n\n");
                                   
                                    pilihan(fifty,timeradd,plus);

                                    sif:
                                        printf("\nMasukkan pilihan anda: ");

                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'c') {
                                            jajawab();
                                            count+=500000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if (tolower(f) == 'e') {
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. 23\tc. 30");
                                                fifty = 0;
                                                goto sif;
                                            } else{ goto sif;}
                                        }else if(tolower(f)=='f') {
                                            if (timeradd == 1){
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto sif;
                                            }else { 
                                                goto sif;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is c. 30");
                                            getch();
                                            goto score2;
                                        }
                                case 4:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp.1.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("4. Manakah kata di bawah ini yang memiliki makna sama dengan \"caprice\"?\n");
                                    printf("\ta. Whim           c. Capture\n");
                                    printf("\tb. Acyion         d. Tact\n\n");
                                   
                                    pilihan(fifty,timeradd,plus);
                                        
                                    rif:
                                        printf("\nMasukkan pilihan anda: ");

                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'c') {
                                            jajawab();
                                            count+=1000000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if(fifty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nc. capture\td. tact");
                                                fifty = 0;
                                                goto rif;
                                            } else{goto rif;}
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto rif;
                                            } else{ 
                                                goto rif;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is c. Capture");
                                            getch();
                                            goto score2;
                                        }
                                case 5:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp2.500.000\n\n");//klo bisa jangan disingkat:)
                                    printf("5. Rumah di Jl. Malioboro dinomori secara berurutan mulai dari nomor 1 \n"
                                        "   sampai nomor 20. Berapa banyak angka 1 yang digunakan?\n");
                                    printf("\ta. 10        c. 9\n");
                                    printf("\tb. 12        d. 11\n\n");
                                    pilihan(fifty,timeradd,plus);

                                    yif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                            }
                                        if (tolower(f) == 'd') {
                                            jajawab();
                                            count+=2500000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (fifty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. 12\td. 11\n");
                                                fifty = 0;
                                                goto yif;
                                            } else{ 
                                                goto yif;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto yif;
                                            } else{ 
                                                goto yif;
                                            }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is d. 11");
                                            getch();
                                            goto score2;
                                        }
                                case 6:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp6.000.000\n\n");
                                    printf("6. kabupaten/kota di provinsi aceh yang pernah menjadi ibukota indonesia adalah \n"
                                        "\ta. Sabang     c. Banda Aceh\n"
                                        "\tb. Bireun     d. Bukit Tinggi \n\n");

                                    pilihan(fifty,timeradd,plus);

                                    nif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'b') {
                                            jajawab();
                                            count+=6000000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (fifty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. Bireun\tc. Banda Aceh\n");
                                                fifty = 0;
                                                goto nif;
                                            } else{goto nif;}
                                            }
                                        else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto nif;
                                            } else{ 
                                                goto nif;
                                            }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is b. Bereun");
                                            getch();
                                            goto score2;
                                        }
                                case 7:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp7.000.000\n\n");
                                    printf("7. Berapakah jumlah kabupaten/kota yang ada di provinsi Aceh\n"
                                        "\ta. 23      c. 24\n"
                                        "\tb. 34      d. 33 \n\n");
                                    pilihan(fifty,timeradd,plus);
                                    cif:
                                        printf("\nMasukkan pilihan anda: ");

                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'a') {
                                            jajawab();
                                            count+=7000000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. 23\tc. 24");
                                                fifty = 0;
                                                goto cif;
                                            } else { 
                                                goto cif; 
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto cif;
                                            } else { 
                                                goto cif;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is a. 23");
                                            getch();
                                            goto score2;
                                        }
                                case 8:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp8.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("8. Dimanakah letak monumen islam asia tenggara ( Monisa ) \n"
                                        "\ta. Campa, Kamboja      c. Padang, Sumatera Barat\n"
                                        "\tb. Perlak, Aceh        d. Jakarta\n\n");
                                    pilihan(fifty,timeradd,plus);

                                    kif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                            printf ("Sorry, you were too slow.\n");
                                            getchar();
                                            goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'b') {
                                            jajawab();
                                            count+=8000000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Campa, Kamboja \tb. Perlak, Aceh ");
                                                fifty = 0;
                                                goto kif;
                                            } else { 
                                                goto kif; 
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto kif;
                                            } else{ 
                                                goto kif;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is b. Perlak aceh");
                                            getch();
                                            goto score2;
                                        }
                                case 9:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp.9.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("9. Siapakah pengarang syair gout gout panyang iku\n"
                                        "\ta. Abu Krueng Kalee             c. Syekh Nuruddin Ar-raniry\n"
                                        "\tb. Syekh Abdurrauf As-Singkiy   d. Sultan Iskandar Muda\n\n");

                                    pilihan(fifty,timeradd,plus);

                                    hif:
                                        printf("\nMasukkan pilihan anda: ");
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                        printf ("Sorry, you were too slow.\n");
                                        getchar();
                                        goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'a') {
                                            jajawab();
                                            count+=9000000;
                                            if (toupper(getch()) == 'N') {
                                                goto score;
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Abu Krueng Kalee\td. Sultan Iskandar Muda");
                                                fifty = 0;
                                                goto hif;
                                            } else { 
                                                goto hif; 
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto hif;
                                            } else {
                                                 goto hif;
                                                 }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is a. abu Kerueng Kalee");
                                            getch();
                                            goto score2;
                                        }
                                case 10:
                                    system ("color 07") ;
                                    system("cls");
                                    start = time (NULL);
                                    printf("\nJika anda menjawab benar, maka anda mendapatkan uang sebesar Rp.10.000.000\n\n");
                                    printf("10. Siapakah pendiri gerakan aceh merdeka ( GAM )\n"
                                        "\ta. Malik Mahmud       c. Tgk Hasan di Tiro\n"
                                        "\tb. Tgk Chik di Tiro   d. Muzakir Manaf\n\n");
                                    printf("\nMasukkan pilihan anda: ");
                                    pilihan(fifty,timeradd,plus);
                                    dif:
                                        f=getch();
                                        end = time (NULL);
                                        seconds = end - start;
                                        if (seconds > 10+plus){
                                            system("cls");
                                        printf ("Sorry, you were too slow.\n");
                                        getchar();
                                        goto score2;//sampai sini
                                        }
                                        if (tolower(f) == 'c') {
                                            count+=10000000;
                                            printf("\nALL PERFECT\n");
                                            goto score;

                                        }else if(tolower(f)=='e') {
                                            if (fifty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. Tgk Chik di Tiro \tc. Tgk Hasan di Tiro");
                                                fifty = 0;
                                                goto dif;
                                            } else { 
                                                goto dif; 
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (timeradd==1) {
                                                printf("\nadd 5 seconds telah dipakai\n");
                                                plus = 5;
                                                timeradd = 0;
                                                goto dif;
                                            } else{ 
                                                goto dif;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nWrong!!! The correct answer is c. Tgk Hasan di Tiro");
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
        return 0;
}
void pilihan (int a,int b,int j) {
    j = 0;
    printf("\nPilihan item untuk membantu Anda\n");
    if (a > 0) {
        printf("\te. 50:50\t");
    }
    if (b > 0) {
        printf("f. add 5 seconds\n");
    }
    if (a == 0) {
        if (b == 0) { 
            printf("(Anda sudah menggunakan item semua)\n"); 
            }
    }
}
void jajawab () {
    system ("color 0a") ;
    printf("\n\nCorrect!!!\n");
    printf("\nDo you want to continue to the next question?");
    printf("\n Press Any key to continue "
           "\n Press N to Enough!");
}
void sscore(int s, int s2){
   int score;
    if (s2==1){
        system ("color 0a") ;
        system("cls");
        score=s;
        printf("\n\n\t\t**************** CONGRATULATION *****************");
        printf("\n\n\t You won!!! Get reward  %d rupiah",score);
        printf(" \n\n\tPress any key if you want to go main menu");       // score untuk user win
        getch();
    } else if (s2==2){
        system("cls");
        system ("color 0c") ;
        printf("\n\n\t\t**************** GAME OVER *****************");
        printf("\n\n\t Hanya karena Anda rakus. Membuat Anda tidak mendapatkan sepeser pun!!\n" //untuk user game over
               "\t Hahahahaha");
        printf(" \n\n\tPress any key if you want to go main menu");
        getch();
    }
}