#pragma once

#include <vector>
#include <algorithm>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right) / 2;

    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    if (array[middle] > array[right]) {
        std::swap(array[middle], array[right]);
    }
    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int middle = medianOfThree(array, left, right);
    std::swap(array[left], array[middle]);

    T pivot = array[left];
    int up = left + 1;
    int down = right;

    do {
        while (up <= right && array[up] <= pivot) {
            ++up;
        }
        while (down >= left && array[down] > pivot) {
            --down;
        }
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    } while (up < down);

    std::swap(array[left], array[down]);

    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(array, left, right);

    sort_helper(array, left, pivotIndex - 1);  // Left subarray
    sort_helper(array, pivotIndex + 1, right); // Right subarray
}

template<class T>
void sort(std::vector<T>& array) {
    if (array.size() > 1) {
        sort_helper(array, 0, array.size() - 1);  // Start sorting the whole array
    }
}
