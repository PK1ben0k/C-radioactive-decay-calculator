#include <iostream>
#include <cmath>

int main()
{
	/* This is a multi-line comment.
	 * the matching asterisks to the left
	 * can make this easier to read
	 */

	// direct initialization of a (integer) and b (integer)
	int a(6), b(6);

	// print (std::cout <<) the natural logarithm of (a multiplied by b)
	std::cout << std::log(a * b);
	return 0;
}
