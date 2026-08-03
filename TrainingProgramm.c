#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("malo argumentov\n");
        return 1;
    }

    int radius;
    sscanf(argv[2], "%d", &radius);

    FILE *fail = fopen(argv[1], "r");
    if (fail == NULL) {
        printf("ne otkrylsya fail\n");
        return 1;
    }

    int setka[100][100];
    int i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++)
            setka[i][j] = 0;

    int x, y;
    while (1) {
        if (fscanf(fail, "%d,%d", &x, &y) != 2)
            break;
        if (x >= 0 && x < 100 && y >= 0 && y < 100)
            setka[x][y] = setka[x][y] + 1;
    }
    fclose(fail);

    int max_popalo = 0;
    int luch_x = 0;
    int luch_y = 0;

    int cx, cy;
    for (cx = 0; cx < 100; cx++) {
        for (cy = 0; cy < 100; cy++) {
            int popalo = 0;
            for (i = 0; i < 100; i++) {
                for (j = 0; j < 100; j++) {
                    if (setka[i][j] > 0) {
                        int dx = cx - i;
                        int dy = cy - j;
                        if (dx * dx + dy * dy <= radius * radius)
                            popalo = popalo + setka[i][j];
                    }
                }
            }
            if (popalo > max_popalo) {
                max_popalo = popalo;
                luch_x = cx;
                luch_y = cy;
            }
        }
    }

    printf("%d %d\n", luch_x, luch_y);
    printf("%d\n", max_popalo);

    return 0;
}

