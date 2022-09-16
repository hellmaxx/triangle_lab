// Triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

/*Класс треугольник*/

class Triangle 
{

public:
	//Координаты
	float dot_x1, dot_x2, dot_x3;
	float dot_y1, dot_y2, dot_y3;
	/*Стороны*/
	double s_side1, s_side2, s_side3;

	/*Конструктор по умолчанию*/
	Triangle() { };

	/*Конструктор с параметрами*/
	Triangle(float x1, float x2, float x3, float y1, float y2, float y3) 
	{

		/*Инициализация точек*/
		dot_x1 = x1;
		dot_y1 = y1;
		dot_x2 = x2;
		dot_y2 = y2;
		dot_x3 = x3;
		dot_y3 = y3;

	};

	/*Деструктор*/
	~Triangle() 
	{
		dot_x1 = 0;
		dot_y1 = 0;
		dot_x2 = 0;
		dot_y2 = 0;
		dot_x3 = 0;
		dot_y3 = 0;


		cout << "Вызов деструктора" << endl;
	};

	void addSide(double side1, double side2, double side3)
	{
		/*Рассчет сторон*/
		side1 = sqrt((dot_x1 - dot_x2) * (dot_x1 - dot_x2) + (dot_y1 - dot_y2) * (dot_y1 - dot_y2));
		side2 = sqrt((dot_x2 - dot_x3) * (dot_x2 - dot_x3) + (dot_y2 - dot_y3) * (dot_y2 - dot_y3));
		side3 = sqrt((dot_x1 - dot_x3) * (dot_x1 - dot_x3) + (dot_y1 - dot_y3) * (dot_y1 - dot_y3));

		/*Инициализация сторон*/
		s_side1 = side1;
		s_side2 = side2;
		s_side3 = side3;

		cout << "Стороны:" << " " << s_side1 << " " << s_side2 << " " << s_side3 << endl;
		cout << endl;
	}

	/*Метод подсчета периметра*/
	void perimeter()
	{
		double perimeter = (s_side1 + s_side2 + s_side3);
		cout << "Периметр: " << perimeter << endl;
	}

	/*Метод подсчета площади*/
	void square()
	{
		double halfOfPerimetr = (s_side1 + s_side2 + s_side3) / 2;
		double square = sqrt((halfOfPerimetr * (halfOfPerimetr - s_side1) * (halfOfPerimetr - s_side2) * (halfOfPerimetr - s_side3)));
		cout << "Площадь: " << square << endl;
	}

	void rotate(double angle)
	{
		double x_pivot = 0;
		double y_pivot = 0;
		const double g2r = M_PI / 180.;
		angle *= g2r;
		double x_shifted1 = dot_x1 - x_pivot;
		double y_shifted1 = dot_y1 - y_pivot;
		double x_shifted2 = dot_x2 - x_pivot;
		double y_shifted2 = dot_y2 - y_pivot;
		double x_shifted3 = dot_x3 - x_pivot;
		double y_shifted3 = dot_y3 - y_pivot;
		dot_x1 = x_pivot + (x_shifted1 * cos(angle) - y_shifted1 * sin(angle));
		dot_y1 = y_pivot + (x_shifted1 * sin(angle) + y_shifted1 * cos(angle));
		dot_x2 = x_pivot + (x_shifted2 * cos(angle) - y_shifted2 * sin(angle));
		dot_y2 = y_pivot + (x_shifted2 * sin(angle) + y_shifted2 * cos(angle));
		dot_x3 = x_pivot + (x_shifted3 * cos(angle) - y_shifted3 * sin(angle));
		dot_y3 = y_pivot + (x_shifted3 * sin(angle) + y_shifted3 * cos(angle));

		cout << "Поворот:" << "X1:" << dot_x1 << " Y1:" << dot_y1 << " X2:" << dot_x2 << " Y2:" << dot_y2 << " X3:" << dot_x3 << " Y3:" << dot_y3 << endl;
		addSide(0, 0, 0);
	}

};

int main() 
{
	setlocale(0, "Russian");

	float x1 = 0;
	float x2 = 0;
	float x3 = 0;

	float y1 = 0;
	float y2 = 0;
	float y3 = 0;

	double side1 = 0;
	double side2 = 0;
	double side3 = 0;

	cout << "Треугольник 1. Введите координаты первой вершины через пробел: ";
	cin >> x1 >> y1;
	cout << "Введите координаты второй вершины через пробел: ";
	cin >> x2 >> y2;
	cout << "Введите координаты третьей вершины через пробел: ";
	cin >> x3 >> y3;

	cout << endl;

	/*Первый объект класса*/
	Triangle triangleOne(x1, x2, x3, y1, y2, y3);
	triangleOne.addSide(side1, side2, side3);

	float _x1 = 0;
	float _x2 = 0;
	float _x3 = 0;

	float _y1 = 0;
	float _y2 = 0;
	float _y3 = 0;

	double _side1 = 0;
	double _side2 = 0;
	double _side3 = 0;

	cout << "Треугольник 2. Введите координаты первой вершины через пробел: ";
	cin >> _x1 >> _y1;
	cout << "Введите координаты второй вершины через пробел: ";
	cin >> _x2 >> _y2;
	cout << "Введите координаты третьей вершины через пробел: ";
	cin >> _x3 >> _y3;

	cout << endl;

	/*Второй объект класса*/
	Triangle triangleTwo(_x1, _x2, _x3, _y1, _y2, _y3);
	triangleTwo.addSide(_side1, _side2, _side3);
	cout << "Создан треугольник с координатами:" << "X1:" << x1 << " Y1:" << y1 << " X2:" << x2 << " Y2:" << y2 << " X3:" << x3 << " Y3:" << y3 << endl;
	cout << "Создан треугольник с координатами:" << "X1:" << _x1 << " Y1:" << _y1 << " X2:" << _x2 << " Y2:" << _y2 << " X3:" << _x3 << " Y3:" << _y3 << endl;

	cout << endl;

	/*Вызов методов для первого объекта*/
	triangleOne.perimeter();
	triangleOne.square();

	cout << endl;

	/*Вызов методов для второго объекта*/
	triangleTwo.perimeter();
	triangleTwo.square();

	cout << endl;

	double ang;
	cout << "На какой угол повернуть треугольники: ";
	cin >> ang;
	/*Поворот*/
	triangleOne.rotate(ang);
	triangleTwo.rotate(ang);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
