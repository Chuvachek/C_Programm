#include <stdio.h>
/*Эта программа считает длины отдельных участков. Можно использовать для подсчета длин стен, забора и т.д. Всго 15 участков*/
int main() {
    double walls[15];  // All walls (3 objects, 3-5 each = max 15) Здесь введи количество стен 
    double total = 0.0;
    int n = 0;  // Counter for entered walls

    printf("Enter wall lengths (press Enter after each, 0 to finish):\n");
/*здесь механизм исполнения*/
    while (n < 15) { /*если количество достигнет 15, то цикл завершится без ввода новой стены */
        printf("Wall %d: ", n+1);
        scanf("%lf", &walls[n]);
        if (walls[n] == 0.0) break; /* если ввести 0, то посчет прекратится*/
        total += walls[n]; 
        n++;
    }

    printf("\nTotal fence length: %.2f m\n", total);
    printf("Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Wall %d: %.2f m\n", i+1, walls[i]);
    }

    return 0;
}