/**
 * @brief Программа для табулирования функции y = 3 * sin(sqrt(x)) + 0.39x - 3.8
 */

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Получает числовое значение от пользователя
 * @return Введенное пользователем число типа double
 * @note При некорректном вводе выводит сообщение об ошибке и завершает программу
 */
double getValue();

/**
 * @brief Проверяет корректность шага табулирования
 * @param step Значение шага для проверки
 * @note Если шаг отрицательный или нулевой, программа завершается
 */
void checkStep(const double step);

/**
 * @brief Вычисляет значение функции y = 3 * sin(sqrt(x)) + 0.39x - 3.8
 * @param x Аргумент функции
 * @return Значение функции в точке x
 * @pre Функция должна быть определена в точке x (проверяется isDomain)
 */
double getY(const double x);

/**
 * @brief Проверяет принадлежность точки x области определения функции
 * @param x Проверяемая точка
 * @return true если функция определена в точке x, false в противном случае
 */
bool isDomain(const double x);

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 * @details Запрашивает у пользователя интервал и шаг табулирования,
 * затем выводит таблицу значений функции или сообщения об ошибках
 */
int main()
{
    // Ввод начальных параметров
    cout << "Enter xn: ";
    double xstart = getValue();
    cout << "Enter xk: ";
    double xend = getValue();
    cout << "Enter step: ";
    double step = getValue();

    // Проверка корректности шага
    checkStep(step);

    // Табулирование функции
    for (double x = xstart; x < xend + step; x += step)
    {
        cout << "x = " << x;
        if (isDomain(x))
        {
            cout << " y = " << getY(x) << endl;
        }
        else
        {
            cout << " not in domain" << endl;
        }
    }
    return 0;
}

double getValue()
{
    double value = 0.0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        cout << "Error: step must be positive" << endl;
        abort();
    }
}

double getY(const double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

bool isDomain(const double x)
{
    return x >= 0; // Функция определена при x >= 0 из-за sqrt(x)
}