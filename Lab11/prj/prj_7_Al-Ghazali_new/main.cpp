#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Структура елемента динамічної пам'яті (Пункт 3.4 методички)
struct TaskElement {
    int id;
    char code[10];
    double value;
    TaskElement* next; // Указник на наступний елемент списку
};

// Функція додавання елемента у динамічну структуру (однозв'язний список)
void add_element(TaskElement*& head, int id, const char* code, double value) {
    TaskElement* new_node = new TaskElement;
    new_node->id = id;
    strncpy(new_node->code, code, 9);
    new_node->code[9] = '\0';
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

// Функція збереження динамічної структури у БІНАРНИЙ файл (ios::binary)
bool save_to_binary_file(const string& filename, TaskElement* head) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        return false;
    }

    TaskElement* current = head;
    while (current != nullptr) {
        file.write(reinterpret_cast<const char*>(&current->id), sizeof(current->id));
        file.write(current->code, sizeof(current->code));
        file.write(reinterpret_cast<const char*>(&current->value), sizeof(current->value));
        current = current->next;
    }

    file.close();
    return true;
}

// Звільнення динамічної пам'яті після завершення роботи програми
void free_list(TaskElement*& head) {
    while (head != nullptr) {
        TaskElement* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul"); // Підтримка української мови в Windows
    #endif

    cout << "=========================================================" << endl;
    cout << " Лабораторна робота № 11. Головний програмний модуль" << endl;
    cout << " Виконав: Султан Аль-Газали (Заочна forma)" << endl;
    cout << " Командна реалізація: Проєкт prj_7_Al-Ghazali" << endl;
    cout << "=========================================================" << endl << endl;

    TaskElement* list_head = nullptr;
    string binary_filename = "database.dat";

    cout << "1. Формування динамічної структури в оперативній пам'яті..." << endl;
    add_element(list_head, 101, "TASK-A", 45.67);
    add_element(list_head, 102, "TASK-B", 89.12);
    add_element(list_head, 103, "TASK-C", 12.34);
    cout << "   [ УСПІШНО ]: Створено 3 елементи в динамічній пам'яті." << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << "2. Запис сформованої структури у бінарний файл '" << binary_filename << "'..." << endl;
    if (save_to_binary_file(binary_filename, list_head)) {
        cout << "   [ УСПІШНО ]: Бінарний файловий потік успішно записано." << endl;
    } else {
        cout << "   [ ПОМИЛКА ]: Не вдалося відкрити файл для бінарного запису!" << endl;
        free_list(list_head);
        return 1;
    }
    cout << "---------------------------------------------------------" << endl;

    free_list(list_head);

    cout << "РЕЗУЛЬТАТ: Програму успішно виконано згідно ISO/IEC 12207!" << endl;
    cout << "=========================================================" << endl;

    return 0;
}
