#include <iostream>

bool RestartProgramm(void);
void printCondition(void);

int main()
{
	printCondition();
  bool flag = RestartProgramm();
  
  while (flag)
  {
      double N = 0;
      double a, b;
      int i = 1;

      while (i <= 30)
      {
      	if (i % 2 != 0)
      	{
      		a = i;
      		b = i * i;
      	}
      	else
      	{
      		a = i / 2;
      		b = i * i * i;
      	}

        N += (a - b) * (a - b);
      	++i;
  		}

    std::cout << "Сумма (N) равна = " << N << '\n';

    flag = RestartProgramm();
  }
	return 0;
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

void printCondition()
{
	std::cout << "----------------------------------------------------------------------\n";
  std::cout << "                     30\n";
  std::cout << "Программа считает N = ∑ (a - b), где a и b определены по формуле: \n";
  std::cout << "                     i=1  i   i\n ";
  std::cout << "⎰a = i, если i - нечетное\t ⎰b = i*i, если i - нечетное\n";
  std::cout << " ⎱a = i/2, если i - четное\t ⎱b = i*i*i, если i - четное\n";
  std::cout << "----------------------------------------------------------------------\n";
}