#include<iostream>
using namespace std;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int*arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr[n] = value;
	n++; //����������� ���������� ��������� � �������
	Print(arr, n);
	delete[]arr;
	arr = push_back(arr, n, value);
	Print(arr, n+1);
	delete[] arr;
	//int*arr2 = new int[n];
 
	/*for (int i = 0; i < n; i++)
	arr2[i] = arr[i];
	arr = arr2;
	arr[n] = n + 1;*/
	/*int m = (n + value);
	int*arr2 = new int[m];
	cout << typeid(arr).name() << endl;*/
	/*arr = arr2;
	delete[] arr;
	delete[]arr2;*/
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int arr[], int n, int value)
{
	//������� �������� ������ ������� ������� � ������ ������ �� 1 ������� ������
	int*buffer = new int[n + 1];
	//�������� ��� ������ �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//����� ���� ��� ������ ����������� � ����� ������, ������ ������ ��� �� �����
	delete[]arr;
	//��������� ����� ������� ������� ������� ������ �������.
	arr = buffer;
	//������ ����� ����� ����� � ����� ������ ����� �������� ��������.
	arr[n] = value;
	//����� ���������� �������� � ������, ���������� ��� ��������� ���������� �� 1.
	n++;
	//Mission complete -������� ��������. 
	return arr;
}
