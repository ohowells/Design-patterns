// A factory method is a static method of a class that returns an object of that class' type.
// But unlike a constructor, the actual object it returns might be an instance of a subclass. 
// Another advantage of a factory method is that it can return existing instances multiple times.
#include <iostream>
#include <vector>

class VendingMachine
{
public:
	// Factory Method
	static VendingMachine *DepenceItem(short choice);
	virtual void Item() = 0;
} typedef VM;



class ChocolateBar : public VM
{
public:
	void Item()
	{
		std::cout << "Chocolate Bar Depenced.\n";
	}
};

class SoftDrink : public VM
{
public:
	void Item()
	{
		std::cout << "Soft Drink Depenced.\n";
	}
};

class Crisps : public VM
{
public:
	void Item()
	{
		std::cout << "Crisps Depenced.\n";
	}
};

VM * VendingMachine::DepenceItem(short choice)
{
	if (choice == 1)
		return new ChocolateBar;
	else if (choice == 2)
		return new SoftDrink;
	else
		return new Crisps;
}



int main(void)
{
	std::vector<VM*> Item;
	short choice;

	while (true)
	{
		std::cout << "Chocolate Bar(1), Soft Drink(2), Crisps(3), end(0): ";
		std::cin >> choice;
		
		if (choice == 0) break;

		Item.push_back(VM::DepenceItem(choice));
	}

	for (size_t i = 0; i < Item.size(); i++)
		Item[i]->Item();

	for (size_t i = 0; i < Item.size(); i++)
		delete Item[i];

	return 0;
}