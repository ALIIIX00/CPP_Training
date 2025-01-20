#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <map>
#include <string.h>

class Player {
    public:
    sf::CircleShape Character;
    sf::Color CharacterColor;
    sf::Vector2f CharacterOrigin;
    int Speed = 5;
    Player(sf::CircleShape player):Character(player){
        Init();
        PlayerRender();
    }
    void Init(){
        CharacterColor = sf::Color::Green;
        CharacterOrigin = sf::Vector2f(50, 50);
        
    }
    void PlayerRender(){
        Character.setFillColor(CharacterColor);
        Character.setOrigin(sf::Vector2f(50, 50));
        Character.setPosition(800 / 2, 600 / 2);        

    }
    void DrawPlayer(sf::RenderWindow &window){
        window.draw(Character);
    }
    void Move(int resolutionX, int resolutionY){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            Character.move(-Speed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            Character.move(Speed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            Character.move(0, Speed); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            Character.move(0, -Speed); 
        }
        if (Character.getPosition().x < 0) {
            Character.setPosition(0, Character.getPosition().y);
        }
        if (Character.getPosition().x > resolutionX) {
            Character.setPosition(resolutionX, Character.getPosition().y);
        }
        if (Character.getPosition().y < 0) {
            Character.setPosition(Character.getPosition().x, 0);
        }
        if (Character.getPosition().y > resolutionY) {
            Character.setPosition(Character.getPosition().x, resolutionY);
        }
    }
    private:
    
    
};
class GameObject{
public:
    sf::RectangleShape Object;
    sf::Color ObjectColor;
    sf::Vector2f ObjectOrigin;
    int Speed = 5;
    GameObject(sf::RectangleShape object):Object(object){
        Init();
        ObjectRender();
    }
    void Init(){
        ObjectColor = sf::Color::Yellow;
        ObjectOrigin = sf::Vector2f(50, 50);
        
    }
    void ObjectRender(){
        Object.setFillColor(ObjectColor);
        Object.setOrigin(sf::Vector2f(50, 50));
        Object.setPosition(800 / 2 + 200, 600 / 2);        

    }
    void DrawObject(sf::RenderWindow &window){
        window.draw(Object);
    }
    void Move(int resolutionX){
        Object.move(Speed, 0);
        Object.rotate(1.0f);
        if(Object.getPosition().x <= 0 || Object.getPosition().x >= resolutionX ){
            Speed = -Speed;
        }
    }
};

class Engine{
    public:
    std::map<std::string, std::string> Config;
    Engine(){   
        Init();
        Update();
    }
    void Init(){
        GetConfigurations();
    };

    void Update(){
    
        sf::RenderWindow window(sf::VideoMode(std::stoi(Config["ResolutionWidth"]), std::stoi(Config["ResolutionHeight"])), Config["Title"]);
        window.setFramerateLimit(stoi(Config["Framerate"]));
        sf::CircleShape circle(50);
        Player player = Player(circle);
        sf::RectangleShape rectangle(sf::Vector2f(150, 75));
        GameObject object = GameObject(rectangle);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            // Очищаем окно
            window.clear(sf::Color::White);
            object.DrawObject(window);
            object.Move(std::stoi(Config["ResolutionWidth"]));
            player.DrawPlayer(window);
            player.Move(std::stoi(Config["ResolutionWidth"]), std::stoi(Config["ResolutionHeight"]));
            window.display();
        }
        
    }


    private:
    void GetConfigurations(){
        std::ifstream is_file("config.ini");
        if (!is_file.is_open()) {
            std::cerr << "Ошибка: файл конфигурации не найден!" << std::endl;
            exit(1);
        }
        std::string line;
        while( std::getline(is_file, line) ){
            std::istringstream is_line(line);
            std::string key;
            if( std::getline(is_line, key, '=') ){
                std::string value;
                if( std::getline(is_line, value) ) 
                Config.insert({key, value});
            }
        }
    }
    
};

int main() {
    Engine engine = Engine();
    
    return 0;
}
