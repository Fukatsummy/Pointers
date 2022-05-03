#include<iostream>
using namespace std;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n=10;
	/*int a = 0;
	int b = 0;
	int*even=new int[a];
	int*odd=new int[b];*/
	//cout << "¬ведите размер массива: "; cin >> n;
	int*arr = new int[n];
	cout << typeid(arr).name() << endl;//
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr[n] = value;
	n++;
	Print(arr, n);
	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	cout << sizeof(int) << endl;*/
	delete[] arr;
	
	//delete[] even;
	//delete[] odd;
	//for (int i = 0; i < n; i++)
	//{
	//	*(arr+i)=rand()% 100;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << tab;
	//	//cout << arr + i << endl;
	//}
	//cout << endl;
	/*for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[a] = arr[i];
			even++;
		}
		else
		{
			odd[b] = arr[i];
			odd++;
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
		cout << even[i] << endl;
	for (int i = 0; i < b; i++)
		cout << odd[i] << endl;*/
	/*for (int i = 0; i < n; i++)	
	{
		if (arr[i] % 2 == 0)
			even[n] = arr[i];
		
	}*/
	//for (int i = 0; i <= even; i++)
	//{
	//	int n = arr[i];
	//	if (n%2 == 0)
	//	{
	//		for (int j = i - 1; j >= 0 && arr[j]>n ; --j)
	//		{
	//			arr[j + 1] = arr[j];
	//		}
	//		//arr[ j + 1] = n;
	//	}
	//}
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr+i)=rand() % 100;
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