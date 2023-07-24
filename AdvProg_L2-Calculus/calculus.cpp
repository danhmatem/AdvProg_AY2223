#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    int i = 1;
    double result = 1.0;
    double temp = 1.0;

    while (std::abs(temp) >= 0.0001) {
        temp *= -x * x / ((2 * i) * (2 * i - 1));
        result += temp;
        i++;
    }
    
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    int i = 1;
    int result = x;
    int temp = x;
    while (std::abs(temp) >= 0.0001){
        temp *= -x * x / ((2 * i + 1) * (2 * i));
        result += temp;
        i ++;
    }
    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double guess = x;
    double error = guess * guess - x;

    while (std::abs(error) >= 0.0001) {
        guess = guess - error / (2.0 * guess);
        error = guess * guess - x ;
    }
    
    return guess;   
}