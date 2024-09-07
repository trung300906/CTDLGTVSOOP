#include <iostream>
using namespace std;

int main()
{
	bool b1{ true };	// b1 is true
	cout << b1 << endl;	// in 1 ra màn hình
	cout << !b1 << endl;	// in 0 ra màn hình

	bool b2{ false };	// b1 is false
	cout << b2 << endl;	// in 0 ra màn hình
	cout << !b2 << endl;	// in 1 ra màn hình
    cout << std::boolalpha;		// in "true" hoặc "false" với kiểu bool
	cout << true << endl;		// in "true" ra màn hình
	cout << false << endl;		// in "false" ra màn hình
	
	cout << std::noboolalpha;		// in 1 hoặc 0 với kiểu bool
	cout << true << endl;		// in 1 ra màn hình
	cout << false << endl;		// in 0 ra màn hình
	if (b1)
		cout << "b1 is true" << endl;
	else
		cout << "b1 is false" << endl;
	if (b2)
		cout << "b2 is true" << endl;
	else
		cout << "b2 is false" << endl;

	return 0;
}