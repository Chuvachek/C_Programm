#include <stdio.h>

int power (int n, int m); /*Говорим компилятору что дал
 в коде будет написана power. n и m в ней не важны. Важны только int и int*/

/*тест функции power*/

int main()
{
    int i; 
    for (i = 0; i < 10; ++i)    
        printf("%d %d %d\n ", i, power(2, i), power(-3, i));
    return 0;

}

/* возвращает base в п-ю степень; n >= 0 */
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}




 #include <stdio.h>
 
/* Преобразует температуру из Цельсия в Фаренгейт */
double celsius_to_fahrenheit(double celsius)
{
    return celsius * 9.0 / 5.0 + 32.0;
}
 
 int main()
 {
    double c;
    
    printf("Таблица преобразования температур: Цельсий -> Фаренгейт\n");
    printf("%-15s %-15s\n", "Цельсий", "Фаренгейт");
    printf("%-15s %-15s\n", "-------", "---------");
    
    for (c = 0; c <= 100; c = c + 10)
        printf("%-15.1f %-15.1f\n", c, celsius_to_fahrenheit(c));
    
     return 0;
