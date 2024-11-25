#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    size_t pos = myString.rfind(pat);
    return string(myString.begin(), myString.begin() + pos + pat.size());
}