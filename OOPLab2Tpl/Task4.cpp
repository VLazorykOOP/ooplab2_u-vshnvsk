#include <iostream>
#include <fstream>
#include <clocale>
#include <string.h>

using namespace std;

void binaryView(char a) {
	int b[8];

	memset(b, 0, sizeof(b));

	b[0] = a & 0b10000000 ? 1 : 0;
	b[1] = a & 0b01000000 ? 1 : 0;
	b[2] = a & 0b00100000 ? 1 : 0;
	b[3] = a & 0b00010000 ? 1 : 0;
	b[4] = a & 0b00001000 ? 1 : 0;
	b[5] = a & 0b00000100 ? 1 : 0;
	b[6] = a & 0b00000010 ? 1 : 0;
	b[7] = a & 0b00000001 ? 1 : 0;

	for (int i = 0; i < 8; i++) {
		cout << b[i];
	}
	cout << "\n";
}

int main() {

	int a, b, c, d, e;
	char k[3]; 
	k[0] = 0; 
	k[1] = 0; 
	k[2] = 0;

	do {
		cout << "\nEnter a number a: ";
		cin >> a;
	} while ((a < 0) || (a > 12));

	do {
		cout << "\nEnter a number b: ";
		cin >> b;
	} while ((b < 0) && (b > 9));

	do {
		cout << "\nEnter a number c: ";
		cin >> c;
	} while ((c < 1940) && (c > 2065));

	do {
		cout << "\nEnter a number d: ";
		cin >> d;
	} while ((d < 0) && (d > 31));

	do {
		cout << "\nEnter a number e: ";
		cin >> e;
	} while ((e < 0) && (e > 1));
	
	
	k[0] = a << 4;
	k[0] |= (b & 0b00001111);

	k[1] = e << 7;
	k[1] |= ((c-1940) & 0b01111111);

    k[2] = d << 3;


	int a1 = (k[0] & 0b11110000) >> 4;
	int b1 = (k[0] & 0b00001111);
	int c1 = (k[1] & 0b01111111);
	int d1 = (k[2] & 0b11111000) >> 3;
	int e1 = (k[1] & 0b10000000) >> 7;

	cout << "    a = " << a1 <<  " binary a = ";
	binaryView(a1);
	cout << "    b = " << b1 <<  " binary b = ";
	binaryView(b1);
	cout << "    c = " << c1 + 1940 << " binary c = ";
	binaryView(c1);
	cout << "    d = " << d1 << " binary d = ";
	binaryView(d1);
	cout << "    e = " << e1 << " binary e = ";
	binaryView(e1);

	return 0;
}