#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

struct Person {
    std::string name;
    int priority;

    bool operator<(const Person& other) const {
        return priority < other.priority;
    }
};

int main() {
    std::priority_queue<Person> pq;
    std::string operation;

    while (true) {
        std::cout << "What do you want to do? ";
        if (!std::getline(std::cin, operation) || operation.empty()) {
            break;
        }

        if (operation == "add") {
            std::string name;
            int priority;

            std::cout << "Name: ";
            std::getline(std::cin, name);

            std::cout << "Priority: ";
            std::cin >> priority;
            std::cin.ignore();

            pq.push(Person{name, priority});
        }
        else if (operation == "take") {
            if (pq.empty()) {
                std::cout << "There are no more people in line" << std::endl;
            } else {
                Person next = pq.top();
                pq.pop();

                std::cout << std::setw(2) << std::setfill('0') << next.priority << " - " << next.name << std::endl;
            }
        }
        else {
            std::cout << operation << " isn't a valid operation" << std::endl;
        }
    }

    return 0;
}
