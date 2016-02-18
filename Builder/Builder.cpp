#include <string>
#include <iostream>
#include <memory>

// Product
class Pizza
{
public:
	void setDough(const std::string& dough)
	{
		m_dough = dough;
	}
	void setSauce(const std::string& sauce)
	{
		m_sauce = sauce;
	}
	void setTopping(const std::string& topping)
	{
		m_topping = topping;
	}
	void open(void) const
	{
		std::cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
			<< m_topping << " topping. Mmm." << std::endl;
	}

private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

// Abstract Builder
class PizzaBuilder
{
public:
	virtual ~PizzaBuilder() {};

	Pizza* getPizza(void)
	{
		return m_pizza.get();
	}
	void createNewPizzaProduct(void)
	{
		m_pizza = std::make_unique<Pizza>();
	}
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;

protected:
	std::unique_ptr<Pizza> m_pizza;
};

// -----------------------------------------------------------------------------------------------
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~HawaiianPizzaBuilder() {};

	virtual void buildDough()
	{
		m_pizza->setDough("cross");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("mild");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("ham+pineapple");
	}
};
// -----------------------------------------------------------------------------------------------

class Cook
{
public:
	void openPizza(void)
	{
		m_pizzaBuilder->getPizza()->open();
	}
	void makePizza(PizzaBuilder* pb)
	{
		m_pizzaBuilder = pb;
		m_pizzaBuilder->createNewPizzaProduct();
		m_pizzaBuilder->buildDough();
		m_pizzaBuilder->buildSauce();
		m_pizzaBuilder->buildTopping();
	}
private:
	PizzaBuilder* m_pizzaBuilder;
};

int main(void)
{
	Cook cook;
	HawaiianPizzaBuilder hawaiianPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();

	return 0;
}