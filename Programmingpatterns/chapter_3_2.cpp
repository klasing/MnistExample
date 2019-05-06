#include <iostream>

using namespace std;
/* Implementor */
class DrawingAPI_3_2 {
public:
	virtual void drawCircle(double x, double y, double radius) = 0;
	virtual ~DrawingAPI_3_2() {}
};

/* Concrete ImplementorA */
class DrawingAPI1_3_2 : public DrawingAPI_3_2 {
public:
	void drawCircle(double x, double y, double radius) {
		cout << "-> API1.circle at " << x << ':' << y << ' ' << radius << endl;
	}
};

/* Concrete ImplementorB */
class DrawingAPI2_3_2 : public DrawingAPI_3_2 {
public:
	void drawCircle(double x, double y, double radius) {
		cout << "-> API2.circle at " << x << ':' << y << ' ' << radius << endl;
	}
};

/* Abstration */
class Shape_3_2 {
public:
	virtual ~Shape_3_2() {}
	virtual void draw() = 0;
	virtual void resizeByPercentage(double pct) = 0;
};

/* Refined Abstration */
class CircleShape_3_2 : public Shape_3_2 {
public:
	CircleShape_3_2(double x, double y, double radius, DrawingAPI_3_2* drawingAPI) :
		m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI) {}
	void draw() {
		m_drawingAPI->drawCircle(m_x, m_y, m_radius);
	}
	void resizeByPercentage(double pct) {
		m_radius *= pct;
	}
private:
	double m_x, m_y, m_radius;
	DrawingAPI_3_2* m_drawingAPI;
};

inline void chapter_3_2() {
	cout << "Bridge" << endl;
	cout << "------" << endl;

	CircleShape_3_2 circle1(1, 2, 3, new DrawingAPI1_3_2());
	CircleShape_3_2 circle2(5, 7, 11, new DrawingAPI2_3_2());
	circle1.resizeByPercentage(2.5);
	circle2.resizeByPercentage(2.5);
	circle1.draw();
	circle2.draw();
}