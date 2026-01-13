#include <iostream>
#include <string>

int main() {
    std::string operation;
    double leftOperand, rightOperand;

    while (true) {
        std::cout << "operation: ";
        std::getline(std::cin, operation);

        if (operation.empty()) {
            break;
        }

        if (operation != "add" && operation != "subtract" && operation != "multiply" &&
            operation != "divide" && operation != "mod") {
            std::cout << operation << " isn't a valid operation" << std::endl;
            continue;
            }

        std::cout << "left operand: ";
        std::cin >> leftOperand;

        std::cout << "right operand: ";
        std::cin >> rightOperand;
        std::cin.ignore();

        if (operation == "add") {
            std::cout << (leftOperand + rightOperand) << std::endl;
        } else if (operation == "subtract") {
            std::cout << (leftOperand - rightOperand) << std::endl;
        } else if (operation == "multiply") {
            std::cout << (leftOperand * rightOperand) << std::endl;
        } else if (operation == "divide") {
            std::cout << (leftOperand / rightOperand) << std::endl;
        } else if (operation == "mod") {
            std::cout << static_cast<int>(leftOperand) % static_cast<int>(rightOperand) << std::endl;
        }
    }

    return 0;
}
