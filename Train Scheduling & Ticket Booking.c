#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


typedef struct kota {
	char kode[100];
	char namaKota[100];
} kota;

typedef struct rute {
	char keberangkatan[100];
	char tujuan[100];
	char kode[100];
	char kode1[100];
	char kode2[100];
	char kode4[100];
	int bisnis;
	int premium;
}rute;

typedef struct jadwal {
	char kode[100];
	char tanggal[100];
	char waktuKbrt[100];
	char kbrt[100];
	char tjn[100];
	char kai[100];
	int sisa;
	int pemasukan;
}jadwal;


typedef struct dataUser{
    int rno; //Member of structure
    char name[20]; //Pointer within structure
    struct subject{ //Structure within Structure
        int scode;
        char name[20]; //Array within structure
        int mark;
    }sub[3]; //Array of Structure
    int total;
    float per;
    
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} dataUser;

int pilih1, pilih2, pilih3,pilih4,pilih5,pilih6,pilih7;
int userbenar,passbenar;
FILE *pf, *pf1;
int i=1;
char hp[12];
char email[30];
char pass[20];
char repass[20];
char namaLengkap[20];
char kar,again = 'y';	
char user[20],passw[20];
char emailAdmin[20], passAdmin[30];

int menu_utama(){
		printf("\n===========================================\n\t\tKereta Api\n-------------------------------------------\n");
        printf("Pilih salah satu pengguna!");
        printf("\n1. User");
        printf("\n2. Admin");
        printf("\n3. Keluar");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda ?");
        scanf("%d",&pilih1);
        printf("\n===========================================\n");
        if(pilih1>3){
     		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(pilih1){
			case 1:
				{
				pengguna();
				break;	
			}
			case 2:
				{
					login_admin();
					break;
				}
			case 3:
				{
					system("exit");
				}
		}
	}

int menu_user(){
	do{
		system("cls");
		printf("========Menu Pengguna========\n");
		printf("Welcome %s \n", user);
		printf("1. Kelola Profile\n");
		printf("2. Lihat Data Kota\n");
		printf("3. Lihat Data Rute\n");
		printf("4. Lihat Jadwal\n");
		printf("5. Logout");
		printf("\nPilihan Anda : ");
		scanf("%d",&pilih3);
		if(pilih3>4){
			system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(pilih3){
			case 1:
				system("cls");
				kelola_akun();
				printf("\n\nMenu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
				
			case 2:
				system("cls");
				kota *k;
				FILE *city, *city1;
				int n,i,j;
				kota k1;
		    	city = fopen("kota.txt","r");
				int counter = 1;
			    city = fopen("kota.txt","r");
				printf("#LIHAT DATA KOTA#");
				printf("\nData Lengkap Kota");
				printf("\n-------------------------------------------------------------------\n");
				printf("No\t\tKode Kota\t\tNama Kota\n");
				while(fread(&k1,sizeof(kota),1,city)) { 
					printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.namaKota);
					counter++;
			    }
				printf("\n\n-------------------------------------------------------------------");
	    		fclose(city);
				printf("\nMenu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
			
			case 3:
				system("cls");
				lihat_rute();
				printf("\nMenu Utama [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
			
			case 4:
				system("cls");
				lihat_jadwal();
				printf("\nMenu Utama [y/t] ? ");
				again=getch();
				system("cls");
			
			case 5:
				system("cls");
				menu_utama();
				system("cls");
		}
	}while(again == 'y');
}

int login_user(){
			system("cls");  
			 int i, j, found=0;
    dataUser s1;
    dataUser *s;
    char email[100];
    char password[100];
			printf("======================\n");
			printf("LOGIN\n");
			printf("======================\n");
			fflush(stdin);
			printf("Username : ");
    		scanf("%[^\n]s",email);
    		fflush(stdin);
    		printf("Password : ");
    		scanf("%[^\n]s",password);

    pf = fopen("dataUser.txt","r");
    while(fread(&s1,sizeof(dataUser),1,pf)){
        if(strcmp(s1.email,email)==0){
            if (strcmp(s1.password,password)==0) {	
       			menu_user();
				found = 1;
				fclose(pf);
			}else if(!found){
				login_user();
			}
        }
	    
	    int pengguna(){
		do{
		system("cls");
        printf("\n===========================================\n\t\tHalaman User\n-------------------------------------------\n");
        printf("Pilih salah satu pengguna!");
        printf("\n1. Registrasi\n");
        printf("\n2. Login\n");
        printf("\n3. Keluar");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda ?");
        scanf("%d",&pilih2);
        printf("\n===========================================\n");
        if(pilih2>3){
     		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(pilih2){
			case 1:
				
				system("cls");
				printf("======================\n");
				printf("REGISTRASI\n");
				printf("======================\n");
				
		           	 dataUser *s;
		        	int n,i,j;

		        s = (dataUser*)malloc(100*sizeof(dataUser));
		        pf = fopen("dataUser.txt","w+");
		
		        for(i=0;i<1;i++){
		        	fflush(stdin);
		            printf("Nomor KTP : ");
		            scanf("%[^\n]s",s[i].ktp);
		            fflush(stdin);
		            printf("Nama Lengkap : ");
		            scanf("%[^\n]s",s[i].nama);
		            fflush(stdin);
		            printf("Nomor Handphone : ");
		            scanf("%[^\n]s",s[i].hp);
		            fflush(stdin);
		            printf("Email : ");
		            scanf("%[^\n]s",s[i].email);
		            fflush(stdin);
		            printf("Password : ");
		            scanf("%[^\n]s",s[i].password);
		            fflush(stdin);
		            printf("Re-Password : ");
		            scanf("%[^\n]s",s[i].repassword);
		
		            fwrite(s+i,sizeof(dataUser),1,pf);
				        }
				    fclose(pf);
				
				printf("Kembali ke menu [y/t] ? ");
        		again=getch();
				break;	
			
			case 2:
					login_user();
					break;
				
			case 3:
					system("cls");
					menu_utama();
					break;
		
		}
	}while (again == 'y');
}
	}
}
