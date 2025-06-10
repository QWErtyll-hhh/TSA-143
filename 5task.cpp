#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int getValue();

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getDouble();

/**
 * @brief Проверяет, что введенное значение удовлетворяет условию n >= 0
 * @param n Считанное значение
 */
void checkN(const int n);

/**
 * @brief Проверяет, что введенное значение удовлетворяет условию e > 0
 * @param e Считанное значение
 */
void checkE(const double e);

/**
 * @brief Вычисляет сумму первых n членов ряда ∑[(-1)^k / ((k+2)! (k+3)!)]
 * @param n Количество суммируемых членов
 * @return Значение частичной суммы ряда
 */
double sumN(const int n);

/**
 * @brief Вычисляет следующий член ряда по рекуррентной формуле
 * @param current Текущий член ряда
 * @param k Текущий индекс (номер члена)
 * @return Следующий член ряда
 */
double getNext(const double current, const int k);

/**
 * @brief Вычисляет сумму членов ряда, больших или равных заданной точности по модулю
 * @param e Требуемая точность вычислений
 * @return Значение суммы с заданной точностью
 */
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена верно
 */
int main() 
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите количество членов ряда (n >= 0): ";
    int n = getValue();
    checkN(n);
    cout << "Сумма первых " << n << " членов ряда: " << fixed << setprecision(10) << sumN(n) << endl;
    
    cout << "Введите точность e (>0): ";
    double e = getDouble();
    checkE(e);
    cout << "Сумма членов ряда с точностью " << e << ": " << sumE(e) << endl;
    
    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Ошибка ввода!" << endl;
        abort();
    }
    return value;
}

double getDouble() 
{
    double value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Ошибка ввода!" << endl;
        abort();
    }
    return value;
}

void checkE(const double e) 
{
    if (e <= 0) 
    {
        cerr << "Ошибка: e должно быть > 0!" << endl;
        abort();
    }
}

void checkN(const int n) 
{
    if (n < 0) 
    {
        cerr << "Ошибка: n должно быть >= 0!" << endl;
        abort();
    }
}

double sumN(const int n) 
{ 
    if (n == 0) return 1.0 / 12.0; // Первый член ряда (k=0): 1/(2!3!) = 1/12

    double sum = 1.0 / 12.0; // Начальное значение (k=0)
    double current = sum; 

    for (int k = 1; k <= n; k++) 
    { 
        current = getNext(current, k - 1); // k-1, так как первый член уже учтен
        sum += current;
    }
    return sum;
}

double getNext(const double current, const int k) 
{
    return -current * (k + 1) / ((k + 4) * (k + 5));
}

double sumE(const double e) 
{
    double sum = 0.0;
    double current = 1.0 / 12.0; // Первый член ряда (k=0)
    int k = 0;

    while (abs(current) >= e)
    {
        sum += current;
        k++;
        current = getNext(current, k - 1);     }
    return sum;
}