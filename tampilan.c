#include "set/setting.h"
#include "validasi.c"

///////////////// ///////////////// ///////////////// 
///////////////// PROTOTYPE PROCEDURE /////////////////  
void start();
void geser();
void cek_geser();
void kejutin_inpdata1();
void kejutin_bayar();
void kejutin_inpdata2();
void kejutin_inpdata3();
void kejutin_inpdata4();
void cek_tanggal();
void cek_kodnik();
void hapus_kejutin();
void riwayat_kejutin();
void bingkai5();
void caridesa();
void caritgl();
void tabel_halaman(int halaman);
void menu();
////////////// ////////////// ////////////// //////
////////////// ////////////// ////////////// //////

///////////////// ///////////////// ///////////////// ///////////////// 
//////////// PROTOTYPE PROCEDURE TAMPILAN BAYAGANGAN ////////////////  
void bingkaitam1();
void bingkaicek();
void bingkaitam3();
void bingkairiwayat();
void informasi_apps();
void tamkec();
void tamkoor();
void tamkoor2();
void tamkeb();
void tamkado();
void tamreq();
void tamextra();
// void tamxtra();
///////////////// ///////////////// ///////////////// ///////////////// 
///////////////// ///////////////// ///////////////// ///////////////// 

///////////////// ///////////////// ///////////////// 
///////////////// PROTOTYPE TYPEDATA ////////////////
char* cekpass(char* pass);
char* banding(char* user);
char* ceknama(char* nama);
///////////////// ///////////////// /////////////////
int edit_data(int hal,int tem);
void edit_data1();
void edit_data2();
void edit_data3();
///////////////// ///////////////// /////////////////
///////////////// ///////////////// /////////////////

///// ///// ///// ///// ///// ///// ///// 
///// ///// VARIABEL GLOBAL ///// ///////
int tampkectrgt=0, tgltrgt;
int tampfav = 0; 
///// ///// ///// ///// ///// ///// /////
char nik[100], jk[100], umur[100], kec[100], desa[100], jln[100], nojal[100], rt[100], rw[100];
char kectrgt[100], jktrgt[100], notefav[100], notetema[100];
///// ///// ///// ///// ///// ///// /////
/////  VARIABEL GLOBAL PEMBAYAR ///// //  
char bayar[2][100]={};
int biayaongkos = 0;
int biayakeamanan = 0;
int biayakado = 0;
int biayaextra = 0;
///// ///// ///// ///// ///// ///// ///// 

/////////////////////////////////////////////////////////
///////////// VARIABEL GLOBAL INPUT NOTEPAD /////////////
char nama[100], nohp[100];                               //// INPDATA 1
char namatrgt[100], notecbgdesa[100] = {}, notetrgtdesa[100] = {}, notetgl[100]={}, notereq[100] = {}, noteextra[100] = {}, notekodnik[100] = {};
int total = 0;
int kesempatan = 1;
///////////// ///////////// ///////////// ///////////// 
///////////// ///////////// ///////////// ///////////// 


// /////// PANJANG 169
// /////// LEBAR 39
void start(){

    char admin[100];
    char tampadm[100] = {}; 
    int hasil = 0;
    int kesempatan;

    tampilan(0,0,169,39,4,15);      /// Bingkai Terluar
    tampilan(2,2,165,35,10,14); 
    tampilan(4,4,161,31,9,8);
    tampilan(6,6,157,27,5,7);
    tampilan(8,8,153,23,5,7);
    tampilan(10,10,149,19,12,14);

    tampilan(60,21,45,4,9,8);           /// BINGKAI INPUT 
    gotoxy(62,23);set(0,8);printf("Masukkan Kode Admin : ");
    strcpy(tampadm, cekpass(admin));
    hasil = atoi(banding(tampadm));
    if(hasil == 1){
        menu();
    }else if( kesempatan < 3){
        kesempatan++;
        start();
    }else{
    set(0,14);gotoxy(70,27);printf("TEKAN ENTER UNTUK KELUAR");   
    exit(0);
    }
    
}


void menu(){
    char inp;

    tampilan(0,0,169,39,4,15);      /// Bingkai Terluar
    tampilan(2,2,165,32,10,14);       /// Bingkai Kedua
    tampilan(2,34,32,4,9,14);                                           //KOTAK 1
    
    set(0,14);gotoxy(143,33);printf("[ESC] KELUAR APLIKASI");
    set(0,14);gotoxy(6,33);printf("[ENTER] MASUK PROGRAM");
    

    gotoxy(11,36);set(0,14);printf("KEJUTIN");
    tampilan(35,34,32,4,9,14);                                     //KOTAK 2
    gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
    tampilan(68,34,32,4,9,14);                                          //KOTAK 3
    gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
    tampilan(101,34,32,4,9,14);                                   //KOTAK 4
    gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
    tampilan(134,34,33,4,9,14);                                         //KOTAK 5
    gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
    geser();
}

void geser(){
    char inp;
    int pos = 1;
    int tempat = 1;
    tampilan(4,4,161,28,9,15);
    tampilan(2,34,32,4,0,14);   
    bingkaitam1();                                        //KOTAK 1
    gotoxy(11,36);set(0,14);printf("KEJUTIN");
    while( (inp = getch()) != 13){
        if(inp == 27){
            exit(0);
        }
        if(inp == 77){
                if(pos == 1){
                        pos = 2;
                        tempat = 2;
                        tampilan(2,34,32,4,9,14);                                           //KOTAK 1
                        gotoxy(11,36);set(0,14);printf("KEJUTIN");
                        tampilan(35,34,32,4,0,14);                                     //KOTAK 2
                        gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
                        tampilan(4,4,161,28,9,15);                   
                        bingkaicek(); 
                }else if(pos == 2){
                        tempat = 3;
                        pos = 3;
                        tampilan(35,34,32,4,9,14);                                     //KOTAK 2
                        gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
                        tampilan(68,34,32,4,0,14);                                             //KOTAK 3
                        gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
                        bingkaitam3();
                        tampilan(4,4,161,28,9,15);
                        bingkaitam3();
                }else if(pos == 3){
                        pos = 4;
                        tempat = 4;
                        tampilan(68,34,32,4,9,14);                                          //KOTAK 3
                        gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
                        tampilan(101,34,32,4,0,14);                                   //KOTAK 4
                        gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
                        tampilan(4,4,161,28,9,15);
                        bingkairiwayat();
                }else if(pos == 4){
                        pos = 5;
                        tempat = 5;
                        tampilan(101,34,32,4,9,14);                                   //KOTAK 4
                        gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
                        tampilan(134,34,33,4,0,14);                                         //KOTAK 5
                        gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
                        tampilan(4,4,161,28,9,15);
                        informasi_apps();
                }else if(pos == 5){
                        pos = 1;
                        tempat = 1;
                        tampilan(134,34,33,4,9,14);                                         //KOTAK 5
                        gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
                        tampilan(2,34,32,4,0,14);                                           //KOTAK 1
                        gotoxy(11,36);set(0,14);printf("KEJUTIN");
                        tampilan(4,4,161,28,9,15);
                        bingkaitam1(); 
                }
        }else if( inp == 75){
                if(pos == 1){ 
                pos = 5;
                tempat = 5;
                tampilan(2,34,32,4,9,14);                                           //KOTAK 1
                gotoxy(11,36);set(0,14);printf("KEJUTIN");    
                tampilan(134,34,33,4,0,14);                                         //KOTAK 5
                gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
                tampilan(4,4,161,28,9,15);               
                informasi_apps();
        }else if(pos == 5){
                pos = 4;
                tempat = 4;
                tampilan(101,34,32,4,0,14);                                   //KOTAK 4
                gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
                tampilan(134,34,33,4,9,14);                                         //KOTAK 5
                gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
                tampilan(4,4,161,28,9,15);
                bingkairiwayat();
        }else if(pos == 4){
                pos = 3;
                tempat = 3;
                tampilan(68,34,32,4,0,14);                                          //KOTAK 3
                gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
                tampilan(101,34,32,4,9,14);                                   //KOTAK 4
                gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
                tampilan(4,4,161,28,9,15);
                bingkaitam3();
        }else if(pos == 3){
                pos = 2;
                tempat = 2;
                tampilan(35,34,32,4,0,14);                                     //KOTAK 2
                gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
                tampilan(68,34,32,4,9,14);                                          //KOTAK 3
                gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
                tampilan(4,4,161,28,9,15);
                bingkaicek();
        }else if(pos == 2){
                pos = 1;
                tempat = 1;
                tampilan(2,34,32,4,0,14);                                           //KOTAK 1
                gotoxy(11,36);set(0,14);printf("KEJUTIN");
                tampilan(35,34,32,4,9,14);                                     //KOTAK 2
                gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
                tampilan(4,4,161,28,9,15);
                bingkaitam1();
        }   
        }
    }
    if(tempat == 1){
        kejutin_inpdata1(); 
    }else if(tempat == 2){
        cek_geser();
    }else if(tempat == 3){
        hapus_kejutin();
    }else if(tempat == 4){
        riwayat_kejutin();
    }else if(tempat == 5){
        tampilan(134,34,33,4,9,14);                                         //KOTAK 5
        gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
        geser();
    }
}

void bingkaitam1(){
    char inp;
    int pos;
    tampilan(4,4,161,28,9,15); 
    tampilan(9,6,72,24,9,8);                //BINGKAI INPUTAN
    gotoxy(13,11);set(0,8);printf("NAMA\t\t: ");
    gotoxy(13,12);set(0,8);printf("_______________________________________________________");
    gotoxy(13,13);set(0,8);printf("NIK\t\t: ");
    gotoxy(13,14);set(0,8);printf("_______________________________________________________");
    gotoxy(13,15);set(0,8);printf("Jenis Kelamin\t: ");
    gotoxy(13,16);set(0,8);printf("_______________________________________________________");
    gotoxy(13,17);set(0,8);printf("Umur\t\t: ");
    gotoxy(13,18);set(0,8);printf("_______________________________________________________");
    gotoxy(13,19);set(0,8);printf("Nomor Handphone\t:");
    gotoxy(13,20);set(0,8);printf("_______________________________________________________");
    gotoxy(13,21);set(0,8);printf("Kecamatan\t\t: ");
    gotoxy(13,22);set(0,8);printf("_______________________________________________________");
    gotoxy(13,23);set(0,8);printf("Desa / Kelurahan\t: ");
    gotoxy(13,24);set(0,8);printf("_______________________________________________________");
    gotoxy(13,25);set(0,8);printf("Jalan / No Jalan\t: ");
    gotoxy(13,26);set(0,8);printf("_______________________________________________________");
    gotoxy(13,27);set(0,8);printf("RT / RW\t\t: ");
    gotoxy(13,28);set(0,8);printf("_______________________________________________________");
}

void bingkaicek(){
    char inp;
    int pos = 1;
    int tempat = 1;
    tampilan(35,34,32,4,0,14);          //BINGKAI MENU
    gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
    tampilan(4,4,161,28,9,15);          //BINGKAI 3
    tampilan(54,14,30, 4,0,15);         //BINGKAI PILIH 1
    tampilan(88,14,30, 4,1,15);         //BINGKAI PILIH 2
    gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
    gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
}

void bingkaitam3(){
    char inp;
    int pos;
    // tampilan(4,4,161,28,9,15);
    gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
    tampilan(103,26,45,4,9,8);
    gotoxy(105,28);set(0,8);printf("MASUKKAN KODE UNIK : ");    
}

