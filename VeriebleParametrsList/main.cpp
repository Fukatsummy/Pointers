#include<iostream>
#include<stdarg.h>
using namespace std;

//int sum(int a, int b);
int sum(int count, int number, ...); //снимает ответственность с компитятора
int product(int number...);
void print(int value...);

void main()
{
	setlocale(LC_ALL, "");
	cout << sum(5,3, 5,8,13,21) << endl;
	cout << "Произведение: " << product(3,5,8,13,21,0) << endl;
	print(3, 5, 8, 13, 21, 0);
}

//int sum(int a, int b)
//{
//	return a + b;
//}
int sum(int count, int number, ...)
{
	//count - количество параметров в списке аргументов
	// number - первое слагаемое
	int sum = 0;
	int* p_number = &number; //получаем адрес первого слагаемого
	for (int i = 0; i < count; i++)
	{
		//sum += *p_number++;
		//p_number++;
		sum += *(&number + i);
	}
	return sum;
}
int product(int number...)
{
	int product = 1;
	for (int* p_number = &number; *p_number != 0; p_number++)
	{
		product *= *p_number;//умножение\\ ++ переход на новый элемент
	}
	return product;
}
void print(int value...)
{
	va_list list;
	va_start(list,value);//определяет начало списка аргументов
	for (int i = va_arg(list, int);i != 0; i=va_arg(list,int))
	{
		cout << i << "\t";
	}
	va_end(list);
}
