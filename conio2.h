#ifndef CONIO2_H
#define CONIO2_H

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

/**
 * Mueve el cursor a la posición especificada en la consola de Windows.
 * 
 * @param x La posición horizontal (columna) del cursor.
 * @param y La posición vertical (fila) del cursor.
 */
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * Limpia toda la pantalla de la consola de Windows.
 */
void clrscr() {
    system("cls");
}

/**
 * Cambia el color del texto en la consola de Windows.
 * 
 * @param color El color deseado para el texto. Debe ser un valor entre 0 y 15,
 *              donde los valores representan diferentes colores.
 */
void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/**
 * Cambia el color de fondo del texto en la consola de Windows.
 * 
 * @param color El color deseado para el fondo. Debe ser un valor entre 0 y 15,
 *              donde los valores representan diferentes colores.
 */
void textbackground(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0x0F) | (color << 4));
}

#else
#include <unistd.h>
#include <term.h>
#include <stdio.h>

/**
 * Mueve el cursor a la posición especificada en la consola de Linux.
 * 
 * @param x La posición horizontal (columna) del cursor (base 1).
 * @param y La posición vertical (fila) del cursor (base 1).
 */
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

/**
 * Limpia toda la pantalla de la consola de Linux.
 */
void clrscr() {
    printf("\033[2J");
}

/**
 * Cambia el color del texto en la consola de Linux.
 * 
 * @param color El color deseado para el texto. Debe ser un valor de 0 a 255,
 *              según la paleta de colores de 256 colores ANSI.
 */
void textcolor(int color) {
    printf("\033[38;5;%dm", color);
}

/**
 * Cambia el color de fondo del texto en la consola de Linux.
 * 
 * @param color El color deseado para el fondo. Debe ser un valor de 0 a 255,
 *              según la paleta de colores de 256 colores ANSI.
 */
void textbackground(int color) {
    printf("\033[48;5;%dm", color);
}

/**
 * Restablece el color del texto y el fondo a los valores predeterminados en la consola de Linux.
 */
void resetColor() {
    printf("\033[0m");
}

#endif

/**
 * Imprime un carácter en la consola.
 * 
 * @param ch El carácter que se desea imprimir.
 */
void putch(char ch) {
    putchar(ch);
}

/**
 * Lee un carácter desde la entrada estándar sin esperar a que se presione Enter.
 * 
 * @return El carácter leído.
 */
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

#endif // CONIO2_H
