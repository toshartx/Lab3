#include <iostream>
#include <cmath>
#define pi 3.14159

double y(double);
bool RestartProgramm(void);
void printCondition(void);

int main()
{
  printCondition();
  bool flag = RestartProgramm();
  while (flag)
  {
    double accuracy = 1e-5;
    double x = 0;
    double M = 20.0;
    double H = pi / (2 * M);

    for (int i = 0;; ++i)
    {
      if (pi / 2 - x < accuracy)
      {
        break;
      }
      else
      {
        x = i * H;
        std::cout << x << " | " << y(x) << '\n';
      }
    }
    std::cout << "Точность была достигнута.\n";

    flag = RestartProgramm();
  }
  return 0;
}

double y(double x)
{
  return sin(x) - cos(x);
}

void printCondition()
{
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << "Программа считает значения y(x) = sin(x) - cos(x) на отрезке [0,pi/2] в точках x = i*H,\n";
  std::cout << "где H = pi/(2*M), M = 20.                                                       i\n";
  std::cout << "Введите '1', чтобы начать\n";
  std::cout << "------------------------------------------------------------------------------------\n";
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