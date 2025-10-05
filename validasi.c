
///////////////////////
// void start();
// void menuadmin();
//////////////////////

///////////////// ///////////////// ///////////////// 
///////////////// PROTOTYPE TYPEDATA ////////////////
// char* cekuser(char* tamp);
char* cekpass(char* tamp);
char* banding(char* tamp);
char* ceknama(char* tamp);
char* cekkec(char* tamp);
char* valuang(char* tampuang);
///////////////// ///////////////// /////////////////
int koorbanding(int tamp, int tampongkos);
int cekpilkec(int tamp2);
int cekpildes(int tamp2);
int cektgl(int tamp);
///////////////// ///////////////// /////////////////
///////////////// ///////////////// /////////////////

/// /// /// /// /// /// /// /// /// /// 
/// /// /// VARIABEL GLOBAL /// /// /// 
/// /// /// /// /// /// /// /// /// /// 
char tampnotedesa[100]={};
char tampnotetgl[100]={};
char bookingtgl[100]={};
/// /// /// /// /// /// /// /// /// ///
int tampkec = 0;
int tampdesa = 0; 
/// /// /// /// /// /// /// /// /// /// 
/// /// /// /// /// /// /// /// /// ///

// char* cekuser(char* tamp){
//     char inp;
//     int index = 0;
//     while((inp=getch()) != 13 || tamp[index-1] == ' ')
//     {
//         if(inp >= 'A' && inp <= 'Z' && index < 20 || 
//         inp >= 'a' && inp <= 'z'  && index < 20
//         ){
//             printf("%c", inp);
//             tamp[index]=inp;
//             index++;
//         }else if( inp == 8 && index != 0){
//             printf("\b \b");
//             index--;
//             tamp[index] = '\0';
//         }
//     }
// }

