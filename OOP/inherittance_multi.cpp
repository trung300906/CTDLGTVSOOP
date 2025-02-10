#include <iostream>
using namespace std;

class grand
{
private:
    string gen_type;

public:
    string gen_grand_type_def()
    {
        this->gen_type = "AABBCc";
        cout << this->gen_type << " grand \n";
        return this->gen_type;
    }
};

class papa : public grand // cannot access private , just can access protected and public class from grand
{
private:
    string gen_type;

public:
    string gen_papa_type_def()
    {
        this->gen_type = gen_grand_type_def() + "Dd";
        cout << this->gen_type << " papa \n";
        return this->gen_type;
    }
};
class child : private papa //=> private all public and protected of papa classs and also grand class
{
private:
    string gen_type;

public:
    using grand::gen_grand_type_def; // using re-expose
    using papa::gen_papa_type_def;
    string gen_child_type_def()
    {
        this->gen_type = gen_papa_type_def() + "EE";
        cout << this->gen_type << " child \n ";
        return this->gen_type;
    }
};

int main()
{
    papa obj;
    child obj1;
    obj1.gen_child_type_def();
}