#include <iostream>
using namespace std;

enum enOperations { greatest_common_divisor = 1 , least_common_multipile= 2 };

int ReadPositiveNumber(string message)
{
	cout << message << endl;
	int num;
	cin >> num; // let the user enter the value of the num(variable) //

	while (num <= 0) // check if the num is positive or not //
	{
		cout << "Wrong it should be positive: ";
		cin >> num;
	}

	return num;
}

int Greater(int num1, int num2) // Give the greater num between two nums
{
	if (num1 >= num2) // equal because if they are equal there is no diffrence
		return num1;
	else if (num1 < num2)
		return num2;
}

int Least(int num1, int num2) // give me the smaller num between the two nums
{
	if (num1 <= num2)
		return num1;
	else if (num2 < num1)
		return num2;
}

int GCD(int num1, int num2)
{	
	int smaller = Least(num1, num2);
	int bigger = Greater(num1, num2);

	for (int i = smaller; i > 1; i--)   //-------- the most important part { all the logic } --------//
	{
		if (smaller % i == 0 && bigger % i == 0)
			return i;
	}

}

int LCM(int num1, int num2)
{
	return ((num1 * num2) / GCD(num1, num2)); // المعادلة يلي طلعها البراء اليوم //  ---->  // GCD(a,b) * LCM(a,b) = a * b //
}

void Header() // let the user choose the operation that he want ( GCD or LCM ) //
{
	cout << " (1) GCD \t (2) LCM" << endl;

	int OpNum = ReadPositiveNumber("Enter your Operation Type:");

	cout << "\n-------------------------------\n";

	int num1 = ReadPositiveNumber("Enter your first positive number: ");
	int num2 = ReadPositiveNumber("Enter your second positive number: ");

	cout << "\n-------------------------------\n";

	switch ((enOperations)OpNum)
	{
		case enOperations::greatest_common_divisor:
			cout << "The GCD (" << num1 << "," << num2 << ") = " << GCD(num1, num2) << endl;
			break;
		case enOperations::least_common_multipile:
			cout << "The LCM (" << num1 << "," << num2 << ") = " << LCM(num1, num2) << endl;
			break;
		default:
			cout << "Wrong Operation!" << endl;
	}
}

int main()
{

	Header();

	return 0;
}