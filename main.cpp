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

	const int GREGORIAN_SECONDS = 31556952;
	std::string unit = "";
	int multiplier{};
	
	std::string errorMessage = "Invalid character. ";

	/* user prompt. 'print' = (std::cout <<). 'submit' = (std::cin >>).
	 * if they choose 'seconds' then the half-lives
	 * (in the form of years) are converted into seconds by multiplying
	 * them by the number of seconds in the gregorian calendar.
	 * dividing them by 3600 (amount of seconds in an hour)
	 * yields hours. exitLoop1 is initialized as false. while (exitLoop1)
	 * means "while exitLoop1 is true". the (!) makes it negative.
	 * exitLoop1 only becomes "true" by entering valid characters.
	 * "if-else" conditionals are utilized instead of "switch" statements
	 * for their ability to use strings and logical comparisons. */
	bool exitLoop1 = false;
	std::string response1{};
    std::cout << "Would you like to measure in years, seconds, or hours (y/s/h)? ";
	while (!exitLoop1) {
		std::cin >> response1;
		if (response1 == "y") {
			unit = "year";
			multiplier = 1;
			exitLoop1 = true;
		}
		else if (response1 == "s") {
			unit = "second";
			multiplier = GREGORIAN_SECONDS;
			exitLoop1 = true;
		}
		else if (response1 == "h") {
			unit = "hour";
			multiplier = GREGORIAN_SECONDS/3600;
			exitLoop1 = true;
		}
		else {
			std::cout << errorMessage;
		}
	}
	
	// half-life of uranium isotopes, measured in years (with scientific notation).
	std::string _233U = "Uranium-233";
	const double HALF_LIFE_233U(1.592e5*multiplier);
	
	std::string _235U = "Uranium-235";
	const double HALF_LIFE_235U(7.04e8*multiplier);
	
	std::string _238U = "Uranium-238";
	const double HALF_LIFE_238U(4.463e9*multiplier);
	// plutonium
	std::string _239Pu = "Plutonium-239";
	const double HALF_LIFE_239Pu(2.411e4*multiplier);
	// thorium
	std::string _232Th = "Thorium-232";
	const double HALF_LIFE_232Th(1.40e10*multiplier);

	// user prompt
	bool exitLoop2 = false;
	std::string response2{};
	double isotopeValue{};
	std::string isotopeName = "";
	std::cout << "Select a fertile radioactive isotope:\n<1>" << _233U << "\n<2>" << _235U << "\n<3>" << _238U << "\n<4>" << _239Pu << "\n<5>" << _232Th << "\n";
    while (!exitLoop2) {
		std::cin >> response2;
		if (response2 == "1") {
			isotopeValue = HALF_LIFE_233U;
			isotopeName = _233U;
			exitLoop2 = true;
		}
		else if (response2 == "2") {
			isotopeValue = HALF_LIFE_235U;
			isotopeName = _235U;
			exitLoop2 = true;
		}
		else if (response2 == "3") {
			isotopeValue = HALF_LIFE_238U;
			isotopeName = _238U;
			exitLoop2 = true;
		}
		else if (response2 == "4") {
			isotopeValue = HALF_LIFE_239Pu;
			isotopeName = _239Pu;
			exitLoop2 = true;
		}
		else if (response2 == "5") {
			isotopeValue = HALF_LIFE_232Th;
			isotopeName = _232Th;
			exitLoop2 = true;
		}
		else {
			std::cout << errorMessage;
		}
	}

	/* decay constant | the natural logarithm of  2 divided by the half life.
	 * print the decay constant as a number with 20 decimal places. */
	const double decay = (std::log(2)) / isotopeValue;
	std::cout << "Probability per " << unit << " for a single " << isotopeName << " nucleus to decay: " << std::fixed << std::setprecision(20) << decay;

	return 0;
}
