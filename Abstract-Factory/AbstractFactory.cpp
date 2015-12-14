#include <iostream>

class Shape 
{
public:
	Shape(void): id_(total_++)
	{
	}

	virtual void draw(void) = 0;
protected:
	int id_;
	static int total_;
};

int Shape::total_ = 0;

class Circle : public Shape 
{
public:
	void draw(void) 
	{
		std::cout << "Circle " << id_ << ": draw" << std::endl;
	}
};
class Square : public Shape 
{
public:
	void draw(void)
	{
		std::cout << "Square " << id_ << ": draw" << std::endl;
	}
};
class Ellipse : public Shape 
{
public:
	void draw(void) 
	{
		std::cout << "Ellipse " << id_ << ": draw" << std::endl;
	}
};
class Rectangle : public Shape 
{
public:
	void draw(void) 
	{
		std::cout << "Rectangle " << id_ << ": draw" << std::endl;
	}
};

class Factory 
{
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory 
{
public:
	Shape* createCurvedInstance(void) 
	{
		return new Circle;
	}
	Shape* createStraightInstance(void) 
	{
		return new Square;
	}
};
class RobustShapeFactory : public Factory 
{
public:
	Shape* createCurvedInstance(void) 
	{
		return new Ellipse;
	}
	Shape* createStraightInstance(void) 
	{
		return new Rectangle;
	}
};

int main(void) 
{
#ifdef SIMPLE
	Factory* factory = new SimpleShapeFactory;
#else
	Factory* factory = new RobustShapeFactory;
#endif
	Shape* shapes[3];

	shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
	shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
	shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

	for (int i = 0; i < 3; i++) 
		shapes[i]->draw();

	return 0;
}