char* cekpass(char* tamp){
    char inp;
    int index = 0;
    while((inp=getch()) != 13 || tamp[index-1] == ' ' || index < 5)
    {
        if(inp >= '0' && inp <= '9' && index < 10
        ){
        printf("*");
        tamp[index]=inp;
        index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    return tamp;
}

char* banding(char* pass){
    int benar = 0;
    char tamp[100] = {};
    char tgllahir[20]={"100104"};
    if(strcmp(pass, tgllahir)==0){
        benar++;
    }else{
        benar = 0;
    }
    itoa(benar, tamp, 10);
    strcpy(pass,tamp);
    return pass;
}

char* ceknama(char* tamp){
    int index=0,strip = 0, kutip=0;
    // char tamp[100];
    char inp;
    while((inp=getch()) != 13 || index < 3 || tamp[index-1] == ' ' || tamp[index-1] == '-' || tamp[index-1] == '\'')
    {
        if(
        index < 20 &&((inp >= 'a' && inp <= 'z') && index!=0 && (inp != tamp[index-1] || inp != tamp[index-2]) && tamp[index-1] != ' ' && (tamp[index-1] != '\'' || inp == 'a' || inp == 'i' || inp =='u' || inp == 'e' || inp == 'o'))|| 
        index < 20 && ((inp >= 'A' && inp <= 'Z') && (index == 0 || tamp[index-1]==' ' || tamp[index-1]=='\'' || tamp[index-1]=='-' || tamp[index-1] == '\'') && (tamp[index-1] != '\'' || inp == 'A' || inp == 'I' || inp =='U' || inp == 'E' || inp == 'O' ) )||
        inp == ' ' && index != 0 && tamp[index-1] != ' ' && tamp[index-2] != ' '&& index >= 3 && tamp[index-1] != '-' && tamp[index-1] != '\''  ||
        inp == '-' && index != 0 && tamp[index-1] != '-' && strip < 1 && tamp[index-1] != ' ' && tamp[index-1] != '-' && tamp[index-1] != '\'' ||
        inp == '\'' && tamp[index-1] != '\'' && kutip < 2 && tamp[index-1] != ' ' && tamp[index-1] != '-' && tamp[index-1] != '\'' 
        )
        {
            printf("%c", inp);
            tamp[index]=inp;
            index++;
            if(inp == '-'){
                strip++;
            }else if(inp == '\''){
                kutip++;
            }
        }
        else if(inp == 8 && index != 0){
            printf("\b \b");
            if(tamp[index-1] == '\''){
                kutip--;
            }else if(tamp[index-1] == '-'){
                strip--;
            }
            index--;
            tamp[index] = '\0';
        }
       
    }
    return tamp;   
}

char* cekkec(char* tamp){
    char inp;
    int index = 0;
    int space = 0;
    while((inp = getch()) != 13 || tamp[index-1] == ' ' || index < 5){
        if(inp >= 'a' && inp <= 'z' && index!=0 && (inp != tamp[index-1] || inp != tamp[index-2] ) && tamp[index-1] != ' ' && index < 20 ||
        inp >= 'A' && inp <= 'Z' && (index == 0 || tamp[index-1]==' ' ) && index < 20 ||
        inp == ' ' && index != 0 && tamp[index-1] != ' ' && tamp[index-2] != ' '&& index >= 3 && space < 1
        ){
        printf("%c", inp);
        tamp[index]=inp;
        index++;
        if( inp == ' '){
            space++;
        }
        }else if( inp == 8 && index !=0 ){
            if(tamp[index-1] == ' '){
                space--;
            }
            printf("\b \b");
            index--;
            tamp[index] = '\0'; 
        }
    }
    return tamp;
}

char* cekjk(char* tamp){
    char inp;
    int index=0;
    while((inp=getch()) != 13 || index == 0){
        if((inp == 'L' || inp == 'P') && index == 0){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if( inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
} 

char* ceknik(char* tamp){
    char inp;
    int index=0;
    while((inp=getch())!= 13 || tamp[index-1] == ' ' || index < 16){
        if(inp == '3' & index == 0 || inp == '2' && index == 1 || inp == '0' && index == 2 || inp == '5' && index == 3 ||
        (inp >= '0' && inp <= '9') && index > 3 && index < 16
        ){
        printf("%c", inp);
        tamp[index]=inp;
        index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index]='\0';
        }
    }
    return tamp;
}

char* cekumur(char* tamp){
    char inp;
    int index = 0;
    while((inp=getch()) != 13 || index < 1){
        if(inp >= '0' && inp <= '9' && index < 2 && inp != ' '){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index]='\0';
        }
    }
    return tamp;
}

char* cekjalan(char* tamp){
    int index=0;
    int space=0;
    char inp;
    while((inp=getch())!= 13 || index < 4 || tamp[index-1]==' '){
        if(inp >= 'a' && inp <= 'z' && index != 0 && (inp != tamp[index-1]|| inp != tamp[index-2]) && index < 19  && tamp[index-1] != ' ' ||
        inp >= 'A' && inp <= 'Z' && (index == 0 || tamp[index-1] == ' ') && index < 19 ||
        inp == ' ' && index != 0 && inp != tamp[index-1] && space < 1
        ){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
            if(inp == ' '){
                space++;
            }
        }else if(inp == 8 && index != 0){
            if(tamp[index-1] == ' '){
                space--;
            }
            printf("\b \b");
            index--;
            tamp[index]='\0';
        }
    }
    return tamp;
}

char* ceknojal(char* tamp){
    int index=0;
    char inp;
    while((inp=getch()) != 13 || index < 1 || tamp[index-1] == ' '){
        if(inp >= '0' && inp <= '9' && (index < 3 && index > 0) ||
        inp == '1' && index == 0 
        ){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index]='\0';
        }
    }
    return tamp;
}

char* cekrt(char* tamp){
    int index=0, x=0;
    char inp;
    while((inp=getch()) != 13 || index < 3 ){
        if(inp >= '0' && inp <= '9' && index < 3 && index > 1 ||
        inp == '0' && index == 0 || (inp <= '6' && inp >= '0') && index == 1 
        ){
        printf("%c", inp);
        tamp[index]=inp;
        index++;
        x++;
        }else if(inp == 8 && inp != 0 && index!= 0 ){
            printf("\b \b");
            index--;
            x--;
            tamp[index]='\0';
        }
    }
    return tamp;
}

char* ceknohp(char* tamp){
    int index=0;
    char inp;
    while((inp=getch())!=13 || index < 11 || index > 14 || tamp[index-1] == ' ')
    {
        if( index < 14 && ((inp=='0' && index==0 || inp== '8' && index==1 || 
        inp== '1' && index==2 || inp== '2' && index==2 || inp== '3' && index==2 || inp== '5' && index==2) ||
        (inp >= '1' && inp <= '9') && inp != '4' && inp != '5' && inp != '6' && tamp[index-1]== '1' ||
        (inp == '1' || inp == '2') && tamp[index-1]== '2' ||
        (inp == '2' || inp == '3' || inp == '8') && tamp[index-1]== '3' ||
        (inp >= '0' && inp <= '9') && tamp[index-1]== '5' ||
        (inp >= '0' && inp <= '9') && index > 3))   
        {
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
        }
    return tamp;    
}

// cekpilkec   // 2
// cekpildes3   // 3

int cekpilkec(int tamp2){
    char inp;
    char tamp[100]= {};
    int index=0;
    while((inp=getch()) != 13 || index == 0){
        if(inp >= '1' && inp <= '2' && index == 0){
            if(inp >= '1' && inp <= '2' && index == 0){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
            }
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    tamp2 = atoi(tamp);
    if( tamp2 == 1){
        for(int i = 0; i <= 6; i++){
            if(i %2 == 0){
            gotoxy(21,18);printf("PAMEUNGPEUK");Sleep(300);
            }
            else{
            gotoxy(21,18);printf("           ");Sleep(300);
            }
        }
    }else if( tamp2 == 2){
        for(int i = 0; i <= 6; i++){
            if(i %2 == 0){
            gotoxy(21,18);printf("CISOMPET");Sleep(300);
            }
            else{
            gotoxy(21,18);printf("        ");Sleep(300);
            }
        }       
    }
    return tamp2;
}

int cekpildes(int tamp2){
    char inp;
    char tamp[100]= {};
    int tamp1 = 0;
    int index=0;
    while((inp=getch()) != 13 || index == 0){
        if(inp >= '1' && inp <= '3' && index == 0){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    tamp1 = atoi(tamp);
    tampdesa = tamp1;
    tampkec = tamp2;
    if( tamp2 == 1){
        if(tamp1 == '1'){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("BOJONG");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("      ");Sleep(300);
                }
            }
        }else if(tamp1 == 2){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("JATIMULYA");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("         ");Sleep(300);
                }
            }
        }else if(tamp1 == 3){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("MANCAGAHAR");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("          ");Sleep(300);
                }
            }
        }
        // strcpy(tampnotber, "PAKET KARGO");   
    }else if( tamp2 == 2){
        if(tamp1 == 1){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("CIKONDANG");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("         ");Sleep(300);
                }
            }
        }else if(tamp1 == 2){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("NEGLASARI");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("         ");Sleep(300);
                }
            }
        }else if(tamp1 == 3){
            for(int i = 0; i <= 6; i++){
                if(i %2 == 0){
                gotoxy(21,21);;printf("SUKAMUKTI");Sleep(300);
                }
                else{
                gotoxy(21,21);;printf("         ");Sleep(300);
                }
            }
        }       
    }
    return tamp2;
}

