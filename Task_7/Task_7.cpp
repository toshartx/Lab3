#include <iostream>
#include <cmath>

int PositiveIntInput();
bool RestartProgramm();
void printCondition();

int main() {
  printCondition();

  bool restartFlag = RestartProgramm();
  while (restartFlag)
  {
    int n = PositiveIntInput();
    for (int i = 1; i < n; i++)
    {
	    int n = 1;
	    int counting = 0;
	    int sum = 0;
	    while (i / n != 0)
	    {
	  	  n *= 10;
	   	counting++;
	    }
		
	    for (int j = 0; j < counting; j++)
	    {
	  	  int l = int(i / std::pow(10, j)) % 10;		// цифра
	  	  sum += std::pow(l, counting);			
	    }
	    if (sum == i)
		  {
			  std::cout << i << '\n';
		  }
	  }
    restartFlag = RestartProgramm();
  }
  return 0;
}

void printCondition()
{
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Программа выводит все числа Армстронга от 1 до n, n - вводится\n";
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
  std::cout << "Введите n: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
    std::cin.clear();
    while (std::cin.get() != '\n');
    std::cout << "Некорректный ввод, повторите попытку: \n";
	}
	return a;
}