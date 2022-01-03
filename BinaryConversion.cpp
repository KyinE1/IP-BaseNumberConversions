#include <iostream>
#include <string>

/** Converts integer into base 2. 
 * 
 * */
void convertToBinaryForm() {
	int decimal = 0;
	std::string binary;

	std::cout << "Input an integer: ";
	std::cin >> decimal;
	std::cout << "\nThe binary form of " << decimal << " is: ";

	// Divides integer by 2.
	while (decimal != 0) {
		binary += std::to_string(decimal % 2);
		decimal /= 2;
	}

	// Print the integer in base 2.
	for (int i = binary.size(); i >= 0; i--)
		std::cout << binary[i];
}

/** Convert binary string into base 10. 
 * 
 * */
void convertToDecimalForm() {
	int decimal = 0;
	int bit = 0;
	std::string binary;
	std::string input;

	std::cout << "Input a binary string: ";
	std::cin >> input;
	
	// Multiply each bit by 2^i and append to decimal form.
	for (int i = input.size() - 1, j = 0; i >= 0; i--, j++) {
		binary = input[j];
		bit = atoi(binary.c_str());
		decimal += bit * pow(2, i);
	}

	std::cout << "\nThe decimal form of " << input << " is: " << decimal << "\n";
}

/** Driver. 
 * 
 * */
int main() {

	convertToBinaryForm();
	convertToDecimalForm();

	return 0;
}
