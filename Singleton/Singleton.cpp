#include <iostream>

//
// Check list
// 1. Define a private static attribute in the "single instance" class.
// 2. Define a public static accessor function in the class.
// 3. Do "lazy initialization" (creation on first use) in the accessor function.
// 4. Define all constructors to be protected or private.
// 5. Clients may only use the accessor function to manipulate the Singleton.
//

class SingletonClass
{
public:
	int GetValue(void) const
	{
		return m_value;
	}

	void SetValue(int v)
	{
		m_value = v;
	}

	// 2.
	static SingletonClass* instance(void)
	{
		// 3.
		if (!s_instance)
			s_instance = new SingletonClass;
		return s_instance;
	}

private:
	int m_value;

	// 1.
	static SingletonClass* s_instance;

	// 4.
	SingletonClass(int v = 0) : m_value(v)
	{
	}
};

// Allocating and initializing SingletonClass's
// static data member.  The pointer is being
// allocated - not the object inself.
SingletonClass *SingletonClass::s_instance = 0;

// 5.

void foo(void) 
{
	SingletonClass::instance()->SetValue(1);
	std::cout << "foo: Globalptr is " << SingletonClass::instance()->GetValue() << std::endl;
}

void bar(void)
{
	SingletonClass::instance()->SetValue(2);
	std::cout << "bar: Globalptr is " << SingletonClass::instance()->GetValue() << std::endl;
}


int main(void)
{
	std::cout << "main: Globalptr is " << SingletonClass::instance()->GetValue() << std::endl;
	foo();
	bar();

	return 0;
}