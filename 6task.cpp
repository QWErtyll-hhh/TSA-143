#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

enum FillMode { RANDOM_FILL = 1, MANUAL_FILL = 2 };

/**
 * @brief Безопасное чтение целого числа с клавиатуры
 * @return Введенное целое число
 * @throws abort() при некорректном вводе
 */
int getValue();

/**
 * @brief Получение и проверка размера массива
 * @return Размер массива (size_t)
 * @throws abort() если размер <= 0
 */
size_t getSize();

/**
 * @brief Проверка корректности размера массива
 * @param n Проверяемый размер массива
 * @throws abort() если n <= 0
 */
void checkN(const int n);

/**
 * @brief Заполнение массива значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 * @throws abort() при неверном выборе режима или выходе за диапазон
 */
void fillArray(int* arr, const size_t n);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив (константный)
 * @param n Размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Находит сумму элементов с нечетными значениями
 * @param arr Указатель на массив (константный)
 * @param n Размер массива
 * @return Сумма нечетных элементов
 */
int sumOddValues(const int* arr, const size_t n);

/**
 * @brief Выводит индексы элементов, больших заданного числа A
 * @param arr Указатель на массив (константный)
 * @param n Размер массива
 * @param A Заданное число для сравнения
 */
void printIndicesGreaterThanA(const int* arr, const size_t n, const int A);

/**
 * @brief Находит максимальный отрицательный элемент в массиве
 * @param arr Указатель на массив (константный)
 * @param n Размер массива
 * @return Максимальный отрицательный элемент или 0, если таких нет
 */
int findMaxNegative(const int* arr, const size_t n);

/**
 * @brief Заменяет второй элемент массива на максимальный отрицательный
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void replaceSecondWithMaxNegative(int* arr, const size_t n);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    size_t n = getSize();
    int* arr = new int[n];

    fillArray(arr, n);

    cout << "Original array: ";
    printArray(arr, n);

    // Задание 1: Сумма нечетных элементов
    int oddSum = sumOddValues(arr, n);
    cout << "Sum of odd elements: " << oddSum << endl;

    // Задание 2: Индексы элементов > A
    cout << "Enter A for task 2: ";
    int A = getValue();
    printIndicesGreaterThanA(arr, n, A);

    // Задание 3: Замена второго элемента
    int* copyArr = new int[n];
    for (size_t i = 0; i < n; i++) copyArr[i] = arr[i];
    replaceSecondWithMaxNegative(copyArr, n);
    cout << "Array after replacing second element with max negative: ";
    printArray(copyArr, n);

    // Освобождение памяти
    delete[] arr;
    delete[] copyArr;
    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Input error!" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    cout << "Enter array size: ";
    int n = getValue();
    checkN(n);
    return static_cast<size_t>(n);
}

void checkN(const int n)
{
    if (n <= 0) 
    {
        cerr << "Error: array size must be positive!" << endl;
        abort();
    }
}

void fillArray(int* arr, const size_t n)
{
    cout << "Choose input method (1 - random, 2 - manual): ";
    int method = getValue();
    
    switch (method) {
        case RANDOM_FILL:
            for (size_t i = 0; i < n; i++) 
            {
                arr[i] = rand() % 21 - 10; 
            }
            break;
            
        case MANUAL_FILL:
            cout << "Enter " << n << " integers in range [-10, 10]:" << endl;
            for (size_t i = 0; i < n; i++) 
            {
                arr[i] = getValue();
                if (arr[i] < -10 || arr[i] > 10) 
                {
                    cerr << "Error: value out of range [-10, 10]!" << endl;
                    abort();
                }
            }
            break;
            
        default:
            cerr << "Error: invalid input method!" << endl;
            abort();
    }
}

void printArray(const int* arr, const size_t n)
{
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOddValues(const int* arr, const size_t n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void printIndicesGreaterThanA(const int* arr, const size_t n, const int A)
{
    cout << "Indices of elements > " << A << ": ";
    bool found = false;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] > A) 
        {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "none";
    cout << endl;
}

int findMaxNegative(const int* arr, const size_t n)
{
    int maxNeg = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] < 0 && (maxNeg == 0 || arr[i] > maxNeg)) 
        {
            maxNeg = arr[i];
        }
    }
    return maxNeg;
}

void replaceSecondWithMaxNegative(int* arr, const size_t n)
{
    if (n < 2) 
    {
        cerr << "Error: array too small for this operation!" << endl;
        return;
    }

    int maxNeg = findMaxNegative(arr, n);
    if (maxNeg == 0) 
    {
        cout << "No negative elements found, second element unchanged." << endl;
    } else {
        arr[1] = maxNeg;
    }
}
