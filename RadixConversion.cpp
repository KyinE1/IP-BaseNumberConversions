#include <iostream>
#include <string>

/** Driver. Converts base 10 integer to radix value.
 * 
 * */
int main() {
	std::string result;		// Result of conversion.
	int integerValue = 0;	// Decimal integer.
	int radixValue = 0;		// Base value.
	int divisions = 0;		// Number of times the place value can be used to divide the integerValue.

	std::cout << "Enter a decimal integer and an integer radix (2-16): ";
	std::cin >> integerValue;
	std::cin >> radixValue;
	
	const int base = radixValue; 

	// Shift place value to the left 
	// (get to value exceeding integer).
	while (radixValue * base < integerValue) 
		radixValue *= base;

	// Convert decimal integer to radix.
	// Divide until remainder of integerValue
	// becomes zero.
	for (int i = 0; integerValue != 0; i++) {
		// Convert to base radix.
		divisions = integerValue / radixValue;
		integerValue -= radixValue * divisions;
		radixValue /= base;
		result += std::to_string(divisions);
	}

	std::cout << "Value of integer in radix is: " << result;
	std::cout << "\nExiting program...\n";

	return 0;
}
