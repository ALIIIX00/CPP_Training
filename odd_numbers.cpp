#include <iostream>

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // Создаём динамический массив
    int* array = new int[n]; 

    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i]; // Вводим элементы в массив
    }

    std::cout << "Чётные числа: ";
    bool hasEven = false; // Флаг для проверки наличия чётных чисел
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            std::cout << array[i] << " ";
            hasEven = true;
        }
    }

    if (!hasEven) {
        std::cout << "Чётных чисел нет"<<std::endl;
    }

    // Освобождаем память
    delete[] array;

    return 0;
}
