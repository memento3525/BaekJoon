#include <stdio.h>
#include <ctime>

using namespace std;

int main(void)
{
    time_t timer = time(0);
    struct tm* t = localtime(&timer);

    printf("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}