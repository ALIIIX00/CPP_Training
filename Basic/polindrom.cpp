#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> // Для isalnum и tolower
#include <limits>

using namespace std;

class MyString {
public:
    string CurrectInput() {
        string userString;
        while (true) {
            cout << "Введите строку: ";
            getline(cin, userString);
            if (!cin.fail()) return userString;
            cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void CheckPalindrome(string userString) {
        string cleanedString = CleanString(ToLowerString(userString));
        string reversedString = ReverseString(cleanedString);
        if (cleanedString == reversedString) {
            cout << "Это палиндром!" << endl;
        } else {
            cout << "Это не палиндром!" << endl;
        }
    }

private:
    string ToLowerString(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    string ReverseString(const string& str) {
        string result = str;
        reverse(result.begin(), result.end());
        return result;
    }

    string CleanString(const string& str) {
        string result;
        for (char c : str) {
            if (isalnum(c)) { // Оставляем только буквы и цифры
                result += c;
            }
        }
        return result;
    }
};

int main() {
    MyString myString;
    string userString = myString.CurrectInput();
    myString.CheckPalindrome(userString);
    return 0;
}
