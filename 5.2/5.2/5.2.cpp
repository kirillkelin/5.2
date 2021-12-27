
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int getValueint()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		cin >> a;

		if (cin.fail()) { // если предыдущее извлечение оказалось неудачным,
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";

		}
		else // если всё хорошо, то возвращаем a
			return a;
	}
}

double f(double** a, int n, int m) {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((j > -1 + m / 2 and i < n / 2) or (j <  m / 2 and i > -1 + n / 2)) sum += a[i][j];

		}
	}
	return sum;
}

int main() {
	setlocale(0, "ru");
	srand(time(0));
	int n, m;
	cout << "N = ";
	n = getValueint();
	cout << "M = ";

	m = getValueint();
	double** a = new double*[n];
	for (int i = 0; i < m; i++) a[i] = new double[m];
	// Инициализация массива
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100 / 1.1;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "______________________________________________________________________\n";

	double r = f(a, m, n);
	cout << r;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}