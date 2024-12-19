#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <functional>

class Hash {
public:
    void MainMenu() {
        while (true) {
            std::cout << "Выберите действие.\n  1 - Записать хэш-файл \t 2 - Проверить файл на целостность хэша \t 3 - Выход" << std::endl;
            int userMenuInput = CurrectInput();
            switch (userMenuInput) {
            case 1:
                WriteHashfile();
                break;
            case 2:
                ScanFile();
                break;
            case 3:
                return;
            default:
                std::cout << "Я не знаю такой команды :/" << std::endl;
                break;
            }
        }
    }

private:
    void ScanFile() {
        std::string filePath, hashFilePath;
        std::cout << "Введите путь к файлу с данными:" << std::endl;
        std::cin >> filePath;
        std::cout << "Введите путь к hash-файлу:" << std::endl;
        std::cin >> hashFilePath;

        std::ifstream userFile = OpenFile(filePath);
        std::ifstream hashFile = OpenFile(hashFilePath);
        std::hash<std::string> hasher;

        std::string fileHashLine, userFileLine;
        bool isIdentical = true;

        while (std::getline(hashFile, fileHashLine) && std::getline(userFile, userFileLine)) {
            size_t hash = hasher(userFileLine);
            if (std::to_string(hash) != fileHashLine) {
                isIdentical = false;
                break;
            }
        }

        if (std::getline(hashFile, fileHashLine) || std::getline(userFile, userFileLine)) {
            isIdentical = false;
        }

        if (isIdentical) {
            std::cout << "Целостность хэша проверена!\nФайл не изменялся" << std::endl;
        } else {
            std::cout << "Целостность хэша проверена!\nФайл был изменен!" << std::endl;
        }
    }

    void WriteHashfile() {
        std::string filePath, hashFilePath;
        std::cout << "Введите путь к файлу с данными:" << std::endl;
        std::cin >> filePath;
        std::cout << "Введите путь к hash-файлу:" << std::endl;
        std::cin >> hashFilePath;

        std::ifstream userFile = OpenFile(filePath);
        std::ofstream hashFile(hashFilePath);
        if (!hashFile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи: " + hashFilePath);
        }

        std::string line;
        std::hash<std::string> hasher;

        while (std::getline(userFile, line)) {
            size_t hash = hasher(line);
            hashFile << hash << std::endl;
        }

        std::cout << "Хэш-файл записан!" << std::endl;
    }

    int CurrectInput() {
        int number;
        while (true) {
            std::cin >> number;
            if (!std::cin.fail()) return number;
            std::cout << "Некорректный ввод. Попробуйте ещё раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::ifstream OpenFile(std::string filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filePath);
        }
        return file;
    }
};

int main() {
    Hash hash;
    try {
        hash.MainMenu();
    } catch (const std::exception& ex) {
        std::cerr << "Критическая ошибка: " << ex.what() << std::endl;
    }
    return 0;
}
