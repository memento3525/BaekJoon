#include <string>
#include <vector>
#include <sstream>

using namespace std;

long solution(string my_string) {
    
    stringstream ss(my_string);
    
    long num1, num2;
    char c;
    ss >> num1;
    
    while (ss >> c)
    {
        ss >> num2;
        
        if (c == '+')
            num1 += num2;
        else
            num1 -= num2;
    }
        
    return num1;
}