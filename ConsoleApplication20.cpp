// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
class bad_length : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        throw bad_length();
    }
    else
    {
        return str.length();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string stroka;
    int zapret;
    std::cout << "Введите запретную длину: ";
    std::cin >> stroka;
    zapret = std::stoi(stroka);

    while (1) {
        std::cout << "Введите слово: ";
        std::cin >> stroka;

        try
        {
                std::cout << "Длина слова " << stroka << " равна " << function(stroka, zapret) << std::endl;
        }

            catch (const bad_length& ex)
        {
                std::cout << ex.what() << std::endl; 
        break;
        }
        catch (...) { std::cout << "Неизвестная ошибка" << std::endl;
        break;
        }
        {

        }
    
    }
}
/*
В этом задании вы попробуете выбросить и обработать исключение.
Создайте функцию int function(std::string str, int forbidden_length). 
Эта функция должна возвращать длину переданной строки, если эта длина не равна значению переданного параметра forbidden_length. 
В противном случае она должна выбрасывать исключение bad_length.
Для проверки функции организуйте работу с пользователем. 
В начале задайте запретную длину, а затем считывайте пользовательские строки и выводите их длину до тех пор, пока пользователь не введёт строку запретной длины. 
После этого сообщите ему, что он ввёл строку запретной длины, и завершите программу.
Пример работы программы
Консоль
Введите запретную длину: 5
Введите слово: Привет
Длина слова "Привет" равна 6
Введите слово: мир
Длина слова "мир" равна 3
Введите слово: пирог
Вы ввели слово запретной длины! До свидания
*/