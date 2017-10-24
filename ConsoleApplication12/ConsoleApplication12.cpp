/*№18 Cформировать случайную матрицу m x n,состоящую из нулей и единиц,причём в каждом столбце число единиц равно номеру столбца.*/
#include "stdafx.h" 
#include <iostream> 
#include <time.h> 
#include <cmath> 
#include <locale> 
#include <fstream> 
using namespace std;
void MatrixInit(int **A, int M, int N)//Инициализация матрицы 
{
	int count;
	srand(time(0));
	for (int j = 0; j < N; ++j)
	{
		do
		{
			count = 0;
			for (int i = 0; i < M; ++i)
			{
				A[i][j] = 0 + rand() % (2 - 0);
				if (A[i][j] == 1)
				{
					count++;
				}
			}
		} while (j != (count - 1));//Пока количество единиц не совпадёт с номером столбца 
	}
}
void PrintMatrix(int **A, int M, int N)//Печать матрицы 
{
	cout << endl << endl;
	cout << "Матрица:" << endl;
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
		{
			if (!(j%N)) cout << endl; //Чтобы массив выглядел как массив 
			cout << A[i][j] << '\t'; //Табуляция символов 
		}
}
void DeleteMatrix(int **A, int M)//Очистка памяти от созданного двумерного массива 
{
	for (int i = 0; i<M; i++) delete[]A[i];
	delete[]A;
	A = NULL;
}
int Chislo(char *tmp, int razr)//Перевод текста в число 
{
	int temp, chislo_ = 0, dec = 10, i = 0;
	temp = pow(dec, razr);
	while (temp != 1)
	{
		chislo_ = chislo_ + (tmp[i] - '0') * temp;
		temp /= dec; ++i;
	}
	return chislo_ / dec;
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int m, n, **a, choice, i = 0, count = 0;
	string str; // буферы промежуточного хранения считываемых данных из файла 
	do
	{
		cout << " **МЕНЮ** " << endl;
		cout << "1:Чтение данных из файла " << endl;
		cout << "2:Чтение данных из консоли" << endl;
		cout << endl << endl;
		cout << "Выбор: ";
		cin >> choice;
	} while ((choice != 1) && (choice != 2));
	if (choice == 1)
	{
		ifstream fin("cppstudio.txt"); // Проверка на существование файла 

		if (!fin.is_open()) // если файл не открыт 
			cout << "Файл не может быть открыт!\n"; // сообщить об этом 
		else
		{
			while (getline(fin, str))
			{

				/* работаем число m*/
				while (str[i] != ' ')
				{
					++count; ++i;
				}
				m = Chislo(&str[0], count);

				count = 0; ++i;

				/* работаем число n*/
				while (str[i])
				{
					++count; ++i;
				}
				n = Chislo(&str[i - count], count);
				count = 0; i = 0;
			}

		}
	}
	else
	{
		cout << "Введите размеры матрицы (m>=n по условию)" << endl;
		cout << "Введите m: ";
		cin >> m;
		cout << "Введите n: ";
		cin >> n;

	}
	if (m >= n)
	{
		a = new int*[m];//создаем массив 
		for (int i = 0; i < m; i++) a[i] = new int[n];
		MatrixInit(a, m, n);
		PrintMatrix(a, m, n);
		DeleteMatrix(a, m);
		system("pause");
	}
	else
	{
		cout << "Введённые данные не соответствуют условию";
	}
}