#include <iostream>

struct Point {
	int x;
	int y;
};

void printPoint(const Point& point) {
	std::cout << "Point(" << point.x << ", " << point.y << ")" << std::endl;
}

int main2()
{
	printPoint(Point{ 1, 2 }); // 输出: Point(1, 2)
	printPoint({ 3, 4 }); // 输出: Point(1, 2)
	Point p{ 5, 6 };
	printPoint(p); // 输出: Point(5, 6)
	return 0;
}
