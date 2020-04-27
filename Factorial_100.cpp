#include <iostream>
using namespace std;

#define MAX 1500

int multiply(int *array, int len, int x);

int factorial(int num)
{
	int array[MAX], len;

	array[0] = 1;
	len = 1;

	for(int i=2; i<=num; ++i)
		len = multiply(array,len,i);

	cout << "Factorial of the given number is: ";
	for(int i=len-1; i>=0; --i)
		cout << array[i];
	cout << "\n";

}

int multiply(int *array, int len, int x)
{
	int prod,carry = 0;

	for(int i=0; i<len; ++i)
	{
		prod = array[i]*x + carry;
		array[i] = prod % 10;
		carry = prod / 10;
	}

	while(carry)
	{
		array[len] = carry % 10;
		carry = carry/10;
		len++;
	}

	return len;
}

int main()
{
	int n;

	cout << "Enter a number: ";
	cin >> n;

	factorial(n);

	return 0;
}