#pragma once

#include <vector>
#include <algorithm>  // for std::find

template<class T>
class VectorSet {
private:
    std::vector<T> _vec;

public:
    bool contains(T item) const {
        return std::find(_vec.begin(), _vec.end(), item) != _vec.end();
    }

    bool insert(T item) {
        if (!contains(item)) {
            _vec.push_back(item);
            return true;
        }
        return false;
    }

    bool remove(T item) {
        auto it = std::find(_vec.begin(), _vec.end(), item);
        if (it != _vec.end()) {
            _vec.erase(it);
            return true;
        }
        return false;
    }

    int size() const {
        return _vec.size();
    }

    bool empty() const {
        return _vec.empty();
    }

    void clear() {
        _vec.clear();
    }
};
