#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main()
{
	/* This is a multi-line comment.
	 * the matching asterisks to the left
	 * can make this easier to read
	 */
    
    std::string unit = "";
    int MULTIPLIER{};
    
    /* user prompt. 'print' = (std::cout <<). 'submit' = (std::cin >>).
     * if they choose 'seconds' then the half-lives (in
     * the form of years) are converted by multiplying them
     * by the number of gregorian calendar seconds. */
    std::cout << "Would you like to measure in years or seconds? (y/s)";
    char responseOne{};
    std::cin >> responseOne;
    switch (responseOne) {
        case 'y':
            unit = "year";
            MULTIPLIER = 1;
            break;
        case 's':
            unit = "second";
            MULTIPLIER = 31556952;
            break;
        default:
            std::cout << "Unknown";
            break;
    }
   
	// half-life of uranium isotopes, measured in years with scientific notation.
	const double HALF_LIFE_233U(1.592e5*MULTIPLIER);
	const double HALF_LIFE_235U(7.04e8*MULTIPLIER);
	const double HALF_LIFE_238U(4.463e9*MULTIPLIER);
	// plutonium
	const double HALF_LIFE_239Pu(2.411e4*MULTIPLIER);
	// thorium
	const double HALF_LIFE_232Th(1.40e10*MULTIPLIER);
	
	// user prompt
	std::cout << "Select a fertile nuclear isotope:\n<1>Uranium-233\n<2>Uranium-235\n<3>Uranium-238\n<4>Plutonium-239\n<5>Thorium-232\n";
    int responseTwo{};
    std::cin >> responseTwo;
    double isotope{};
    if (responseTwo == 1) {
        isotope = HALF_LIFE_233U;
    } else if (responseTwo == 2) {
        isotope = HALF_LIFE_235U;
    } else if (responseTwo == 3) {
        isotope = HALF_LIFE_238U;
    } else if (responseTwo == 4) {
        isotope = HALF_LIFE_239Pu;
    } else if (responseTwo == 5) {
        isotope = HALF_LIFE_232Th;
    }
    
	/* decay constant | the natural logarithm of  2 divided by the half life
	 * print the decay constant as a number with 20 decimal places */
	const double decay = (std::log(2)) / isotope;
	std::cout << "Probability per " << unit << " for a single nucleus to decay: " << std::fixed << std::setprecision(20) << decay;

	return 0;
}
