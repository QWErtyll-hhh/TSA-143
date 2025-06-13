#include <iostream>

/**
 * @brief Пространство имен стандартной библиотеки C++
 */
using namespace std;

/**
 * @brief Вычисляет длину второй стороны прямоугольника
 * @param a Длина первой стороны
 * @param n Коэффициент в процентах
 * @return Длина второй стороны (b = n * a / 100)
 */
double calculateSecondSide(const double a, const double n);

/**
 * @brief Вычисляет площадь прямоугольника
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @return Площадь прямоугольника (a * b)
 */
double calculateArea(const double a, const double b);

/**
 * @brief Вычисляет периметр прямоугольника
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @return Периметр прямоугольника (2 * (a + b))
 */
double calculatePerimeter(const double a, const double b);

/**
 * @brief Точка входа в программу
 * @return Код возврата: 0 - успешное выполнение, 1 - ошибка ввода
 * @details Программа запрашивает у пользователя длину стороны (a) и коэффициент (n),
 * затем вычисляет и выводит площадь и периметр прямоугольника.
 */
int main() 
{
    cout << "Вычисление площади и периметра прямоугольника" << endl;
    cout << "Формулы:" << endl;
    cout << "1) Длина второй стороны: b = n * a / 100" << endl;
    cout << "2) Площадь: S = a * b" << endl;
    cout << "3) Периметр: P = 2 * (a + b)" << endl;
    
    double a = 0;
    double n = 0;
    
    cout << "Введите длину стороны a (в см): ";
    cin >> a;
    if (a <= 0) 
    {
        cout << "Ошибка: длина стороны должна быть положительной!" << endl;
        return 1;
    }
    
    cout << "Введите коэффициент n (в %): ";
    cin >> n;
    if (n <= 0) 
    {
        cout << "Ошибка: коэффициент должен быть положительным!" << endl;
        return 1;
    }
    
    double b = calculateSecondSide(a, n);
    double area = calculateArea(a, b);
    double perimeter = calculatePerimeter(a, b);
    
    cout << "Результаты:" << endl;
    cout << "1) Длина второй стороны (b): " << b << " см" << endl;
    cout << "2) Площадь прямоугольника: " << area << " см²" << endl;
    cout << "3) Периметр прямоугольника: " << perimeter << " см" << endl;
    
    return 0;
}

double calculateSecondSide(const double a, const double n) 
{
    return a * n / 100.0;
}

double calculateArea(const double a, const double b) 
{
    return a * b;
}

double calculatePerimeter(const double a, const double b) 
{
    return 2 * (a + b);
}