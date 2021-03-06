// Project01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
using namespace std;

int multiResult[4];
int sumResult[4];
int reverseResult[4];
	
int tempArray1[4];
int tempArray2[4];

int finalArray1[4];
int finalArray2[4];

int i = 0;



void reverseArray(int Array[]);
void copyArray(int aArray[], int bArray[]);

void isArraysEqual(int aArray[] = finalArray1, int bArray[] = finalArray2);

void arraysMulti(int aArray[], int bArray[]);
void arraysSum(int aArray[], int bArray[]);


int main()
{
	setlocale(LC_CTYPE, "rus");

	int xArray[4] = { 0, 1, 0, 1 };
	int yArray[4] = { 0, 0, 1, 1 };
	int zArray[4] = { 1, 0, 0, 1 };

	int xArrayReverse[4] = { 1, 0, 1, 0 };
	int yArrayReverse[4] = { 1, 1, 0, 0 };
	int zArrayReverse[4] = { 0, 1, 1, 0 };



	cout << "\n	Законы дистрибутивности пересечения относительно объединения" << endl;
	cout << "		и объединения относительно пересечения\n" << endl;

	cout << "	X && (Y || Z) = (X && Y) || (X && Z)\n" << endl;
	
	arraysSum(yArray, zArray);
	arraysMulti(yArray, sumResult);//x
	copyArray(multiResult, finalArray1);

	arraysMulti(xArray, yArray);
	copyArray(multiResult, tempArray1);
	arraysMulti(xArray, zArray);
	copyArray(multiResult, tempArray2);
	arraysSum(tempArray1, tempArray2);
	copyArray(sumResult, finalArray2);

	isArraysEqual();

	cout << "	X || (Y && Z) = (X || Y) && (X || Z)\n" << endl;

	arraysMulti(yArray, zArray);
	arraysSum(xArray, multiResult);
	copyArray(sumResult, finalArray1);

	arraysSum(xArray, yArray);
	copyArray(sumResult, tempArray1);
	arraysSum(xArray, zArray);
	copyArray(sumResult, tempArray2);
	arraysMulti(tempArray1, tempArray2);
	copyArray(multiResult, finalArray2);

	isArraysEqual();

	cout << "\n		Законы поглощения\n" << endl;

	cout << "	X || (X && Y) = X\n" << endl;

	arraysMulti(xArray, yArray);
	arraysSum(xArray, multiResult);

	copyArray(sumResult, finalArray1);
	copyArray(xArray, finalArray2);
	isArraysEqual();

	cout << "	X && (X || Y) = X\n" << endl;

	arraysSum(xArray, yArray);
	arraysMulti(xArray, sumResult);

	copyArray(multiResult, finalArray1);
	copyArray(xArray, finalArray2);

	isArraysEqual();
	

	cout << "\n		Законы склеивания\n" << endl;

	cout << "	(X && Y) || (X && !Y) = X\n" << endl;

	arraysMulti(xArray, yArray);
	copyArray(multiResult, tempArray1);
	arraysMulti(xArray, yArrayReverse);
	copyArray(multiResult, tempArray2);
	arraysSum(tempArray1, tempArray2);

	copyArray(xArray, finalArray1);
	copyArray(sumResult, finalArray2);
		
	isArraysEqual();

	cout << "	(X || Y) && (X || !Y) = X\n" << endl;

	arraysSum(xArray, yArray);
	copyArray(sumResult, tempArray1);
	arraysSum(xArray, yArrayReverse);
	copyArray(sumResult, tempArray2);
	arraysMulti(tempArray1, tempArray2);

	copyArray(xArray, finalArray1);
	copyArray(multiResult, finalArray2);

	isArraysEqual();

	cout << "\n		Законы Порецкого\n" << endl;

	cout << "	X && (!X || Y) = X && Y\n" << endl;

	arraysSum(xArrayReverse, yArray);
	arraysMulti(xArray, sumResult);
	copyArray(multiResult, finalArray1);

	arraysMulti(xArray, yArray);
	copyArray(multiResult, finalArray2);

	isArraysEqual();

	cout << "	X || (!X && Y) = X || Y\n" << endl;

	arraysMulti(xArrayReverse, yArray);
	arraysSum(xArray, multiResult);
	copyArray(sumResult, finalArray1);

	arraysSum(xArray, yArray);
	copyArray(sumResult, finalArray2);
		
	isArraysEqual();

	cout << "\n		Законы де Моргана\n" << endl;

	cout << "	!(X && Y) = !X || !Y\n" << endl;

	arraysMulti(xArray, yArray);
	reverseArray(multiResult);
	copyArray(reverseResult, finalArray1);

	arraysSum(xArrayReverse, yArrayReverse);
	copyArray(sumResult, finalArray2);

	isArraysEqual();

	cout << "	!(X || Y) = !X && !Y\n" << endl;

	arraysSum(xArray, yArray);
	reverseArray(sumResult);
	copyArray(reverseResult, finalArray1);

	arraysMulti(xArrayReverse, yArrayReverse);
	copyArray(multiResult, finalArray2);

	isArraysEqual();

	cout << "\n		Закон Двойного дополнения\n" << endl;
	
	cout << "	X >> !X >> !!X" << endl;
	for (i = 0; i < 4; i++) {
		cout << "	" << xArray[i] << " >>  " << xArrayReverse[i] << "  >>  " << xArray[i] << endl;
	}
	
	system("pause");
    return 0;
}

void copyArray(int aArray[], int bArray[]) {
	for (i = 0; i < 4; i++)	{
		bArray[i] = aArray[i];
	}
}

void isArraysEqual(int aArray[], int bArray[]) {
	int check = 0;
	for (i = 0; i < 4; i++) {
		if (aArray[i] == bArray[i]) {
			check++;
			cout << "	Элемент "<< i << ")    " << aArray[i] 
				 << " = " << bArray[i] << "    " << i << " Элемент" << endl;
		}
		else {
			cout << "	Элемент " << i << ")    " << aArray[i] 
				<< " != " << bArray[i]  << "    " << i << " Элемент" << endl;
		}
	}
	if (check == 4) {
		cout << "Законы доказан\n" << endl;
	}
	else {
		cout << "Законы не доказан\n" << endl;
	}

}
void arraysMulti(int aArray[], int bArray[]) {
	for (i = 0; i < 4; i++) {
		if (aArray[i] == 1 && bArray[i] == 1) {
			multiResult[i] = 1;
		}
		else {
			multiResult[i] = 0;
		}
	}
}

void arraysSum(int aArray[], int bArray[]) {
	for (i = 0; i < 4; i++) {
		if (aArray[i] == 1 || bArray[i] == 1) {
			sumResult[i] = 1;
		}
		else {
			sumResult[i] = 0;
		}
	}
}

void reverseArray(int Array[]) {
	for (i = 0; i < 4; i++) {
		if (Array[i] == 1)  reverseResult[i] = 0;
		else				reverseResult[i] = 1;
	}
}


