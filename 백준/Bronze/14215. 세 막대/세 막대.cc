#include <iostream>
#include <algorithm>
int main(void){
    int v[3];
    std::cin >> v[0] >> v[1] >> v[2];
    std::sort(v, v + 3);
    std::cout << (v[0] + v[1] + std::min(v[2], v[0] + v[1] - 1));
}