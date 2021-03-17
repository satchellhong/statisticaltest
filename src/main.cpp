#include <iostream>
#include <cmath> // for calculating log() and exp()
#include "../header/statisticaltest.h" // contains statistical test methods

using namespace std;
using namespace STATTEST;
int main() {
	cout << GetFisherPvalue(5,0,1,4) << endl;
	return 0;
}
