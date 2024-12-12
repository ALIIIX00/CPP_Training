#include <iostream>
#include <limits>

class Numbers{
    public: 
    void PrintResult(int number){
        std::cout<<"Число "<<number<< " является ";
        if(IsEven(number)) std::cout<<"четным"<<std::endl;
        else std::cout<<"нечетным"<<std::endl;
    }
    void FindEvenNumbersInArray(int number){
        std::cout<<"Четные числа в диапазоне от 1 до "<<number<<":"<<std::endl;
        for(int i = 1; i <= number; i++){
            if(IsEven(i)) std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    private:
    bool IsEven(int number){
        return number%2 == 0;
    }
};

int main(){
    while(true){
        int number;
        std::cout<<"Введите число: ";
        std::cin>>number;
        if (!std::cin.fail()){
            Numbers numbers;
            numbers.PrintResult(number);
            numbers.FindEvenNumbersInArray(number);
            break;
        }
        if (std::cin.fail()){
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}