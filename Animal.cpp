#include <iostream>

class Animal
{
protected:
	int age;
	int feet;
	int teeth;
	int weight;
	int lifespan;
	std::string name;
	std::string breathin_system;
public:
	Animal(int age, int weight) :age(age), weight(weight)
	{
		std::cout << "Call " << __func__ << std::endl;
	}
	virtual void voice() = 0;
	virtual ~Animal()
	{
		std::cout << "Call " << __func__ << std::endl;
	}
};

class Aquatic_animal :virtual public Animal
{
protected:
	int fins_count;
	int depth_of_living;
	int gills_count;
	std::string habitat;
public:
	Aquatic_animal(int age,int weight, int depth_of_living) :Animal(age,weight), depth_of_living(depth_of_living)
	{
		std::cout << "Call " << __func__ << std::endl;
	}
	virtual void voice() = 0;
	virtual ~Aquatic_animal()
	{
		std::cout << "Call " << __func__ << std::endl;

	}
};
class Terrestrial_animals :virtual public Animal
{
protected:
	int legs;
	int ears;
	std::string cattle_type;
public:
	Terrestrial_animals(int age, int weight, int legs) :Animal(age, weight), legs(legs)
	{
		std::cout << "Call " << __func__ << std::endl;
	}
	virtual void voice() = 0;
	virtual~Terrestrial_animals()
	{
		std::cout << "Call " << __func__ << std::endl;

	}
};

class Amphibious :virtual public Aquatic_animal, Terrestrial_animals
{
protected:
	int fingersCount;
	bool hasGills;
public:
	Amphibious(int age, int weight, int depth_of_living, int legs, int fingersCount) :Animal(age,weight), Aquatic_animal(age,weight, depth_of_living), Terrestrial_animals(age,weight, legs), fingersCount(fingersCount)
	{
		std::cout << "Call " << __func__ << std::endl;
	}
    void voice() override
	{
		std::cout << "Voice of amphibious \n";
	}
	virtual ~Amphibious()
	{

		std::cout << "Call " << __func__ << std::endl;
	}

};
int main(int argc, char** argv)
{
	Amphibious frog(3,2,1,4,9);
	frog.voice();
	return 0;
}