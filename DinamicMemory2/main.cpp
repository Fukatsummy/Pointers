#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int&n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int&n, int value, int index);
int* pop_back(int arr[], int&n);
int* pop_front(int arr[], int&n);
int* erase(int arr[], int&n, int value, int index);
int**Allocate( const int rows, const int cols);
int** clear(int** arr, const int rows, const int cols);
int**push_row_front(int** arr, int& rows, const int cols);
//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int*arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое в начало массива значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int*arr2 = new int[n + 1];
	arr2[0] = value;
	for (int i = 0; i < n + 1; i++)
	{
		arr2[i + 1] = arr[i];
	}
	n++;
	delete[] arr;
	arr = arr2;
	Print(arr, n);

	//Моя верия решения push_back
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
	int index;
	cout << "Введите значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	//delete[]arr;
	cout << "Удаляемое значение: ";
	arr = pop_back(arr, n);
	Print(arr, n);
	//delete[] arr;
	arr = pop_front(arr, n);
	Print(arr, n);
	//delete[] arr;
	cout << "Введите значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = erase(arr, n, value, index);
	Print(arr, n);
#endif DYNAMIC_MEMORY1

#ifdef DYNAMIC_MEMORY2
	int rows;//количество строк двумерного динамического массива
	int cols;//количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	
	//3) Обращение к элементам двумерного динамического массива:
	int** arr=Allocate( rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	//cout << " Введите количество: "; cin >> cols;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY2

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int&n, int value)
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
int* push_front(int arr[], int& n, int value)
{
	int*buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int&n, int value, int index)
{
	int*buffer = new int[n + 1];
	for (int i = n - 1; i >= index - 1; i--)	buffer[i + 1] = arr[i];
	for (int i = 0; i <= index - 1; i++)buffer[i] = arr[i];
	delete[]arr;
	buffer[index] = value;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int arr[], int&n)
{
	int*buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int arr[], int&n)
{
	int*buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int arr[], int&n, int value, int index)
{
	int*buffer = new int[n - 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i] = arr[i + 1];
	delete[]arr;
	buffer[index] = value;
	//arr = buffer;
	//n--;
	return arr;
}
int**Allocate(const int rows, const int cols)
{
    //1)Создаем массив указателей:
	int** arr = new int*[rows];// Вернется указатель на указатель
	//2)Cоздаем строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
int** clear(int** arr, const int rows, const int cols)
{
	//4) Удаление массива
	//4.1.Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4.2 Удаляем массив указателей
	
	return arr;
}
int**push_row_front(int** arr, int& rows, const int cols)
{
	int**buffer = new int*[rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int[cols] {};
	++rows;
	return buffer;
}