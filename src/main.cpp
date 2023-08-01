#include <iostream>
#include <vector>
#include <string>
#include <math.h>

struct Math_Vector
{
	double x;
	double y;
};

void receiving_two_vectors(Math_Vector& firstMathVector, Math_Vector& secondMathVector)
{
	std::cout << "Enter arguments.\n";
	std::cout << "First vector.\n x: ";
	std::cin >> firstMathVector.x;
	std::cout << "First vector.\n y: ";
	std::cin >> firstMathVector.y;

	std::cout << "Second vector.\n x: ";
	std::cin >> secondMathVector.x;
	std::cout << "Second vector.\n y: ";
	std::cin >> secondMathVector.y;
}

void receiving_vector(Math_Vector& firstMathVector)
{
	std::cout << "Enter arguments.\n";
	std::cout << "Vector.\n x: ";
	std::cin >> firstMathVector.x;
	std::cout << "Vector.\n y: ";
	std::cin >> firstMathVector.y;
}

void add(Math_Vector& firstMathVector, Math_Vector& secondMathVector)
{
	receiving_two_vectors(firstMathVector, secondMathVector);

	std::cout << "{" << firstMathVector.x + secondMathVector.x << ";"
		<< firstMathVector.y + secondMathVector.y << "}" << std::endl;
}

void subtract(Math_Vector& firstMathVector, Math_Vector& secondMathVector)
{
	receiving_two_vectors(firstMathVector, secondMathVector);

	std::cout << "{" << firstMathVector.x - secondMathVector.x << ";"
		<< firstMathVector.y - secondMathVector.y << "}" << std::endl;
}

void scale(Math_Vector& firstMathVector)
{
	receiving_vector(firstMathVector);
	double scalar;
	std::cout << "Scalar: ";
	std::cin >> scalar;

	std::cout << "{" << scalar * firstMathVector.x << ";" << scalar * firstMathVector.y << "}" << std::endl;
}

double length(Math_Vector& firstMathVector)
{
	receiving_vector(firstMathVector);
	return sqrt(std::pow(firstMathVector.x, 2) + std::pow(firstMathVector.y, 2));
}

void normalize(Math_Vector& firstMathVector)
{
	double len = length(firstMathVector);

	std::cout << pow(firstMathVector.x / len, 2) + pow(firstMathVector.y / len, 2) << std::endl;
}

int main()
{
	Math_Vector firstMathVector;
	Math_Vector secondMathVector;
	std::string command;

	std::cout << "Enter the command: \nadd\nsubtract\nscale\nlength\nnormalize\n:";
	std::getline(std::cin, command);

	if (command == "add")
		add(firstMathVector, secondMathVector);
	else if (command == "subtract")
		subtract(firstMathVector, secondMathVector);
	else if (command == "scale")
		scale(firstMathVector);
	else if (command == "length")
		std::cout << length(firstMathVector) << std::endl;
	else if (command == "normalize")
		normalize(firstMathVector);
	else std::cerr << "Error! You have not entered any commands. " << std::endl;
	

	return 0;
}
