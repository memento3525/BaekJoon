#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(string numbers) {

    map<string, string> _map
    { 
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };
    
    for (const auto& pair : _map)
    {
        size_t pos;
        do
        {
            pos = numbers.find(pair.first);
            if (pos != string::npos)
                numbers.replace(pos, pair.first.size(), pair.second);
        }
        while (pos != string::npos);
    }
    
    return stoll(numbers);
}