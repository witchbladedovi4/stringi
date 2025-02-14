#include <iostream>
#include <vector>
#include "allocator.hpp" // Подключаем наш аллокатор

int main() {
    // Использование аллокатора с std::vector
    std::vector<int, Allocator<int>> vec = { 1, 2, 3, 4, 5 };

    // Выводим элементы вектора
    std::cout << "Элементы вектора: ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
