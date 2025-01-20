#include <iostream>
#include <limits>
#include <vector>
#include<algorithm>

class User{
    public:
    //Constructor
    User(std::string name, int age, int mark) : Name(name), Age(age), Mark(mark) {}

    std::string GetName(){ return Name; }
    int GetAge() { return Age; }
    int GetMark() { return Mark; }

    void PrintUserInformation(){
        std::cout << "Привет, " << Name << "!" << " Тебе " << Age << " лет, и твоя оценка - " << Mark << std::endl;
    }
    
    bool operator<(const User& user) const
    {
        return Mark > user.Mark;
    }
    
    private:
    std::string Name;
    int Age;
    int Mark;
    

};

class Game{
    public:
    std::vector<User> Users;
    void Init(){
        std::cout << "My Task #1 Advenced in GameDev :)" << std::endl;

        while(true){
            int userQuantity = InputQuantity();
            while(userQuantity > 0){
                std::string username = InputUserName();
                int age = InputAge();
                int mark = InputMark(); 
                User user = User(username, age, mark);
                Users.push_back(user);
                userQuantity--;
            }

            //sorting
            std::sort(Users.begin(),Users.end());

            std::cout << "Полный список пользователей:" << std::endl;
            for(auto& user : Users){
                user.PrintUserInformation();
            }
            
            std::cout << "Для выхода используйте сочитание клавиш \"Ctrl + C\"" << std::endl;
            
        }
        
    }


    private:
    std::vector<User> SortingUsers(std::vector<User> users){
        
        return users;
    }
    int InputQuantity(){
        std::cout << "Введите количество пользователей которых хотите добавить: ";
        int quantity;
        while (true) {
            std::cin >> quantity;
            if (!std::cin.fail() && quantity > 0) return quantity;
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cout << "Введите количество пользователей которых хотите добавить: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
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