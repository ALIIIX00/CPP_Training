#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class Calculator {
public:
    // Переменные для хранения чисел и знака
    long double NUM1 = 0;
    long double NUM2 = 0;
    char SIGN = '\0';

    // Чтение данных
    void ReadInput() {
        if (NUM1 == 0) {
            NUM1 = ReadNumber("Введите первое число (или 'exit' для выхода): ");
        } else if (SIGN == '\0') {
            SIGN = ReadOperator("Введите операцию (+, -, *, /) (или 'exit' для выхода): ");
        } else {
            NUM2 = ReadNumber("Введите второе число (или 'exit' для выхода): ");
        }
    }

    // Выполнение расчета
    void Calculate() {
        try {
            long double result = PerformCalculation();
            std::cout << "Результат: " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Произошла неизвестная ошибка!" << std::endl;
        }
        ResetInputs();
    }

private:
    // Сброс значений
    void ResetInputs() {
        NUM1 = 0;
        NUM2 = 0;
        SIGN = '\0';
    }

    // Ввод числа
    long double ReadNumber(const std::string& prompt) {
        while (true) {
            std::cout << prompt;
            std::string input;
            std::cin >> input;

            if (IsExitCommand(input)) {
                exit(0);
            }

            try {
                return std::stold(input);
            } catch (...) {
                std::cerr << "Некорректный ввод числа. Попробуйте ещё раз." << std::endl;
                ClearInputStream();
            }
        }
    }

    // Ввод оператора
    char ReadOperator(const std::string& prompt) {
        while (true) {
            std::cout << prompt;
            std::string input;
            std::cin >> input;

            if (IsExitCommand(input)) {
                exit(0);
            }

            if (input.size() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')) {
                return input[0];
            }

            std::cerr << "Некорректный ввод оператора. Ожидается +, -, *, /. Попробуйте ещё раз." << std::endl;
            ClearInputStream();
        }
    }

    // Проверка команды выхода
    bool IsExitCommand(const std::string& input) {
        return input == "exit" || input == "quit" || input == "q";
    }

    // Очистка потока ввода
    void ClearInputStream() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Выполнение арифметической операции
    long double PerformCalculation() {
        switch (SIGN) {
            case '+': return NUM1 + NUM2;
            case '-': return NUM1 - NUM2;
            case '*': return NUM1 * NUM2;
            case '/':
                if (NUM2 == 0) {
                    throw std::invalid_argument("Деление на ноль невозможно.");
                }
                return NUM1 / NUM2;
            default:
                throw std::invalid_argument("Неизвестный оператор.");
        }
    }
};

int main() {
    Calculator calculator;

    while (true) {
        try {
            calculator.ReadInput();
            calculator.ReadInput();
            calculator.ReadInput();
            calculator.Calculate();
        } catch (...) {
            std::cerr << "Произошла критическая ошибка. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