int koorbanding(int tamp, int tampongkos){
    
    char posisi[2][100]={"Paas", "Depok", };

    float derajat_posisi[2]={7,7};
    float menit_posisi[2]={37,36};
    float detik_posisi[2]={56.6,25.1};

    char tempat[6][100]={"Bojong", "Jatimulya", "Mancagahar", "Cikondang", "Neglasari", "Sukamukti"};

    float derajat_tempat[6]={7,7,7,7,7,7};
    float menit_tempat[6]={36,38,40,35,30,33};
    float detik_tempat[6]={42.5,7.8,1.1,35.2,3.5,30.2};

    float jarak_posisi=0;
    float jarak_tempat[6]={};
    float jarak_total[6]={};

    int bayar[6]={};

    for(int i = 0; i <= 5; i++){
        jarak_posisi = ((derajat_posisi[tamp-1]*111.322) + ((menit_posisi[tamp-1]*1885.37)/1000) + (((detik_posisi[tamp-1]*30.92)/1000)));
        jarak_tempat[i] = ((derajat_tempat[i]*111.322) + ((menit_tempat[i]*1885.37)/1000) + (((detik_tempat[i]*30.92)/1000)));

        // printf("\n\nJarak Posisi %d = %.f", tamp, jarak_posisi);
        // printf("\nJarak Tempat %d= %.f", i+1, jarak_tempat[i]);
        if( jarak_posisi >= jarak_tempat[i]){
            jarak_total[i] = (jarak_posisi - jarak_tempat[i])*1000;
            if(i < 3 && tamp == 1){
            gotoxy(103, 16+i+i);set(0,8);
            printf("%d) %s ---> %s = %.f Meter\n\n",i+1, posisi[0], tempat[i], jarak_total[i]);
            }else if( i > 2 && tamp == 2){
            gotoxy(103, 16+(i-3)+(i-3));set(0,8);
            printf("%d) %s ---> %s = %.f Meter\n\n",i-2, posisi[1], tempat[i], jarak_total[i]);
            }
        }else if( jarak_tempat[i] >= jarak_posisi){
            jarak_total[i] = (jarak_tempat[i] - jarak_posisi)*1000;
            if(i < 3 && tamp == 1){
            gotoxy(103, 16+i+i);set(0,8);
            printf("%d) %s ---> %s = %.f Meter\n\n",i+1, posisi[0], tempat[i], jarak_total[i]);
            }else if( i > 2 && tamp == 2){
            gotoxy(103, 16+(i-3)+(i-3));set(0,8);
            printf("%d) %s ---> %s = %.f Meter\n\n",i-2, posisi[1], tempat[i], jarak_total[i]);
            }
        }
    }
//////////BAYARR///////////
        for(int h = 0; h <= 5; h++){
                for(int j = 1; j <= jarak_total[h]; j++){
                    if(j%300==0){
                        bayar[h]+=1000;
                    }
                }
            }

            for(int i = 0; i <= 5; i++){
                if(i < 3 && tamp == 1){
                    gotoxy(103, 22+i+i);set(0,8);
                    printf("Ongkos Kirim PAAS -> %s = Rp. %d", tempat[i], bayar[i]);
                }else if( i > 2 && tamp == 2){
                    gotoxy(103, 22+(i-3)+(i-3));set(0,8);
                    printf("Ongkos Kirim DEPOK -> %s = Rp. %d", tempat[i], bayar[i]);
                }
            }
            if(tampkec == 1){                       /// KECAMATAN PAMEUNGPEUK
                if(tampdesa == 1){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                    tampongkos = 7000;
                    strcpy(tampnotedesa, "BOJONG");
                }else if(tampdesa == 2){
                    tampongkos = 1000;
                    strcpy(tampnotedesa, "JATIMULYA");
                }else if(tampdesa == 3){
                    tampongkos = 13000;
                    strcpy(tampnotedesa, "MANCAGAHAR");
                }
            }else if(tampkec == 2){                 /// KECAMATA CISOMPET
                 if(tampdesa == 1){
                    tampongkos = 5000;
                    strcpy(tampnotedesa, "CIKONDANG");
                }else if(tampdesa == 2){
                    tampongkos = 39000;
                    strcpy(tampnotedesa, "NEGLASARI");
                }else if(tampdesa == 3){
                    tampongkos = 18000;
                    strcpy(tampnotedesa, "SUKAMUKTI");
                }
            } 
    return tampongkos;
}


