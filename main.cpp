#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

unsigned int hilbert(int x, int y) {
	//this function is dificult to explain without diagrams,
	short orientation = 0;
	int reflectedX = 0;
	int reflectedY = 0;
	unsigned int result = 0;

	//for the nth bit of x and y(bitwise opperations used)
	for (int n = 15; n >= 0; n--) {
		if (orientation == 0) {
			reflectedX |= ((x >> n) & 1) << n;
			reflectedY |= ((y >> n) & 1) << n;
		}
		else if (orientation == 1) {
			reflectedX |= ((y >> n) & 1) << n;
			reflectedY |= ((x >> n) & 1) << n;
		}
		else if (orientation == 2) {
			reflectedX |= (~(y >> n) & 1) << n;
			reflectedY |= (~(x >> n) & 1) << n;
		}
		else if (orientation == 3) {
			reflectedX |= (~(x >> n) & 1) << n;
			reflectedY |= (~(y >> n) & 1) << n;
		}
		else {
			return 15;
		}


		result |= ((((reflectedX >> n) & 1) ^ ((reflectedY >> n) & 1)) | (((reflectedX >> n) & 1) << 1)) << (2 * n);

		if (((reflectedY >> n) & 1) == 0) {
			orientation ^= (((reflectedX >> n) & 1) + 1);
		}
		
		
	}



	return result;
}

int main() {

	//main input
	cout << hilbert(3, 2) << "this is indeed a change, fuck you it did'nt show up, damn it.";
	return 0;
}