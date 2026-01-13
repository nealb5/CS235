#pragma once
#include <vector>
#include <list>
#include <functional>

template<class T>
class HashSet {
private:
    std::vector<std::list<T>> buckets;
    size_t num_elements;
    float max_load_factor;

    size_t hash(const T& item) const {
        return std::hash<T>{}(item) % buckets.size();
    }

    void rehash() {
        std::vector<std::list<T>> new_buckets(buckets.size() * 2);
        for (const auto& bucket : buckets) {
            for (const T& item : bucket) {
                size_t new_index = std::hash<T>{}(item) % new_buckets.size();
                new_buckets[new_index].push_back(item);
            }
        }
        buckets = std::move(new_buckets);
    }

public:
    HashSet() : buckets(8), num_elements(0), max_load_factor(0.75) {}

    ~HashSet() = default;

    bool insert(T item) {
        if (contains(item)) return false;

        if (static_cast<float>(num_elements + 1) / buckets.size() > max_load_factor) {
            rehash();
        }

        size_t index = hash(item);
        buckets[index].push_back(item);
        num_elements++;
        return true;
    }

    bool remove(T item) {
        size_t index = hash(item);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == item) {
                bucket.erase(it);
                num_elements--;
                return true;
            }
        }
        return false;
    }

    bool contains(T item) const {
        size_t index = hash(item);
        const auto& bucket = buckets[index];
        for (const T& element : bucket) {
            if (element == item) return true;
        }
        return false;
    }

    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        num_elements = 0;
    }

    int size() const {
        return static_cast<int>(num_elements);
    }
};
