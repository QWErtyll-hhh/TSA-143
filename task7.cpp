#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Константы для выбора режима заполнения
enum {RANDOM = 5, MANUAL = 6};

/**
 * @brief Считывает целое число с клавиатуры
 * @return Введенное число
 * @throws abort() при некорректном вводе
 */
int getValue();

/**
 * @brief Получает и проверяет размер массива
 * @return Размер массива (size_t)
 * @throws abort() если размер <= 0
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемый размер
 * @throws abort() если n <= 0
 */
void checkN(const int n);

/**
 * @brief Создает новый двумерный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Указатель на созданный массив
 */
int** getNewArray(const size_t m, const size_t n);

/**
 * @brief Выводит массив на экран
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив вручную
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заменяет максимальный элемент в каждой строке
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void changeMaxElementInLine(int** array, const size_t m, const size_t n);

/**
 * @brief Находит индекс максимального элемента в строке
 * @param array Указатель на строку массива
 * @param n Количество элементов в строке
 * @return Индекс максимального элемента
 */
size_t getMaxIndexInLine(int* array, const size_t n);

/**
 * @brief Освобождает память, занятую массивом
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void deleteArray(int** array, const size_t m, const size_t n);

/**
 * @brief Создает копию массива
 * @param array Указатель на исходный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Указатель на новый массив-копию
 */
int** copyArray(int** array, const size_t m, const size_t n);

/**
 * @brief Подсчитывает количество минимальных отрицательных элементов
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Количество минимальных отрицательных элементов
 */
int getCountOfMinNegative(int** array, const size_t m, const size_t n);

/**
 * @brief Добавляет новые столбцы в массив
 * @param array Указатель на исходный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param newarray Указатель на результирующий массив
 */
void addNewColumns(int** array, const size_t m, const size_t n, int** newarray);

/**
 * @brief Находит минимальный отрицательный элемент в массиве
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Значение минимального отрицательного элемента
 */
int findMinNegative(int** array, const size_t m, const size_t n);

/**
 * @brief Находит первый отрицательный элемент в массиве
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Значение первого отрицательного элемента
 * @throws abort() если отрицательных элементов нет
 */
int findFirstNegative(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив случайными числами
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param start Нижняя граница диапазона
 * @param end Верхняя граница диапазона
 */
void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

int main()
{
    cout << "Enter m: ";
    size_t m = getSize();
    cout << "Enter n: ";
    size_t n = getSize();
    
    int** array = getNewArray(m, n);
    
    cout << "Enter the way to fill array: " << (int)MANUAL <<
        " to fill manually, " << (int)RANDOM << " to fill randomly: ";
    int choice = getValue();
    int start = 0;
    int end = 0;
    
    switch (choice)
    {    
        case RANDOM:
            cout << "Enter start: ";
            start = getValue();
            cout << "Enter end: ";
            end = getValue();
            fillRandom(array, m, n, start, end);
            break;
        case MANUAL:
            fillArray(array, m, n);
            break;
        default:
            cout << "Error" << endl;
            return 1;
    }
    
    printArray(array, m, n);
    cout << endl;
    
    int** arrayCopy = copyArray(array, m, n);
    changeMaxElementInLine(arrayCopy, m, n);
    printArray(arrayCopy, m, n);
    deleteArray(arrayCopy, m, n);
    
    size_t newn = n + getCountOfMinNegative(array, m, n);
    int** resultarray = getNewArray(m, newn);
    addNewColumns(array, m, n, resultarray);
    printArray(resultarray, m, newn);
    
    deleteArray(resultarray, m, newn);
    deleteArray(array, m, n);
    
    return 0;
}

// Реализация функций

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end)
{
    srand(time(0));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Error" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error" << endl;
        abort();
    }
}

int** getNewArray(const size_t m, const size_t n)
{
    int** array = new int*[m];
    for (size_t i = 0; i < m; i++)
    {
        array[i] = new int[n];
    }
    return array;
}

void printArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << "Enter array[" << i << "," << j << "] = ";
            array[i][j] = getValue();
        }
    }
}

size_t getMaxIndexInLine(int* array, const size_t n)
{
    size_t maxIndex = 0; 
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void changeMaxElementInLine(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        size_t maxIndex = getMaxIndexInLine(array[i], n);
        array[i][maxIndex] *= 5;
    }
}

int** copyArray(int** array, const size_t m, const size_t n)
{
    int** result = getNewArray(m, n);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            result[i][j] = array[i][j];
        }
    }
    return result;
}

void deleteArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

int findFirstNegative(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] < 0)
            {
                return array[i][j];
            }
        }
    }
    cout << "No negative elements" << endl;
    abort();
}

int findMinNegative(int** array, const size_t m, const size_t n)
{
    int minNegative = findFirstNegative(array, m, n);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] < minNegative)
            {
                minNegative = array[i][j];
            }
        }
    }
    return minNegative;
}

void addNewColumns(int** array, const size_t m, const size_t n, int** newarray)
{
    int minNegative = findMinNegative(array, m, n);
    size_t newj = 0;
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            newarray[i][newj] = array[i][j];
        }
        for (size_t i = 0; i < m; i++)
        {
            if (array[i][j] == minNegative)
            {
                for (size_t k = 0; k < m; k++)
                {
                    newarray[k][newj + 1] = 0;
                }
                newj++;
                break;
            }
        }
        newj++;
    }
}

int getCountOfMinNegative(int** array, const size_t m, const size_t n)
{
    int result = 0;
    int minNegative = findMinNegative(array, m, n);
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            if (array[i][j] == minNegative)
            {
                result++;
                break;
            }
        }
    }
    return result;
}
