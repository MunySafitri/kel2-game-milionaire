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
    }


    return 0;
}