void bingkairiwayat(){    
    char nama[100];
    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    int index=0;

    // char inp;
    int pos=4;
    int tempat = 4;
    gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
    tampilan(4,4,161,28,9,15);       /// BIMGKAI KETIGA
    tampilan(7,6,155,24,9,8);        /// BINGKAI RIWAYAT
    tampilan(10,8,149,20,15,15);     /// BINGKAI RIWAYAT

    gotoxy(10,9);set(0,15);printf("NO");
    gotoxy(13,9);set(0,15);printf("NAMA KEJUTER");                           //smpe 20
    gotoxy(34,9);set(0,15);printf("NO HP");                         //smpe 35
    gotoxy(49,9);set(0,15);printf("NAMA TARGET");                   //SMPE 45
    gotoxy(70,9);set(0,15);printf("KODE UNIK");
    gotoxy(81,9);set(0,15);printf("TANGGAL KEJUT");
    gotoxy(96,9);set(0,15);printf("REQUEST KADO");
    gotoxy(110,9);set(0,15);printf("EXTRA KADO");
    gotoxy(122,9);set(0,15);printf("DESA CABANG");
    gotoxy(135,9);set(0,15);printf("DESA TARGET");
    gotoxy(148,9);set(0,15);printf("TOTAL BAYAR");
//////// READ
    // FILE * SHOW = fopen("datakejut.txt", "r");
    // while(fscanf(SHOW, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index], tampnotetgl[index], tampnotenama[index], tampnotenohp[index], tampnotenamatrgt[index], tampnotecbgdesa[index], tampnotetrgtdesa[index], tampnotereq[index], tampnoteextra[index], tampnotetotal[index]) != EOF )
    // {
    //     index++;   
    // }
// 
    // for(int i = 0; i < 8; i++){
    //     gotoxy(10,11+i+i);set(0,15);printf("%d", i+1);                                //NOMOR
    //     gotoxy(14,11+i+i);set(0,15);printf("%s", tampnotenama[i]);
    //     gotoxy(34,11+i+i);set(0,15);printf("%s", tampnotenohp[i]);
    //     gotoxy(49,11+i+i);set(0,15);printf("%s", tampnotenamatrgt[i]);
    //     gotoxy(72,11+i+i);set(0,15);printf("%s", tampnotekodnik[i]);
    //     gotoxy(83,11+i+i);set(0,15);printf("%s", tampnotetgl[i]);
    //     gotoxy(96,11+i+i);set(0,15);printf("%s", tampnotereq[i]);
    //     gotoxy(110,11+i+i);set(0,15);printf("%s", tampnoteextra[i]);
    //     gotoxy(125,11+i+i);set(0,15);printf("%s", tampnotecbgdesa[i]);
    //     gotoxy(136,11+i+i);set(0,15);printf("%s", tampnotetrgtdesa[i]);
    //     gotoxy(150,11+i+i);set(0,15);printf("%s", tampnotetotal[i]);
    // }

}


void informasi_apps(){
    char inp;
    int pos;
    gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
    // tampilan(2,34,32,4,9,14);  
    gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
    
    tampilan(4,4,161,28,9,15);       /// BIMGKAI KETIGA
    tampilan(7,6,155,24,9,14);        /// BINGKAI RIWAYAT
    tampilan(10,8,149,20,15,8);     /// BINGKAI RIWAYAT
    
    gotoxy(68,10);set(0,8);printf("SEKILAS TENTANG APLIKASI APLIKASI KEJUTIN AJA");
    gotoxy(22,12);set(0,8);printf("HALO SEMUANYA !! Selamat Datang Di Aplikasi KEJUTIN AJA ! Bersama KEJUTIN AJA, kita Kejut Banyak Orang Aplikasi KEJUTIN!");
    gotoxy(22,14);set(0,8);printf("AJA dibuat ketika maraknya PERMUSUHAN di lingkungan masyarakat maupun keluarga. Banyak Hal yang menyebabkan terjadinya itu semua,");
    gotoxy(22,16);set(0,8);printf(" dan satu hal yang tidak menutup kemungkinan, yaitu kurangnya Silaturrahmi antar individu, sesuai yang diajarkan AGAMA ISLAM,");
    gotoxy(22,18);set(0,8);printf(" yaitu \"perkuatlah silaturrahmi, kemudian Perbanyaklah memberi\". Maka dari itu lahir, KEJUTIN AJA sebagai upaya solusi PERMUSUHAN, ");
    gotoxy(22,20);set(0,8);printf("baik di lingkungan KELUARGA maupun MASYARAKAT dengan menyediakan jasa KADO KEJUT ke daerah kecamatan Pameungpeuk dan sekitarnya.");
    // gotoxy(30,22);set(0,8);printf("");

}   

void kejutin_inpdata1(){
    char inp;    
    int tampumur = 0;
    tampilan(2,34,32,4,9,14);                                           //KOTAK 1
    gotoxy(11,36);set(0,14);printf("KEJUTIN");
    tampilan(4,4,161,28,9,15);                           //// BINGKAI TERDALAM                                                                                                 
    tampilan(9,6,72,24,9,8);                             //// KOTAK INPUT DATA
    gotoxy(13,11);set(0,8);printf("Nama\t\t: ");
    gotoxy(13,12);set(0,8);printf("_______________________________________________________");
    gotoxy(13,13);set(0,8);printf("NIK\t\t: ");
    gotoxy(13,14);set(0,8);printf("_______________________________________________________");
    gotoxy(13,15);set(0,8);printf("Jenis Kelamin\t: ");
    gotoxy(13,16);set(0,8);printf("_______________________________________________________");
    gotoxy(13,17);set(0,8);printf("Umur\t\t: ");
    gotoxy(13,18);set(0,8);printf("_______________________________________________________");
    gotoxy(13,19);set(0,8);printf("Nomor Handphone\t:");
    gotoxy(13,20);set(0,8);printf("_______________________________________________________");
    gotoxy(13,21);set(0,8);printf("Kecamatan\t\t: ");
    gotoxy(13,22);set(0,8);printf("_______________________________________________________");
    gotoxy(13,23);set(0,8);printf("Desa / Kelurahan\t: ");
    gotoxy(13,24);set(0,8);printf("_______________________________________________________");
    gotoxy(13,25);set(0,8);printf("Jalan / No Jalan\t: Jl.                     / No.      ");
    gotoxy(13,26);set(0,8);printf("_______________________________________________________");
    gotoxy(13,27);set(0,8);printf("RT / RW\t\t:      / ");
    gotoxy(13,28);set(0,8);printf("_______________________________________________________");
    while((inp = getch()) != 13){ 
        if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
            geser();
        }
    }
/////////////////////////////////////////////////////////////////////////////////////// INPUT DATA KEJUTER 
    gotoxy(34,11);ceknama(nama);
    gotoxy(34,13);ceknik(nik);
    gotoxy(34,15);cekjk(jk);
    for(;;){
        gotoxy(34,17);cekumur(umur);
        tampumur = atoi(umur);
        if(tampumur < 17 ){
                gotoxy(34,17);set(0,8);
                for(int i = 0; i < 3; i++){
                    gotoxy(34,17);printf("Usia tidak mencukupi");Sleep(300);
                    gotoxy(34,17);printf("                    ");Sleep(300);    
                }
        }else if(tampumur > 70){    
                for(int i = 0; i < 3; i++){
                    gotoxy(34,17);set(0,8);printf("Usia tidak sesuai");Sleep(300);
                    gotoxy(34,17);set(0,8);printf("                 ");Sleep(300);    
                }
        }else{
                break;  
        }
    }
    gotoxy(34,19);ceknohp(nohp);
    gotoxy(34,21);cekkec(kec);
    gotoxy(34,23);cekkec(desa);
    gotoxy(38,25);cekjalan(jln);gotoxy(64,25);ceknojal(nojal);
    gotoxy(34,27);cekrt(rt);gotoxy(42,27);cekrt(rw);
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<<<< || >>>>> Space untuk lanjutt <<<");   //57
    while((inp=getch())){
        if(inp == ' '){
            break;
        }
    }
    kejutin_inpdata2();
}

void kejutin_inpdata2(){
    char tampinp[6][100]={"Nama Target", "Jenis Kelamin Target", "Pilih Kecamatan Target", "Pilih Desa Target", "Tanggal Kejut"};
    char inp;
    int tamptgl = 0;
    int kesempatan = 0;
    int kectrgt;
    tampilan(4,4,161,28,9,15);                        ///// BINGKAI TERDALAM 
    tampilan(9,6,72,24,9,8);                            ///// BINGKAI INPUT
    for(int i = 0; i <= 4; i++){
        gotoxy(13,11+i+i+i);set(0,8);printf("%s", tampinp[i]);              //NAMA TARGET           //Pilih Desa Lokasi Target
        gotoxy(13,11+i+i+i+1);set(0,8);printf("Input > ");                  //JENIS KELAMIN         //PILIH TANGGAL KEJUT
        if(i==4){                                                           //PILIH KECAMATAN
            gotoxy(13,11+i+i+i+1);set(0,8);printf("Input >\t/\t/2023");
        }                                                                       
    }    
// /////////////////////////////////////////////////////////////////////////////////////////////////// INPUT DATA TARGET KEJUT
    gotoxy(21,12);ceknama(namatrgt);
    gotoxy(21,15);cekjk(jktrgt);
    tamkec();
    gotoxy(21,18);tampkectrgt = cekpilkec(kectrgt);     //// CEK KECAMATAN >> 2
    tamkoor();
    gotoxy(21,21);cekpildes(tampkectrgt);               //// CEK DESA      >> 3
    tamkoor2();            
    caridesa();
    set(0,8);gotoxy(21,24);tamptgl = cektgl(tgltrgt);
    caritgl();
    do{
    if(tamptgl == 0){
        break;
    }else{
        gotoxy(13,11+4+4+4+1);set(0,8);printf("Input >\t/\t/2023");
        gotoxy(21,24);set(0,8);tamptgl = cektgl(tgltrgt);
        caritgl();
    }
    kesempatan++;
    }while(kesempatan > 0 );
///////////////////
    // gotoxy(100,29);set(0,15);printf("Apakah anda yakin data  yang anda masukan BENAR ?");            //47
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<<<< || >>>>> Space untuk lanjutt <<<");   //57
    while((inp=getch())){   
        if(inp == ' '){
            break;
        }
    }
    kejutin_inpdata3();
}


