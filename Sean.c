#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;	
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

struct history{
	char list[100];
};

void loadingscreen();
void Exit();

typedef struct pasien{
	int id;
	char nama[25]; 
	char goldarah[3], diagnosa[25], keluhan[25]; 
}pasien;

int main(){
	char admin[10], pass[10], chara, conf,  ubnama[25], ubgol[3], ubkel[25], ubdiag[25], carnama[25], carkel[25], cargol[3], cardiag[25], z[50];
	int i, pilihan, banyak=0, data, tam, banyak1, dhapus, hapbag1, del, del2, pos, temukan = 0, idgan, pilgan, ubah, pilcar, carid, confh, pilur, urut, urut1, j;	
	pasien psn[100];
	pasien temp;
	struct history hst[100];
	int history = -1, history_display;
	char cur_time[128];
    time_t t;
    struct tm* ptm;
    t = time(NULL);
    ptm = localtime(&t);
    strftime(cur_time, 128, "%b %d %Y \t\t\t     %H:%M:%S", ptm);
	
	login :
		system("color 47");
		gotoxy(35,7);	
		printf("  SELAMAT DATANG DI DATABASE RUMAH SAKIT");	
		gotoxy(35,9);
		printf("==========================================");
		gotoxy(35,13);
		printf("==========================================");	
		gotoxy(35,14);
		printf("%s\n", cur_time);
		gotoxy(35,10);
		printf("Masukkan username (admin) : ");
		scanf("%s", &admin);
		printf("\n");
		gotoxy(35,12);
		printf("Masukkan password (admin) : ");
	
		i = 0;
		while(i < 9){
			pass[i] = getch();
			chara = pass[i];
			if(chara == 13)break;
			else printf("*");
			i++;
		}
		pass[i]='\0';
		i = 0;
		
		gotoxy(35,18);
		if(strcmp(admin, "admin") == 0 && strcmp(pass, "admin") == 0){
			system("cls");
			loadingscreen();
			system("cls");
			goto menu;
			
		}else{
			printf("Password atau Username salah");
			getch();
			system("cls");
			goto login;
		}
	menu :
		system("color 17");
		Sleep(50);
		gotoxy(26,4);
		printf("+=================================================================+");
		Sleep(50);
		gotoxy(40,6);
		printf("SELAMAT DATANG DI DATABASE RUMAH SAKIT");
		Sleep(50);
		gotoxy(47,7);
		printf(" === DATA PASIEN RS ===");
		Sleep(50);
		gotoxy(26,9);
		printf("+-----------------------------------------------------------------+");
		Sleep(50);
		gotoxy(26,11);
		printf("|                                                                 |");
		Sleep(50);
		gotoxy(26,12);
		printf("|   Tekan 1. Membuat Database Pasien                              |");
		Sleep(50);
		gotoxy(26,13);
		printf("|   Tekan 2. Menampilkan Isi Database Pasien                      |");
		Sleep(50);
		gotoxy(26,14);
		printf("|   Tekan 3. Menambah Data Baru ke Database Pasien                |");
		Sleep(50);
		gotoxy(26,15);
		printf("|   Tekan 4. Menghapus Data di Database Pasien                    |");
		Sleep(50);
		gotoxy(26,16);
		printf("|   Tekan 5. Mengedit Data di Database Pasien                     |");
		Sleep(50);
		gotoxy(26,17);
		printf("|   Tekan 6. Mencari Data di Database Pasien                      |");
		Sleep(50);
		gotoxy(26,18);
		printf("|   Tekan 7. Riwayat Aktivitas                                    |");
		Sleep(50);
		gotoxy(26,19);
		printf("|   Tekan 8. Mengurutkan Data di Database Pasien                  |");
		Sleep(50);
		gotoxy(26,20);
		printf("|   Tekan 9. Keluar Dari Program                                  |");
		Sleep(50);
		gotoxy(26,21);
		printf("|                                                                 |");
		Sleep(50);
		gotoxy(26,22);
		printf("|   Masukkan Pilihan Anda : ");
		Sleep(50);
		gotoxy(92,22);
		printf("|");
		Sleep(50);
		gotoxy(26,24);
		printf("+=================================================================+");
		gotoxy(54,22);
		scanf("%d", &pilihan);
		
		if(pilihan == 1){
			system("cls");
			system("color 04");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(41,4);
			printf("=== Membuat Database Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(39,7);
			printf("Data Maksimum yang bisa diinput : 100");
			gotoxy(39,8);
			printf("Banyak Data yang ingin diiput   : ");
			gotoxy(18,9);
			printf("+===============================================================================+\n");
			gotoxy(73,8);
			scanf("%d", &banyak);
			data = 0;
			while(data < banyak){
				printf("\n\t\t  :: DATA PASIEN KE-%d\n", data+1);
				printf("\t\t  :: Nama Pasien     : ");
				scanf(" %[^\n]", &psn[data].nama);
				printf("\t\t  :: ID Pasien       : ");
				scanf("%d", &psn[data].id);
				printf("\t\t  :: Golongan Darah  : ");
				scanf("%s", &psn[data].goldarah);
				printf("\t\t  :: Keluhan         : ");
				scanf(" %[^\n]", &psn[data].keluhan);
				printf("\t\t  :: Diagnosa        : ");
				scanf(" %[^\n]", &psn[data].diagnosa);
				data++;
			}
			printf("\n\t\t  Press Any Key to Continue >> ");
			getch();
			history += 1;
			sprintf(z, "%d", banyak);
			char bag1[] = "Admin Membuat ";
			strcat(bag1, z);
			strcat(bag1, " Data Baru");
			strcpy(hst[history].list, bag1);
			system("cls");
			goto menu;	
		}else if(pilihan == 2){
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("DATA PASIEN RS");
			gotoxy(41,4);
			printf("Data Pasien yang Telah Diinput");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			gotoxy(12,7);printf("NAMA");		
			gotoxy(37,7);printf("ID");
			gotoxy(42,7);printf("Gol. Darah");
			gotoxy(56,7);printf("Keluhan");
			gotoxy(83,7);printf("Diagnosa");
			gotoxy(11,8);
			printf("+-------------------------------------------------------------------------------------------------+");
			for(tam = 0 ; tam < banyak ; tam++){
				gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
				gotoxy(37,9+tam);printf("%d", psn[tam].id);
				gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
				gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
				gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
			}
			gotoxy(11,9+tam);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tam);
			printf("Press Any Key to Continue >> ");
			getch();
			history += 1;
			char bag2[] = "Admin Menampilkan Data ";
			strcpy(hst[history].list, bag2);
			system("cls");
			goto menu;	
		}else if(pilihan == 3){
			system("cls");
			system("color 05");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(41,4);
			printf("=== Menambah Database Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(39,7);
			printf("Data Maksimum yang bisa diinput : 100");
			gotoxy(39,8);
			printf("Banyak Data yang ingin diiput   : ");
			gotoxy(18,9);
			printf("+===============================================================================+\n");
			gotoxy(73,8);
			scanf("%d", &banyak1);
			data = banyak;
			while(data < banyak+banyak1){
				printf("\n\t\t  :: DATA PASIEN KE-%d\n", data+1);
				printf("\t\t  :: Nama Pasien     : ");
				scanf(" %[^\n]", &psn[data].nama);
				printf("\t\t  :: ID Pasien       : ");
				scanf("%d", &psn[data].id);
				printf("\t\t  :: Golongan Darah  : ");
				scanf("%s", &psn[data].goldarah);
				printf("\t\t  :: Keluhan         : ");
				scanf(" %[^\n]", &psn[data].keluhan);
				printf("\t\t  :: Diagnosa        : ");
				scanf(" %[^\n]", &psn[data].diagnosa);
				data++;
			}
			banyak = banyak+banyak1;
			printf("\n\t\t  Press Any Key to Continue >> ");
			getch();
			history += 1;
			sprintf(z, "%d", banyak1);
			char bag3[] = "Admin Menambah ";
			strcat(bag3, z);
			strcat(bag3, " Data ");
			strcpy(hst[history].list, bag3);
			system("cls");
			goto menu;	
		}else if(pilihan == 4){
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("DATA PASIEN RS");
			gotoxy(41,4);
			printf("Data Pasien yang Telah Diinput");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			gotoxy(12,7);printf("NAMA");		
			gotoxy(37,7);printf("ID");
			gotoxy(42,7);printf("Gol. Darah");
			gotoxy(56,7);printf("Keluhan");
			gotoxy(83,7);printf("Diagnosa");
			gotoxy(11,8);
			printf("+-------------------------------------------------------------------------------------------------+");
			if(banyak == 0){
				gotoxy(11,9);printf("Data Belum Ada");
				gotoxy(11,10);printf("+-------------------------------------------------------------------------------------------------+");
				gotoxy(11, 11);printf("Press Any Key to Continue");
				getch();
				system("cls");
				goto menu;
			}
			for(tam = 0 ; tam < banyak ; tam++){
				gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
				gotoxy(37,9+tam);printf("%d", psn[tam].id);
				gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
				gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
				gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
			}
			gotoxy(11,9+tam);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tam);
			printf("Press Any Key to Continue >> ");
			getch();
			system("cls");
		menu3:
			system("color 87");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(44,4);
			printf("=== Menghapus Data Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(41,7);
			printf("Masukkan ID yang ingin dihapus : ");
			gotoxy(18,8);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(74, 7);
			scanf("%d", &dhapus);
			
			for(confh = 0 ; confh < banyak ; confh++){
				if(psn[confh].id == dhapus){
					goto menukhusus;
				}
			}
			for(confh = 0 ; confh < banyak ; confh++){
				if(psn[confh].id != dhapus){
					gotoxy(18,9);
					printf("Data Dengan ID : %d, Tidak Tersedia", dhapus);
					gotoxy(18,10);
					printf("Press Any Key to Continue >> ");
					getch();
					system("cls");
					goto menu;
				}
			}
		menukhusus:
			for(confh = 0 ; confh < banyak ; confh++){
				gotoxy(41,9);printf(":: DATA");
				for(hapbag1 = 0 ; hapbag1 < banyak ; hapbag1++){
					if(dhapus == psn[hapbag1].id){
						gotoxy(41,10);printf(":: Nama Pasien    : %s", psn[hapbag1].nama);
						gotoxy(41,11);printf(":: ID Pasien      : %d", psn[hapbag1].id);
						gotoxy(41,12);printf(":: Golongan Darah : %s", psn[hapbag1].goldarah);
						gotoxy(41,13);printf(":: Keluhan        : %s", psn[hapbag1].keluhan);
						gotoxy(41,14);printf(":: Diagnosa       : %s", psn[hapbag1].diagnosa);
					}
				}
				gotoxy(41, 16);printf("Lanjutkan menghapus? [y|n] ---> ");
				scanf("%s", &conf);
				if(conf == 'y'|| conf == 'Y'){
					for(del = 0 ; del < banyak ; del++){
						if(psn[del].id == dhapus){
							temukan = 1;
							pos = del;
							break;
						}
					}
					banyak = banyak-1;
					if(temukan == 1){
						for(del2 = pos ; del2 < banyak ; del2++){
							psn[del2] = psn[del2+1];
						}
					}
					gotoxy(41,18);
					printf("Data %d telah dihapus!", dhapus);
					gotoxy(41,19);
					printf("Press Any Key to Continue >> ");
					getch();
					history += 1;
					sprintf(z, "%d", dhapus);
					char bag4[] = "Admin Menghapus Data Dengan ID Pasien ' ";
					strcat(bag4, z);
					strcat(bag4, " '");
					strcpy(hst[history].list, bag4);
					system("cls");
					goto menu;
				}else{
					gotoxy(41,18);
					printf("Data %d tidak jadi dihapus!", dhapus);
					gotoxy(41,19);
					printf("Press Any Key to Continue >> ");
					getch();
					history += 1;
					sprintf(z, "%d", dhapus);
					char bag4_2[] = "Admin Batal Menghapus Data Dengan ID Pasien ' ";
					strcat(bag4_2, z);
					strcat(bag4_2, " '");
					strcpy(hst[history].list, bag4_2);
					system("cls");
					goto menu;
				}
			}
			}else if(pilihan == 5){	
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("DATA PASIEN RS");
			gotoxy(41,4);
			printf("Data Pasien yang Telah Diinput");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			gotoxy(12,7);printf("NAMA");		
			gotoxy(37,7);printf("ID");
			gotoxy(42,7);printf("Gol. Darah");
			gotoxy(56,7);printf("Keluhan");
			gotoxy(83,7);printf("Diagnosa");
			gotoxy(11,8);
			printf("+-------------------------------------------------------------------------------------------------+");
			if(banyak == 0){
				gotoxy(11,9);printf("Data Belum Ada");
				gotoxy(11,10);printf("+-------------------------------------------------------------------------------------------------+");
				gotoxy(11, 11);printf("Press Any Key to Continue");
				getch();
				system("cls");
				goto menu;
			}
			for(tam = 0 ; tam < banyak ; tam++){
				gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
				gotoxy(37,9+tam);printf("%d", psn[tam].id);
				gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
				gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
				gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
			}
			gotoxy(11,9+tam);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tam);
			printf("Press Any Key to Continue >> ");
			getch();
		menu1:
			system("cls");
			system("color 0C");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(44,4);
			printf("=== Mengubah Data Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Apa yang ingin anda edit? ");
			gotoxy(34, 8);printf("1. Nama Pasien             3. Keluhan Pasien");
			gotoxy(34, 9);printf("2. Golongan Darah          4. Diagnosa Pasien");
			gotoxy(34, 11);printf("Pilihan anda       : ");
			gotoxy(34, 12);printf("Masukkan ID Pasien : ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(55, 11);scanf("%d", &pilgan);
			gotoxy(55, 12);scanf("%d", &idgan);
			if(pilgan == 1){
				gotoxy(34,14);printf("UBAH DATA NAMA PASIEN");
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan == psn[ubah].id){
						gotoxy(34,15);printf("Data saat ini  : %s", psn[ubah].nama);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubnama);
						history += 1;
						sprintf(z, "%d", psn[ubah].id);
						char bag5_1[] = "Admin Mengubah Nama Pasien Dengan ID ' ";
						strcat(bag5_1, z);
						strcat(bag5_1, " ' Dari ");
						strcat(bag5_1, psn[ubah].nama);
						strcat(bag5_1, " Menjadi ");
						strcat(bag5_1, ubnama);
						strcpy(hst[history].list, bag5_1);
						strcpy(psn[ubah].nama, ubnama);
						gotoxy(34, 17);	
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan != psn[ubah].id){
						gotoxy(34,14);
						printf("Tidak Ada ID Pasien bernomor %d!", idgan);
						gotoxy(34, 16);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu1;	
					}
				}
			}else if(pilgan == 2){
				gotoxy(34,14);printf("UBAH DATA GOL. DARAH PASIEN");
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan == psn[ubah].id){
						gotoxy(34,15);printf("Data saat ini  : %s", psn[ubah].goldarah);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf("%s", &ubgol);
						history += 1;
						sprintf(z, "%d", psn[ubah].id);
						char bag5_2[] = "Admin Mengubah Golongan Darah Pasien Dengan ID ' ";
						strcat(bag5_2, z);
						strcat(bag5_2, " ' Dari ");
						strcat(bag5_2, psn[ubah].goldarah);
						strcat(bag5_2, " Menjadi ");
						strcat(bag5_2, ubgol);
						strcpy(hst[history].list, bag5_2);
						strcpy(psn[ubah].goldarah, ubgol);
						gotoxy(34, 17);	
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan != psn[ubah].id){
						gotoxy(34,14);
						printf("Tidak Ada ID Pasien bernomor %d!", idgan);
						gotoxy(34, 16);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu1;	
					}
				}
			}else if(pilgan == 3){
				gotoxy(34,14);printf("UBAH DATA KELUHAN PASIEN");
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan == psn[ubah].id){
						gotoxy(34,15);printf("Data saat ini  : %s", psn[ubah].keluhan);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubkel);
						history += 1;
						sprintf(z, "%d", psn[ubah].id);
						char bag5_3[] = "Admin Mengubah Keluhan Pasien Dengan ID ' ";
						strcat(bag5_3, z);
						strcat(bag5_3, " ' Dari ");
						strcat(bag5_3, psn[ubah].keluhan);
						strcat(bag5_3, " Menjadi ");
						strcat(bag5_3, ubkel);
						strcpy(hst[history].list, bag5_3);
						strcpy(psn[ubah].keluhan, ubkel);
						gotoxy(34, 17);	
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu;
					}
				}	
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan != psn[ubah].id){
						gotoxy(34,14);
						printf("Tidak Ada ID Pasien bernomor %d!", idgan);
						gotoxy(34, 16);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu1;	
					}
				}
			}else if(pilgan == 4){
				gotoxy(34,14);printf("UBAH DATA DIAGNOSA PASIEN");
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan == psn[ubah].id){
						gotoxy(34,15);printf("Data saat ini  : %s", psn[ubah].diagnosa);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubdiag);
						history += 1;
						sprintf(z, "%d", psn[ubah].id);
						char bag5_4[] = "Admin Mengubah Diagnosa Pasien Dengan ID ' ";
						strcat(bag5_4, z);
						strcat(bag5_4, " ' Dari ");
						strcat(bag5_4, psn[ubah].diagnosa);
						strcat(bag5_4, " Menjadi ");
						strcat(bag5_4, ubdiag);
						strcpy(hst[history].list, bag5_4);
						strcpy(psn[ubah].diagnosa, ubdiag);
						gotoxy(34, 17);	
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(ubah = 0 ; ubah < banyak ; ubah++){
					if(idgan != psn[ubah].id){
						gotoxy(34,14);
						printf("Tidak Ada ID Pasien bernomor %d!", idgan);
						gotoxy(34, 16);
						printf("Press Any Key to Continue >> ");
						getch();
						system("cls");
						goto menu;	
					}
				}	
			}else{
				gotoxy(34,14);
				printf("Pilihan Tidak Tersedia!");
				gotoxy(34, 16);
				printf("Press Any Key to Continue >> ");
				getch();
				system("cls");
				goto menu;				
			}
		}else if(pilihan == 6){
		menu2:
			system("cls");
			system("color 02");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(42,4);
			printf("=== Mencari Database Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Apa yang ingin anda cari : ");
			gotoxy(34, 8);printf("1. Nama Pasien             4. Keluhan Pasien");
			gotoxy(34, 9);printf("2. ID Pasien               5. Diagnosa Pasien");
			gotoxy(34, 10);printf("3. Golongan Darah   ");
			gotoxy(34, 11);printf("Pilihan anda                   : ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(67, 11);scanf("%d", &pilcar);	
			if(pilcar == 1){
				gotoxy(34, 12);
				printf("Nama Pasien yang Dicari        : ");
				scanf(" %[^\n]", &carnama);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tam = 0 ; tam < banyak ; tam++){
					if(strcmp(psn[tam].nama, carnama) == 0){
						gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
						gotoxy(37,9+tam);printf("%d", psn[tam].id);
						gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
						gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
						gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag6_1[] = "Admin Mencari Data Dengan Nama ' ";
				strcat(bag6_1, carnama);
				strcat(bag6_1, " '");
				strcpy(hst[history].list, bag6_1);
				system("cls");
				goto menu;	
			}else if(pilcar == 2){
				gotoxy(34, 12);
				printf("ID Pasien yang Dicari          : ");
				scanf("%d", &carid);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tam = 0 ; tam < banyak ; tam++){
					if(psn[tam].id == carid){
						gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
						gotoxy(37,9+tam);printf("%d", psn[tam].id);
						gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
						gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
						gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				history += 1;
				sprintf(z, "%d", carid);
				char bag6_2[] = "Admin Mencari Data Dengan ID ' ";
				strcat(bag6_2, z);
				strcat(bag6_2, " '");
				strcpy(hst[history].list, bag6_2);
				getch();
				system("cls");
				goto menu;	
			}else if(pilcar == 3){
				gotoxy(34, 12);
				printf("Gol. Darah Pasien yang Dicari  : ");
				scanf(" %[^\n]", &cargol);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tam = 0 ; tam < banyak ; tam++){
					if(strcmp(psn[tam].goldarah, cargol) == 0){
						gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
						gotoxy(37,9+tam);printf("%d", psn[tam].id);
						gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
						gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
						gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag6_3[] = "Admin Mencari Data Dengan Golongan Darah ' ";
				strcat(bag6_3, cargol);
				strcat(bag6_3, " '");
				strcpy(hst[history].list, bag6_3);
				system("cls");
				goto menu;	
			}else if(pilcar == 4){
				gotoxy(34, 12);
				printf("Keluhan Pasien yang Dicari     : ");
				scanf(" %[^\n]", &carkel);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tam = 0 ; tam < banyak ; tam++){
					if(strcmp(psn[tam].keluhan, carkel) == 0){
						gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
						gotoxy(37,9+tam);printf("%d", psn[tam].id);
						gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
						gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
						gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag6_4[] = "Admin Mencari Data Dengan Keluhan ' ";
				strcat(bag6_4, carkel);
				strcat(bag6_4, " '");
				strcpy(hst[history].list, bag6_4);
				system("cls");
				goto menu;	
			}else if(pilcar == 5){
				gotoxy(34, 12);
				printf("Diagnosa Pasien yang Dicari    : ");
				scanf(" %[^\n]", &cardiag);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tam = 0 ; tam < banyak ; tam++){
					if(strcmp(psn[tam].diagnosa, cardiag) == 0){
						gotoxy(12,9+tam);printf("%s", psn[tam].nama);		
						gotoxy(37,9+tam);printf("%d", psn[tam].id);
						gotoxy(46,9+tam);printf("%s", psn[tam].goldarah);
						gotoxy(56,9+tam);printf("%s", psn[tam].keluhan);
						gotoxy(83,9+tam);printf("%s", psn[tam].diagnosa);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag6_5[] = "Admin Mencari Data Dengan Diagnosa ' ";
				strcat(bag6_5, cardiag);
				strcat(bag6_5, " '");
				strcpy(hst[history].list, bag6_5);
				system("cls");
				goto menu;	
			}else{
				gotoxy(18,14);
				printf("Pilihan tidak ada!");
				gotoxy(18,16);
				printf("Press Any Key to Continue >> ");
				getch();
				system("cls");
				goto menu2;	
			}
		}else if(pilihan == 7){
			system("cls");
			system("color 05");
			history += 1;
			char bag7[] = "Admin Mengecek Riwayat Aktivitas";
			strcpy(hst[history].list, bag7);
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("DATA PASIEN RS");
			gotoxy(41,4);
			printf("Data Pasien yang Telah Diinput");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			gotoxy(15,7);
			printf("NO.");
			gotoxy(21,7);
			printf("AKTIVITAS");
			gotoxy(11,8);
			printf("---------------------------------------------------------------------------------------------------");
			for(history_display = 0 ; history_display < history+1 ; history_display++){
				gotoxy(15,9+history_display);printf("%d", history_display+1);
				gotoxy(21,9+history_display);printf("%s", hst[history_display].list);	
			}
			gotoxy(11,9+history_display);
			printf("---------------------------------------------------------------------------------------------------");
			gotoxy(11, 11+history_display);
			printf("Press Any Key to Continue");
			getch();
			system("cls");
			goto menu;
		}else if(pilihan == 8){
			system("cls");
			system("color 02");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(38,4);
			printf("=== Mengurutkan Database Pasien ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Urutkan berdasarkan apa?");
			gotoxy(34, 8);printf("1. Nama Pasien             4. Keluhan Pasien");
			gotoxy(34, 9);printf("2. ID Pasien               5. Diagnosa Pasien");
			gotoxy(34, 10);printf("3. Golongan Darah   ");
			gotoxy(34, 11);printf("Pilihan anda  :  ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(51,11);
			scanf("%d", &pilur);
			if(pilur == 1){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(i = 0 ; i < banyak ; i++){
					for(j = 0 ; j < banyak ; j++){
						if (strcmp(psn[i].nama,psn[j].nama)< 0){
                			temp=psn[i];
                			psn[i]=psn[j];
                			psn[j]=temp;
            			}
					}
				}
				for(urut1 = 0 ; urut1 < banyak ; urut1++){
					gotoxy(12,9+urut1);printf("%s", psn[urut1].nama);	
					gotoxy(37,9+urut1);printf("%d", psn[urut1].id);
					gotoxy(46,9+urut1);printf("%s", psn[urut1].goldarah);
					gotoxy(56,9+urut1);printf("%s", psn[urut1].keluhan);
					gotoxy(83,9+urut1);printf("%s", psn[urut1].diagnosa);	
				}
				printf("\n           +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag8_1[] = "Admin Mengurutkan Data Berdasarkan Nama pasien";
				strcpy(hst[history].list, bag8_1);
				system("cls");
				goto menu;
			}else if(pilur == 2){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(i = 0 ; i < banyak ; i++){
					for(j = 0 ; j < banyak ; j++){
						if (psn[i].id > psn[j].id){
                			temp=psn[i];
                			psn[i]=psn[j];
                			psn[j]=temp;
            			}
					}
				}
				for(urut1 = 0 ; urut1 < banyak ; urut1++){
					gotoxy(12,9+urut1);printf("%s", psn[urut1].nama);	
					gotoxy(37,9+urut1);printf("%d", psn[urut1].id);
					gotoxy(46,9+urut1);printf("%s", psn[urut1].goldarah);
					gotoxy(56,9+urut1);printf("%s", psn[urut1].keluhan);
					gotoxy(83,9+urut1);printf("%s", psn[urut1].diagnosa);	
				}
				printf("\n           +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag8_2[] = "Admin Mengurutkan Data Berdasarkan ID pasien";
				strcpy(hst[history].list, bag8_2);
				system("cls");
				goto menu;
			}else if(pilur == 3){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(i = 0 ; i < banyak ; i++){
					for(j = 0 ; j < banyak ; j++){
						if (strcmp(psn[i].goldarah,psn[j].goldarah)< 0){
                			temp=psn[i];
                			psn[i]=psn[j];
                			psn[j]=temp;
            			}
					}
				}
				for(urut1 = 0 ; urut1 < banyak ; urut1++){
					gotoxy(12,9+urut1);printf("%s", psn[urut1].nama);	
					gotoxy(37,9+urut1);printf("%d", psn[urut1].id);
					gotoxy(46,9+urut1);printf("%s", psn[urut1].goldarah);
					gotoxy(56,9+urut1);printf("%s", psn[urut1].keluhan);
					gotoxy(83,9+urut1);printf("%s", psn[urut1].diagnosa);	
				}
				printf("\n           +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag8_3[] = "Admin Mengurutkan Data Berdasarkan Golongan Darah pasien";
				strcpy(hst[history].list, bag8_3);
				system("cls");
				goto menu;
			}else if(pilur == 4){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
				for(i = 0 ; i < banyak ; i++){
					for(j = 0 ; j < banyak ; j++){
						if (strcmp(psn[i].keluhan,psn[j].keluhan)< 0){
                			temp=psn[i];
                			psn[i]=psn[j];
                			psn[j]=temp;
            			}
					}
				}
				for(urut1 = 0 ; urut1 < banyak ; urut1++){
					gotoxy(12,9+urut1);printf("%s", psn[urut1].nama);	
					gotoxy(37,9+urut1);printf("%d", psn[urut1].id);
					gotoxy(46,9+urut1);printf("%s", psn[urut1].goldarah);
					gotoxy(56,9+urut1);printf("%s", psn[urut1].keluhan);
					gotoxy(83,9+urut1);printf("%s", psn[urut1].diagnosa);	
				}
				printf("\n           +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag8_4[] = "Admin Mengurutkan Data Berdasarkan Keluhan pasien";
				strcpy(hst[history].list, bag8_4);
				system("cls");
				goto menu;
			}else if(pilur == 5){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("DATA PASIEN RS");
				gotoxy(41,4);
				printf("Data Pasien yang Telah Diinput");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				gotoxy(12,7);printf("NAMA");		
				gotoxy(37,7);printf("ID");
				gotoxy(42,7);printf("Gol. Darah");
				gotoxy(56,7);printf("Keluhan");
				gotoxy(83,7);printf("Diagnosa");
				gotoxy(11,8);
				printf("+-------------------------------------------------------------------------------------------------+");
					for(i = 0 ; i < banyak ; i++){
					for(j = 0 ; j < banyak ; j++){
						if (strcmp(psn[i].diagnosa,psn[j].diagnosa)< 0){
                			temp=psn[i];
                			psn[i]=psn[j];
                			psn[j]=temp;
            			}
					}
				}
				for(urut1 = 0 ; urut1 < banyak ; urut1++){
					gotoxy(12,9+urut1);printf("%s", psn[urut1].nama);	
					gotoxy(37,9+urut1);printf("%d", psn[urut1].id);
					gotoxy(46,9+urut1);printf("%s", psn[urut1].goldarah);
					gotoxy(56,9+urut1);printf("%s", psn[urut1].keluhan);
					gotoxy(83,9+urut1);printf("%s", psn[urut1].diagnosa);	
				}
				printf("\n           +-------------------------------------------------------------------------------------------------+");
				printf("\n           Press Any Key to Continue >> ");
				getch();
				history += 1;
				char bag8_5[] = "Admin Mengurutkan Data Berdasarkan Diagnosa pasien";
				strcpy(hst[history].list, bag8_5);
				system("cls");
				goto menu;
			}else{
				gotoxy(17,15);printf("Pilihan tidak ada!");
				gotoxy(19,15);printf("\n            Press Any Key to Continue >> ");
				getch();
				system("cls");
				goto menu;
			}
		}else if(pilihan == 9){
			system("cls");
			Exit();
			printf("\n\n\n\n\n\n\n");
		}else{
			gotoxy(26,26);
			printf("Pilihan tidak ada");
			gotoxy(26,27);
			printf("Press Any Key to Continue >> ");
			getch();
			system("cls");
			goto menu;
		}
	}	
	
void Exit(){
	int s;
	char persen='%';
	char ch=177, ce = 178;
	system("color 04");
	system("cls");
	gotoxy(41, 13);
	printf("A");
	Sleep(70);
	gotoxy(42, 13);
	printf("u");
	Sleep(70);
	gotoxy(43, 13);
	printf("t");
	Sleep(70);
	gotoxy(44, 13);
	printf("h");
	Sleep(70);
	gotoxy(45, 13);
	printf("o");
	Sleep(70);
	gotoxy(46, 13);
	printf("r");
	Sleep(70);
	gotoxy(47, 13);
	printf("");
	Sleep(70);
	gotoxy(48, 13);
	printf(":");
	Sleep(70);
	gotoxy(49, 13);
	printf("");
	Sleep(70);
	gotoxy(50, 13);
	printf("S");
	Sleep(70);
	gotoxy(51, 13);
	printf("e");
	Sleep(70);
	gotoxy(52, 13);
	printf("a");
	Sleep(70);
	gotoxy(53, 13);
	printf("n");
	Sleep(70);
	gotoxy(54, 13);
	printf("");
	Sleep(70);
	gotoxy(55, 13);
	printf("A");
	Sleep(70);
	gotoxy(56, 13);
	printf("l");
	Sleep(70);
	gotoxy(57, 13);
	printf("e");
	Sleep(70);
	gotoxy(58, 13);
	printf("s");
	Sleep(70);
	gotoxy(59, 13);
	printf("s");
	Sleep(70);
	gotoxy(60, 13);
	printf("a");
	Sleep(70);
	gotoxy(61, 13);
	printf("n");
	Sleep(70);
	gotoxy(62, 13);
	printf("d");
	Sleep(70);
	gotoxy(63, 13);
	printf("r");
	Sleep(70);
	gotoxy(64, 13);
	printf("o");
	Sleep(70);
	gotoxy(65, 13);
	printf(" ");
	Sleep(70);
	gotoxy(66, 13);
	printf("P");
	Sleep(70);
	gotoxy(67, 13);
	printf("a");
	Sleep(70);
	gotoxy(68, 13);
	printf("t");
	Sleep(70);
	gotoxy(69, 13);
	printf("t");
	Sleep(70);
	gotoxy(70, 13);
	printf("i");
	Sleep(70);
	gotoxy(71, 13);
	printf("r");
	Sleep(70);
	gotoxy(72, 13);
	printf("a");
	Sleep(70);
	gotoxy(73, 13);
	printf("n");
	Sleep(70);
	gotoxy(74, 13);
	printf("e");
	Sleep(1000);
	gotoxy(4, 15);
	printf("EXIT...!!!\n");
	gotoxy(4, 16);
	printf("[");
	gotoxy(106, 16);
	printf("]");
	gotoxy(111, 16);
	printf("%c", persen);
	for(s = 0 ; s <= 100 ; s++){
		Sleep(25);
		gotoxy(108, 16);
		printf("%d", s);
		gotoxy(5+s, 16);
		printf("%c", ce);		
	}
	gotoxy(4, 18);	
	printf("OUT THE PROGRAM >>>");
	Sleep(3000);
}

void loadingscreen(){
	int s;
	char persen='%';
	char ch=177, ce = 178;
	system("color 02");
	system("cls");
	gotoxy(4, 11);
	printf("LOADING...!!!\n");
	gotoxy(4, 12);
	printf("[");
	gotoxy(106, 12);
	printf("]");
	gotoxy(111, 12);
	printf("%c", persen);
	for(s = 0 ; s <= 100 ; s++){
		Sleep(25);
		gotoxy(108, 12);
		printf("%d", s);
		gotoxy(5+s, 12);
		printf("%c", ce);		
	}
	gotoxy(4, 14);	
	printf("GO TO MENU >>>");
	Sleep(3000);
}
