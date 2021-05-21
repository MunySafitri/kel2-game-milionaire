#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>

int main(int arguments, char *argument[]){
    int pil1,i=0;
    char usernameinput[50],passwordinput[50],c,d;
    if (arguments ==1){
        system("cls");
        printf("WELCOME HUMAN!\n");
        
        mainmenu:
        system ("color 07") ;
        printf("1.Sign in\t\t2.Log-in\n3.Keluar\n");
        printf("masukkan pilihan anda: ");
        scanf("%i",&pil1);
        if(pil1 == 2){
            system("cls");
            printf("Sudah sign-in??\nOke lanjut dengan commmand line berikut ini\n");
            printf("./namaprogram namauser@code\n");
            printf("\n^_^Silahkan Masuk!^_^\n");
            return EXIT_FAILURE;
        }else if(pil1 == 3){
            system("cls");
            printf("TERIMAKASIH!!\n");
            return EXIT_FAILURE;
        }else if(pil1==1){
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
            //printf("%s\n",usernameinput);
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
            //printf("\n%s",passwordinput);
            strcat(usernameinput,"@");
            strcat(usernameinput,passwordinput);
            FILE* fip;
            
            //printf("%s",usernameinput);
            char username[50];
            strcpy(username,usernameinput);
            strcat(usernameinput,".bin");
            //printf("%s",usernameinput);
            getchar();
            if((fip=fopen(usernameinput,"r"))!=NULL){
                system("cls");
                system ("color 0c") ;
                printf("\nMaaf, akun ini telah digunakan\nMohon gunakan username dan password yang berbeda\n");
                printf("Klik enter untuk kembali ke menu utama\n");
                getch();
                system("cls");
                goto mainmenu;
            }
            //printf("\nhasil sttcat .bin: %s",usernameinput);
            FILE* finp = fopen(usernameinput,"wb");
            fwrite(username, sizeof(char), sizeof(username)/sizeof(char), finp);
            //membaca file binary
            fclose(finp);
            // finp=fopen(usernameinput,"rb");
            // fread(username, sizeof(char), sizeof(username)/sizeof(char), finp);
     		// printf("\n%s.",username);
            printf("\nAnda berhasil login!");
            printf("\nGunakan akun %s untuk login",username);
            getchar();
            system("cls");
            goto mainmenu;   
        }
    }else if(arguments == 2){
        //char usernameinput[50], passwordinput[50];
        //printf("sampai disini\n");
        strcpy(usernameinput, argument[1]);
        char* user[3];
        user[0] = strtok(usernameinput, "@");
        //printf("%s\n",user[0]);
        int ctrl=0;
        while(user[ctrl++] != NULL)
        {
            user[ctrl] = strtok(NULL, "@");
        }
        //printf("%s\n",user[1]);
         //printf("sampai disini\n");
        FILE *fpr;
        strcat(argument[1],".bin");
        if((fpr = fopen(argument[1], "rb")) == NULL)
        {
            printf("\nMaaf, Anda belum mendaftar\nSilahkan daftar terlebih dahulu..\n");
            return EXIT_FAILURE;
        }

        char account[100];
        fread(account, sizeof(char), sizeof(account)/sizeof(char), fpr);
        //printf("%s",account);
        fclose(fpr);


        char *string[3];
        char username[50], password[50];
        //int ctrl = 0;

        string[0] = strtok(account, "@");
        //printf("%s\n",string[0]);
        ctrl=0;
        while(string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, "@");
        }
        // printf("%s\n",string[1]);
        strcpy(username, string[0]);
        strcpy(password, string[1]);
        //printf("%s\n",password);
        //printf("usernameinput:%s,passwordinput:%s,input:%s,pass:%s",user[0],user[1],username,password);
        if( (strcmp(user[0], username) == 0) && (strcmp(user[1], password) == 0) )
        {
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
        
        //toupper(username);
        printf("Welcome %s!\n",username);
        //mulai permainan
    }
    return 0;
}
