#include <iostream>
#include <limits>

class Math{
    public:
    bool IsPositiveNumber(int number){
        return number>=0;
    }
    long long CalculateFactorial(int userNumber, long long result){
        if(userNumber == 0) return result;
        result *= userNumber;
        return CalculateFactorial(userNumber-1, result);
    }
    private:
    

};

int main(){
    Math math;
    int number;
    std::cout<<"Введите число: ";
    
    std::cin>>number;
    if (!std::cin.fail() && math.IsPositiveNumber(number)){
        std::cout<<"Факториал "<<number<<" равен "<<math.CalculateFactorial(number, 1)<<std::endl;
    }
    else{
        std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}