void kejutin_inpdata3(){
    char tampinp[6][100]={"Kesukaan Target Kejut", "Pilih Tema Kado", "Pilih Request Isi Kado", "Mau Nambah Kado ga? (y/t)", "Kode Unik Kado"};
    char inp, tamp;
    int fav, temakado, reqkado, extra;
    int kodnik;
    int tampkado = 0, tampreq = 0, tampextra = 0;
    int index = 0;
    int tampkodnik = 0;
    

    tampilan(4,4,161,28,9,15);                        ///// BINGKAI TERDALAM 
    tampilan(9,6,72,24,9,8);                            ///// BINGKAI INPUT
    for(int i = 0; i <= 4; i++){
        gotoxy(13,11+i+i+i);set(0,8);printf("%s", tampinp[i]);              //KESUKAAN TARGET           //REQUEST KADO      //KODE UNIK
        gotoxy(13,11+i+i+i+1);set(0,8);printf("Input > ");                  //TEMA KADO                 //NAMBAH KADO                                                                  
    }

// /////////////////////////////////////////////////////////////////////////////// INPUT DATA KADO
    tamkeb();
    gotoxy(21,12);
    tampfav = cekpil2(fav);
    if( tampfav == 1){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,12);printf("SUKA NGEMIL");Sleep(300);
            }else{
            gotoxy(21,12);printf("           ");Sleep(300);
            }
        }
        strcpy(notefav, "TUKANG NGEMIL"); 
    }else if(tampfav == 2){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,12);printf("SUKA KOLEKSI BARANG");Sleep(300);
            }else{
            gotoxy(21,12);printf("                   ");;Sleep(300);
            }
        }
        strcpy(notefav, "TUKANG KOLEKSI BARANG"); 
    }
    // / NAMPILIN TEMA KADO 1 || 2 || 3
    tamkado();
    gotoxy(21,15);
    tampkado = cekpil3(temakado);
    if( tampkado == 1){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,15);printf("ROMANTIC GIFT");Sleep(300);
            }else{
            gotoxy(21,15);printf("             ");;Sleep(300);
            }
        }
        strcpy(notetema, "KADO ROMANTIS");
    }else if(tampkado == 2){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,15);printf("FAMILY GIFT");Sleep(300);
            }else{
            gotoxy(21,15);printf("           ");Sleep(300);
            }
        }
        strcpy(notetema, "KADO KELUARGA");
    }else if(tampkado == 3){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,15);printf("GRADUATION GIFT");Sleep(300);
            }else{
            gotoxy(21,15);printf("               ");Sleep(300);
            }
        }
        strcpy(notetema, "KADO KELULUSAN");
    }
    // NAMPILIN REQUEST KADO BERDASARKAN KEBIASAAN 1 || 2 || 3
    tamreq();
    gotoxy(21, 18);
    tampreq = cekpil3(reqkado);
    if (tampfav == 1)
    {
        if (tampreq == 1)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("BOLU");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("    ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "BOLU");
            biayakado = 98500;
            strcpy(notereq, "BOLU");
        }
        else if (tampreq == 2)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("DONAT");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("     ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "DONAT");
            biayakado = 65000;
            strcpy(notereq, "DONAT");
        }
        else if (tampreq == 3)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("PARCEL SNACK");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("            ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "PARCEL SNACK");
            biayakado = 85000;
            strcpy(notereq, "SNACK");
        }
    }
    else if (tampfav == 2)
    {
        if (tampreq == 1)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("PERHIASAN");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("          ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "PERHIASAN");
            biayakado = 150000;
            strcpy(notereq, "PERHIASAN");
        }
        else if (tampreq == 2)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("AKSESORIS");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("         ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "AKSESORIS");
            biayakado = 125000;
            strcpy(notereq, "AKSESORIS");
        }
        else if (tampreq == 3)
        {
            for (int i = 1; i <= 7; i++)
            {
                if (i % 2 == 1)
                {
                    gotoxy(21, 18);
                    printf("PARCEL KOSMETIK");
                    Sleep(300);
                }
                else
                {
                    gotoxy(21, 18);
                    printf("               ");
                    Sleep(300);
                }
            }
            strcpy(bayar[0], "PARCEL KOSMETIK");
            biayakado = 110000;
            strcpy(notereq, "PARCEL KOSMETIK");
        }
    }
    tamextra();
    gotoxy(21,21);                                      ////// NAMBAH KADO GA?
    while( (inp=getch()) != 13  || index==0){
    if(index < 1 && (inp == 'y' || inp == 't')){
            printf("%c", inp);
            tamp = inp;
            index++;
    }else if( inp == 8  && index != 0){
            printf("\b \b");
            index--;
            tamp='\0';
    }
    }
    if( tamp == 'y'){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,21);set(0,8);printf("MAU NAMBAH KADO");Sleep(300);
            }else{
            gotoxy(21,21);set(8,8);printf("               ");Sleep(300);
            }
            }
            tamextra();

    }else if(tamp == 't'){
        for(int i = 1; i <= 7; i++){
            if( i % 2 == 1){
            gotoxy(21,21);set(0,8);printf("GAMAU NAMBAH KADO");Sleep(300);
            }else{
            gotoxy(21,21);set(8,8);printf("                 ");Sleep(300);
            }
        }
        strcpy(noteextra, "NO EXTRA KADO");
    }
    tampkodnik = kodeunik(kodnik);
    gotoxy(21,24);printf("%d", tampkodnik);
    itoa(tampkodnik, notekodnik, 10);            
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<<<< || >>>>> Space untuk lanjutt <<<");
    while((inp=getch())){   
        if(inp == ' '){
            break;
        }
    }
    kejutin_inpdata4();
}

