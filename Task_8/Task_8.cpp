#include <iostream>

int IntInput();
int PositiveIntInput();
bool RestartProgramm();
void printCondition();

int main()
{
  printCondition();

  bool restartFlag = RestartProgramm();
  while (restartFlag)
  {
    std::cout << "Введите количество членов ряда: ";
    int n = PositiveIntInput();
    int* members = new int[n];
    int result = 0, sign = 1;
    for (int i = 0; i < n; ++i)
    {
      std::cout << "Введите число a" << i << ": ";
      members[i] = IntInput();
      result += (sign*members[i]) << i;
    }
    std::cout << "Результат вычислений: " << result << '\n';
    delete [] members;
    restartFlag = RestartProgramm();
  }
}

void printCondition()
{
  std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Вычислить a[0] - 2*a[1] + 4*a[2] + ... + 2^(n-1)*a[n-1]\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
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

int IntInput() 
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
    std::cin.clear();
    while (std::cin.get() != '\n');
    std::cout << "Некорректный ввод, повторите попытку: \n";
	}
	return a;
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