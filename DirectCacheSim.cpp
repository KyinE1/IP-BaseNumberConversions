#include <iostream>
#include <string>

/** Driver. Direct Cache Simulation. Evicts a block whenever another memory
 * 	reference needs that block.
 *
 * 	@note: The number of cache misses are the items that
 * 	have not been indexed into the cache.
 */
int main() {
	struct CacheSim {
		unsigned int data : 8;
		unsigned int tag : 8;
	};

	CacheSim mem[256];			// The collection of all items.
	CacheSim cache[8];			// The collection of recent items.
	unsigned int cacheMiss = 0;	// Number of times the item was not in the cache.
	unsigned int addr = 0;		// Address used for the memory.
	unsigned int idx = 0;		// Index of cache (index = address % size).

	// Enter memory values.
	for (unsigned int i = 0; i < 256; i++) {
		mem[i].data = i;
		mem[i].tag = i % 8;
	}

	// Enter first set of recent values.
	for (unsigned int i = 0; i < 8; i++)
		cache[i] = mem[i];

	while (1) {
		std::cout << "Enter a memory address (0 to 255, -1 to exit): ";
		std::cin >> addr;

		// End the loop.
		if (addr == -1)
			break;

		// Convert the address to a smaller value.
		idx = addr % 8;

		// Check if the item has already been loaded into the cache (hit).
		if (cache[idx].data == mem[addr].data)
			std::cout << "Item " << cache[idx].data << " has already been cached.\n\n";

		// Replace item in the cache with the data (miss).
		else {
			std::cout << "Adding item " << mem[addr].data << " to cache at index " << idx << ".\n\n";
			cache[idx].tag = idx;
			cache[idx].data = mem[addr].data;
			cacheMiss++;
		}
	}

	std::cout << "\nCache misses: " << cacheMiss;
	std::cout << "\nExiting...";

	return 0;
}
