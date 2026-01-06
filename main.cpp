#include <iostream>
#include <string>
#include <cmath>

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
    std::string y_or_s{};
    std::cin >> y_or_s;
    if (y_or_s == "y") {
        unit = "year";
        MULTIPLIER = 1;
    } else if (y_or_s == "s") {
        unit = "second";
        MULTIPLIER = 31556952;
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
    double isotope{};
    std::cin >> isotope;
    if (isotope == 1) {
        isotope = HALF_LIFE_233U;
    } else if (isotope == 2) {
        isotope = HALF_LIFE_235U;
    } else if (isotope == 3) {
        isotope = HALF_LIFE_238U;
    } else if (isotope == 4) {
        isotope = HALF_LIFE_239Pu;
    } else if (isotope == 5) {
        isotope = HALF_LIFE_232Th;
    }
    
	// the natural logarithm of  2 divided by the half life | decay constant
	const double decay = (std::log(2)) / isotope;
	std::cout << "Probability per " << unit << " for a single nucleus to decay: " << decay << ".";

	return 0;
}
