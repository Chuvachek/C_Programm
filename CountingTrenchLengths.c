#include <stdio.h>
#include <math.h>

// Определяем число Пи, если оно не определено в math.h
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // --- ПЕРЕМЕННЫЕ ---
    double top_tr, bot_tr, height_tr, length;
    double height_sand;

    // === ШАГ 1: ВВОД ПАРАМЕТРОВ ТРАНШЕИ ===
    printf("--- ПАРАМЕТРЫ ТРАНШЕИ ---\n");
    printf("Введите верхнее основание траншеи (м): ");
    scanf("%lf", &top_tr);

    printf("Введите нижнее основание траншеи (м): ");
    scanf("%lf", &bot_tr);

    printf("Введите высоту траншеи (м): ");
    scanf("%lf", &height_tr);

    printf("Введите длину траншеи (м): ");
    scanf("%lf", &length);

    // Расчеты для траншеи
    double area_tr = (top_tr + bot_tr) / 2.0 * height_tr; // Площадь трапеции
    double volume_tr = area_tr * length;                  // Объем
    
    // Вычисляем угол откоса
    double dx_per_side = (top_tr - bot_tr) / 2.0;         // Вылет откоса с одной стороны
    double angle_rad = atan2(dx_per_side, height_tr);    // Угол в радианах
    double angle_deg = angle_rad * 180.0 / M_PI;         // Угол в градусах
    double slope_coeff = dx_per_side / height_tr;        // Коэффициент заложения откоса

    // Вывод результатов по траншее
    printf("\n>>> РЕЗУЛЬТАТЫ ПО ТРАНШЕЕ:");
    printf("\nСечение траншеи: %.3f м2", area_tr);
    printf("\nОбъем траншеи:   %.3f м3", volume_tr);
    printf("\nУгол откоса:     %.2f град.\n", angle_deg);


    // === ШАГ 2: ВВОД ПАРАМЕТРОВ ЗАСЫПКИ ===
    printf("\n--- ПАРАМЕТРЫ ЗАСЫПКИ ---\n");
    printf("Введите высоту слоя песка (м): ");
    scanf("%lf", &height_sand);

    // Проверка: не превышает ли песок высоту траншеи
    if (height_sand > height_tr) {
        printf("\nОшибка: высота песка не может быть больше глубины траншеи!\n");
        return 1;
    }

    // 1. РАСЧЕТ ПЕСКА
    // Нижнее основание песка = дно траншеи (bot_tr)
    // Вычисляем верхнее основание песка по коэффициенту откоса траншеи
    double top_sand = bot_tr + (2.0 * slope_coeff * height_sand);
    double area_sand = (top_sand + bot_tr) / 2.0 * height_sand;
    double volume_sand = area_sand * length;

    // 2. РАСЧЕТ ГРУНТА
    // Высота грунта — это остаток высоты траншеи
    double height_soil = height_tr - height_sand;
    // Нижнее основание грунта — это верх песка (top_sand)
    // Верхнее основание грунта — это верх траншеи (top_tr)
    double area_soil = (top_tr + top_sand) / 2.0 * height_soil;
    double volume_soil = area_soil * length;

    // ВЫВОД РЕЗУЛЬТАТОВ ЗАСЫПКИ
    printf("\n>>> РЕЗУЛЬТАТЫ ПО ПЕСКУ:");
    printf("\nСечение песка:   %.3f м2", area_sand);
    printf("\nОбъем песка:     %.3f м3", volume_sand);

    printf("\n\n>>> РЕЗУЛЬТАТЫ ПО ГРУНТУ:");
    printf("\nСечение грунта:  %.3f м2", area_soil);
    printf("\nОбъем грунта:    %.3f м3\n", volume_soil);

    // ИТОГО
    printf("\n===============================");
    printf("\nОбщий объем (песок + грунт): %.3f м3", volume_sand + volume_soil);
    printf("\nОбъем выемки (контроль):     %.3f м3\n", volume_tr);

    return 0;
}