/*�18 C����������� ��������� ������� m x n,��������� �� ����� � ������,������ � ������ ������� ����� ������ ����� ������ �������.*/
#include "stdafx.h" 
#include <iostream> 
#include <time.h> 
#include <cmath> 
#include <locale> 
#include <fstream> 
using namespace std;
void MatrixInit(int **A, int M, int N)//������������� ������� 
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
		} while (j != (count - 1));//���� ���������� ������ �� ������� � ������� ������� 
	}
}
void PrintMatrix(int **A, int M, int N)//������ ������� 
{
	cout << endl << endl;
	cout << "�������:" << endl;
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
		{
			if (!(j%N)) cout << endl; //����� ������ �������� ��� ������ 
			cout << A[i][j] << '\t'; //��������� �������� 
		}
}
void DeleteMatrix(int **A, int M)//������� ������ �� ���������� ���������� ������� 
{
	for (int i = 0; i<M; i++) delete[]A[i];
	delete[]A;
	A = NULL;
}
int Chislo(char *tmp, int razr)//������� ������ � ����� 
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
	string str; // ������ �������������� �������� ����������� ������ �� ����� 
	do
	{
		cout << " **����** " << endl;
		cout << "1:������ ������ �� ����� " << endl;
		cout << "2:������ ������ �� �������" << endl;
		cout << endl << endl;
		cout << "�����: ";
		cin >> choice;
	} while ((choice != 1) && (choice != 2));
	if (choice == 1)
	{
		ifstream fin("cppstudio.txt"); // �������� �� ������������� ����� 

		if (!fin.is_open()) // ���� ���� �� ������ 
			cout << "���� �� ����� ���� ������!\n"; // �������� �� ���� 
		else
		{
			while (getline(fin, str))
			{

				/* �������� ����� m*/
				while (str[i] != ' ')
				{
					++count; ++i;
				}
				m = Chislo(&str[0], count);

				count = 0; ++i;

				/* �������� ����� n*/
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
		cout << "������� ������� ������� (m>=n �� �������)" << endl;
		cout << "������� m: ";
		cin >> m;
		cout << "������� n: ";
		cin >> n;

	}
	if (m >= n)
	{
		a = new int*[m];//������� ������ 
		for (int i = 0; i < m; i++) a[i] = new int[n];
		MatrixInit(a, m, n);
		PrintMatrix(a, m, n);
		DeleteMatrix(a, m);
		system("pause");
	}
	else
	{
		cout << "�������� ������ �� ������������� �������";
	}
}