#include <iostream>
	
/** Convert IP address to 32 bit unsigned int, 2 variable size groups 
 *  or a single bit.
 * 
 * */
void convertIPAddress() {
	// Bit field (assign bits).
	// Reads from top to bottom (left to right), 
	// so the order of the members matter.
	struct IP {
		unsigned int bit4 : 8;
		unsigned int bit3 : 8;
		unsigned int bit2 : 8;
		unsigned int bit1 : 8;
	};
	unsigned int input;
	IP a;

	// Get input of IP address.
	// Assign values to structure.
	std::cout << "Enter an IP address:\n";
	std::cin >> input; a.bit1 = input;
	std::cin >> input; a.bit2 = input;
	std::cin >> input; a.bit3 = input;
	std::cin >> input; a.bit4 = input;

	// In place of shifting which involves math, a union
	// can be used to deal with the bit operations.
	union all {
		unsigned int full32 : 32;
		IP Bits;
	};

	all addr;

	// Assign the vlaues of the IP address into the union.
	addr.Bits.bit1 = a.bit1;
	addr.Bits.bit2 = a.bit2;
	addr.Bits.bit3 = a.bit3;
	addr.Bits.bit4 = a.bit4;

	while (1) {
		std::cout << "How should the IP address be displayed ((1) single value, (2) four values, (3), two values, (4) a single bit value)?\nEnter (5) to exit: " ;
		std::cin >> input;

		// Display bit type dependent on user input.
		if (input == 1) {
			// Display single 32 bit unsigned integer value.
			std::cout << addr.full32 << "\n\n";
		}

		else if (input == 2) {
			std::cout << a.bit1 << '.' << a.bit2 << '.' << a.bit3 << '.' << a.bit4 << "\n\n";
		}

		// All 32 bits assigned into 2 variable size groups (1 to 31 bits each).
		else if (input == 3) {	
			std::cout << "How many bits are in the network address? ";
			std::cin >> input;

			// Network	=	192.168 =	1100 0000 1010 1000 = 49320
			// Host		=	1.5		=	0000 0001 0000 0101 = 261

			// Display 16 bit unsigned integer values (high and low order).
			std::cout << (addr.full32 << (16 - input) >> 16) << ", " << (addr.full32 << (32 - input) >> 16) << "\n\n";
		}

		else if (input == 4) {
			std::cout << "Which bit would you like to view (0-31)? ";
			std::cin >> input;

			// Shifts the bit of choice to the left 
			// (rids the value of all bits but the one of interest).
			// Places the bit in LSB position.
			std::cout << ((addr.full32 << (32 - input)) >> 31) << "\n\n";
		}

		else if (input == 5) {
			std::cout << "Exiting program.\n\n";
			return;
		}
	}
}

/** Driver code. 
 * 
 * */
int main() {
	convertIPAddress();

	return 0;
}

/*	Display the address in binary (debug).
	for (int i = 32; i > 0; i--) {
			if (i % 8 == 0 && i != 32)
				std::cout << " ";
			std::cout << ((addr.full32 << (32 - i)) >> 31);
	}
*/
