#include <iostream>
#include <fstream>
#include <string>

class FileScaner {
public:
    void ScanFile(std::string filePath) {
        int errorsCount = 0; // Инициализация счетчика ошибок
        std::ifstream wordlist = GetWordlist();
        std::ifstream userFile = OpenFile(filePath);
        
        std::string fileLine;
        while (std::getline(userFile, fileLine)) { // Читаем файл по строкам
            std::string errorWord;
            while (std::getline(wordlist, errorWord)) { // Читаем каждое слово из словаря
                size_t pos = 0;
                while ((pos = fileLine.find(errorWord, pos)) != std::string::npos) {
                    errorsCount++;
                    pos += errorWord.length(); // Двигаем позицию дальше
                }
            }
            wordlist.clear();             // Сбрасываем флаг конца файла
            wordlist.seekg(0, std::ios::beg); // Возвращаемся в начало словаря
        }
        
        if (errorsCount > 0) {
            std::cout << "В файле \"" << filePath << "\" найдено " << errorsCount << " подозрительных совпадений!\n";
        } else {
            std::cout << "Файл \"" << filePath << "\" безопасен!\n";
        }
        
        userFile.close();
        wordlist.close();
    }

private:
    const std::string WORDLIST_PATH = "wordlist.txt";

    std::ifstream OpenFile(std::string filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filePath);
        }
        return file;
    }
    std::ifstream GetWordlist() {
        return OpenFile(WORDLIST_PATH);
    }
};

int main() {
    FileScaner fs;
    std::string fileName;
    std::cout << "Введите путь к проверяемому файлу:" << std::endl;
    std::cin >> fileName;
    try {
        fs.ScanFile(fileName);
    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }
    return 0;
}
