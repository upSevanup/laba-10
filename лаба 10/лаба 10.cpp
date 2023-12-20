#include <iostream>
#include <clocale>
#include <fstream>

using namespace std;

/*
* Лабораторная работа 10. Поливцев Михаил, ИВТ-31. Индивидуальный вариант 16.
* Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N).
* Найти среднее арифметическое элементов массива с номерами от K до L включительно.
* с использованием файлового ввода-вывода. 
*/

int main() {
	setlocale(LC_ALL, "ru");

	ifstream inputfile("inp.txt");
	ofstream outputfile("oup.txt");

	if (!inputfile.is_open()) {
		cout << "не удалось открыть файл для чтения" << endl;
		return 1;
	}
	if (!outputfile.is_open()) {
		cout << "не удалось открыть файл для чтения" << endl;
		return 1;
	}

	const int max_size = 10;
	int lst[max_size];
	int n, k, l;
	double s = 0;
	cout << "Введите размер массива, числа K и L соответственно >> ";
	cin >> n >> k >> l;
	if (!(1 <= k && k <= l && l <= n) || n > max_size) {
		cout << "неверный ввод";
		return 1;
	}
	for (int i = 0; i < n; i++) {
		inputfile >> lst[i];
	}

	for (int i = k; i <= l; i++) {
		s += lst[i];
	}
	s /= (l - k + 1);

	cout << s << endl;
	outputfile << s;

	inputfile.close();
	outputfile.close();
}