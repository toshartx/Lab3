#include <iostream>
#include <cmath>

bool RestartProgramm();
int PositiveIntInput();
double DoubleInput();
void printCondition();
double func(double);

int main()
{
  printCondition();

  bool restartFlag = RestartProgramm();
  while (restartFlag)
  {
    double left = -1;
    double right = 1;
    std::cout << "Введите количество частей, на которые нужно разбить отрезок: ";
    int numberOfParts = PositiveIntInput();
    double step = (right - left) / numberOfParts;
    double minResult = func(left), minArgument = left;
    double newResult;
    for (int i = 0; i < numberOfParts; ++i)
    {
      newResult = func(left + step);
      if (std::abs(newResult) < std::abs(minResult))
      {
        minResult = newResult;
        minArgument = left + step;
      }
      left += step;
    }
    std::cout << "Минимальное значение функции по модулю: " << minResult << " - достигается при x = "<< minArgument << '\n';

    restartFlag = RestartProgramm();
  }
  return 0;
}

void printCondition()
{
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "                                                                 2\n";
	std::cout << "Необходимо приближенно найти корень уравнения sin(x)+tg(x)-1/(1+x)\n";
	std::cout << "на промежутке [-1; 1]\n";
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

int PositiveIntInput() 
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
    std::cin.clear();
    while (std::cin.get() != '\n');
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
    while (std::cin.get() != '\n');
    std::cout << "Некорректный ввод, повторите попытку: \n";
	}
	return a;
}

double func(double x)
{
  return std::sin(x) + std::tan(x) - double(1/(1+x*x));
}