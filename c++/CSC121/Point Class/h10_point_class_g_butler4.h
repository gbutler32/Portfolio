// ===================================================================
// class Point declaration including some inline function definitions.
// ===================================================================
#ifndef H10_POINT_CLASS_G_BUTLER4_H
#define H10_POINT_CLASS_G_BUTLER4_H

#include "h10_point_class_g_butler4.h"
class Point 
{
public:
	// Constructors
	Point() : x(0.0), y(0.0) {} // default constructor
	Point(const Point &p) : x(p.x), y(p.y) {}// copy constructor
	Point(double new_x, double new_y) : x(new_x), y(new_y) {}

	// Accessors
	double getX() const { return x; };
	double getY() const { return y; };	
	void print(); // in format of (x, y)
	
	// Mutators
	void resetX(double new_x) { x = new_x; };
	void resetY(double new_y) { y = new_y; };
	void resetXY(double new_x, double new_y );

	// Utilities
	Point add(const Point &p2) const; // addition of two points
	Point sub(const Point &p2) const;	// difference of two points
	void move(double a, double b);	// move current point to a new position
	double distanceTo(const Point &p2) const;	// distance between two points	

private:
	double x; 
	double y;
};

#endif
