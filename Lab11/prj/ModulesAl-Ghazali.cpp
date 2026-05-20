#include "struct_type_project_7.h"
#include <fstream>
#include <cstring>
#include <iostream>

// Функція додавання елемента у динамічну структуру (однозв'язний список)
void add_element(TaskElement*& head, int id, const char* code, double value) {
    TaskElement* new_node = new TaskElement;
    new_node->id = id;
    std::strncpy(new_node->code, code, 9);
    new_node->code[9] = '\0';
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

// Функція збереження динамічної структури у БІНАРНИЙ файл (ios::binary)
bool save_to_binary_file(const std::string& filename, TaskElement* head) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    TaskElement* current = head;
    while (current != nullptr) {
        // Записуємо дані блоком пам'яті (Пункт 1 завдання, робота з бінарними потоками)
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
