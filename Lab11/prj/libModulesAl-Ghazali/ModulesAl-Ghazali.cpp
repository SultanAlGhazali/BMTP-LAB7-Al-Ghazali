#include "ModulesAl-Ghazali.h"
#include <cmath>

// Функція з ЛР 8
double s_calculation(double x, double y, double z) {
    double pod_kornem = x + y + z;
    if (pod_kornem < 0) return -999.99;
    return std::sqrt(pod_kornem) + (std::sin(x) / (std::cos(y) + 2.0));
}

// Задача 9.1: Розгалужений процес (умова)
double compute_task_9_1(double x, double y) {
    if (x > y) {
        return std::pow(x, 2) - std::pow(y, 2); // Якщо x > y, рахуємо різницю квадратів
    } else {
        return std::pow(x, 2) + std::pow(y, 2); // Інакше — суму квадратів
    }
}

// Задача 9.2: Циклічний процес (Сума числового ряду)
double compute_task_9_2(int n) {
    if (n <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i; // Рахуємо гармонічний ряд: 1 + 1/2 + 1/3 + ... + 1/n
    }
    return sum;
}

// Задача 9.3: Ітераційний процес (Пошук парних чисел у масиві)
int compute_task_9_3(int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            count++; // Рахуємо кількість парних чисел у масиві
        }
    }
    return count;
}