int cektgl(int tamp){
    char inp;
    char tamptgl[100]={}, tampbln[100]={}, tampthn[100]={};
    int tahun =0, bulan = 0, tanggal = 0;
    int indextgl=0, benar = 0, indexbln = 0;

    struct tm *waktu;
    int tgl, bln;
    int laptop;

    time_t validasi_waktu;
    validasi_waktu = time(NULL);
    waktu = localtime(&validasi_waktu);

    while((inp=getch()) != 13 || indextgl == 0 ){
        if(indextgl < 2 && ((inp >= '1' && inp <= '9') && indextgl == 0 || (inp >= '0' && inp <= '9') && (tamptgl[0] >= '1' && tamptgl[0] <= '2') ||
        (inp == '0' || inp == '1') && tamptgl[0] == '3'
        )){
            printf("%c", inp);
            tamptgl[indextgl]=inp;
            indextgl++;
        }else if(inp == 8 && indextgl != 0){
            printf("\b \b");
            indextgl--;
            tamptgl[indextgl]='0';    
        }
    }
    while((inp=getch()) != 13 || indexbln == 0){
        if(indexbln < 2 && ((inp >= '1' && inp <= '9') && indexbln == 0 || (inp >= '0' && inp <= '2') && tampbln[0] == '1'))
        {
            gotoxy(28+indexbln,24);printf("%c", inp);
            tampbln[indexbln]=inp;
            indexbln++;
        }else if( inp == 8 && indexbln != 0){
            printf("\b \b");
            indexbln--;
            tampbln[indexbln]=inp;
        }
    }

    bulan=atoi(tampbln);
    tanggal=atoi(tamptgl);

    if(bulan%2==1 && bulan != 2){
        if(bulan > 7){
            if(tanggal > 30 || bulan < waktu->tm_mon + 1 || tanggal < waktu->tm_mday && bulan == waktu->tm_mon + 1 ){
            for(int i = 0; i <= 7; i++){
                if(i %2 == 0){
                gotoxy(21,24);printf("Inputan Invalid !");Sleep(300);
                }
                else{
                gotoxy(21,24);printf("                     ");Sleep(300);
                }
                }
                benar++;
                tamp = benar++;
            }
        }else if(bulan < 8){
            if(bulan < waktu->tm_mon + 1 || tanggal < waktu->tm_mday && bulan == waktu->tm_mon + 1 ){
            for(int i = 0; i <= 7; i++){
                if(i %2 == 0){
                gotoxy(21,24);printf("Inputan Invalid !");Sleep(300);
                }
                else{
                gotoxy(21,24);printf("                     ");Sleep(300);
                }
                }
                benar++;
                tamp = benar++;
            }
        }
    }else if(bulan%2==0 && bulan != 2){
        if(bulan < 7){
            if(tanggal > 30 || bulan < waktu->tm_mon + 1 || tanggal < waktu->tm_mday && bulan == waktu->tm_mon + 1 ){
            for(int i = 0; i <= 7; i++){
                if(i %2 == 0){
                gotoxy(21,24);printf("Inputan Invalid !");Sleep(300);
                }
                else{
                gotoxy(21,24);printf("                     ");Sleep(300);
                }
            }
            benar++;
            tamp = benar;
            }
        }else if(bulan > 7){
                if(bulan < waktu->tm_mon + 1 || tanggal < waktu->tm_mday && bulan == waktu->tm_mon + 1 ){
                for(int i = 0; i <= 7; i++){
                    if(i %2 == 0){
                        gotoxy(21,24);printf("Inputan Invalid !");Sleep(300);
                    }
                    else{
                        gotoxy(21,24);printf("                     ");Sleep(300);
                    }
                    }
                    benar++;
                    tamp = benar++;
                }
        }
    }else if(bulan==2){
            if(tanggal > 29 || bulan < waktu->tm_mon + 1 || tanggal < waktu->tm_mday && bulan == waktu->tm_mon + 1 || tanggal == 29){
            for(int i = 0; i <= 7; i++){
                if(i %2 == 0){
                gotoxy(21,24);printf("Inputan Invalid !");Sleep(300);
                }
                else{
                gotoxy(21,24);printf("                     ");Sleep(300);
                }
                }            
            benar++;
            tamp = benar;
            }
    }
    strcat(tamptgl, "-");
    strcat(tamptgl, tampbln);
    strcat(tamptgl, "-");
    strcat(tamptgl, "2023");
    strcpy(tampnotetgl, tamptgl);
    strcpy(bookingtgl, tamptgl);
    return tamp;
}

