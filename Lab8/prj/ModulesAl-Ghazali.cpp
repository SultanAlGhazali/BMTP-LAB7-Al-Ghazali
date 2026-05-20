#include "ModulesAl-Ghazali.h"
#include <cmath>

// Реалізація функції s_calculation за стандартом лабораторної роботи №8
double s_calculation(double x, double y, double z) {
    double pod_kornem = x + y + z;

    // Перевірка області допустимих значень (ОДЗ)
    if (pod_kornem < 0) {
        return -999.99; // Сигнальне значення помилки для тест-драйвера
    }

    // Математичний розрахунок функції
    return std::sqrt(pod_kornem) + (std::sin(x) / (std::cos(y) + 2.0));
}
