//Этот проект создан с помощью классического шаблона
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>


struct route {
	int number_of_route;
	std::string type_of_transport;
	std::string route_start;
	std::string route_finish;
} r1{ 1, "Bus", "Lenin Str", "Railway Station"},
r2 { 2, "Trolley", "Lenin Str", "Airport"}
;




template <typename T>
void memory(T*& ptr, int num1, int num2);

std::string replace_sym(std::string& str, char sym1, char sym2);

void show_route(route& P) {
	std::cout << "Number of route: " << P.number_of_route << '\n';
	std::cout << "Type of transport: " << P.type_of_transport << '\n';
	std::cout << "Route_start: " << P.route_start << '\n';
	std::cout << "Final destination: " << P.route_finish << '\n';
	
}

int total_cost(int num) {
	const int price = 20;
	return price * num;;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;

	std::cout << "Задача 1.\nВведите 2 числа: \n";
	std::cin >> n;
	std::cin >> m;
	int** pArr = nullptr;
	memory(pArr, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pArr[i][j] = rand() % 20;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << pArr[i][j] << "\t";
		}
		std::cout << '\n';
	}

	for (int i = 0; i < n;i++)
		delete[] pArr[i];
	delete[] pArr;
	std::cout << "\n\n";


	std::cout << "Задача 2.\nВведите строку\n";
	std::string str;
	std::cin >> str;
	std::getline(std::cin, str);
	char ch1 = 'a';
	char ch2 = 'b';
	std::cout << "В переданной строке мы будем менять все " << ch1 << " на " << ch2 << ".\n";
	std::cout << "Итоговая строка: " << replace_sym(str, ch1, ch2) << ".\n";






	std::cout << "Задача 3.\n";
	std::cout << "Описание маршрута: \n\n";
	show_route(r1);
	std::cout << "\n";
	std::cout << "Описание маршрута: \n\n";
	show_route(r2);
	std::cout << "\n";
	std::cout << "Введите количество человек: ";
	int x;
	std::cin >> x;
	std::cout << "Стоимость проезда равна: " << total_cost(x)  << ".\n";



	return 0;
}





template <typename T>
void memory(T*& ptr, int num1, int num2) {
	ptr = new T[num1];
	for (int i = 0; i < num1; i++) {
		ptr[i] = new int[num2];
	}
}

std::string replace_sym(std::string& str, char sym1, char sym2) {
	std::string tmp;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == sym1)
			tmp[i] = sym2;
		else
			tmp[i] = str[i];
	}
	return tmp;
}