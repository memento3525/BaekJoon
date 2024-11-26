#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    
    stringstream ss(binomial + " ");
    string splited[3]; 
    for (int i = 0; i < 3; ++i)
    {
        std::getline(ss, splited[i], ' ');
    }
    
    int a = stoi(splited[0]);
    string op = splited[1];    
    int b = stoi(splited[2]);

    if (op == "+")      return a + b;
    else if (op == "-") return a - b;
    else                return a * b;
}