#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

typedef struct anak_kost{
	int nomor_kamar;
	char nama[25];
	char nomor_hp[14], asal[25], nomor_hp_orang_tua[14];
}anak_kost;
void entrance(int);
int countLoading;
int nama(const void* p, const void* q) {
    return strcmp(((struct anak_kost*)p)->nama, ((struct anak_kost*)q)->nama);
}

int nomor_hp(const void* p, const void* q) {
    return strcmp(((struct anak_kost*)p)->nomor_hp, ((struct anak_kost*)q)->nomor_hp);
}

int nomor_hp_orang_tua(const void* p, const void* q) {
    return strcmp(((struct anak_kost*)p)->nomor_hp_orang_tua, ((struct anak_kost*)q)->nomor_hp_orang_tua);
}

int asal(const void* p, const void* q) {
    return strcmp(((struct anak_kost*)p)->asal, ((struct anak_kost*)q)->asal);
}

void headerTable(){
	gotoxy(12,7);printf("NAMA");
	gotoxy(30,7);printf("Nomor Kamar");
	gotoxy(46,7);printf("Nomor HP");
	gotoxy(60,7);printf("Nomor HP Orang Tua");
	gotoxy(83,7);printf("Asal");
	gotoxy(11,8);
}

void tableContent(int tambah, struct anak_kost anak[]){
	gotoxy(12,9+tambah);printf("%s", anak[tambah].nama);
	gotoxy(30,9+tambah);printf("%d", anak[tambah].nomor_kamar);
	gotoxy(46,9+tambah);printf("%s", anak[tambah].nomor_hp);
	gotoxy(60,9+tambah);printf("%s", anak[tambah].nomor_hp_orang_tua);
	gotoxy(83,9+tambah);printf("%s", anak[tambah].asal);
}
int main(){
	anak_kost anak[100];
	anak_kost temporaryStruct;
	struct history hst[100];
	int history = -1, history_display;
	char admin[10],
		pass[10],
		CharA,
		config,
		ubahNama[50],
		ubahNomorHP[50],
		ubahAsal[50],
		ubah_nomor_hp_orang_tua[50],
		cari_nama[50],
		cari_asal[50],
		cari_NHPOT[50],
		cari_nomor_hp[50],
		z[50];

	int cari_nomor_kamar,
		configH,
		PilihUrutan,
		sort,
		j,
		i,
		pilih,
		banyakData=0,
		data_anak,
		tambah,
		banyak1,
		dihapus,
		hapus,
		delete,
		itemDelete,
		posistion,
		find = 0,
		nomorKamar,
		changeChoice,
		change,
		choice;

	char waktu[128];
    time_t t;
    struct tm* ptm;
    t = time(NULL);
    ptm = localtime(&t);
    strftime(waktu, 128, "%b %d %Y \t\t\t     %H:%M:%S", ptm);

	// ADMIN LOGIN
	char status[100] = {"Starting Program..."};

      for (int i = 1; i <= 100; i++)
      {
        gotoxy(0,18);printf("\n%s\n", status);
		entrance(i);
		if(i==5)strcpy(status, "Loading Assets...");
		if(i==20)strcpy(status, "Loading Resources...");
		if(i==50)strcpy(status, "Loading Packages...");
		if(i==70)strcpy(status, "Loading App Bundles...");
		if(i==90)strcpy(status, "Preparing Desktop... ");
        Sleep(100);
      }
	  printf("\nDone...\n");
	  Sleep(500);
	  system("cls");
	  gotoxy(35,3);printf("                     ***********                           ");
	  gotoxy(35,4);printf("                     ****   ****                           ");
	  gotoxy(35,5);printf("                     ****   ****                           ");
	  gotoxy(35,6);printf("                     ****   ****                           ");
	  gotoxy(35,7);printf("                     ****   ****                           ");
	  gotoxy(35,8);printf("*************************   **************************       ");
	  gotoxy(35,9);printf("***                                                ***       ");
	  gotoxy(35,10);printf("*************************   *************************       ");
	  gotoxy(35,11);printf("                     ****   ****                           ");
	  gotoxy(35,12);printf("                     ****   ****                           ");
	  gotoxy(35,13);printf("                     ****   ****                           ");
	  gotoxy(35,14);printf("                     ****   ****                           ");
	  gotoxy(35,15);printf("                     ****   ****                           ");
	  gotoxy(35,16);printf("                     ****   ****                           ");
	  gotoxy(35,17);printf("                     ****   ****                           ");
	  gotoxy(35,18);printf("                     ****   ****                           ");
	  gotoxy(35,19);printf("                     ****   ****                           ");
	  gotoxy(35,20);printf("                     ***********                           ");
	  char wel[] = "Welcome";
	  for(i = 0; i< strlen(wel); i++){
		  gotoxy(58+i,21);printf("%c", wel[i]);
		  Sleep(70);
	  }
      getch();
      Sleep(1000);
	  system("cls");


	login :
		system("color 47");
		gotoxy(35,7);
		printf("   SELAMAT DATANG DI DATABASE KOS VANFAY  ");
		gotoxy(35,9);
		printf("==========================================");
		gotoxy(35,13);
		printf("==========================================");
		gotoxy(35,14);
		printf("%s\n", waktu);
		gotoxy(35,10);
		printf("Masukkan username (admin) : ");
		scanf("%s", &admin);
		printf("\n");
		gotoxy(35,12);
		printf("Masukkan password (admin) : ");
		i = 0;
		while(i < 9){
			pass[i] = getch();
			CharA = pass[i];
			if(CharA == 13)break;
			else printf("*");
			i++;
		}
		pass[i]='\0';
		i = 0;

		gotoxy(35,18);
		if(	strcmp(admin, "admin") == 0 && strcmp(pass, "admin") == 0){
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
		gotoxy(26,4);
		printf("+=================================================================+");
		gotoxy(36,6);
		printf("SELAMAT DATANG DI SYSTEM DATA KOS-KOSAN VANFAY");
		gotoxy(47,7);
		printf(" === DATA ANAK KOS ===");
		gotoxy(26,9);
		printf("+-----------------------------------------------------------------+");
		gotoxy(26,11);
		printf("|                                                                 |");
		gotoxy(26,12);
		printf("|   Tekan 1. Membuat Data Anak Kos                                |");
		gotoxy(26,13);
		printf("|   Tekan 2. Menampilkan Isi Data Anak Kos                        |");
		gotoxy(26,14);
		printf("|   Tekan 3. Menambah Data Baru ke Data Anak Kos                  |");
		gotoxy(26,15);
		printf("|   Tekan 4. Menghapus Data di Data Anak Kos                      |");
		gotoxy(26,16);
		printf("|   Tekan 5. Mengedit Data di Data Anak Kos                       |");
		gotoxy(26,17);
		printf("|   Tekan 6. Mencari Data di Data Anak Kos                        |");
		gotoxy(26,18);
		printf("|   Tekan 7. Riwayat Aktivitas                                    |");
		gotoxy(26,19);
		printf("|   Tekan 8. Mengurutkan Data di Data Anak Kos                    |");
		gotoxy(26,20);
		printf("|   Tekan 9. Keluar Dari Program                                  |");
		gotoxy(26,21);
		printf("|                                                                 |");
		gotoxy(26,22);
		printf("|   Masukkan Pilihan Anda : ");
		gotoxy(92,22);printf("|");
		gotoxy(26,24);
		printf("+=================================================================+");
		gotoxy(54,22);
		scanf("%d", &pilih);

		if(pilih == 1){
			system("cls");
			system("color 04");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(41,4);
			printf("=== Membuat Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(39,7);
			printf("Data Maksimum yang bisa diinput : 10");
			gotoxy(39,8);
			printf("Banyak Data yang ingin diiput   : ");
			gotoxy(18,9);
			printf("+===============================================================================+\n");
			gotoxy(73,8);
			scanf("%d", &banyakData);
			data_anak = 0;
			while(data_anak < banyakData){
				printf("\n\t\t   Data Anak Kos KE-%d\n", data_anak+1);
				printf("\t\t   Nama               : ");scanf(" %[^\n]", &anak[data_anak].nama);
				printf("\t\t   Nomor Kamar        : ");scanf("%d", &anak[data_anak].nomor_kamar);
				printf("\t\t   Nomor HP           : ");scanf("%s", &anak[data_anak].nomor_hp);
				printf("\t\t   Nomor HP orang tua : ");scanf(" %[^\n]", &anak[data_anak].nomor_hp_orang_tua);
				printf("\t\t   Asal               : ");scanf(" %[^\n]", &anak[data_anak].asal);
				data_anak++;
			}
			printf("\n\t\t  Tekan Apapapun untuk melanjutkan >> ");
			getch();
			system("cls");
			history += 1;
			sprintf(z, "%d", banyakData);
			char bag1[] = "Admin Membuat ";
			strcat(bag1, z);
			strcat(bag1, " Data Baru");
			strcpy(hst[history].list, bag1);
			system("cls");
			goto menu;
		}else if(pilih == 2){
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(54,3);
			printf("Data Anak Kos");
			gotoxy(41,4);
			printf("Data Anak Kos yang ada dalam database");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			headerTable();
			printf("+-------------------------------------------------------------------------------------------------+");
			for(tambah = 0 ; tambah < banyakData ; tambah++){
				tableContent(tambah, anak);
			}
			gotoxy(11,9+tambah);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tambah);
			printf("Tekan Apapapun untuk melanjutkan >> ");
			getch();
			system("cls");
			history += 1;
			char bag2[] = "Admin Menampilkan Data ";
			strcpy(hst[history].list, bag2);
			system("cls");
			goto menu;
		}else if(pilih == 3){
			system("cls");
			system("color 05");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(41,4);
			printf("=== Menambah Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(39,7);
			printf("Data Maksimum yang bisa diinput : 5");
			gotoxy(39,8);
			printf("Banyak Data yang ingin diiput   : ");
			gotoxy(18,9);
			printf("+===============================================================================+\n");
			gotoxy(73,8);
			scanf("%d", &banyak1);
			data_anak = banyakData;
			while(data_anak < banyakData+banyak1){
				printf("\n\t\t   Data Anak Kos KE-%d\n", data_anak+1);
				printf("\t\t   Nama               : ");
				scanf(" %[^\n]", &anak[data_anak].nama);
				printf("\t\t   Nomor Kamar        : ");
				scanf("%d", &anak[data_anak].nomor_kamar);
				printf("\t\t   Nomor HP			  : ");
				scanf("%s", &anak[data_anak].nomor_hp);
				printf("\t\t   Nomor HP orang tua : ");
				scanf(" %[^\n]", &anak[data_anak].nomor_hp_orang_tua);
				printf("\t\t   Asal               : ");
				scanf(" %[^\n]", &anak[data_anak].asal);
				data_anak++;
			}
			banyakData = banyakData+banyak1;
			printf("\n\t\t  Tekan Apapapun untuk melanjutkan >> ");
			getch();
			system("cls");
			history += 1;
			sprintf(z, "%d", banyak1);
			char bag3[] = "Admin Menambah ";
			strcat(bag3, z);
			strcat(bag3, " Data ");
			strcpy(hst[history].list, bag3);
			system("cls");
			goto menu;
		}else if(pilih == 4){
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("Data Anak Kos");
			gotoxy(41,4);
			printf("Data Anak Kos yang ada dalam database");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			headerTable();
			printf("+-------------------------------------------------------------------------------------------------+");
			for(tambah = 0 ; tambah < banyakData ; tambah++){
				tableContent(tambah, anak);
			}
			gotoxy(11,9+tambah);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tambah);
			printf("Tekan Apapapun untuk melanjutkan >> ");
			getch();
			system("cls");
		menu3:
			system("color 87");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(44,4);
			printf("=== Menghapus Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(41,7);
			printf("Masukkan Nomor Kamar yang ingin dihapus : ");
			gotoxy(18,8);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(82, 7);
			scanf("%d", &dihapus);

			for(configH = 0 ; config < banyakData ; configH++){
				if(anak[configH].nomor_kamar == dihapus){
					goto menukhusus;
				}
			}
			for(configH = 0 ; config < banyakData ; configH++){
				if(anak[configH].nomor_kamar != dihapus){
					gotoxy(18,9);
					printf("Data Dengan Nomor Kamar : %d, Tidak Tersedia", dihapus);
					gotoxy(18,10);
					printf("Tekan Apapapun untuk melanjutkan >> ");
					getch();
					system("cls");
					goto menu3;
				}
			}
			menukhusus:
			for(configH = 0 ; configH < banyakData ; configH++){
				gotoxy(41,9);printf(" DATA");
				for(hapus = 0 ; hapus < banyakData ; hapus++){
					if(dihapus == anak[hapus].nomor_kamar){
						gotoxy(41,10);printf(" Nama                : %s", anak[hapus].nama);
						gotoxy(41,11);printf(" Nomor Kamar         : %d", anak[hapus].nomor_kamar);
						gotoxy(41,12);printf(" Nomor HP            : %s", anak[hapus].nomor_hp);
						gotoxy(41,13);printf(" Nomor HP Orang Tua  : %s", anak[hapus].nomor_hp_orang_tua);
						gotoxy(41,14);printf(" Asal                : %s", anak[hapus].asal);
					}
				}
				gotoxy(41, 16);printf("Lanjutkan menghapus? [y|n] ---> ");
				scanf("%s", &config);
				if(config == 'y'|| config == 'Y'){
					for(delete = 0 ; delete < banyakData ; delete++){
						if(anak[delete].nomor_kamar == dihapus){
							find = 1;
							posistion = delete;
							break;
						}
					}
					banyakData = banyakData-1;
					if(find == 1){
						for(itemDelete = posistion ; itemDelete < banyakData ; itemDelete++){
							anak[itemDelete] = anak[itemDelete+1];
						}
					}
					gotoxy(41,18);
					printf("Data %d telah dihapus!", dihapus);
					gotoxy(41,19);
					printf("Tekan Apapapun untuk melanjutkan >> ");
					getch();
					history += 1;
					sprintf(z, "%d", dihapus);
					char bag4[] = "Admin Menghapus Data Dengan Nomor Kamar ' ";
					strcat(bag4, z);
					strcat(bag4, " '");
					strcpy(hst[history].list, bag4);
					system("cls");
					goto menu;
				}else{
					gotoxy(41,18);
					printf("Data %d tidak jadi dihapus!", dihapus);
					gotoxy(41,19);
					printf("Tekan Apapapun untuk melanjutkan >> ");
					getch();
					history += 1;
					sprintf(z, "%d", dihapus);
					char bag4_2[] = "Admin Batal Menghapus Data Dengan Nomor Kamar ' ";
					strcat(bag4_2, z);
					strcat(bag4_2, " '");
					strcpy(hst[history].list, bag4_2);
					system("cls");
					system("cls");
					goto menu;
				}
			}

			}else if(pilih == 5){
			system("cls");
			system("color 0B");
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("Data Anak Kos");
			gotoxy(41,4);
			printf("Data Anak Kos yang ada dalam database");
			gotoxy(11,6);
			printf("+=================================================================================================+");
			headerTable();
			printf("+-------------------------------------------------------------------------------------------------+");
			for(tambah = 0 ; tambah < banyakData ; tambah++){
				tableContent(tambah, anak);
			}
			gotoxy(11,9+tambah);
			printf("+-------------------------------------------------------------------------------------------------+");
			gotoxy(11,11+tambah);
			printf("Tekan Apapapun untuk melanjutkan >> ");

			getch();
		menu1:
			system("cls");
			system("color 0C");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(44,4);
			printf("=== Mengubah Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Apa yang ingin anda edit? ");
			gotoxy(34, 8);printf("1. Nama                    3. Nomor HP Orang Tua");
			gotoxy(34, 9);printf("2. Nomor HP          4. Asal ANAK");
			gotoxy(34, 11);printf("Pilihan anda        : ");
			gotoxy(34, 12);printf("Masukkan Nomor Kamar: ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(55, 11);scanf("%d", &changeChoice);
			gotoxy(55, 12);scanf("%d", &nomorKamar);
			if(changeChoice == 1){
				gotoxy(34,14);printf("UBAH DATA NAMA       ");
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar == anak[change].nomor_kamar){
						gotoxy(34,15);printf("Data saat ini  : %s", anak[change].nama);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubahNama);
						history += 1;
						sprintf(z, "%d", anak[change].nomor_kamar);
						char bag5_1[] = "Admin Mengubah Nama Anak Kost Dengan Nomor Kamar ' ";
						strcat(bag5_1, z);
						strcat(bag5_1, " ' Dari ");
						strcat(bag5_1, anak[change].nama);
						strcat(bag5_1, " Menjadi ");
						strcat(bag5_1, ubahNama);
						strcpy(hst[history].list, bag5_1);
						strcpy(anak[change].nama, ubahNama);
						strcpy(anak[change].nama, ubahNama);
						gotoxy(34, 17);
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar != anak[change].nomor_kamar){
						gotoxy(34,14);
						printf("Tidak Ada Nomor Kamar bernomor %d!", nomorKamar);
						gotoxy(34, 16);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu1;
					}
				}
			}else if(changeChoice == 2){
				gotoxy(34,14);printf("UBAH DATA NOMOR HP");
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar == anak[change].nomor_kamar){
						gotoxy(34,15);printf("Data saat ini  : %s", anak[change].nomor_hp);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf("%s", &ubahNomorHP);
						history += 1;
						sprintf(z, "%s", anak[change].nomor_hp);
						char bag5_2[] = "Admin Mengubah Nomor HP ANAK Dengan Nomor Kamar ' ";
						strcat(bag5_2, z);
						strcat(bag5_2, " ' Dari ");
						strcat(bag5_2, anak[change].nomor_hp);
						strcat(bag5_2, " Menjadi ");
						strcat(bag5_2, ubahNomorHP);
						strcpy(hst[history].list, bag5_2);
						strcpy(anak[change].nomor_hp, ubahNomorHP);
						strcpy(anak[change].nomor_hp, ubahNomorHP);
						gotoxy(34, 17);
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar != anak[change].nomor_kamar){
						gotoxy(34,14);
						printf("Tidak Ada Nomor Kamar bernomor %d!", nomorKamar);
						gotoxy(34, 16);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu1;
					}
				}
			}else if(changeChoice == 3){
				gotoxy(34,14);printf("UBAH DATA NOMOR HP ORANG TUA ANAK KOST");
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar == anak[change].nomor_kamar){
						gotoxy(34,15);printf("Data saat ini  : %s", anak[change].nomor_hp_orang_tua);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubahAsal);
						history += 1;
						sprintf(z, "%d", anak[change].nomor_kamar);
						char bag5_3[] = "Admin Mengubah NO HP Orang Tuan Dengan Nomor Kamar ' ";
						strcat(bag5_3, z);
						strcat(bag5_3, " ' Dari ");
						strcat(bag5_3, anak[change].nomor_hp_orang_tua);
						strcat(bag5_3, " Menjadi ");
						strcat(bag5_3, ubah_nomor_hp_orang_tua);
						strcpy(hst[history].list, bag5_3);
						strcpy(anak[change].nomor_hp_orang_tua, ubah_nomor_hp_orang_tua);
						strcpy(anak[change].nomor_hp_orang_tua, ubahAsal);
						gotoxy(34, 17);
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar != anak[change].nomor_kamar){
						gotoxy(34,14);
						printf("Tidak Ada Nomor Kamar bernomor %d!", nomorKamar);
						gotoxy(34, 16);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu1;
					}
				}
			}else if(changeChoice == 4){
				gotoxy(34,14);printf("UBAH DATA ASAL ANAK KOSt");
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar == anak[change].nomor_kamar){
						gotoxy(34,15);printf("Data saat ini  : %s", anak[change].asal);
						gotoxy(34,16);printf("Data yang baru : ");
						scanf(" %[^\n]", &ubahAsal);
						history += 1;
						sprintf(z, "%d", anak[change].nomor_kamar);
						char bag5_4[] = "Admin Mengubah Diagnosa ANAK Dengan ID ' ";
						strcat(bag5_4, z);
						strcat(bag5_4, " ' Dari ");
						strcat(bag5_4, anak[change].asal);
						strcat(bag5_4, " Menjadi ");
						strcat(bag5_4, ubahAsal);
						strcpy(hst[history].list, bag5_4);
						strcpy(anak[change].asal, ubahAsal);
						gotoxy(34, 17);
						printf("**Data Diubah!");
						gotoxy(34, 19);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu;
					}
				}
				for(change = 0 ; change < banyakData ; change++){
					if(nomorKamar != anak[change].nomor_kamar){
						gotoxy(34,14);
						printf("Tidak Ada Nomor Kamar bernomor %d!", nomorKamar);
						gotoxy(34, 16);
						printf("Tekan Apapapun untuk melanjutkan >> ");
						getch();
						system("cls");
						goto menu1;
					}
				}
			}else{
				gotoxy(34,14);
				printf("Pilihan Tidak Tersedia!");
				gotoxy(34, 16);
				printf("Tekan Apapapun untuk melanjutkan >> ");
				getch();
				system("cls");
				goto menu1;
			}
		}else if(pilih == 6){
		menu2:
			system("cls");
			system("color 02");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(46,4);
			printf("=== Mencari Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Apa yang ingin anda cari : ");
			gotoxy(34, 8);printf("1. Nama                    4. Nomor HP Orang Tua");
			gotoxy(34, 9);printf("2. Nomor Kamar              5. Asal ");
			gotoxy(34, 10);printf("3. Nomor HP   ");
			gotoxy(34, 11);printf("Pilihan anda                   : ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(67, 11);scanf("%d", &choice);
			if(choice == 1){
				gotoxy(34, 12);
				printf("Nama yang Dicari        : ");
				scanf(" %[^\n]", &cari_nama);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tambah = 0 ; tambah < banyakData ; tambah++){
					if(strcmp(anak[tambah].nama, cari_nama) == 0){
						tableContent(tambah, anak);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag6_1[] = "Admin Mencari Data Dengan Nama ' ";
				strcat(bag6_1, cari_nama);
				strcat(bag6_1, " '");
				strcpy(hst[history].list, bag6_1);
				system("cls");
				goto menu;
			}else if(choice == 2){
				gotoxy(34, 12);
				printf("Nomor Kamar yang Dicari          : ");
				scanf("%d", &cari_nomor_kamar);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tambah = 0 ; tambah < banyakData ; tambah++){
					if(anak[tambah].nomor_kamar == cari_nomor_kamar){
						tableContent(tambah, anak);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				sprintf(z, "%d", cari_nomor_kamar);
				char bag6_2[] = "Admin Mencari Data Nomor Kamar ' ";
				strcat(bag6_2, z);
				strcat(bag6_2, " '");
				strcpy(hst[history].list, bag6_2);
				system("cls");
				goto menu;
			}else if(choice == 3){
				gotoxy(34, 12);
				printf("Nomor HP Orang Tua yang Dicari  : ");
				scanf(" %[^\n]", &cari_NHPOT);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tambah = 0 ; tambah < banyakData ; tambah++){
					if(strcmp(anak[tambah].nomor_hp, cari_NHPOT) == 0){
						tableContent(tambah, anak);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag6_3[] = "Admin Mencari Data Dengan Nomor HP ' ";
				strcat(bag6_3, cari_NHPOT);
				strcat(bag6_3, " '");
				strcpy(hst[history].list, bag6_3);
				system("cls");
				goto menu;
			}else if(choice == 4){
				gotoxy(34, 12);
				printf("ASAL Anak Kos Yang Dicari     : ");
				scanf(" %[^\n]", &cari_asal);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tambah = 0 ; tambah < banyakData ; tambah++){
					if(strcmp(anak[tambah].asal, cari_asal) == 0){
						tableContent(tambah, anak);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag6_4[] = "Admin Mencari Data Dengan Keluhan ' ";
				strcat(bag6_4, cari_asal);
				strcat(bag6_4, " '");
				strcpy(hst[history].list, bag6_4);
				system("cls");
				goto menu;
			}else if(choice == 5){
				gotoxy(34, 12);
				printf("Nomor HP yang Dicari    : ");
				scanf(" %[^\n]", &cari_nomor_hp);
				system("cls");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(tambah = 0 ; tambah < banyakData ; tambah++){
					if(strcmp(anak[tambah].asal, cari_nomor_hp) == 0){
						tableContent(tambah, anak);
					}
				}
				printf("\n\t   +-------------------------------------------------------------------------------------------------+");
				printf("\n           Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag6_5[] = "Admin Mencari Data Dengan Nomor HP ' ";
				strcat(bag6_5, cari_nomor_hp);
				strcat(bag6_5, " '");
				strcpy(hst[history].list, bag6_5);
				system("cls");
				goto menu;
			}else{
				gotoxy(18,14);
				printf("Pilihan tidak ada!");
				gotoxy(18,16);
				printf("Tekan Apapapun untuk melanjutkan >> ");
				getch();
				system("cls");
				goto menu2;
			}
		}else if(pilih == 7){
			system("cls");
			system("color 05");
			history += 1;
			char bag7[] = "Admin Mengecek Riwayat Aktivitas";
			strcpy(hst[history].list, bag7);
			gotoxy(11,1);
			printf("+=================================================================================================+");
			gotoxy(49,3);
			printf("DATA ANAK RS");
			gotoxy(41,4);
			printf("Data ANAK yang Telah Diinput");
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
		}else if(pilih == 8){
			system("cls");
			system("color 02");
			gotoxy(18,1);
			printf("+===============================================================================+");
			gotoxy(54,3);
			printf("DATABASE");
			gotoxy(38,4);
			printf("=== Mengurutkan Data Anak Kos ===");
			gotoxy(18,6);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(34, 7);printf("Urutkan berdasarkan apa?");
			gotoxy(34, 8);printf("1. Nama                    4. Nomor HP Orang Tua");
			gotoxy(34, 9);printf("2. Nomor Kamar              5. Asal");
			gotoxy(34, 10);printf("3. Nomor HP   ");
			gotoxy(34, 11);printf("Pilihan anda  :  ");
			gotoxy(18,13);
			printf("+-------------------------------------------------------------------------------+");
			gotoxy(51,11);
			scanf("%d", &PilihUrutan);
			if(PilihUrutan == 1){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				qsort(anak, banyakData, sizeof(struct anak_kost), nama);
				for(sort = 0 ; sort < banyakData ; sort++){
					tableContent(sort, anak);
				}
				printf("\n            +-------------------------------------------------------------------------------------------------+");
				printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag8_1[] = "Admin Mengurutkan Data Berdasarkan Nama ANAK";
				strcpy(hst[history].list, bag8_1);
				system("cls");
				goto menu;
			}else if(PilihUrutan == 2){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				for(i = 0 ; i < banyakData ; i++){
					for(j = 0 ; j < banyakData ; j++){
						if (anak[i].nomor_kamar < anak[j].nomor_kamar){
                			temporaryStruct=anak[i];
                			anak[i]=anak[j];
                			anak[j]=temporaryStruct;
            			}
					}
				}
				for(sort = 0 ; sort < banyakData ; sort++){
					tableContent(sort, anak);
				}
				printf("\n            +-------------------------------------------------------------------------------------------------+");
				printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag8_2[] = "Admin Mengurutkan Data Berdasarkan ID ANAK";
				strcpy(hst[history].list, bag8_2);
				system("cls");
				goto menu;
			}else if(PilihUrutan == 3){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				qsort(anak, banyakData, sizeof(struct anak_kost), nomor_hp);
				for(sort = 0 ; sort < banyakData ; sort++){
					tableContent(sort, anak);
				}
				printf("\n            +-------------------------------------------------------------------------------------------------+");
				printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag8_3[] = "Admin Mengurutkan Data Berdasarkan Nomor HP ANAK";
				strcpy(hst[history].list, bag8_3);
				system("cls");
				goto menu;
			}else if(PilihUrutan == 4){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				qsort(anak, banyakData, sizeof(struct anak_kost), nomor_hp_orang_tua);
				for(sort = 0 ; sort < banyakData ; sort++){
					tableContent(sort, anak);
				}
				printf("\n            +-------------------------------------------------------------------------------------------------+");
				printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag8_4[] = "Admin Mengurutkan Data Berdasarkan Keluhan ANAK";
				strcpy(hst[history].list, bag8_4);
				system("cls");
				goto menu;
			}else if(PilihUrutan == 5){
				system("cls");
				system("color 02");
				gotoxy(11,1);
				printf("+=================================================================================================+");
				gotoxy(49,3);
				printf("Data Anak Kos");
				gotoxy(41,4);
				printf("Data Anak Kos yang ada dalam database");
				gotoxy(11,6);
				printf("+=================================================================================================+");
				headerTable();
				printf("+-------------------------------------------------------------------------------------------------+");
				qsort(anak, banyakData, sizeof(struct anak_kost), asal);
				for(sort = 0 ; sort < banyakData ; sort++){
					tableContent(sort, anak);
				}
				printf("\n            +-------------------------------------------------------------------------------------------------+");
				printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				history += 1;
				char bag8_5[] = "Admin Mengurutkan Data Berdasarkan Diagnosa ANAK";
				strcpy(hst[history].list, bag8_5);
				system("cls");
				goto menu;
			}else{
				gotoxy(17,15);printf("Pilihan tidak ada!");
				gotoxy(19,15);printf("\n            Tekan Apapapun untuk melanjutkan >> ");
				getch();
				system("cls");
				goto menu;
			}
		}else if(pilih == 9){
			system("cls");

		}else {
			printf("PILIHAN TIDAK ADA");
			goto menu;
		}
	}

void entrance(int persen){

    const int mul = 10; // width factor
    persen = min(100, persen);

    static int spin_index = 0;
    char spinning[] = "_-\\|/-";

    int len = (persen * mul / 10) + 1;
    char *bar = malloc(len);
    memset(bar, '<', len - 1);
    bar[len - 1] = 0;

    printf("%c Loading: [%*s] %*d%%\r",
    persen == 100 ? ' ' : spinning[spin_index],mul * 10, bar,3, persen);
    spin_index = (spin_index + 1) % strlen(spinning);
    free(bar);

}

