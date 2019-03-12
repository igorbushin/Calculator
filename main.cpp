#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
#include <exception>
using namespace std;

bool str2num (string str, double &res)
{
    istringstream is(str);
    is >> res;
    return !is.fail() && is.eof();
}

int main()
{
    try
    {
        map< string, function <double(double, double)> > operations;
        operations["+"] = [](double a, double b) {return a + b;};
        operations["-"] = [](double a, double b) {return a - b;};
        operations["*"] = [](double a, double b) {return a * b;};
        operations["/"] = [](double a, double b) {return a / b;};
        operations["%"] = [](double a, double b) {return fmod(a, b);};
        operations["^"] = [](double a, double b) {return pow(a, b);};

        string operation, operand1, operand2;
        cin >> operand1 >> operation >> operand2;

        if(operations.count(operation) == 0) throw string("wrong operation");

        double number1, number2;
        if(!str2num(operand1, number1)) throw string("first operand is not number");
        if(!str2num(operand2, number2)) throw string("second operand is not number");

        if((operation == "/" || operation == "%") && abs(number2) < 1e-9) throw string("division by zero");

        cout << operations[operation] (number1, number2) << endl;
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
