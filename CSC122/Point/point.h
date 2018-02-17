#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <iostream>

// A 2D point class

class Point
{
	double x, // x coordinate of point
	y; // y coordinate of point

public:
	Point(void)
		:x(0.0), y(0.0){}

	Point(double new_x, double new_y)
		:x(new_x), y(new_y){}

	std::ostream & Output(std::ostream & out) const  // output this point
	{
		out << "( " << x << ", " << y << " )";//(x,y)
		return out;
	}
	std::istream & Input(std::istream & in)    // input this point
	{
				in.ignore();
				in>>x;
				in.ignore();
				in >> y;
				in.ignore();
					return in;
	}

	Point distance(const Point & b)   // distance between this point and other
	{
		Point temp;
		temp.x = (x + b.x) / 2;
		temp.y = (y + b.x) / 2;
		return temp;
	}
	double get_x(void) { return x; }
	double get_y(void) { return y; }

	void set_x(double new_x) { x = new_x; };
	void set_y(double new_y) { y = new_y; };

	Point flip_x(void)
	{
		return Point(x, -y);
	}

	Point flip_y(void)
	{
		return Point(-x, y);
	}

	Point shift_x(double move_by)
	{
		return Point(x + move_by, y);
	}

	Point shift_y(double move_by)
	{
		return Point(x, y + move_by);
	}

	Point operator-(const Point & b)
	{
		Point temp;
		temp.x = x - b.x;
		temp.y = y - b.y;
		return temp;
	}

	Point operator+(const Point & b)
	{
		Point temp;
		temp.x =(x + b.x);
		temp.y =(y + b.y);
		return temp;
	}

	Point & operator=(const Point & b)
	{

		x = b.x;
		y = b.y;
		return *this;
	}

	bool operator==(const Point & b)
	{
		if (((x) == b.x) && ((y) == b.y))
			return true;
		else
			return false;
	}

	bool operator!=(const Point & b)
	{
		if (((x) != b.x) || ((y) != b.y))
			return true;
		else
			return false;
	}

	Point operator/(const Point & b)
	{
		return distance(b);
	}

	friend std::istream& operator>>(std::istream & in,Point & b);
	friend std::ostream& operator<<(std::ostream & out,const Point & b);
};

inline std::istream& operator>>(std::istream & in,Point & b)//input
{
	b.Input(in);
	return (in);
}

inline std::ostream& operator<<(std::ostream & out,const Point & b)//output
{
	b.Output(out);
	return out;
}

#endif
