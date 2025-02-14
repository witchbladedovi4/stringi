#include "Source.hpp"
#include <cstring> 

// Конструктор по умолчанию
String::String() : str_(nullptr), length(0) {}

// Конструктор из C-строки
String::String(const char* str) {
    if (str) {
        length = std::strlen(str);
        str_ = new char[length + 1];
        std::strcpy(str_, str);
    }
    else {
        str_ = nullptr;
        length = 0;
    }
}

// Конструктор копирования
String::String(const String& other) {
    copyData(other.str_);
}

// Конструктор перемещения
String::String(String&& other) noexcept
    : str_(other.str_), length(other.length) {
    other.str_ = nullptr;
    other.length = 0;
}

// Деструктор
String::~String() {
    delete[] str_;
}

// Оператор присваивания копированием
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str_;
        copyData(other.str_);
    }
    return *this;
}

// Оператор присваивания перемещением
String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str_;
        str_ = other.str_;
        length = other.length;
        other.str_ = nullptr;
        other.length = 0;
    }
    return *this;
}

// Оператор присваивания из C-строки
String& String::operator=(const char* str) {
    if (str_ != str) {
        delete[] str_;
        if (str) {
            length = std::strlen(str);
            str_ = new char[length + 1];
            std::strcpy(str_, str);
        }
        else {
            str_ = nullptr;
            length = 0;
        }
    }
    return *this;
}

// Возвращает длину строки
std::size_t String::size() const {
    return length;
}

// Возвращает C-строку
const char* String::c_str() const {
    return str_ ? str_ : "";
}

// Вспомогательная функция для копирования данных
void String::copyData(const char* str) {
    if (str) {
        length = std::strlen(str);
        str_ = new char[length + 1];
        std::strcpy(str_, str);
    }
    else {
        str_ = nullptr;
        length = 0;
    }
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.c_str();
    return os;
}