void kejutin_inpdata4(){
    char inp;
    int pos = 1;
    int tempat = 1;
    tampilan(4,4,161,28,9,15);
    tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
    tampilan(87,6,72,22,9,8);                          ///// Bingkai Output KANAN
    set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
    set(0,15);gotoxy(143,30);printf("[ENTER] EDIT DATA");
// HALAMAN 1
/////////////////// SLIDE 1
                gotoxy(75,30);set(0,15);printf("HALAMAN <   / 2 >");
                gotoxy(85,30);set(1,15);printf("1");
                gotoxy(19,10);set(0,8);printf("_______________________________________________________");
                gotoxy(19,12);set(0,8);printf("NAMA\t\t\t : %s", strupr(nama));
                gotoxy(19,13);set(0,8);printf("_______________________________________________________");
                gotoxy(19,15);set(0,8);printf("NIK\t\t\t : %s", nik);
                gotoxy(19,16);set(0,8);printf("_______________________________________________________");
                gotoxy(19,18);set(0,8);printf("JENIS KELAMIN\t : %s", strupr(jk));
                gotoxy(19,19);set(0,8);printf("_______________________________________________________");
                gotoxy(19,21);set(0,8);printf("UMUR\t\t\t : %s", umur);
                gotoxy(19,22);set(0,8);printf("_______________________________________________________");
                gotoxy(19,24);set(0,8);printf("NOMOR HANDPHONE\t : %s", nohp);
                gotoxy(19,25);set(0,8);printf("_______________________________________________________");
// // /////////////////// SLIDE 2t
                gotoxy(97,10);set(0,8);printf("_______________________________________________________");
                gotoxy(97,12);set(0,8);printf("KECAMATAN\t\t : %s", strupr(kec));
                gotoxy(97,13);set(0,8);printf("_______________________________________________________");
                gotoxy(97,15);set(0,8);printf("DESA / KELURAHAN\t : %s", strupr(desa));
                gotoxy(97,16);set(0,8);printf("_______________________________________________________");
                gotoxy(97,18);set(0,8);printf("JALAN / NO. JALAN\t : %s / %s", strupr(jln), nojal);
                gotoxy(97,19);set(0,8);printf("_______________________________________________________");
                gotoxy(97,21);set(0,8);printf("RT / RW\t\t : %s   / %s", rt, rw);
                gotoxy(97,22);set(0,8);printf("_______________________________________________________");
                set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
                set(0,15);gotoxy(143,30);printf("[ENTER] EDIT DATA");
    while((inp=getch()) != ' ' || tempat == 1){
        if(inp == 77){
            if(pos == 1){
            tempat = 2;
            pos = 2;

// HALAMAN 2
/////////////////// SLIDE 1
                tampilan(4,4,161,28,9,15);
                tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
                tampilan(87,6,72,22,9,8);
                gotoxy(75,30);set(0,15);printf("HALAMAN < 1 /   >");
                gotoxy(89,30);set(1,15);printf("2");
                gotoxy(19,10);set(0,8);printf("_______________________________________________________");
                gotoxy(19,12);set(0,8);printf("NAMA TARGET\t\t : %s", strupr(namatrgt));
                gotoxy(19,13);set(0,8);printf("_______________________________________________________");
                gotoxy(19,15);set(0,8);printf("JENIS KELAMIN TARGET  : %s", jktrgt);
                gotoxy(19,16);set(0,8);printf("_______________________________________________________");
                gotoxy(19,18);set(0,8);printf("KECAMATAN TARGET\t : %s", strupr(kectrgt));
                gotoxy(19,19);set(0,8);printf("_______________________________________________________");
                gotoxy(19,21);set(0,8);printf("DESA TARGET\t\t : %s", strupr(notetrgtdesa));
                gotoxy(19,22);set(0,8);printf("_______________________________________________________");
                gotoxy(19,24);set(0,8);printf("TANGGAL KEJUT\t : %s", notetgl);
                gotoxy(19,25);set(0,8);printf("_______________________________________________________");
/////////////////// SLIDE 2
                gotoxy(97,10);set(0,8);printf("_______________________________________________________");
                gotoxy(97,12);set(0,8);printf("KESUKAAN TARGET\t : %s", strupr(notefav));
                gotoxy(97,13);set(0,8);printf("_______________________________________________________");
                gotoxy(97,15);set(0,8);printf("TEMA KADO\t\t : %s", strupr(notetema));
                gotoxy(97,16);set(0,8);printf("_______________________________________________________");
                gotoxy(97,18);set(0,8);printf("REQUEST KADO\t\t : %s", strupr(notereq));
                gotoxy(97,19);set(0,8);printf("_______________________________________________________");
                gotoxy(97,21);set(0,8);printf("EXTRA ADDITION KADO\t : %s", strupr(noteextra));
                gotoxy(97,22);set(0,8);printf("_______________________________________________________");
                gotoxy(97,24);set(0,8);printf("KODE UNIK KADO\t\t : %s", notekodnik);
                gotoxy(97,25);set(0,8);printf("_______________________________________________________");
                set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
                set(0,15);gotoxy(143,30);printf("[SPACE] NEXT PROGRAM");
            }else if(pos == 2){
                pos = 1;
                tempat = 1;

// HALAMAN 1
/////////////////// SLIDE 1
                tampilan(4,4,161,28,9,15);
                tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
                tampilan(87,6,72,22,9,8);
                gotoxy(75,30);set(0,15);printf("HALAMAN <   / 2 >");
                gotoxy(85,30);set(1,15);printf("1");
                gotoxy(19,10);set(0,8);printf("_______________________________________________________");
                gotoxy(19,12);set(0,8);printf("NAMA\t\t\t : %s", strupr(nama));
                gotoxy(19,13);set(0,8);printf("_______________________________________________________");
                gotoxy(19,15);set(0,8);printf("NIK\t\t\t : %s", nik);
                gotoxy(19,16);set(0,8);printf("_______________________________________________________");
                gotoxy(19,18);set(0,8);printf("JENIS KELAMIN\t : %s", strupr(jk));
                gotoxy(19,19);set(0,8);printf("_______________________________________________________");
                gotoxy(19,21);set(0,8);printf("UMUR\t\t\t : %s", umur);
                gotoxy(19,22);set(0,8);printf("_______________________________________________________");
                gotoxy(19,24);set(0,8);printf("NOMOR HANDPHONE\t : %s", nohp);
                gotoxy(19,25);set(0,8);printf("_______________________________________________________");
// /////////////////// SLIDE 2
                gotoxy(97,10);set(0,8);printf("_______________________________________________________");
                gotoxy(97,12);set(0,8);printf("KECAMATAN\t\t : %s", strupr(kec));
                gotoxy(97,13);set(0,8);printf("_______________________________________________________");
                gotoxy(97,15);set(0,8);printf("DESA / KELURAHAN\t : %s", strupr(desa));
                gotoxy(97,16);set(0,8);printf("_______________________________________________________");
                gotoxy(97,18);set(0,8);printf("JALAN / NO. JALAN\t : %s / %s", strupr(jln), nojal);
                gotoxy(97,19);set(0,8);printf("_______________________________________________________");
                gotoxy(97,21);set(0,8);printf("RT / RW\t\t : %s   / %s", rt, rw);
                gotoxy(97,22);set(0,8);printf("_______________________________________________________");
                set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
                set(0,15);gotoxy(143,30);printf("[ENTER] EDIT DATA");

            }        
        }else if(inp == 75){
            if(pos == 1){
                pos = 2;
                tempat = 2;
                // HALAMAN 2
/////////////////// SLIDE 1
                tampilan(4,4,161,28,9,15);
                tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
                tampilan(87,6,72,22,9,8);                          ///// Bingkai Output KANAN
                gotoxy(75,30);set(0,15);printf("HALAMAN < 1 /   >");
                gotoxy(89,30);set(1,15);printf("2");
                gotoxy(19,10);set(0,8);printf("_______________________________________________________");
                gotoxy(19,12);set(0,8);printf("NAMA TARGET\t\t : %s", strupr(namatrgt));
                gotoxy(19,13);set(0,8);printf("_______________________________________________________");
                gotoxy(19,15);set(0,8);printf("JENIS KELAMIN TARGET  : %s", jktrgt);
                gotoxy(19,16);set(0,8);printf("_______________________________________________________");
                gotoxy(19,18);set(0,8);printf("KECAMATAN TARGET\t : %s", strupr(kectrgt));
                gotoxy(19,19);set(0,8);printf("_______________________________________________________");
                gotoxy(19,21);set(0,8);printf("DESA TARGET\t\t : %s", strupr(notetrgtdesa));
                gotoxy(19,22);set(0,8);printf("_______________________________________________________");
                gotoxy(19,24);set(0,8);printf("TANGGAL KEJUT\t : %s", notetgl);
                gotoxy(19,25);set(0,8);printf("_______________________________________________________");
/////////////////// SLIDE 2
                gotoxy(97,10);set(0,8);printf("_______________________________________________________");
                gotoxy(97,12);set(0,8);printf("KESUKAAN TARGET\t : %s", strupr(notefav));
                gotoxy(97,13);set(0,8);printf("_______________________________________________________");
                gotoxy(97,15);set(0,8);printf("TEMA KADO\t\t : %s", strupr(notetema));
                gotoxy(97,16);set(0,8);printf("_______________________________________________________");
                gotoxy(97,18);set(0,8);printf("REQUEST KADO\t\t : %s", strupr(notereq));
                gotoxy(97,19);set(0,8);printf("_______________________________________________________");
                gotoxy(97,21);set(0,8);printf("EXTRA ADDITION KADO\t : %s", strupr(noteextra));
                gotoxy(97,22);set(0,8);printf("_______________________________________________________");
                gotoxy(97,24);set(0,8);printf("KODE UNIK KADO\t\t : %s", notekodnik);
                gotoxy(97,25);set(0,8);printf("_______________________________________________________");
                set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
                set(0,15);gotoxy(143,30);printf("[SPACE] NEXT PROGRAM");
            }else if(pos == 2){
                pos = 1;
                tempat = 1;
                // HALAMAN 1
/////////////////// SLIDE 1
                tampilan(4,4,161,28,9,15);
                tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
                tampilan(87,6,72,22,9,8);        
                gotoxy(75,30);set(0,15);printf("HALAMAN <   / 2 >");
                gotoxy(85,30);set(1,15);printf("1");
                gotoxy(19,10);set(0,8);printf("_______________________________________________________");
                gotoxy(19,12);set(0,8);printf("NAMA\t\t\t : %s", strupr(nama));
                gotoxy(19,13);set(0,8);printf("_______________________________________________________");
                gotoxy(19,15);set(0,8);printf("NIK\t\t\t : %s", nik);
                gotoxy(19,16);set(0,8);printf("_______________________________________________________");
                gotoxy(19,18);set(0,8);printf("JENIS KELAMIN\t : %s", strupr(jk));
                gotoxy(19,19);set(0,8);printf("_______________________________________________________");
                gotoxy(19,21);set(0,8);printf("UMUR\t\t\t : %s", umur);
                gotoxy(19,22);set(0,8);printf("_______________________________________________________");
                gotoxy(19,24);set(0,8);printf("NOMOR HANDPHONE\t : %s", nohp);
                gotoxy(19,25);set(0,8);printf("_______________________________________________________");
// /////////////////// SLIDE 2
                gotoxy(97,10);set(0,8);printf("_______________________________________________________");
                gotoxy(97,12);set(0,8);printf("KECAMATAN\t\t : %s", strupr(kec));
                gotoxy(97,13);set(0,8);printf("_______________________________________________________");
                gotoxy(97,15);set(0,8);printf("DESA / KELURAHAN\t : %s", strupr(desa));
                gotoxy(97,16);set(0,8);printf("_______________________________________________________");
                gotoxy(97,18);set(0,8);printf("JALAN / NO. JALAN\t : %s / %s", strupr(jln), nojal);
                gotoxy(97,19);set(0,8);printf("_______________________________________________________");
                gotoxy(97,21);set(0,8);printf("RT / RW\t\t : %s   / %s", rt, rw);
                gotoxy(97,22);set(0,8);printf("_______________________________________________________");
                set(0,15);gotoxy(6,30);printf("[ENTER] EDIT DATA");
                set(0,15);gotoxy(143,30);printf("[ENTER] EDIT DATA");
            }        
        }else if( inp == 13){
            int halaman = tempat;
            int tempat2 = 1;
            edit_data(halaman, tempat2);
            while((inp=getch()) != 13 ){
                if(halaman == 1){
                    if(inp == 77){
                        if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 2){
                            tempat2 = 1;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }

                    }else if(inp == 75){
                        if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 2){
                            tempat2 = 1;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }
                    }
                }else if(halaman == 2){
                    if(inp == 77){
                        if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 1){
                            tempat2 = 2;
                            edit_data(halaman, tempat2);
                        }else if(tempat2 == 2){
                            tempat2 = 1;
                            edit_data(halaman, tempat2);
                        }
                    }else if(inp == 75){
                            if(tempat2 == 1){
                                tempat2 = 2;
                                edit_data(halaman, tempat2);
                            }else if(tempat2 == 2){
                                tempat2 = 1;
                                edit_data(halaman, tempat2);
                            }else if(tempat2 == 1){
                                tempat2 = 2;
                                edit_data(halaman, tempat2);
                            }
                    }
                }
            }
            if(halaman == 1){
                if(tempat2 == 1){
                    strcpy(nama, "");
                    strcpy(nik, "");
                    strcpy(jk, "");
                    strcpy(umur, "");
                    strcpy(nik, "");
                    strcpy(nohp, "");
                    Sleep(600);
                    tampilan(4,4,161,28,9,15);
                    edit_data2();

                }else if(tempat2 == 2){
                    strcpy(kec, "");
                    strcpy(desa, "");
                    strcpy(nojal, "");
                    strcpy(rt, "");
                    strcpy(rw, "");
                    edit_data1();
                }
            }else if(halaman == 2){
                if(tempat2 == 1){
                    strcpy(namatrgt, "");
                    strcpy(jktrgt, "");
                    strcpy(kectrgt, "");
                    strcpy(notetrgtdesa, "");
                    strcpy(notetgl, "");
                    Sleep(600);
                    tampilan(4,4,161,28,9,15);
                    edit_data3();
                }else if(tempat2 == 2){
                    strcpy(notefav, "");
                    strcpy(notetema, "");
                    strcpy(notereq, "");
                    strcpy(noteextra, "");
                    strcpy(notekodnik, "");
                    total = 0;
                    Sleep(600);
                    tampilan(4,4,161,28,9,15);
                    kejutin_inpdata3();
                }
            }
        }
    }
    kejutin_bayar();
}


void kejutin_bayar(){
    char uang[100];
    int kembalian = 0, benar = 0;
    int tampuang = 0;
    tampilan(4,4,161,28,9,15);
    tampilan(10,10,72,20,9,8);      // BINGKAI KIRI
    tampilan(100,12,50,15,9,8);     // BINGKAI KANAN    
    gotoxy(20,12);set(0,8);printf("-----------> RINCIAN BIAYA KEJUTIN AJA <-----------");
    gotoxy(14,14);set(0,8);printf(">>> BIAYA PERJALANAN <<<");
    gotoxy(14,15);set(0,8);printf("Ongkos Kirim        = %d", biayaongkos);
    gotoxy(14,16);set(0,8);printf("Biaya Keamanan      = %d", biayakeamanan);
    gotoxy(14,17);set(0,8);printf("\n\n");
    gotoxy(14,18);set(0,8);printf(">>> BIAYA KEJUTAN <<<");
    gotoxy(14,19);set(0,8);printf("Request Kado\t %s\t = %d", bayar[0], biayakado);
    gotoxy(14,20);set(0,8);printf("Extra Kado\t %s\t = %d", bayar[1], biayaextra);
    total = biayaongkos+biayakeamanan+biayakado+biayaextra;
    gotoxy(102,14);set(0,8);printf(" >>> PEMBAYARAN <<<");
    gotoxy(102,17);set(0,8);printf(" ~ Total Biaya = %d", total);
    gotoxy(102,18);set(0,8);printf(" ~ Bayar       = ");
    gotoxy(119,18);set(0,8);tampuang = atoi(cekuang(uang));
    
    FILE * add = fopen("datakejut.txt", "a");
    fprintf(add, "%s#%s#%s#%s#%s#%s#%s#%s#%s#%d\n", notekodnik, notetgl, nama, nohp, namatrgt, notecbgdesa, notetrgtdesa, notereq, noteextra, total);
    fclose(add);
    do{
        if(tampuang >= total){
            kembalian = tampuang - total;
            benar++;
        }else if( tampuang < total){
            benar = 0;
            for(int i = 0; i <= 10; i++){
                if(i < 5){
                        if(i%2==0){
                        gotoxy(119,18);printf("Uang Anda Tidak Mencukupi !");Sleep(300);
                        }else if(i%2==1){
                        gotoxy(119,18);printf("                           ");Sleep(300);    
                        }
                }else if( i > 4){
                        if(i%2==1){
                        gotoxy(119,18);printf("Silahkan Input Kembali !");Sleep(300);
                        }else if(i%2==0){
                        gotoxy(119,18);printf("                           ");Sleep(300);    
                        }   
                }
            }
            gotoxy(119,18);set(0,8);tampuang = atoi(cekuang(uang));
        }
    }while(benar == 0);
     for(int i = 0; i <= 17; i++){
                if(i < 5){
                        if(i%2==0){
                        gotoxy(119,18);printf("Pembayaran Telah Berhasil");Sleep(300);
                        }else if(i%2==1){
                        gotoxy(119,18);printf("                         ");Sleep(300);    
                        }
                }else if( i > 4){
                    if(i < 10){
                        if(i%2==1){
                        gotoxy(119,18);printf("Belanja Puas Harga Pas   ");Sleep(300);
                        }else if(i%2==0){
                        gotoxy(119,18);printf("                         ");Sleep(300);    
                        }   
                    }else{
                        if(i%2==1){
                        gotoxy(119,18);printf("Sampai Jumpa Kembali !!  ");Sleep(300);
                        }else if(i%2==0){
                        gotoxy(119,18);printf("                         ");Sleep(300);    
                        }   
                    }
                }
            }
            gotoxy(102,19);set(0,8);printf("Uang Kembalian Anda sebesar = %d", kembalian);
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<<<< || >>>>> Space untuk lanjutt <<<");
    int inp;
    while((inp=getch()) != ' '){   
        if(inp == ' '){
        }
    }
    menu();
}   

