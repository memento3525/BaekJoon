#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string myString, string pat) {
    
    std::transform(myString.begin(), myString.end(), myString.begin(), [](char a){ return std::tolower(a); });    
    std::transform(pat.begin(), pat.end(), pat.begin(), [](char a){ return std::tolower(a); });
    
    size_t pos = myString.find(pat);
    return pos != std::string::npos;
}