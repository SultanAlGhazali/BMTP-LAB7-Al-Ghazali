#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ModulesAl-Ghazali.h" // Підключаємо заголовок вашої бібліотеки

using namespace std;

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul"); // Підтримка української мови в Windows
    #endif

    cout << "=========================================================" << endl;
    cout << " Лабораторна робота № 10. Файловий тестовий драйвер" << endl;
    cout << " Виконав: Султан Аль-Газали (Заочна форма)" << endl;
    cout << " Автоматизоване тестування з файловим введенням/виведенням" << endl;
    cout << "=========================================================" << endl << endl;

    // Шляхи до файлів згідно з структурою Lab10
    string input_file = "input.txt";
    string protocol_file = "../TestSuite/protocol.txt";

    // Створюємо вхідний файл з тестовими даними
    ofstream init_file(input_file);
    if (!init_file.is_open()) {
        cout << "[ ПОМИЛКА ]: Не вдалося створити вхідний файл тесту!" << endl;
        return 1;
    }
    init_file << "hello sultan alghazali"; // Тестовий рядок нижнім регістром
    init_file.close();

    // Очищаємо старий протокол, якщо він існував
    ofstream clear_proto(protocol_file, ios::trunc);
    clear_proto.close();

    // --- КРОК 1: Тестування читання файлу (Завдання 10.1) ---
    string file_content = "";
    bool read_ok = read_input_data(input_file, file_content);
    string status_1 = (read_ok && !file_content.empty()) ? "PASSED" : "FAILED";
    write_test_protocol(protocol_file, "Зчитування файлу даних (10.1)", status_1);
    cout << "Тест 1 (Читання): " << status_1 << " (Зчитано: " << file_content << ")" << endl;

    // --- КРОК 2: Тестування обробки рядка (Завдання 10.2) ---
    string processed_content = "";
    bool process_ok = process_text_data(file_content, processed_content);
    // Очікуємо переведення всього тексту у верхній регістр
    string status_2 = (process_ok && processed_content == "HELLO SULTAN ALGHAZALI") ? "PASSED" : "FAILED";
    write_test_protocol(protocol_file, "Обробка тексту модуля (10.2)", status_2);
    cout << "Тест 2 (Обробка): " << status_2 << " (Результат: " << processed_content << ")" << endl;

    cout << "---------------------------------------------------------" << endl;
    cout << "  РЕЗУЛЬТАТ: Процес тестування завершено успішно!" << endl;
    cout << "  Протокол запису збережено у файл: Lab10/TestSuite/protocol.txt" << endl;
    cout << "=========================================================" << endl;

    return 0;
}
