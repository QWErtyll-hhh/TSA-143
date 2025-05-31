#include <iostream>
#include <cmath>
using namespace std;

/**
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возращает вычесленное значение
 */
double geta(const double x, const double y, const double z );

/**
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возращает вычесленное значение
 */

 double getb(const double x, const double y, const double z);
/**
 *@return - возращает 0 если программа выполнена корректно
 */
int main()

{
  const double x = 0.78;
  const double y = 1.24;    
  const double z = 0.5;
    cout<<"a = "<<geta(x,y,z)<<endl;
    cout<<"b = "<<getb(x,y,z);
    return 0;
}

double geta(const double x, const double y, const double z )
{
    return 2 * pow(z, x)/sqrt(pow(y, x)*pow(cos(x + y), 2))-3*z;
}

double getb(const double x, const double y, const double z)
{
    return x * exp(sqrt(z)) * cos(pow(x, 2) / y * z);
}
