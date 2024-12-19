#include <iostream>
#include <limits>
#include <string>
#include <locale>

class Crypting {
public:
    void MainMenu() {
        setlocale(LC_ALL, ""); // Устанавливаем локаль для поддержки всех символов
        while (true) {
            std::cout << "Программа шифрования/дешифрования текста.\n1 - Зашифровать текст\n2 - Дешифровать текст\n3 - Выход" << std::endl;
            int userMenuInput = CurrectInput();
            switch (userMenuInput) {
                case 1:
                    GetCryptedString();
                    break;
                case 2:
                    GetDecryptedString();
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
    void GetCryptedString() {
        std::cout << "Введите текст для шифрования: ";
        std::string userString = CurrectStringInput();
        std::cout << "Введите сдвиг: ";
        int shift = CurrectInput();
        std::string result = ExecuteCrypting(userString, shift);
        std::cout << "Результат: " << result << std::endl;
    }

    void GetDecryptedString() {
        std::cout << "Введите текст для дешифрования: ";
        std::string userString = CurrectStringInput();
        std::cout << "Введите сдвиг: ";
        int shift = CurrectInput();
        std::string result = ExecuteCrypting(userString, -shift);
        std::cout << "Результат: " << result << std::endl;
    }

    std::string ExecuteCrypting(const std::string& userInput, int shift) {
        std::string cryptedString;
        for (char32_t symbol : userInput) {
            char32_t shifted = (symbol + shift) % 0x110000; // Сдвиг в диапазоне всех Unicode символов (0x110000 - макс. значение)
            if (shifted < 0) {
                shifted += 0x110000; // Корректировка отрицательного значения
            }
            cryptedString += static_cast<char>(shifted); // Преобразование в строку
        }
        return cryptedString;
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

    std::string CurrectStringInput() {
        std::string userString;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
        std::getline(std::cin, userString);
        return userString;
    }
};

int main() {
    Crypting crypting;
    try {
        crypting.MainMenu();
    } catch (const std::exception& ex) {
        std::cerr << "Критическая ошибка: " << ex.what() << std::endl;
    }
    return 0;
}
