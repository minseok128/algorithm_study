#include <iostream>
using namespace std;

int main()
{
	cout.tie(0);
	cout << "1999\n";
	for (int i = 1; i < 1000; i++)
		cout << "1 ";
	for (int i = 0; i < 1000; i++)
		cout << "1000 ";
}