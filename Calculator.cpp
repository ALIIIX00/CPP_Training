#include <iostream>
#include <limits>

class Calculator{
    public:
    double CurrectNumberInput(){
        double number;
        while (true) {
            std::cout << "Введите число: ";
            std::cin >> number;
            if (!std::cin.fail()) return number; // Корректный ввод
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    private:

};

int main(){
    Calculator calculator;
    double number1 = calculator.CurrectNumberInput();
    double number2 = calculator.CurrectNumberInput();

}