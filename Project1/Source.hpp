#pragma once

#ifndef SOURCE_HPP
#define SOURCE_HPP

//#include <string.h>
#include <iostream>
#include <cstddef>

class String {
public:
	// Конструкторы
	String(); // Конструктор по умолчанию
	String(const char* str); // Конструктор из C-строки
	String(const String& other); // Конструктор копирования
	String(String&& other) noexcept; // Конструктор перемещения

	//Деструктор
	~String(); 
	
	// Операторы
	String& operator=(const String& other); // Оператор присваивания копированием
	String& operator=(String&& other) noexcept; // Оператор присваивания перемещением
	String& operator=(const char* str); // Оператор присваивания из C-строки

	
	/*void reserve(int new_len);
	void shrink_to_fit();
	void clean();
	void empty()const;

	String& operator+=(const String& other);
	String& operator+=(char ch);
	friend String& operator+(const String& lsd, const String& rsd);
	friend String& operator+(const String& lsd, char ch);
	friend String& operator+(char ch, const String& rsd);
	
	friend bool operator<(const String& lsd, const String& rsd);
	friend bool operator>(const String& lsd, const String& rsd);
	friend bool operator>=(const String& lsd, const String& rsd);
	friend bool operator<=(const String& lsd, const String& rsd);
	friend bool operator==(const String& lsd, const String& rsd);
	friend bool operator!=(const String& lsd, const String& rsd);

	char& operator[](int i)noexcept;
	const char& operator[](int i)const noexcept;

	char& at(int i);
	const char& at(int i)const;*/

	// Методы
	std::size_t size() const; // Возвращает длину строки
	const char* c_str() const; // Возвращает C-строку

	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& os, const String& str);


private:
	char* str_; //Указатель на массив символов
	std::size_t length; // Длина
	void copyData(const char* str); 
	std::size_t capacity;
};
#endif // !SOURCE_HPP
