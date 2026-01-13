#pragma once
#include <stdexcept>

template<class T>
class Vector {
private:
    T* data;
    int vec_size;
    int capacity;

    void grow() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (int i = 0; i < vec_size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Vector() : data(nullptr), vec_size(0), capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(T item) {
        if (vec_size == capacity) {
            grow();
        }
        data[vec_size++] = item;
    }

    void insert(T item, int position) {
        if (position < 0 || position > vec_size) {
            throw std::out_of_range("Index out of range");
        }
        if (vec_size == capacity) {
            grow();
        }
        for (int i = vec_size; i > position; --i) {
            data[i] = data[i - 1];
        }
        data[position] = item;
        ++vec_size;
    }

    void remove(int position) {
        if (position < 0 || position >= vec_size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = position; i < vec_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --vec_size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= vec_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() const {
        return vec_size;
    }

    void clear() {
        vec_size = 0;
    }
};
