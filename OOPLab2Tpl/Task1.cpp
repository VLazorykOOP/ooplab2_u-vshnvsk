#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main()
{
    int a, b, c, d, x, y;
    std::cout << "Enter numbers: a, b, c, d: \n";
    std::cin >> a >> b >> c >> d;
    x = (17*a + 312*c)/32 - 120*b + 127*d;
    y = (((a<<4) + a + (c<<8) + (c<<5) + (c<<4) + (c<<3))>>5) - (b<<7) + (b<<3) + (d<<7) - d;
    std::cout << x << endl;
    std::cout << y << endl;
    return 0;
}