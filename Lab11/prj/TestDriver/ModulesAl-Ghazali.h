#ifndef MODULESAL_GHAZALI_H_INCLUDED
#define MODULESAL_GHAZALI_H_INCLUDED
#include <string>

// Структури для ЛР 10
struct StudentResult {
    std::string name;
    int score;
    bool passed;
};

// Прототипи функцій для Лабораторної роботи №10
bool read_input_data(const std::string& input_filename, std::string& data);
bool process_text_data(const std::string& data, std::string& result);
bool write_test_protocol(const std::string& output_filename, const std::string& test_name, const std::string& status);

#endif // MODULESAL_GHAZALI_H_INCLUDED
