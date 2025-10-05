#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

#define handle GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(handle, pos);
}

void set(int text,int bg)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, bg * 16 + text);
}

void tampilan(int x, int y, int panjang, int lebar, int tulis,int bag){   
    for(int i = 0; i <= panjang; i++){
        for(int j = 0; j <= lebar; j++){
            if(i == 0 || j == 0 || i == panjang || j == lebar){
            gotoxy(x+i,y+j);set(tulis,tulis);printf("%c",219);
            }
            else{
                gotoxy(x+i,y+j);set(bag,bag);printf("%c",219);
            }
        }
    }
}

void tamstruk(int x, int y, int panjang, int lebar, int tulis,int bag){   
    for(int i = 0; i <= panjang; i++){
        for(int j = 0; j <= lebar; j++){
            if(i == 0 || j == 0 || i == panjang || j == lebar){
            gotoxy(x+i,y+j);set(tulis,tulis);printf("-");
            }
            else{
                gotoxy(x+i,y+j);set(bag,bag);printf("-");
            }
        }
    }
}
