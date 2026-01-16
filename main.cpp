#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

struct Measurement  {
                        std::string unit;
                        int multiplier;
                    };
struct Isotopes {
                    std::string name;
                    long double value;
                };

int main()
{
	/* This is a multi-line comment.
	 * the matching asterisks to the left
	 * can make this easier to read
	 */
    
    const int GREGORIAN_SECONDS = 31556952;
    std::vector<Measurement> measurement =  {
                                                {"years",GREGORIAN_SECONDS/GREGORIAN_SECONDS},
                                                {"seconds",GREGORIAN_SECONDS/1},
                                                {"hours",GREGORIAN_SECONDS/3600}
                                            };
	
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
	int stringToInt{};
    std::cout << "Would you like to measure in years, seconds, or hours (y/s/h)? ";
	while (!exitLoop1) {
		std::cin >> response1;
    	if (response1 == "y") {
			stringToInt = 1;
			exitLoop1 = true;
		}
		else if (response1 == "s") {
			stringToInt = 2;
			exitLoop1 = true;
		}
		else if (response1 == "h") {
			stringToInt = 3;
			exitLoop1 = true;
		}
		else {
			std::cout << errorMessage;
		}
	}
	
	std::vector<Isotopes> isotopes =
	    {
	        {"Uranium-233",1.592e5*measurement[stringToInt].multiplier},
	        {"Uranium-235",7.04e8*measurement[stringToInt].multiplier},
	        {"Uranium-238",4.463e9*measurement[stringToInt].multiplier},
	        {"Plutonium-239",2.411e4*measurement[stringToInt].multiplier},
	        {"Thorium-232",1.40e10*measurement[stringToInt].multiplier}
	    };
    
    // user prompt
    bool exitLoop2 = false;
	int response2{};
	int count = 0;
	std::cout << "Select a fertile radioactive isotope:\n";
	for (const auto & i:isotopes) {
        count += 1;
        std::cout << '<' << count << '>' << i.name << '\n';
    }
    while (!exitLoop2) {
		std::cin >> response2;
		if (response2 == 1) {
			exitLoop2 = true;
		}
		else if (response2 == 2) {
			exitLoop2 = true;
		}
		else if (response2 == 3) {
			exitLoop2 = true;
		}
		else if (response2 == 4) {
			exitLoop2 = true;
		}
		else if (response2 == 5) {
			exitLoop2 = true;
		}
		else {
			std::cout << errorMessage;
		}
	}
	
	/* decay constant | the natural logarithm of  2 divided by the half life.
	 * print the decay constant as a number with 20 decimal places. */
	const double decay = (std::log(2)) / isotopes[response2-1].value;
	std::cout
	    << "Probability per " << measurement[stringToInt-1].unit << " for a single " << isotopes[response2-1].name
	    << " nucleus to decay: " << std::fixed << std::setprecision(20) << decay;
	
	return 0;
}
