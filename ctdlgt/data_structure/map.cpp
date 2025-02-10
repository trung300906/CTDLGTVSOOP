#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> people = {{"John", 32}, {"Adele", 45}, {"Bo", 29}};
    cout << "John is: " << people["John"] << endl;
    cout << "john is: " << people.at("John") << endl;
    people["John"] = 50;
    people.at("John") = 50;
    cout << "John is: " << people.at("John") << endl;
    people.insert({"Jenny", 22});
    people.insert({"Liam", 24});
    people.insert({"Kasper", 20});
    people.insert({"Anja", 30});
    map<string, int>::iterator itr = people.begin();
    cout << "========================================= \n";
    for (auto &i : people)
    {
        cout << i.first << " " << i.second << " ";
    }
    itr++;
    cout << "\n debug " << (*itr).first << " " << (*itr).second << endl; // same as -> ==>>>>> (*class_name).iterator = classname ->iterator

    map<string, int> mixxter = {{"John", 32}, {"Adele", 45}, {"Bo", 29}}; // sort follow key
    for (auto pair : mixxter)
    {
        cout << pair.first << " is: " << pair.second << " ";
    }
}