void cek_geser(){
    char inp;
    int pos = 1;
    int tempat = 1;
    tampilan(35,34,32,4,9,14);          //BINGKAI MENU
    gotoxy(43,36);set(0,14);printf("CEK KEJUTAN");
    tampilan(4,4,161,28,9,15);          //BINGKAI 3
    tampilan(54,14,30, 4,0,15);         //BINGKAI PILIH 1
    tampilan(88,14,30, 4,1,15);         //BINGKAI PILIH 2
    gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
    gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
    while((inp = getch()) != 13){ 
        if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
            geser();
        }
    }
    while((inp=getch()) != 13){
        if(inp == 77){
            if(pos == 1){
                pos = 2;
                tempat = 2;
                tampilan(54,14,30, 4,1,15);         //BINGKAI PILIH 1
                tampilan(88,14,30, 4,0,15);         //BINGKAI PILIH 2
                gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
                gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
            }else if(pos == 2){
                pos = 1;
                tempat = 1;
                tampilan(54,14,30, 4,0,15);         //BINGKAI PILIH 1
                tampilan(88,14,30, 4,1,15);         //BINGKAI PILIH 2
                gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
                gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
            }
        }else if(inp == 75){
            if(pos == 1){
                pos = 2;
                tempat = 2;
                tampilan(54,14,30, 4,1,15);         //BINGKAI PILIH 1
                tampilan(88,14,30, 4,0,15);         //BINGKAI PILIH 2
                gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
                gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
            }else if(pos == 2){
                pos = 1;
                tempat = 1;
                tampilan(54,14,30, 4,0,15);         //BINGKAI PILIH 1
                tampilan(88,14,30, 4,1,15);         //BINGKAI PILIH 2
                gotoxy(58,16);set(0,15);printf("CEK TANGGAL KEJUTIN AJA");
                gotoxy(91,16);set(0,15);printf("CEK KODE UNIK KEJUTIN AJA");
            }
        }
    }
    if(tempat == 1){
        cek_tanggal();
    }else if(tempat == 2){
        cek_kodnik();
    }


}

void cek_tanggal(){
    tampilan(4,4,161,28,9,8);          //BINGKAI 3

    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    char tamp[100];
    char inp;
    int tamptgl = 0;
    int kesempatan = 0;
    int index = 0, ada = 0, index2 = 0;



    tampilan(6,21,40,4,9,15);
    
    set(0,8);gotoxy(143,30);printf("[ESC] KELUAR ");
    set(0,8);gotoxy(6,30);printf("[SPACE] INPUT ULANG");

    gotoxy(7,23);set(0,15);printf("MASUKKAN TANGGAL & BULAN : ");
    gotoxy(7,24);set(0,15);printf("KEJUTIN AJA :\t /");
    gotoxy(21,24);set(0,15);tamptgl = cektgl(tgltrgt);
    caritgl();
    do{
    if(tamptgl == 0){
        break;
    }else{
        gotoxy(7,23);set(0,15);printf("MASUKKAN TANGGAL & BULAN");
        gotoxy(7,24);set(0,15);printf("KEJUTIN AJA :\t /");
        gotoxy(21,24);set(0,15);tamptgl = cektgl(tgltrgt);
        caritgl();
    }
    kesempatan++;
    }while(kesempatan > 0 );
    strcpy(tamp, notetgl);
    
    FILE *SHOW, *ADD; 
    SHOW = fopen("datakejut.txt", "r");
    while(fscanf(SHOW, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index], tampnotetgl[index], tampnotenama[index], tampnotenohp[index], tampnotenamatrgt[index], tampnotecbgdesa[index], tampnotetrgtdesa[index], tampnotereq[index], tampnoteextra[index], tampnotetotal[index]) != EOF )
    {
        index++;
        // Sleep(1000);
    }
    fclose(SHOW);


    ADD = fopen("npc.txt", "w");
    for(int i = 0; i < index; i++){
        if(strcmp(tamp, tampnotetgl[i])==0){
        ada++;
            fprintf(SHOW ,"%s#%s#%s#%s#%s#%s#%s#%s#%s#%s\n", tampnotetgl[i], tampnotenama[i], tampnotenamatrgt[i], tampnotekodnik[i], tampnotenohp[i], tampnotereq[i], tampnoteextra[i], tampnotecbgdesa[i], tampnotetrgtdesa[i], tampnotetotal[i]);
        }
    }
    fclose(ADD);

if(ada!=0){
    tampilan(4,4,161,28,9,15);       /// BIMGKAI KETIGA
    tampilan(7,6,155,24,9,8);        /// BINGKAI RIWAYAT
    tampilan(10,8,149,20,15,15);     /// BINGKAI RIWAYAT
    
    gotoxy(10,9);set(0,15);printf("NO");
    gotoxy(13,9);set(0,15);printf("TANGGAL KEJUT");                           //smpe 20
    gotoxy(28,9);set(0,15);printf("NAMA KEJUTER");                         //smpe 35
    gotoxy(49,9);set(0,15);printf("NAMA TARGET");                   //SMPE 45
    gotoxy(70,9);set(0,15);printf("KODE UNIK");
    gotoxy(81,9);set(0,15);printf("NO HP");
    gotoxy(96,9);set(0,15);printf("REQUEST KADO");
    gotoxy(110,9);set(0,15);printf("EXTRA KADO");
    gotoxy(122,9);set(0,15);printf("DESA CABANG");
    gotoxy(135,9);set(0,15);printf("DESA TARGET");
    gotoxy(148,9);set(0,15);printf("TOTAL BAYAR");
    
    SHOW = fopen("npc.txt", "r");
    while(fscanf(SHOW, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index2], tampnotetgl[index2], tampnotenama[index2], tampnotenohp[index2], tampnotenamatrgt[index2], tampnotecbgdesa[index2], tampnotetrgtdesa[index2], tampnotereq[index2], tampnoteextra[index2], tampnotetotal[index2]) != EOF )
    {
        
        gotoxy(10,11+index2+index2);set(0,15);printf("%d", index2+1);                                //NOMOR
        gotoxy(14,11+index2+index2);set(0,15);printf("%s", tampnotetgl[index2]);
        gotoxy(28,11+index2+index2);set(0,15);printf("%s", tampnotenama[index2]);
        gotoxy(49,11+index2+index2);set(0,15);printf("%s", tampnotenamatrgt[index2]);
        gotoxy(72,11+index2+index2);set(0,15);printf("%s", tampnotekodnik[index2]);
        gotoxy(81,11+index2+index2);set(0,15);printf("%s", tampnotenohp[index2]);
        gotoxy(96,11+index2+index2);set(0,15);printf("%s", tampnotereq[index2]);
        gotoxy(110,11+index2+index2);set(0,15);printf("%s", tampnoteextra[index2]);
        gotoxy(125,11+index2+index2);set(0,15);printf("%s", tampnotecbgdesa[index2]);
        gotoxy(135,11+index2+index2);set(0,15);printf("%s", tampnotetrgtdesa[index2]);
        gotoxy(151,11+index2+index2);set(0,15);printf("%s", tampnotetotal[index2]);
        index2++;

    }
    fclose(SHOW);
    while((inp=getch()) != 27){
        if(inp==' ');
    }
    menu();

}else if(ada == 0){
        for(int i = 0; i <= 7; i++){
                    if(i%2==0){
                    set(0,15);gotoxy(21,24);printf("Data Tidak Ditemukan !");Sleep(300);
                    }else{
                    set(0,15);gotoxy(21,24);printf("                      ");Sleep(300);    
                    }
        }
        while((inp=getch()) != 27){
            if(inp == ' '){
                cek_tanggal();
            }
        }
        menu();
}
}

void cek_kodnik(){
    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    char inp;
    char kodnik[100];
    char tamp[100];
    int pos;
    int index = 0, data = 0, ada = 0;
    
    tampilan(4,4,161,28,9,15);          //BINGKAI 3
    tampilan(93,26,45,4,9,8);

    set(0,15);gotoxy(143,30);printf("[ESC] KELUAR ");
    set(0,15);gotoxy(6,30);printf("[SPACE & ENTER] INPUT ULANG");

    gotoxy(95,28);set(0,8);printf("MASUKKAN KODE UNIK : ");
    gotoxy(116,28);strcpy(tamp, cekkodnik(kodnik));
    
    FILE * SHOW;
    SHOW = fopen("datakejut.txt", "r");
    while(fscanf(SHOW, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index], tampnotetgl[index], tampnotenama[index], tampnotenohp[index], tampnotenamatrgt[index], tampnotecbgdesa[index], tampnotetrgtdesa[index], tampnotereq[index], tampnoteextra[index], tampnotetotal[index]) != EOF )
    {
        index++;   
    }
     for(int i = 0; i < index; i++){
        if(strcmp(tamp, tampnotekodnik[i])==0){
            data = i;
            ada++;
            break;
        }
    }

    if(ada != 0){
            tampilan(9,6,72,24,9,8);
            gotoxy(13,9);set(0,8);printf("NAMA KEJUTER\t: %s", tampnotenama[data]);
            gotoxy(13,10);set(0,8);printf("_______________________________________________________");
            gotoxy(13,11);set(0,8);printf("NO HP KEJUTER\t: %s", tampnotenohp[data]);
            gotoxy(13,12);set(0,8);printf("_______________________________________________________");
            gotoxy(13,13);set(0,8);printf("NAMA TARGET\t: %s", tampnotenamatrgt[data]);
            gotoxy(13,14);set(0,8);printf("_______________________________________________________");
            gotoxy(13,15);set(0,8);printf("KADO KEJUTAN\t: %s", tampnotereq[data]);
            gotoxy(13,16);set(0,8);printf("_______________________________________________________");
            gotoxy(13,17);set(0,8);printf("EXTRA KADO SPESIAL\t: %s", tampnoteextra[data]);
            gotoxy(13,18);set(0,8);printf("_______________________________________________________");
            gotoxy(13,19);set(0,8);printf("CABANG KEJUTIN AJA\t: %s", tampnotecbgdesa[data]);
            gotoxy(13,20);set(0,8);printf("_______________________________________________________");
            gotoxy(13,21);set(0,8);printf("DESA TARGET\t: %s", tampnotetrgtdesa[data]);
            gotoxy(13,22);set(0,8);printf("_______________________________________________________");
            gotoxy(13,23);set(0,8);printf("TANGGAL KEJUTAN\t: %s", tampnotetgl[data]);
            gotoxy(13,24);set(0,8);printf("_______________________________________________________");
            gotoxy(13,25);set(0,8);printf("KODE UNIK KADO\t: %s", tampnotekodnik[data]);
            gotoxy(13,26);set(0,8);printf("_______________________________________________________");
            gotoxy(13,27);set(0,8);printf("TOTAL BAYAR KADO\t: %s",tampnotetotal[data]);
            gotoxy(13,28);set(0,8);printf("_______________________________________________________");
    
    fclose(SHOW);
    }else{
        for(int i = 0; i <= 7; i++){
                    if(i%2==0){
                    set(0,8);gotoxy(116,28);printf("Data Tidak Ditemukan !");Sleep(300);
                    }else{
                    set(0,8);gotoxy(116,28);printf("                      ");Sleep(300);    
                    }
        }

        while((inp=getch()) != 27){
                if(inp == ' '){
                    cek_kodnik();
                }
            }
        menu();
        }
}



