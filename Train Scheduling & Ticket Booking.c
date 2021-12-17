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
