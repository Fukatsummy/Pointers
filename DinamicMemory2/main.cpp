#include<iostream>
using namespace std;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int n, int value);
//int* push_front(int arr[], int n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int*arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n+1);
	delete[] arr;
	cout << "Введите добавляемое в начало массива значение: "; cin >> value;
	/*arr = push_front(arr, n, value);
	Print(arr, n + 1);
	delete[] arr;*/
	//arr = push_front(arr, n, value);
	int*arr2 = new int[n + 1];
	arr2[n] = value;
	for (int i = 1; i < n+1; i++)
	{
		arr2[i+1] = arr[i];
	}
	//n++;
	delete[] arr;
	arr = arr2;
	Print(arr, n+1);
	//arr2 = nullptr;

	//Моя верия решения
	/*int*arr2 = new int[n+1];
	  for (int i = 0; i < n; i++)
	{
	  arr2[i] = arr[i];
	}
	  delete[]arr;
	  arr = arr2;
	  arr2=nullptr;
	  int value;
	  cout << "Введите добавляемое значение: "; cin >> value;
	  arr[n]=value;
	  n++;
	*/
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
	//Создаем буферный массив нужного размера в данном случае на 1 элемент больше
	int*buffer = new int[n + 1];
	//Копируем все данные из исходного массива в буферный
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//После того как данные скопированы в новый массив, старый массив уже не нужен
	delete[]arr;
	//Подменяем адрес старого массива адресом нового массива.
	arr = buffer;
	//Только после всего этого в новый массив можно добавить значение.
	arr[n] = value;
	//После добавления элемента в массив, количество его элементов увеличится на 1.
	n++;
	//Mission complete -элемент добавлен. 
	return arr;
}
//int* push_front(int arr[], int n, int value)
//{
//	int*buffer2 = new int[n + 1];
//	for (int i = 1; i < n; i++)buffer2[i] = arr[i-1];
//	delete[]arr;
//	arr = buffer2;
//	//arr[n] = value;
//	n++;
//	return arr;
//}
