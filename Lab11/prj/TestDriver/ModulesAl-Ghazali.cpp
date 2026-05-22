#include "ModulesAl-Ghazali.h"
#include <fstream>
#include <iostream>

// Функція зчитування вхідних даних з текстового файлу (Завдання 10.1)
bool read_input_data(const std::string& input_filename, std::string& data) {
    std::ifstream file(input_filename);
    if (!file.is_open()) {
        return false;
    }
    std::getline(file, data);
    file.close();
    return true;
}

// Функція обробки символьної інформації (Завдання 10.2)
bool process_text_data(const std::string& data, std::string& result) {
    if (data.empty()) return false;
    result = data;
    for (char &c : result) {
        c = toupper(c);
    }
    return true;
}

// Функція запису протоколу тестування у вихідний файл (Завдання 10.3)
bool write_test_protocol(const std::string& output_filename, const std::string& test_name, const std::string& status) {
    std::ofstream file(output_filename, std::ios_base::app);
    if (!file.is_open()) {
        return false;
    }
    file << "Тест: " << test_name << " | Статус: [ " << status << " ]" << std::endl;
    file.close();
    return true;
}
