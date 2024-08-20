# Biblioteca `conio2.h` / `conio2.h` Library

La biblioteca `conio2.h` proporciona funciones para manipular la consola en C y C++ que son compatibles con sistemas Windows y Linux. Esta biblioteca emula algunas de las funcionalidades de la antigua biblioteca `conio.h` en entornos modernos.

The `conio2.h` library provides functions to manipulate the console in C and C++ that are compatible with Windows and Linux systems. This library emulates some of the functionalities of the old `conio.h` library in modern environments.

## Funciones / Functions

### `void gotoxy(int x, int y)`

**Español:** Mueve el cursor a la posición especificada `(x, y)` en la consola, donde `(0, 0)` es la esquina superior izquierda en Windows, y `(1, 1)` en Linux.

**English:** Moves the cursor to the specified `(x, y)` position in the console, where `(0, 0)` is the top-left corner on Windows, and `(1, 1)` on Linux.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    gotoxy(10, 5);
    printf("Texto en (10, 5)"); // Text at (10, 5)
    return 0;
}
```

### `void clrscr()`

**Español:** Limpia toda la pantalla de la consola. En Windows usa el comando `cls`, y en Linux usa el código de escape ANSI `\033[2J`.

**English:** Clears the entire console screen. On Windows, it uses the `cls` command, and on Linux, it uses the ANSI escape code `\033[2J`.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    clrscr();
    printf("La pantalla ha sido limpiada."); // The screen has been cleared.
    return 0;
}
```
### `void textcolor(int color)`

**Español:** Cambia el color del texto en la consola. En Windows usa valores estándar para los colores, y en Linux usa un valor en la paleta de colores de 256 colores ANSI.

**English:** Changes the text color in the console. On Windows, it uses standard color values, and on Linux, it uses a value from the ANSI 256-color palette.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    textcolor(34); // Cambia el color del texto a azul / Changes text color to blue
    printf("Texto en color."); // Text in color.
    resetColor(); // Restablece el color a los predeterminados / Resets color to default
    return 0;
}
```
### `void textbackground(int color)`

**Español:** Cambia el color de fondo del texto en la consola. En Windows usa valores estándar para los colores de fondo, y en Linux usa un valor en la paleta de colores de 256 colores ANSI.

**English:** Changes the background color of the text in the console. On Windows, it uses standard background color values, and on Linux, it uses a value from the ANSI 256-color palette.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    textbackground(40); // Cambia el color de fondo a verde / Changes background color to green
    textcolor(15);      // Cambia el color del texto a blanco / Changes text color to white
    gotoxy(5, 5);
    printf("Texto con fondo verde."); // Text with green background.
    resetColor();     // Restablece los colores a los predeterminados / Resets colors to default
    return 0;
}
```
### `void resetColor()`

**Español:** Restablece los colores del texto y del fondo a los valores predeterminados. Esto es útil después de cambiar los colores con `textcolor` o `textbackground` para volver a los valores de color originales.

**English:** Resets the text and background colors to their default values. This is useful after changing colors with `textcolor` or `textbackground` to return to the original color settings.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    textcolor(31); // Cambia el color del texto a rojo / Changes text color to red
    printf("Texto en rojo."); // Text in red.
    resetColor(); // Restablece el color a los predeterminados / Resets color to default
    printf("Texto con color predeterminado."); // Text with default color.
    return 0;
}
```

### `void putch(char ch)`

**Español:** Imprime un carácter en la consola. Esta función es útil para mostrar un solo carácter sin necesidad de usar `printf` u otras funciones similares.

**English:** Prints a single character to the console. This function is useful for displaying just one character without using `printf` or similar functions.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    putch('A'); // Imprime el carácter 'A' / Prints the character 'A'
    return 0;
}
```
### `char getch()`

**Español:** Lee un carácter desde la entrada estándar sin esperar a que se presione Enter. Esta función es útil para capturar la entrada del usuario de manera inmediata.

**English:** Reads a character from the standard input without waiting for Enter to be pressed. This function is useful for capturing user input immediately.

**Ejemplo / Example:**

```cpp
#include "conio2.h"

int main() {
    char ch = getch(); // Lee un carácter desde la entrada estándar / Reads a character from standard input
    printf("Caracter leído: %c\n", ch); // Imprime el carácter leído / Prints the read character
    return 0;
}
```





