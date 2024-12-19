#include <iostream>

class Numbers{
    public: 
    void GetSum(int number1, int number2){
        std::cout<<"Сумма чисел: "<<number1<< " и "<< number2<< " равна " << Sum(number1, number2)<<std::endl;
    }

    private:
    int Sum(int number1, int number2){
        return number1 + number2;
    }
};

int main(){
    int number1, number2;
    std::cout<<"Введите 1-е число:";
    std::cin>>number1;
    std::cout<<"Введите 2-е число:";
    std::cin>>number2;
    Numbers numbers;
    numbers.GetSum(number1, number2);
    return 0;
}