#if 0
#include <iostream>
#include <iomanip>
using namespace std;

int sum(int a, int b)
{
	return a + b;
}
int main()
{
	cout << "Enter an integer: ";
	int x;
	cin >> x;

	cout << "Enter another integer: ";
	int y;
	cin >> y;

	if (x == y)
		cout << x << " == " << y << "\n";
	if (x != y)
		cout << x << " != " << y << "\n";
	if (x > y)
		cout << x << " > " << y << "\n";
	if (x < y)
		cout << x << " < " << y << "\n";
	if (x >= y)
		cout << x << " >= " << y << "\n";
	if (x <= y)
		cout << x << " <= " << y << "\n";
    double	d1{ 1.0 };
	double	d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

	if (d1 == d2)
		cout << "d1 == d2" << "\n";
	else if (d1 > d2)
		cout << "d1 > d2" << "\n";
	else if (d1 < d2)
		cout << "d1 < d2" << "\n";

	cout << setprecision(20);	// show 20 digits
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
    cout << "Enter a number: ";
	int value;
	cin >> value;

	if (!value)
		cout << value << " is false" << endl;
	else
		cout << value << " is true" << endl;

	if ((value > 1) && (value < 100))
		cout << value << " is between 1 and 100" << endl;
	else
		cout << value << " is not between 1 and 100" << endl;

	if ((value == 1) || (value == 100))
		cout << value << " == 1 or "<< value <<" == 100" << endl;
	else
		cout << value << " != 1 or " << value << " != 100" << endl;

	return 0;
}
#endif
#include <iostream>

using namespace std;

// Main function
int main()
{
    int a = 5; //  101
    int b = 3; //  011

    // Bitwise AND
    int bitwise_and = a & b;

    // Bitwise OR
    int bitwise_or = a | b;

    // Bitwise XOR
    int bitwise_xor = a ^ b;

    // Bitwise NOT
    int bitwise_not = ~a;

    // Bitwise Left Shift
    int left_shift = a << 2;

    // Bitwise Right Shift
    int right_shift = a >> 1;

      // Printing the Results of
    // Bitwise Operators
    cout << "AND: " << bitwise_and << endl;
    cout << "OR: " << bitwise_or << endl;
    cout << "XOR: " << bitwise_xor << endl;
    cout << "NOT a: " << bitwise_not << endl;
    cout << "Left Shift: " << left_shift << endl;
    cout << "Right Shift: " << right_shift << endl;
    //XOR >< AND

    return 0;
}