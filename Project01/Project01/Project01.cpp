// Project01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	int i = 0;
	int check = 0;

	int xArray[4] = { 0, 1, 0, 1 };
	int yArray[4] = { 0, 0, 1, 1 };
	int zArray[4] = { 1, 1, 0, 0 };

	int firstRArray[4];
	int secondRArray[4];
	int finalRArray[4];

	for (i = 0; i < 4; i++) {
		if (xArray[i] == 1 && yArray[i] == 1) {
			firstRArray[i] = 1;
		} 
		else {
			firstRArray[i] = 0;
		}
	}

	for (i = 0; i < 4; i++) {
		if (xArray[i] == 1 || firstRArray[i] == 1) {
			finalRArray[i] = 1;
		}
		else {
			finalRArray[i] = 0;
		}
	}
	

	for (i = 0; i < 4; i++) {
		if (finalRArray[i] == xArray[i]) {
			check++;
			cout << finalRArray[i] << " = " << xArray[i] << endl;
		}
		else {
			cout << finalRArray[i] << " != " << xArray[i] << endl;
		}
	}

	if (check == 4) {
		cout << /*"Закон поглощения соблюдается"*/"Succes" << endl;
	}
	else
	{
		cout << /*"Закон поглощения не соблюден"*/"Error" << endl;
	}


	cout << "Hi" << endl;
	system("pause");
    return 0;
}

