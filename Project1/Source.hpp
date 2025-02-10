#pragma once

#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <string.h>
#include <iostream>


class String {
public:
	String();
	explicit String(int lenght);
	String(const char* std);

	~String();
	String(const String& other);
	String& operator=(const String& other);

	String(String&& other)noexcept;
	String& operator=(String&& other);


	void reserve(int new_len);
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
	const char& at(int i)const;

private:
	char* str_;
	size_t capacity;
};
#endif // !SOURCE_HPP
