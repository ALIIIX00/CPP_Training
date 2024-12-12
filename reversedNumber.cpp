#include <iostream>
#include <limits>
#include <string>

class Numbers{
    public:
    int CurrectInput(){
        int number;
        while (true) {
            std::cout << "Введите число: ";
            std::cin >> number;
            if (!std::cin.fail()) return number; // Корректный ввод
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void PrintReversedNumber(int userNumber){
        std::cout<<"Число наоборот: "<< FindReversedNumber(userNumber)<<std::endl;
    }
    private:
    std::string FindReversedNumber(int userNumber) {
        std::string stringNumber;
        if (userNumber < 0) {
            stringNumber = "-";
            userNumber = -userNumber;
        }
        do {
            stringNumber += std::to_string(userNumber % 10); // Добавляем последнюю цифру
            userNumber /= 10;
        } while (userNumber > 0); // Гарантируем, что 0 обрабатывается правильно

        return stringNumber;
    }
};

int main(){
    Numbers numbers;
    int userNumber = numbers.CurrectInput();
    numbers.PrintReversedNumber(userNumber);
    

    return 0;
}