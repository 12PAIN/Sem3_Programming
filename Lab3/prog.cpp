#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <chrono>
using namespace std;

int charToNum(char);
bool DimArr(int&);
bool GetFile(int*&);
void allinfo(int&, int, int*&);
void sortinfo(int&, int, int*&);

class datetime
{
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;

public:
	
	datetime() {}

	datetime(int& i, int*& arr) {
		day = arr[i];
		month = arr[i + 1];
		year = arr[i + 2];
		hour = arr[i + 3];
		minute = arr[i + 4];
		second = arr[i + 5];
	}

	~datetime() {}

	void Out();
	void NextDate(int& i, int n, int*& arr, int key);
	void PrevDate(int& i, int n, int*& arr);
	void SysTime();
};

void datetime::SysTime()
{
	auto const time = chrono::system_clock::now(); // Получаем системное время в числе
	time_t seconds = chrono::system_clock::to_time_t(time); // Системное время в секундах

	std::stringstream ss;
	ss << ctime(&seconds);
	std::string sysDate = ss.str();

	if (charToNum(sysDate[8]) != 404) day = charToNum(sysDate[8]);
	else day = 0;
	day = day * 10 + charToNum(sysDate[9]);

	if (sysDate[4] == 'J')
	{
		if (sysDate[5] == 'a') month = 1;
		else
		{
			if (sysDate[6] == 'n') month = 6;
			else month = 7;
		}
	}
	else if (sysDate[4] == 'F') month = 2;
	else if (sysDate[4] == 'M')
	{
		if (sysDate[6] == 'r') month = 3;
		else month = 5;
	}
	else if (sysDate[4] == 'A')
	{
		if (sysDate[5] == 'p') month = 4;
		else month = 8;
	}
	else if (sysDate[4] == 'S') month = 9;
	else if (sysDate[4] == 'O') month = 10;
	else if (sysDate[4] == 'N') month = 11;
	else if (sysDate[4] == 'D') month = 12;

	year = charToNum(sysDate[20]) * 10;
	year = (year + charToNum(sysDate[21])) * 10;
	year = (year + charToNum(sysDate[22])) * 10;
	year += charToNum(sysDate[23]);

	hour = charToNum(sysDate[11]) * 10;
	hour += charToNum(sysDate[12]);

	minute = charToNum(sysDate[14]) * 10;
	minute += charToNum(sysDate[15]);

	second = charToNum(sysDate[17]) * 10;
	second += charToNum(sysDate[18]);
}

void datetime::Out() //Вывод данных из объекта
{
	cout << "Date: " << day << "." << month << "." << year << " Time: " << hour << ":" << minute << ":" << second;
}

void datetime::NextDate(int& i, int n, int*& arr, int key)
{


	if (key == 1)
	{
		i = i + 6;
		if (i < n)
		{
			cout << " - ";
			datetime temp(i, arr);
			temp.Out();
		}
	}

	if (key == 2)
	{
		datetime temp(i, arr);
		i = i + 6;
		if (i < n)
		{
			datetime temp1(i, arr);
			if (temp.year < year || temp.year > year)
			{
				temp.Out();
				cout << " - ";
				temp1.Out();
				cout << endl;
			}
		}
	}
}

void datetime::PrevDate(int& i, int n, int*& arr)
{
	if (i - 6 != 0)
	{
		i = i - 12;
		cout << " - ";
		datetime temp(i, arr);
		i = i + 12;
		temp.Out();
	}
}

int main()
{
	//Создание объектов под данные
	

	int n = 0, i = 0;

	//Подготовка места под данные
	DimArr(n);

	int* arr = new int[n];

	GetFile(arr); // Получение данных

	int key = 0; //Сис. перем. выбор кнопки

	do
	{
		cout << "1) Info output" << endl
			<< "2) Op. 2 Info output" << endl
			<< "3) System Date" << endl
			<< "0) Exit" << endl;
		cout << endl << "Select an action: ";
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1: {
			i = 0;
			allinfo(i, n, arr);
			cout << endl;
			break;
		}

		case 2: {
			i = 0;
			sortinfo(i, n, arr);
			cout << endl;
			break;
		}

		case 3: {
			datetime data;
			data.SysTime();
			data.Out();
			cout << endl;
			break;
		}

		default:
			if (key != 0)
			{
				cout << "There is no such action !" << endl << endl;
			}
			break;
		}
	} while (key != 0);
	delete[] arr;
}

int charToNum(char str)
{
	if (str == '0') return 0;
	else if (str == '1') return 1;
	else if (str == '2') return 2;
	else if (str == '3') return 3;
	else if (str == '4') return 4;
	else if (str == '5') return 5;
	else if (str == '6') return 6;
	else if (str == '7') return 7;
	else if (str == '8') return 8;
	else if (str == '9') return 9;

	return 404;
}

void allinfo(int& i, int n, int*& arr)
{

	while (i < n)
	{
		//Создание объектов дат
		datetime data(i, arr);
		data.Out(); //вывод

		data.NextDate(i, n, arr, 1);
		data.PrevDate(i, n, arr);
		cout << endl;
	}
}

void sortinfo(int& i, int n, int*& arr)
{
	datetime data;
	while (i < n)
	{
		data.NextDate(i, n, arr, 2);
	}
}

bool DimArr(int& n) // Подсчёт файлов
{
	//datetime data;
	int temp;
	ifstream F("Date.txt"); //Открытие файла
	if (!F)
	{
		cout << "Cant find file" << endl;
		return false;
	}
	while (F >> temp)
	{
		n++;
	}
	F.close();
	return true; // Подтверждение существования файла и самого массива данных
}

bool GetFile(int*& arr) // Ф-ция получения данных из файла
{
	//datetime data;
	int temp, i = 0;
	ifstream F("Date.txt");
	if (!F)
	{
		cout << "Cant find file" << endl;
		return false;
	}
	while (F >> temp)
	{
		arr[i] = temp;
		i++;
	}
	F.close();
	return true;
}