#include <iostream>
#include <string>

// Prototype base class.
class Prototype
{
protected:
	std::string type;
	int value;

public:
	virtual Prototype* clone() = 0;

	std::string getType(void)
	{
		return type;
	}

	int getValue(void)
	{
		return value;
	}
};

class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1(int number)
	{
		type = "Type";
		value = number;
	}

	Prototype* clone(void)
	{
		return new ConcretePrototype1(*this);
	}
};

// Factory that manages prorotype instances and produces their clones. 
class ObjectFactory
{
	static Prototype* typeValue1;
	static Prototype* typeValue2;

public:
	static void initialize(void)
	{
		typeValue1 = new ConcretePrototype1(1);
		typeValue2 = new ConcretePrototype1(2);
	}

	static Prototype* getTypeValue(void)
	{
		return typeValue1->clone();
	}

	static Prototype* getTypeValue1(void)
	{
		return typeValue2->clone();
	}
};

Prototype* ObjectFactory::typeValue1 = 0;
Prototype* ObjectFactory::typeValue2 = 0;


int main(void)
{
	ObjectFactory::initialize();
	Prototype* object;

	// All the object were created by cloning the prototype.
	object = ObjectFactory::getTypeValue();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;

	object = ObjectFactory::getTypeValue1();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;


	return 0;
}