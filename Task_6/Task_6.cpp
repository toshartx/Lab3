#include <iostream>
#include <cmath>

const long double pi = 3.14159;
const long double ln2 = 0.69314718056;

long double sinus(long double);
long double cosinus(long double);
long double logE(long double);
long double Factorial(int);
void printCondition();
bool RestartProgramm();
long double LongDoubleInput();
long double Minimum(long double, long double);

int main()
{
  printCondition();

  bool restartFlag = RestartProgramm();
  while (restartFlag)
  {
    long double x = LongDoubleInput();
    long double a = sinus(x);
    long double b = cosinus(x);
    long double c = logE(std::abs(x));
    std::cout << "         CMath    | без CMath\n";
    std::cout << "sin(x): " << std::sin(x) << " | " << a << '\n';
    std::cout << "cos(x): " << std::cos(x) << " | " << b << '\n';
    std::cout << "ln|x|:  " << std::log(std::abs(x)) << " | " << c << '\n'; 
    std::cout << "Минимальное значение среди a, b и с: " << Minimum(sinus(x), Minimum(cosinus(x), logE(x))) << '\n';

    restartFlag = RestartProgramm();
  }
  return 0;
}

void printCondition()
{
  std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Из величин a = sin(x), b = cos(x), c = ln|x| программа определяет\n";
	std::cout << "НАИМЕНЬШУЮ\n";
	std::cout << "В консоль выводится значения, посчитанные с помощью CMath | без CMath, и отдельное наименьшее\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
}

bool RestartProgramm()
{
	std::cout << "Введите 0, чтобы завершить программу\n        1, чтобы запустить программу\n";
	bool a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

long double LongDoubleInput()
{
	std::cout << "Введите число x:\n";
	long double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

long double Factorial(int x)
{
	if (x == 0 || x == 1)
	{
		return 1;
	}
	return x*Factorial(x-1);
}



long double cosinus(long double x)
{
	long double variable = x;
	while (std::abs(variable) > 2*pi)
	{
		variable /= 2;
	}
	long double result = 0;
	short sign = 1;
	long double x2 = variable*variable;
	long double PowerOfX = 1;
  for (int i = 0; i < 49; i += 2)
  {
    result += sign * PowerOfX / Factorial(i);
    sign = -sign;
		PowerOfX *= x2;
  }
	while (std::abs(variable) < std::abs(x))
	{
		result = 2*result*result - 1;
		variable *= 2;
	}
  return result;
}

long double sinus(long double x)
{
	long double variable = x;
	while (std::abs(variable) > 2*pi)
	{
		variable /= 2;
	}
	long double result = 0;
	short sign = 1;
	long double x2 = variable*variable;
	long double PowerOfX = variable;
  for (int i = 1; i < 50; i += 2)
  {
    result += sign * PowerOfX / Factorial(i);
    sign = -sign;
		PowerOfX *= x2;
  }
	long double resultcos = cosinus(variable);
	while (std::abs(variable) < std::abs(x))
	{
		result = 2*result*resultcos;
		resultcos = 2*resultcos*resultcos - 1;
		variable *= 2;
	}
  return result;
}

long double logE(long double x)
{
	long double variable = x;
	int n = 0;
	while (variable >= 2)
	{
		variable /= 2;
		++n;
	}
	long double result = 0;
	short sign = 1;
	long double PowerOfX = variable - 1;
  for (int i = 1; i < 25; i += 1)
  {
    result += sign * PowerOfX / i;
    sign = -sign;
		PowerOfX *= variable - 1;
  }
	
	return result + n*ln2;
}

long double Minimum(long double x, long double y)
{
  return x > y + 1e-10 ? y : x;
}