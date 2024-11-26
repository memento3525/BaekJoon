#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    
    string newPat;
    for (const char& c : pat)
    {
        if (c == 'A')
            newPat.push_back('B');
        else if (c == 'B')
            newPat.push_back('A');
        else
            newPat.push_back(c);
    }
    
    size_t pos = myString.find(newPat);
    return pos != std::string::npos ? 1 : 0;
}