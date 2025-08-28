#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

//new hilbert function, more readable, around 21% faster
unsigned int hilbert(int x, int y) {


	short orientation = 0;
	short quadrentX;
	short quadrentY;
	unsigned int result = 0;

	//for the nth bit of x and y
	for (int n = 15; n >= 0; n--) {

		//finds what quadrent its in(acounting for current reflection/ orientation)
		if (orientation == 0) {
			quadrentX = (x >> n) & 1;
			quadrentY = (y >> n) & 1;
		}
		else if (orientation == 1) {
			quadrentX = (y >> n) & 1;
			quadrentY = (x >> n) & 1;
		}
		else if (orientation == 2) {
			quadrentX = ~(y >> n) & 1;
			quadrentY = ~(x >> n) & 1;
		}
		else if (orientation == 3) {
			quadrentX = ~(x >> n) & 1;
			quadrentY = ~(y >> n) & 1;
		}
		else {
			return 15;
		}

		//the first bit is quadrentY, second is quadrentX 
		// [00, 01, 10, 11] -> [00, 11, 01, 10], then apends it the the result
		result |= ((quadrentX << 1) | (quadrentX ^ quadrentY)) << (2 * n);

		//changes orientation based on if it's in the bottom left or bottom right quadrent
		if (quadrentY == 0) {
			orientation ^= (quadrentX + 1);
		}


	}



	return result;
	//sidenote: i personally write binary backwards(powers of two alighned with the number line) from what you would consider normal,
	//so i have to *specifically* switch everything that involves bit manipulation, like using << instead of >>, or ordering things "corectly".
	//god, i wonder if i can switch << and >> in the compiler or something, because the way i do binary is just better,
}

int main() {
	//main input
	cout << hilbert(3, 2) << "this is indeed a change, fuck you it did'nt show up, damn it. i created a new branch for this one";
	return 0;

}