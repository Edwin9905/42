#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc(argv[1]);
}
