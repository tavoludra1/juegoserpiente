#include <stdlib.h>
#include <stdio.h>

// definir las columnas y las filas
#define COLS 60
#define ROWS 30

int main() {

    // Cursor
    printf("\e[?25l");

    int x[1000], y[1000];
    int quit = 0;
    while (!quit) {
        // forma de la tabla
        printf("⎡");
        for (int i = 0; i < COLS; i++) {
            printf("¯");
        }
        printf("⎤\n");

        for (int j = 0; j < ROWS; j++) {
            printf("|");
            for (int i = 0; i < COLS; i++) {
                printf("∙");
            }
            printf("|\n");
        }

        printf("⎣");
        for (int i = 0; i < COLS; i++) {
            printf("_");
        }
        printf("⎦\n");

        printf("\e[%iA", ROWS + 2);

        int head = 0, tail = 0;
        x[head] = COLS / 2;
        y[head] = ROWS / 2;
        int gameover = 0;
        int xdir = 1, ydir = 0;

        while (!quit && !gameover) {
            // limpiar cola de la serpiente
            printf("\e[%iB\e[%iC・", y[tail] + 1, x[tail] + 1);
            printf("\e[%iF", y[tail] + 1);

            tail = (tail + 1) % 1000;
            int newhead = (head + 1) % 1000;
            x[newhead] = (x[head] + xdir + COLS) % COLS;
            y[newhead] = (y[head] + ydir + ROWS) % ROWS;
            head = newhead;

            // cabeza
            printf("\e[%iB\e[%iC◼", y[head] + 1, x[head] + 1);
            printf("\e[%iF", y[head] + 1);

        }

    }
    printf("\e[?25h");

    return 0;
}
