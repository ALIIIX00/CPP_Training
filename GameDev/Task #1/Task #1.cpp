#include <iostream>
#include <limits>

class User{
    public:
    //Конструктор
    User(std::string name, int age, int mark) : Name(name), Age(age), Mark(mark) {}

    void PrintUserInformation(){
        std::cout << "Привет, " << Name << "!" << std::endl;
        std::cout << "Тебе " << Age << " лет, и твоя оценка - " << Mark << std::endl;
    }
    
    private:
    std::string Name;
    int Age;
    int Mark;
    

};
class Game{
    public:
    
    void Init(){
        std::cout << "My Task #1 in GameDev :)" << std::endl;
        std::string username = InputUserName();
        int age = InputAge();
        int mark = InputMark(); 
        User user(username, age, mark);
        user.PrintUserInformation();
    }


    private:
    std::string InputUserName(){
        std::cout << "Введите ваше имя: ";
        std::string username;
        std::cin >> username;
        return username;
    }
    int InputAge(){
        std::cout << "Введите ваш возраст: ";
        int age;
        while (true) {
            std::cin >> age;
            if (!std::cin.fail() && age > 0) return age;
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cout << "Введите ваш возраст: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    int InputMark(){
        std::cout << "Введите вашу оценку: ";
        int mark;
        while (true) {
            std::cin >> mark;
            if (!std::cin.fail() && mark >= 0) return mark;
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cout << "Введите вашу оценку: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};


int main(){
    
    Game game;
    game.Init();

    return 0;
}