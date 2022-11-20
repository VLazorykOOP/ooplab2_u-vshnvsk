#include <iostream>
using namespace std;

void Shifruvanna(char S[64], unsigned short Rez[64])
{
    unsigned char c;
    unsigned short r, t, i, b, num, numB;
    short j;

    std::cin.get(S, 64);
    for (i = 0;i<64;i++) 
    {
        int k = 64, counter = 1;
        while ((k - 16) > 0)
        { 
            k = k - 16;
            counter++;
        }

        r = 0;            // 0000 0000 0000 0000
        c = S[i];         // s - 0x73 = 0111 0011
        t = c;
        num = counter;
        numB = k;
        r |= num << 3;      // 0-2
        r |= numB << 3;     // 3-5
        //t = c;

        b = 0;
        for (j = 0; j < 2; j++)    // обчислення біта парності
        {
            if (r&t) 
            {
                if (b==0) b = 1; else b = 0;
            }
                t <<= 1;
        }
        r |= b << 6;

        r |= t << 8;       //ASCII 7-14 
        //t = 1;

        for (j = 0; j < 16; j++) // обчислення біта парності
        {
            if (r&t) 
            {
                if (b==0) b = 1; else b = 0;
            }
                t <<= 1;
        }
        r |= b << 15;   
        Rez[i] = r;
    }
}

int main()
{
    char S[64];
    unsigned short Rez[64];
    unsigned short i;
    cin.get(S, 64);
    Shifruvanna(S, Rez);
    for (i = 0;i<64;i++)
    cout << hex << Rez[i] << endl;
    return 0;
}