void hapus_kejutin(){
    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    char inp;
    char kodnik[100];
    char tamp[100];
    int pos;
    int index = 0, data = 0, ada = 0;
    tampilan(68,34,32,4,9,14);          //BINGKAI PILIH MENU
    gotoxy(78,36);set(0,14);printf("BATAL KEJUTIN");
    tampilan(4,4,161,28,9,15);          //BINGKAI 3
    tampilan(103,26,45,4,9,8);

    set(0,15);gotoxy(6,6);printf("[ESC] KELUAR ");
    set(0,15);gotoxy(6,30);printf("[SPACE] INPUT ULANG");


    gotoxy(105,28);set(0,8);printf("MASUKKAN KODE UNIK : ");
    while((inp = getch()) != 13){ 
        if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
            geser();
        }
    }
    gotoxy(126,28);strcpy(tamp, cekkodnik(kodnik));
    FILE * HAPUS;
    HAPUS = fopen("datakejut.txt", "r");
    while(fscanf(HAPUS, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index], tampnotetgl[index], tampnotenama[index], tampnotenohp[index], tampnotenamatrgt[index], tampnotecbgdesa[index], tampnotetrgtdesa[index], tampnotereq[index], tampnoteextra[index], tampnotetotal[index]) != EOF )
    {
        index++;   
    }
    for(int i = 0; i < index; i++){
        if(strcmp(tamp, tampnotekodnik[i])==0){
            data = i;
            ada++;
            break;
        }
    }
//////////////// NAMPILIN DLU
if(ada != 0){
            tampilan(9,6,72,24,9,8);
            gotoxy(13,9);set(0,8);printf("NAMA KEJUTER\t: %s", tampnotenama[data]);
            gotoxy(13,10);set(0,8);printf("_______________________________________________________");
            gotoxy(13,11);set(0,8);printf("NO HP KEJUTER\t: %s", tampnotenohp[data]);
            gotoxy(13,12);set(0,8);printf("_______________________________________________________");
            gotoxy(13,13);set(0,8);printf("NAMA TARGET\t: %s", tampnotenamatrgt[data]);
            gotoxy(13,14);set(0,8);printf("_______________________________________________________");
            gotoxy(13,15);set(0,8);printf("KADO KEJUTAN\t: %s", tampnotereq[data]);
            gotoxy(13,16);set(0,8);printf("_______________________________________________________");
            gotoxy(13,17);set(0,8);printf("EXTRA KADO SPESIAL\t: %s", tampnoteextra[data]);
            gotoxy(13,18);set(0,8);printf("_______________________________________________________");
            gotoxy(13,19);set(0,8);printf("CABANG KEJUTIN AJA\t: %s", tampnotecbgdesa[data]);
            gotoxy(13,20);set(0,8);printf("_______________________________________________________");
            gotoxy(13,21);set(0,8);printf("DESA TARGET\t: %s", tampnotetrgtdesa[data]);
            gotoxy(13,22);set(0,8);printf("_______________________________________________________");
            gotoxy(13,23);set(0,8);printf("TANGGAL KEJUTAN\t: %s", tampnotetgl[data]);
            gotoxy(13,24);set(0,8);printf("_______________________________________________________");
            gotoxy(13,25);set(0,8);printf("KODE UNIK KADO\t: %s", tampnotekodnik[data]);
            gotoxy(13,26);set(0,8);printf("_______________________________________________________");
            gotoxy(13,27);set(0,8);printf("TOTAL BAYAR KADO\t: %s",tampnotetotal[data]);
            gotoxy(13,28);set(0,8);printf("_______________________________________________________");

            while((inp=getch()) != 32){
                if(inp == 27){
                    hapus_kejutin();
                }
            }
            /////////////////// MENGHAPUS 
            if(ada != 0){
                HAPUS = fopen("datakejut.txt", "w");
                for(int i = 0; i < index; i++){
                    if( data != i){
                        fprintf(HAPUS, "%s#%s#%s#%s#%s#%s#%s#%s#%s#%d\n", tampnotekodnik[i], tampnotetgl[i], tampnotenama[i], tampnotenohp[i], tampnotenamatrgt[i], tampnotecbgdesa[i], tampnotetrgtdesa[i], tampnotereq[i], tampnoteextra[i], tampnotetotal[i]);
                    }
                }
            }
            fclose(HAPUS);
   
            tampilan(4,4,161,28,9,15);
            for(int i = 0; i <= 7; i++){
                if(i%2==0){
                    set(0,15);gotoxy(70,18);printf("DATA BERHASIL TERHAPUS !");Sleep(300);
                }else{
                    set(0,15);gotoxy(70,18);printf("                        ");Sleep(300);    
                }
            }
            menu();
    }else{
        for(int i = 0; i <= 7; i++){
                if(i%2==0){
                    gotoxy(126,28);set(0,8);printf("Data Tidak Ditemukan !");Sleep(300);
                }else{
                    gotoxy(126,28);set(0,8);printf("                      ");Sleep(300);    
                }
    }
    while((inp=getch()) != 27){
        if(inp == ' '){
            hapus_kejutin();
        }
    }
    menu();
}
}



void riwayat_kejutin(){
    char nama[100];
    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    int index=0;
    char inp;
    int tempat = 1;
    int pos = 1;
    int halaman = 1;

    tampilan(101,34,32,4,9,14);
    gotoxy(110,36);set(0,14);printf("RIWAYAT KEJUTAN");
    tampilan(4,4,161,28,9,15);       /// BIMGKAI KETIGA
    tampilan(7,6,155,24,9,8);        /// BINGKAI RIWAYAT 1
    tampilan(10,8,149,20,15,15);     /// BINGKAI RIWAYAT 2                  // 26
                                                                            // 69

//////// READ
    tabel_halaman(halaman);
    gotoxy(80,27);printf("< 1 / 2 >");
    gotoxy(82,27);set(9,15);printf("1");
    // gotoxy(86,27);set(9,15);printf("2");    
    while((inp=getch()) != 27){
        if( inp == 77 ){
            if(halaman == 1){
                halaman = 2;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 1 / 2 >");
                gotoxy(86,27);set(9,15);printf("2");
            }else if(halaman == 2){
                halaman = 3;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 2 / 3 >");
                gotoxy(86,27);set(9,15);printf("3");
            }else if(halaman == 3){
                halaman = 1;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 1 / 2 >");
                gotoxy(82,27);set(9,15);printf("1");
            }
        }else if( inp == 75){
            if(halaman == 1){
                halaman = 3;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 2 / 3 >");
                gotoxy(86,27);set(9,15);printf("3");
            }else if(halaman == 3){
                halaman = 2;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 1 / 2 >");
                gotoxy(86,27);set(9,15);printf("2");
            }else if(halaman == 2){
                halaman = 1;
                tampilan(10,8,149,20,15,15);
                tabel_halaman(halaman);
                gotoxy(80,27);printf("< 1 / 2 >");
                gotoxy(82,27);set(9,15);printf("1");
            }
        }
    }
    geser();
    // while((inp = getch()) != 13){ 
    // if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
    //     geser();
    //     }
    // }
}

