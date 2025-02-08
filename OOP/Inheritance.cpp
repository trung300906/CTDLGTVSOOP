#include <iostream>
using namespace std;

class car
{
public:
    void car_output()
    {
        cout << " motor ";
    }
};
class model : public car
{
public:
    void model_output()
    {
        cout << "tesla";
    }
};
int main()
{
    model obj;
    obj.car_output();
    obj.model_output();
}