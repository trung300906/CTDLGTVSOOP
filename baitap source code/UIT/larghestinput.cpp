#include <iostream>
using namespace std;

int largest_input()
{
    // Nested lambda function to handle recursion and input
    auto max_input_lambda = [](auto &&self) -> int
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            return 0;
        }

        int max = self(self);
        return (n > max) ? n : max;
    };

    // Initial call to the lambda function
    return max_input_lambda(max_input_lambda);
}

int main()
{
    cout << largest_input() << endl;
    return 0;
}
