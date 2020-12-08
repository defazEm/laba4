#include <iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class Shape {
public:
	Shape(){}
	~Shape() {}

	virtual double area() = 0;
	virtual double volume() = 0;
};

class TwoDShape :public Shape {
private:
	int x, y;
public:
	TwoDShape(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}
	~TwoDShape() {}


	double area()
	{
		return 0;
	}
	double volume()
	{
		cout << "Не имеет объема!" << endl;
		return 0;
	}

	void set(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}

};

class ThreeDShape :public Shape {
private:
	int rad;
public:
	ThreeDShape(int _rad = 0)
	{
		this->rad = _rad;
	}
	~ThreeDShape() {}

	double volume()
	{
		return 0;
	}
	double area()
	{
		return 0;
	}

	void set(int _rad)
	{
		rad = _rad;
	}
};

class Circle :public TwoDShape {
private:
	int x2;
	int y2;
public:
	Circle(int _x = 0, int _y = 0, int _x2 = 0, int _y2 = 0) : TwoDShape(_x, _y)
	{
		this->x2 = _x2;

	}
	~Circle() {}


	void set(int _x, int _y, int _x2, int _y2)
	{
		this->x2 = _x2;
	}

	double area()
	{
		double area = 3.14 * x2 * x2;
		return area;

	}

	void Input()
	{
		cout << "Введите радиус круга: ";
		cin >> x2;
	}
};

class Rectangle :public TwoDShape {
private:
	int x2;
	int y2;
public:
	Rectangle(int _x = 0, int _y = 0, int _x2 = 0, int _y2 = 0) : TwoDShape(_x, _y)
	{
		this->x2 = _x2;
		this->y2 = _y2;
	}
	~Rectangle() {}

	void set(int _x, int _y, int _x2, int _y2)
	{
		this->x2 = _x2;
		this->y2 = _y2;
	}

	double area()
	{
		double area = x2 * y2;
		return area;
	}

	void Input()
	{
		cout << "Введите первую сторону прямоугольника: ";
		cin >> x2;
		cout << "Введите второю сторону прямоугольника: ";
		cin >> y2;
	}
};

class Cube :public ThreeDShape {
private:
	int len;
public:
	Cube(int _len = 0)
	{
		this->len = _len;
	}
	~Cube() {}
	void set(int _len)
	{
		this->len = _len;
	}

	double area()
	{
		return 6 * pow(len, 2);
	}
	double volume()
	{
		return pow(len, 3);
	}
	void Input()
	{
		cout << "Введите длину ребра куба: ";
		cin >> len;
	}
};

class Sphere :public ThreeDShape {
private:
	int rad;
public:
	Sphere(int _rad = 0)
	{
		this->rad = _rad;
	}
	~Sphere() {}

	void set(int _rad)
	{
		this->rad = _rad;
	}

	double area()
	{
		return 4 * 3.14 * rad * rad;
	}
	double volume()
	{
		return 1.33 * 3.14 * rad * rad * rad;
	}

	void Input()
	{
		cout << "Введите радиус сферы: ";
		cin >> rad;
	}
};


int main()
{
	setlocale(LC_ALL, "");
	Circle tmp1;
	tmp1.Input();
	Shape* p1 = &tmp1;
	cout << "Площадь круга: ";
	cout << p1->area() << endl;
	cout << "Объем круга: ";
	cout << p1->volume() << endl;

	Rectangle tmp2;
	tmp2.Input();
	Shape* p2 = &tmp2;
	cout << "Площадь прямоугольника: ";
	cout << p2->area() << endl;
	cout << "Объем прямоугольника: ";
	cout << p2->volume() << endl;

	Cube tmp3;
	tmp3.Input();
	Shape* p3 = &tmp3;
	cout << "Площадь поверхности куба: ";
	cout << p3->area() << endl;
	cout << "Объем куба: ";
	cout << p3->volume() << endl;

	Sphere tmp4;
	tmp4.Input();
	Shape* p4 = &tmp4;
	cout << "Площадь поверхности сферы: ";
	cout << p4->area() << endl;
	cout << "Объем сферы: ";
	cout << p4->volume() << endl;
	return 0;
}