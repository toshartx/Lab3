#include <iostream>
#include <cmath>

bool RestartProgramm(void);
void printCondition(void);

int main()
{
  printCondition();
  bool flag = RestartProgramm();

  while (flag)
  {
    double accuracy = 1e-3;
    double d;
    int counter = 1;
    double sum = 0;
    do
    {
      d = 1.0 / pow(2, counter) + 1.0 / pow(3, counter);
      sum += d;
      ++counter;
    } while (d >= accuracy);

    std::cout << "Сумма ряда: " << sum << '\n';

    flag = RestartProgramm();
  }
  return 0;
}

bool RestartProgramm(void)
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

void printCondition()
{
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << "                                               -3                         -n  -n\n";
  std::cout << "Программа считает сумму ряда с точностью ε = 10, общий член которого d = 2 + 3 \n";
  std::cout << "------------------------------------------------------------------------------------\n";
}