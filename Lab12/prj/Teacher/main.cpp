#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // Для фіксу кодування консолі та створення папок
#include "AlGhazali.h"

class Teacher {
public:
    void punish() {
        // 100 звукових сигналів
        for (int i = 0; i < 100; ++i) {
            std::cout << '\a';
        }

        // Спроба створити папку TestSuite, якщо проект запущено невірно
        CreateDirectoryA("../TestSuite", NULL);

        // Запис помилки у файл за правильним шляхом
        std::ofstream outFile("../TestSuite/TestResults.txt");
        if (outFile.is_open()) {
            outFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!\n";
            outFile.close();
        }
        std::cout << "Помилка: проект запущено не в папці Lab12/prj!" << std::endl;
    }

    void runTests() {
        std::cout << "Шлях коректний. Запуск тестування класу ClassLab12_AlGhazali..." << std::endl;

        // Автоматичне створення папки TestSuite поруч із prj (якщо її ще немає)
        CreateDirectoryA("../TestSuite", NULL);

        // Локальний клас для запуску тестів (Вимога №12 методички)
        class TestRunner {
        public:
            void execute() {
                ClassLab12_AlGhazali num1(2.5, 3.5);
                ClassLab12_AlGhazali num2(1.5, 1.5);

                ClassLab12_AlGhazali result = num1.add(num2);

                // Запис протоколу тестування строго у папку TestSuite
                std::ofstream log("../TestSuite/TestResults.txt");
                if (log.is_open()) {
                    log << "=== Протокол тестування АТД ===\n";
                    log << "ID: TestCase_01\n";
                    log << "Action: Add (2.5 + 3.5i) + (1.5 + 1.5i)\n";
                    log << "Expected: 4.0 + 5.0i\n";

                    if (result.getReal() == 4.0 && result.getImag() == 5.0) {
                        log << "Test Result: PASSED\n";
                        std::cout << "Тест успішно пройдено! Результати збережено у TestSuite/TestResults.txt" << std::endl;
                    } else {
                        log << "Test Result: FAILED\n";
                        std::cout << "Тест провалено." << std::endl;
                    }
                    log.close();
                } else {
                    std::cout << "Помилка: Не вдалося створити файл звіту у TestSuite." << std::endl;
                }
            }
        };

        TestRunner runner;
        runner.execute();
    }
};

int main() {
    // Фікс кодування: змушуємо консоль Windows коректно виводити українську мову (UTF-8)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::string currentFile = __FILE__;
    Teacher teacher;

    // Перевірка коректності розташування проекту
    if (currentFile.find("Lab12\\prj") == std::string::npos &&
        currentFile.find("Lab12/prj") == std::string::npos) {
        teacher.punish();
    } else {
        teacher.runTests();
    }

    return 0;
}
