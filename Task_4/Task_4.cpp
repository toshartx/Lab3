#include <iostream>
#include <cmath>

bool RestartProgramm();
int PositiveIntInput();
double DoubleInput();
void printCondition();
double S(double, int);
double cmathLog(double);

int main()
{
	printCondition();
	bool flag = RestartProgramm();
	while (flag)
	{
		std::cout << "Введите число членов ряда (n) на которых будет посчитана функция: ";
		int n = PositiveIntInput();
		std::cout << "Введите количество чисел, на которых будет подсчитана функция: ";
		int numberOfCalculate = PositiveIntInput();
		double argument;
		for (int i = 1; i <= numberOfCalculate; ++i)
		{
			argument = DoubleInput();
			std::cout << "My ln: " << S(argument, n) << "\t" << "Cmath ln: " << cmathLog(argument) << "\n";
		}
		flag = RestartProgramm();
		return 0;
	}
}

void printCondition()
{
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Программа запрашивает количество членов ряда (n) и количество чисел, на которых будет подсчитана функция\n";
	std::cout << "         2\n";
	std::cout << "y = -ln(x - 2x + 2) при помощи: 1) ряда, 2) стандартных математических методов C++\n";
	std::cout << "Затем программа запросит по числу для которых будет выводить соответствующие значения\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
}

bool RestartProgramm()
{
	std::cout << "Введите 0, чтобы завершить программу\n        1, чтобы запустить программу\n";
	bool a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

int PositiveIntInput()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Некорректный ввод, повторите попытку: \n";
	}
	return a;
}

double DoubleInput()
{
	double a;
	std::cout << "Введите число из отрезка [0.1 , 1]: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0.1 || a > 1)
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Некорректный ввод, повторите попытку: \n";
	}
	return a;
}

double S(double x, int n)
{
	double result = 0;
	double Member;
	double Sign = 1;
	for (int i = 1; i <= n; ++i)
	{
		Sign *= -1;
		Member = Sign * pow(1 - x, 2 * i) / i;
		result += Member;
	}
	return result;
}

double cmathLog(double x)
{
	return -log(2 - 2 * x + x * x);
}
