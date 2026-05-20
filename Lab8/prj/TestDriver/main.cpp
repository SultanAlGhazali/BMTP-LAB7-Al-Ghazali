#include <iostream>
#include <cmath>
#include <cstdlib>
#include "ModulesAl-Ghazali.h" // Подключаем заголовок вашей библиотеки

using namespace std;

struct TestCase {
    double x;
    double y;
    double z;
    double expected;
};

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << "=========================================================" << endl;
    cout << " Лабораторна робота № 8. Автоматичний тестовий драйвер" << endl;
    cout << " Виконав: Султан Аль-Газали (Заочна форма)" << endl;
    cout << " Протоколювання процесу модульного тестування (Пункт 12)" << endl;
    cout << "=========================================================" << endl << endl;

    TestCase tests[3] = {
    {2.0, 3.0, 4.0, 3.90029},
    {0.0, 0.0, 0.0, 0.0},
    {-5.0, 2.0, 1.0, -999.99}
};


    bool all_passed = true;

    for (int i = 0; i < 3; i++) {
        double real_result = s_calculation(tests[i].x, tests[i].y, tests[i].z);

        cout << "Тест-кейс №" << i + 1 << ":" << endl;
        cout << "  Вхідні дані: x = " << tests[i].x << ", y = " << tests[i].y << ", z = " << tests[i].z << endl;
        cout << "  Очікуваний результат: " << tests[i].expected << endl;
        cout << "  Отриманий результат:  " << real_result << endl;

        if (std::abs(real_result - tests[i].expected) < 0.001) {
            cout << "  Статус: [ PASSED ]" << endl;
        } else {
            cout << "  Статус: [ FAILED ]" << endl;
            all_passed = false;
        }
        cout << "---------------------------------------------------------" << endl;
    }

    if (all_passed) {
        cout << "\nРЕЗУЛЬТАТ: Модульне тестування завершено УСПІШНО! Усі тести пройдені." << endl;
    } else {
        cout << "\nРЕЗУЛЬТАТ: Тестування НЕ ПРОЙДЕНО. Знайдено помилки в коді!" << endl;
    }
    cout << "=========================================================" << endl;

    return 0;
}