int cekpil2(int tamp2){
    char inp;
    char tamp[100]= {};
    int index=0;
    while((inp=getch()) != 13 || index == 0){
        if(inp >= '1' && inp <= '2' && index == 0){
            if(inp >= '1' && inp <= '2' && index == 0){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
            }
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    tamp2 = atoi(tamp);
}

int cekpil3(int tamp2){
    char inp;
    char tamp[100]= {};
    int tamp1 = 0;
    int index=0;
    while((inp=getch()) != 13 || index == 0){
        if(inp >= '1' && inp <= '3' && index == 0){
            printf("%c", inp);
            tamp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    tamp2 = atoi(tamp);
}

int kodeunik(int angka){
    int x;
    int tamp1[100];
    int index=0;
    int j = 0;
    int tamp[100];
    FILE* data;
    data = fopen("kodeunik.txt","r");
    while(fscanf(data,"%d\n",&tamp1[j]) != EOF){
        j++;
    }
    for(int i = 0; i <= j;){
        x = rand();
        if( i == j && x > 10000){
            tamp[index]= x;
            index++;        
        }
        else if(x > 10000){
            i++;
        }
    }
    data = fopen("kodeunik.txt","a");
    for(int i = 0; i <= index; i++){
        if(tamp1[i] != tamp[i]){
            fprintf(data,"%d\n",tamp[i]);
            angka = tamp[i];
            break;
        }
    }
    fclose(data);
    return angka;
}

char* lempardesa(char* tamp){
    strcpy(tamp, tampnotedesa);
    return tamp;
}

char* lempartgl(char* tamp){
    strcpy(tamp, tampnotetgl);
    return tamp;
}

char* cekuang(char* tampuang){
    char inp;
    int index = 0;
    
    while((inp=getch()) != 13 || index < 5){
        if( index < 9 && ((inp >= '0' && inp <= '9') && index > 0 || (inp >= '1' && inp <= '9') && index == 0)){
            printf("%c", inp);
            tampuang[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            tampuang[index]='\0';
        }
    }
    tampuang[index]='\0';
    return tampuang;
}

char* cekkodnik(char* kodnik){
    char inp;
    int index = 0;
    while((inp=getch()) != 13 || index < 5){    
        if(index < 5 &&(inp >= '0' && inp <= '9')){
            printf("%c", inp);
            kodnik[index] = inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            kodnik[index]='\0';
        }
    }
    return kodnik;
}
