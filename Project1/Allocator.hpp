#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef> // Для std::size_t

// Шаблонная структура аллокатора
template <typename T>
struct Allocator {
    using value_type = T; // Тип значения, для которого работает аллокатор

    // Ребиндинг для совместимости с контейнерами
    template <typename U>
    struct rebind {
        using other = Allocator<U>;
    };

    // Конструктор по умолчанию
    Allocator() = default;

    // Конструктор копирования для другого типа
    template <typename U>
    Allocator(const Allocator<U>&) {}

    // Выделение памяти
    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    // Освобождение памяти
    void deallocate(T* p, std::size_t n) {
        ::operator delete(p);
    }
};

#endif // ALLOCATOR_HPP