void tabel_halaman(int halaman){
    char tampnotekodnik[100][100], tampnotetgl[100][100], tampnotenama[100][100], tampnotenohp[100][100], tampnotenamatrgt[100][100], tampnotecbgdesa[100][100], tampnotetrgtdesa[100][100], tampnotereq[100][100], tampnoteextra[100][100], tampnotetotal[100][100];
    int index = 0;
    
    gotoxy(10,9);set(0,15);printf("NO");
    gotoxy(13,9);set(0,15);printf("NAMA KEJUTER");                           //smpe 20
    gotoxy(34,9);set(0,15);printf("NO HP");                         //smpe 35
    gotoxy(49,9);set(0,15);printf("NAMA TARGET");                   //SMPE 45
    gotoxy(70,9);set(0,15);printf("KODE UNIK");
    gotoxy(81,9);set(0,15);printf("TANGGAL KEJUT");
    gotoxy(96,9);set(0,15);printf("REQUEST KADO");
    gotoxy(110,9);set(0,15);printf("EXTRA KADO");
    gotoxy(122,9);set(0,15);printf("DESA CABANG");
    gotoxy(135,9);set(0,15);printf("DESA TARGET");
    gotoxy(148,9);set(0,15);printf("TOTAL BAYAR");

    FILE * SHOW = fopen("datakejut.txt", "r");
    while(fscanf(SHOW, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", tampnotekodnik[index], tampnotetgl[index], tampnotenama[index], tampnotenohp[index], tampnotenamatrgt[index], tampnotecbgdesa[index], tampnotetrgtdesa[index], tampnotereq[index], tampnoteextra[index], tampnotetotal[index]) != EOF )
    {
        if(halaman == 1 && index < 8){
                gotoxy(10,11+index+index);set(0,15);printf("%d", index+1);                                //NOMOR
                gotoxy(14,11+index+index);set(0,15);printf("%s", tampnotenama[index]);
                gotoxy(34,11+index+index);set(0,15);printf("%s", tampnotenohp[index]);
                gotoxy(49,11+index+index);set(0,15);printf("%s", tampnotenamatrgt[index]);
                gotoxy(72,11+index+index);set(0,15);printf("%s", tampnotekodnik[index]);
                gotoxy(83,11+index+index);set(0,15);printf("%s", tampnotetgl[index]);
                gotoxy(96,11+index+index);set(0,15);printf("%s", tampnotereq[index]);
                gotoxy(110,11+index+index);set(0,15);printf("%s", tampnoteextra[index]);
                gotoxy(125,11+index+index);set(0,15);printf("%s", tampnotecbgdesa[index]);
                gotoxy(136,11+index+index);set(0,15);printf("%s", tampnotetrgtdesa[index]);
                gotoxy(150,11+index+index);set(0,15);printf("%s", tampnotetotal[index]);
        }else if(halaman == 2 && index >= 8 && index < 16){
                gotoxy(10,11+index+index-16);set(0,15);printf("%d", index+1);                                //NOMOR
                gotoxy(14,11+index+index-16);set(0,15);printf("%s", tampnotenama[index]);
                gotoxy(34,11+index+index-16);set(0,15);printf("%s", tampnotenohp[index]);
                gotoxy(49,11+index+index-16);set(0,15);printf("%s", tampnotenamatrgt[index]);
                gotoxy(72,11+index+index-16);set(0,15);printf("%s", tampnotekodnik[index]);
                gotoxy(83,11+index+index-16);set(0,15);printf("%s", tampnotetgl[index]);
                gotoxy(96,11+index+index-16);set(0,15);printf("%s", tampnotereq[index]);
                gotoxy(110,11+index+index-16);set(0,15);printf("%s", tampnoteextra[index]);
                gotoxy(125,11+index+index-16);set(0,15);printf("%s", tampnotecbgdesa[index]);
                gotoxy(136,11+index+index-16);set(0,15);printf("%s", tampnotetrgtdesa[index]);
                gotoxy(150,11+index+index-16);set(0,15);printf("%s", tampnotetotal[index]);
        }  else if (halaman == 3 && index >= 16 && index < 25)
        {
                gotoxy(10,11+index+index-34);set(0,15);printf("%d", index+1);                                //NOMOR
                gotoxy(14,11+index+index-34);set(0,15);printf("%s", tampnotenama[index]);
                gotoxy(34,11+index+index-34);set(0,15);printf("%s", tampnotenohp[index]);
                gotoxy(49,11+index+index-34);set(0,15);printf("%s", tampnotenamatrgt[index]);
                gotoxy(72,11+index+index-34);set(0,15);printf("%s", tampnotekodnik[index]);
                gotoxy(83,11+index+index-34);set(0,15);printf("%s", tampnotetgl[index]);
                gotoxy(96,11+index+index-34);set(0,15);printf("%s", tampnotereq[index]);
                gotoxy(110,11+index+index-34);set(0,15);printf("%s", tampnoteextra[index]);
                gotoxy(125,11+index+index-34);set(0,15);printf("%s", tampnotecbgdesa[index]);
                gotoxy(136,11+index+index-34);set(0,15);printf("%s", tampnotetrgtdesa[index]);
                gotoxy(150,11+index+index-34);set(0,15);printf("%s", tampnotetotal[index]);

        }
        index++;   
    }
}

   



void bingkai5(){
    char inp;
    int pos;
    tampilan(134,34,33,4,9,14);
    while((inp = getch()) != 13){ 
        if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
            geser();
        }
    }
    gotoxy(141,36);set(0,14);printf("INFORMASI APLIKASI");
    gotoxy(84,19);set(0,15);printf("5");
    while((inp = getch()) != 13){ 
        if(inp == 27){
        geser();
        }
    }
}

void tamkec(){
    tampilan(100,12,50,15,9,8);
    gotoxy(112,14);set(0,8);printf(">>> PILIHAN KECAMATAN <<<");
    gotoxy(112,15);set(0,8);printf("-- Sekitar Garut Selatan --");
    gotoxy(106,17);set(0,8);printf("1) Kecamatan Pameungpeuk");       //38
    gotoxy(106,18);set(0,8);printf("2) Kecamatan Cisompet");
}


void tamkoor(){
    int ongkos;
    tampilan(100,12,50,15,9,8);
    if(tampkectrgt == 1){
        gotoxy(106,14);set(0,8);printf(">>> KEJUTIN AJA CABANG PAMEUNGPEUK <<<");       //38
        strcpy(kectrgt, "KECAMATAN PAMEUNGPEUK");
        strcpy(notecbgdesa, "PASS");
    }else if(tampkectrgt == 2){
        gotoxy(107,14);set(0,8);printf(">>> KEJUTIN AJA CABANG CISOMPET <<<");          //35
        strcpy(notecbgdesa, "DEPOK");
        strcpy(kectrgt, "KECAMATAN CISOMPET");
    }
    koorbanding(tampkectrgt, ongkos);
}

void tamkoor2(){
    int ongkos;
    biayaongkos = koorbanding(tampkectrgt, ongkos);
    biayakeamanan = 3000;
    // printf("biaya ongkos : %d", biayaongkos);
}

void tamkeb(){
    tampilan(100,12,50,15,9,8);
    gotoxy(102,14);set(0,8);printf(">>> KESUKAAN/KEBIASAAN TARGET KEJUT <<<");
    gotoxy(106,16);set(0,8);printf("1. Suka Ngemil");
    gotoxy(106,17);set(0,8);printf("2. Suka Ngoleksi Barang");       //38   
}


void tamkado(){
    tampilan(100,12,50,15,9,8);
    gotoxy(117,14);set(0,8);printf(">>> TEMA KADO <<<");
    gotoxy(106,16);set(0,8);printf("1. ROMANTIC GIFT");
    gotoxy(106,17);set(0,8);printf("2. FAMILY GIFT");
    gotoxy(106,18);set(0,8);printf("3. GRADUATION GIFT"); 
}

void tamreq(){
    tampilan(100,12,50,15,9,8);
    if(tampfav == 1){
        gotoxy(109,14);set(0,8);printf(">>> REKOMENDASI KADO CEMILAN <<<");
        gotoxy(106,16);set(0,8);printf("1. BOLU\t\t\tRp. 98500");
        gotoxy(106,17);set(0,8);printf("2. DONAT\t\t\tRp. 65000");
        gotoxy(106,18);set(0,8);printf("3. PARCEL SNACK\t\tRp. 85000");    
    }else if(tampfav == 2){
    gotoxy(108,14);set(0,8);printf(">>> REKOMENDASI KADO BARANG LUCU <<<");
    gotoxy(106,16);set(0,8);printf("1. PERHIASAN\t\t\tRp. 150000");
    gotoxy(106,17);set(0,8);printf("2. AKSESORIS\t\t\tRp. 125000");
    gotoxy(106,18);set(0,8);printf("3. PARCEL KOSMETIK\t\tRp. 110000"); 
    }
}

void tamextra(){
    tampilan(100,12,50,15,9,8);
    gotoxy(104,14);set(0,8);printf(">>> TAMBAHAN KADO SPESIAL KEJUTIN AJA <<<");
    gotoxy(104,15);set(0,8);printf("------------------------------------------");
    gotoxy(104,16);set(0,8);printf("------------------------------------------");
    gotoxy(104,17);set(0,8);printf("------------------------------------------");
    gotoxy(104,18);set(0,8);printf("------------------------------------------");
    if( strcmp(jktrgt, "L")==0){
    gotoxy(104,19);set(0,8);printf("--------- JAM TANGAN KEJUTIN AJA ---------");
    gotoxy(104,20);set(0,8);printf("--------     Rp. 115.000,00      --------");
    strcpy(bayar[1], "JAM TANGAN");
    strcpy(noteextra, "JAM TANGAN");
    biayaextra = 115000;
    }else if( strcmp(jktrgt, "P")==0){
    gotoxy(104,19);set(0,8);printf("--------- BONEKA BEAR KEJUTIN AJA --------");
    gotoxy(104,20);set(0,8);printf("----------     Rp. 80.000,00      --------");    
    strcpy(bayar[1], "BONEKA BEAR");
    biayaextra = 80000;
    strcpy(noteextra, "BONEKA BEAR");
    }
    gotoxy(104,21);set(0,8);printf("------------------------------------------");
    gotoxy(104,22);set(0,8);printf("------------------------------------------");
    gotoxy(104,23);set(0,8);printf("------------------------------------------");
    gotoxy(104,24);set(0,8);printf("------------------------------------------");
}

void caridesa(){
    char desa[100];
    strcpy(notetrgtdesa, lempardesa(desa));
}

void caritgl(){
    char tgl[100];
    strcpy(notetgl, lempartgl(tgl));
}

int edit_data(int halaman,int tempat){
    if(halaman == 1){
        if(tempat == 1){
            tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
            tampilan(87,6,72,22,0,8);                          ///// Bingkai Output KANAN

            gotoxy(19,10);set(0,8);printf("_______________________________________________________");
            gotoxy(19,12);set(0,8);printf("NAMA\t\t\t : %s", strupr(nama));
            gotoxy(19,13);set(0,8);printf("_______________________________________________________");
            gotoxy(19,15);set(0,8);printf("NIK\t\t\t : %s", nik);
            gotoxy(19,16);set(0,8);printf("_______________________________________________________");
            gotoxy(19,18);set(0,8);printf("JENIS KELAMIN\t : %s", strupr(jk));
            gotoxy(19,19);set(0,8);printf("_______________________________________________________");
            gotoxy(19,21);set(0,8);printf("UMUR\t\t\t : %s", umur);
            gotoxy(19,22);set(0,8);printf("_______________________________________________________");
            gotoxy(19,24);set(0,8);printf("NOMOR HANDPHONE\t : %s", nohp);
            gotoxy(19,25);set(0,8);printf("_______________________________________________________");

            gotoxy(97,10);set(0,8);printf("_______________________________________________________");
            gotoxy(97,12);set(0,8);printf("KECAMATAN\t\t : %s", strupr(kec));
            gotoxy(97,13);set(0,8);printf("_______________________________________________________");
            gotoxy(97,15);set(0,8);printf("DESA / KELURAHAN\t : %s", strupr(desa));
            gotoxy(97,16);set(0,8);printf("_______________________________________________________");
            gotoxy(97,18);set(0,8);printf("JALAN / NO. JALAN\t : %s / %s", jln, nojal);
            gotoxy(97,19);set(0,8);printf("_______________________________________________________");
            gotoxy(97,21);set(0,8);printf("RT / RW\t\t : %s   / %s", rt, rw);
            gotoxy(97,22);set(0,8);printf("_______________________________________________________");

        }else if(tempat == 2){
            tampilan(10,6,72,22,0,8);                          ///// Bingkai Output KIRI        
            tampilan(87,6,72,22,9,8);                          ///// Bingkai Output KANAN
            gotoxy(19,10);set(0,8);printf("_______________________________________________________");
            gotoxy(19,12);set(0,8);printf("NAMA\t\t\t : %s", strupr(nama));
            gotoxy(19,13);set(0,8);printf("_______________________________________________________");
            gotoxy(19,15);set(0,8);printf("NIK\t\t\t : %s", nik);
            gotoxy(19,16);set(0,8);printf("_______________________________________________________");
            gotoxy(19,18);set(0,8);printf("JENIS KELAMIN\t : %s", strupr(jk));
            gotoxy(19,19);set(0,8);printf("_______________________________________________________");
            gotoxy(19,21);set(0,8);printf("UMUR\t\t\t : %s", umur);
            gotoxy(19,22);set(0,8);printf("_______________________________________________________");
            gotoxy(19,24);set(0,8);printf("NOMOR HANDPHONE\t : %s", nohp);
            gotoxy(19,25);set(0,8);printf("_______________________________________________________");

            gotoxy(97,10);set(0,8);printf("_______________________________________________________");
            gotoxy(97,12);set(0,8);printf("KECAMATAN\t\t : %s", strupr(kec));
            gotoxy(97,13);set(0,8);printf("_______________________________________________________");
            gotoxy(97,15);set(0,8);printf("DESA / KELURAHAN\t : %s", strupr(desa));
            gotoxy(97,16);set(0,8);printf("_______________________________________________________");
            gotoxy(97,18);set(0,8);printf("JALAN / NO. JALAN\t : %s / %s", jln, nojal);
            gotoxy(97,19);set(0,8);printf("_______________________________________________________");
            gotoxy(97,21);set(0,8);printf("RT / RW\t\t : %s   / %s", rt, rw);
            gotoxy(97,22);set(0,8);printf("_______________________________________________________");

        }

    }else if(halaman == 2){
        if(tempat == 1){
            tampilan(10,6,72,22,0,8);                          ///// Bingkai Output KIRI        
            tampilan(87,6,72,22,9,8);                          ///// Bingkai Output KANAN
            gotoxy(19,10);set(0,8);printf("_______________________________________________________");
            gotoxy(19,12);set(0,8);printf("NAMA TARGET\t\t : %s", strupr(namatrgt));
            gotoxy(19,13);set(0,8);printf("_______________________________________________________");
            gotoxy(19,15);set(0,8);printf("JENIS KELAMIN TARGET  : %s", jktrgt);
            gotoxy(19,16);set(0,8);printf("_______________________________________________________");
            gotoxy(19,18);set(0,8);printf("KECAMATAN TARGET\t : %s", strupr(kectrgt));
            gotoxy(19,19);set(0,8);printf("_______________________________________________________");
            gotoxy(19,21);set(0,8);printf("DESA TARGET\t\t : %s", strupr(notetrgtdesa));
            gotoxy(19,22);set(0,8);printf("_______________________________________________________");
            gotoxy(19,24);set(0,8);printf("TANGGAL KEJUT\t : %s", notetgl);
            gotoxy(19,25);set(0,8);printf("_______________________________________________________");

            gotoxy(97,10);set(0,8);printf("_______________________________________________________");
            gotoxy(97,12);set(0,8);printf("KESUKAAN TARGET\t : %s", strupr(notefav));
            gotoxy(97,13);set(0,8);printf("_______________________________________________________");
            gotoxy(97,15);set(0,8);printf("TEMA KADO\t\t : %s", strupr(notetema));
            gotoxy(97,16);set(0,8);printf("_______________________________________________________");
            gotoxy(97,18);set(0,8);printf("REQUEST KADO\t\t : %s", strupr(notereq));
            gotoxy(97,19);set(0,8);printf("_______________________________________________________");
            gotoxy(97,21);set(0,8);printf("EXTRA ADDITION KADO\t : %s", strupr(noteextra));
            gotoxy(97,22);set(0,8);printf("_______________________________________________________");
            gotoxy(97,24);set(0,8);printf("KODE UNIK KADO\t\t : %s", notekodnik);
            gotoxy(97,25);set(0,8);printf("_______________________________________________________");
        
        }else if(tempat == 2){
            tampilan(10,6,72,22,9,8);                          ///// Bingkai Output KIRI        
            tampilan(87,6,72,22,0,8);                          ///// Bingkai Output KANAN
            
            gotoxy(19,10);set(0,8);printf("_______________________________________________________");
            gotoxy(19,12);set(0,8);printf("NAMA TARGET\t\t : %s", strupr(namatrgt));
            gotoxy(19,13);set(0,8);printf("_______________________________________________________");
            gotoxy(19,15);set(0,8);printf("JENIS KELAMIN TARGET  : %s", jktrgt);
            gotoxy(19,16);set(0,8);printf("_______________________________________________________");
            gotoxy(19,18);set(0,8);printf("KECAMATAN TARGET\t : %s", strupr(kectrgt));
            gotoxy(19,19);set(0,8);printf("_______________________________________________________");
            gotoxy(19,21);set(0,8);printf("DESA TARGET\t\t : %s", strupr(notetrgtdesa));
            gotoxy(19,22);set(0,8);printf("_______________________________________________________");
            gotoxy(19,24);set(0,8);printf("TANGGAL KEJUT\t : %s", notetgl);
            gotoxy(19,25);set(0,8);printf("_______________________________________________________");
        

            gotoxy(97,10);set(0,8);printf("_______________________________________________________");
            gotoxy(97,12);set(0,8);printf("KESUKAAN TARGET\t : %s", strupr(notefav));
            gotoxy(97,13);set(0,8);printf("_______________________________________________________");
            gotoxy(97,15);set(0,8);printf("TEMA KADO\t\t : %s", strupr(notetema));
            gotoxy(97,16);set(0,8);printf("_______________________________________________________");
            gotoxy(97,18);set(0,8);printf("REQUEST KADO\t\t : %s", strupr(notereq));
            gotoxy(97,19);set(0,8);printf("_______________________________________________________");
            gotoxy(97,21);set(0,8);printf("EXTRA ADDITION KADO\t : %s", strupr(noteextra));
            gotoxy(97,22);set(0,8);printf("_______________________________________________________");
            gotoxy(97,24);set(0,8);printf("KODE UNIK KADO\t\t : %s", notekodnik);
            gotoxy(97,25);set(0,8);printf("_______________________________________________________");
        }
    }
}           

void edit_data1(){
    char inp;    
    int tampumur = 0;
    tampilan(2,34,32,4,9,14);                                           //KOTAK 1
    gotoxy(11,36);set(0,14);printf("KEJUTIN");
    tampilan(4,4,161,28,9,15);                           //// BINGKAI TERDALAM                                                                                                 
    tampilan(9,6,72,24,9,8);                             //// KOTAK INPUT DATA
    gotoxy(13,11);set(0,8);printf("Nama\t\t: ");
    gotoxy(13,12);set(0,8);printf("_______________________________________________________");
    gotoxy(13,13);set(0,8);printf("NIK\t\t: ");
    gotoxy(13,14);set(0,8);printf("_______________________________________________________");
    gotoxy(13,15);set(0,8);printf("Jenis Kelamin\t: ");
    gotoxy(13,16);set(0,8);printf("_______________________________________________________");
    gotoxy(13,17);set(0,8);printf("Umur\t\t: ");
    gotoxy(13,18);set(0,8);printf("_______________________________________________________");
    gotoxy(13,19);set(0,8);printf("Nomor Handphone\t:");
    gotoxy(13,20);set(0,8);printf("_______________________________________________________");
    gotoxy(13,21);set(0,8);printf("Kecamatan\t\t: ");
    gotoxy(13,22);set(0,8);printf("_______________________________________________________");
    gotoxy(13,23);set(0,8);printf("Desa / Kelurahan\t: ");
    gotoxy(13,24);set(0,8);printf("_______________________________________________________");
    gotoxy(13,25);set(0,8);printf("Jalan / No Jalan\t: Jl.                     / No.      ");
    gotoxy(13,26);set(0,8);printf("_______________________________________________________");
    gotoxy(13,27);set(0,8);printf("RT / RW\t\t:      / ");
    gotoxy(13,28);set(0,8);printf("_______________________________________________________");
    // while((inp = getch()) != 13){ 
    //     if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
    //         geser();
    //     }
    // }
/////////////////////////////////////////////////////////////////////////////////////// INPUT DATA KEJUTER 
    gotoxy(34,11);ceknama(nama);
    gotoxy(34,13);ceknik(nik);
    gotoxy(34,15);cekjk(jk);
    for(;;){
        gotoxy(34,17);cekumur(umur);
        tampumur = atoi(umur);
        if(tampumur < 17 ){
                gotoxy(34,17);set(0,8);
                for(int i = 0; i < 3; i++){
                    gotoxy(34,17);printf("Usia tidak mencukupi");Sleep(300);
                    gotoxy(34,17);printf("                    ");Sleep(300);    
                }
        }else if(tampumur > 70){    
                for(int i = 0; i < 3; i++){
                    gotoxy(34,17);set(0,8);printf("Usia tidak sesuai");Sleep(300);
                    gotoxy(34,17);set(0,8);printf("                 ");Sleep(300);    
                }
        }else{
                break;
        }
    }
    gotoxy(34,19);ceknohp(nohp);
    gotoxy(100,29);set(0,15);printf("Apakah anda yakin data yang anda masukan BENAR ?");            //47
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<< || >>> Esc untuk kembali input <<<");   //57
    while((inp=getch())){
        if(inp == ' '){
            break;
        }else if(inp == 27){
            edit_data1();
        }
    }
    tampilan(4,4,161,28,9,15);
    kejutin_inpdata4();
}

void edit_data2(){
    char inp;    
    int tampumur = 0;
    tampilan(2,34,32,4,9,14);                                           //KOTAK 1
    gotoxy(11,36);set(0,14);printf("KEJUTIN");
    tampilan(4,4,161,28,9,15);                           //// BINGKAI TERDALAM                                                                                                 
    tampilan(9,6,72,24,9,8);                             //// KOTAK INPUT DATA
    gotoxy(13,11);set(0,8);printf("Nama\t\t: ");
    gotoxy(13,12);set(0,8);printf("_______________________________________________________");
    gotoxy(13,13);set(0,8);printf("NIK\t\t: ");
    gotoxy(13,14);set(0,8);printf("_______________________________________________________");
    gotoxy(13,15);set(0,8);printf("Jenis Kelamin\t: ");
    gotoxy(13,16);set(0,8);printf("_______________________________________________________");
    gotoxy(13,17);set(0,8);printf("Umur\t\t: ");
    gotoxy(13,18);set(0,8);printf("_______________________________________________________");
    gotoxy(13,19);set(0,8);printf("Nomor Handphone\t:");
    gotoxy(13,20);set(0,8);printf("_______________________________________________________");
    gotoxy(13,21);set(0,8);printf("Kecamatan\t\t: ");
    gotoxy(13,22);set(0,8);printf("_______________________________________________________");
    gotoxy(13,23);set(0,8);printf("Desa / Kelurahan\t: ");
    gotoxy(13,24);set(0,8);printf("_______________________________________________________");
    gotoxy(13,25);set(0,8);printf("Jalan / No Jalan\t: Jl.                     / No.      ");
    gotoxy(13,26);set(0,8);printf("_______________________________________________________");
    gotoxy(13,27);set(0,8);printf("RT / RW\t\t:      / ");
    gotoxy(13,28);set(0,8);printf("_______________________________________________________");
    while((inp = getch()) != 13){ 
        if(inp == 27 && !(inp >= 'A' && inp <= 'Z') && !(inp >= 'a' && inp <= 'z')){
            geser();
        }
    }
/////////////////////////////////////////////////////////////////////////////////////// INPUT DATA KEJUTER 
    gotoxy(34,21);cekkec(kec);
    gotoxy(34,23);cekkec(desa);
    gotoxy(38,25);cekjalan(jln);gotoxy(64,25);ceknojal(nojal);
    gotoxy(34,27);cekrt(rt);gotoxy(42,27);cekrt(rw);
    while((inp=getch())){
        if(inp == ' '){
            break;
        }else if(inp == 27){
            kejutin_inpdata1();
        }
    }
    gotoxy(100,29);set(0,15);printf("Apakah anda yakin data  yang anda masukan BENAR ?");            //47
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<< || >>> Esc untuk kembali input <<<");   //57
    while((inp=getch())){   
        if(inp == ' '){
            break;
        }else if(inp == 27){
            edit_data3();
        }
    }
    tampilan(4,4,161,28,9,15);
    kejutin_inpdata4();
}

void edit_data3(){
    char tampinp[6][100]={"Nama Target", "Jenis Kelamin Target", "Pilih Kecamatan Target", "Pilih Desa Target", "Tanggal Kejut"};
    char inp;
    int tamptgl = 0;
    int kesempatan = 0;
    int kectrgt;
    tampilan(4,4,161,28,9,15);                        ///// BINGKAI TERDALAM 
    tampilan(9,6,72,24,9,8);                            ///// BINGKAI INPUT
    for(int i = 0; i <= 4; i++){
        gotoxy(13,11+i+i+i);set(0,8);printf("%s", tampinp[i]);              //NAMA TARGET           //Pilih Desa Lokasi Target
        gotoxy(13,11+i+i+i+1);set(0,8);printf("Input > ");                  //JENIS KELAMIN         //PILIH TANGGAL KEJUT
        if(i==4){                                                           //PILIH KECAMATAN
            gotoxy(13,11+i+i+i+1);set(0,8);printf("Input >\t/\t/2023");
        }                                                                       
    }    
// /////////////////////////////////////////////////////////////////////////////////////////////////// INPUT DATA TARGET KEJUT
    gotoxy(21,12);ceknama(namatrgt);
    gotoxy(21,15);cekjk(jktrgt);
    tamkec();
    gotoxy(21,18);tampkectrgt = cekpilkec(kectrgt);     //// CEK KECAMATAN >> 2
    tamkoor();
    gotoxy(21,21);cekpildes(tampkectrgt);               //// CEK DESA      >> 3
    tamkoor2();            
    caridesa();
    set(0,8);gotoxy(21,24);tamptgl = cektgl(tgltrgt);
    caritgl();
    do{
    if(tamptgl == 0){
        break;
    }else{
        gotoxy(13,11+4+4+4+1);set(0,8);printf("Input >\t/\t/2023");
        gotoxy(21,24);set(0,8);tamptgl = cektgl(tgltrgt);
        caritgl();
    }
    kesempatan++;
    }while(kesempatan > 0 );
///////////////////
    gotoxy(100,29);set(0,15);printf("Apakah anda yakin data  yang anda masukan BENAR ?");            //47
    gotoxy(93,30);set(0,15);printf(">>> Space untuk lanjut <<< || >>> Esc untuk kembali input <<<");   //57
    while((inp=getch())){   
        if(inp == ' '){
            break;
        }else if(inp == 27){
            edit_data3();
        }
    }
    tampilan(4,4,161,28,9,15);
    kejutin_inpdata4();
}


                



            
                

