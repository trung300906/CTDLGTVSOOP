#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    /* Khởi tạo một chuỗi theo nhiều cách */
    /* Khởi tạo một chuỗi HowKteam.com cho biến strString */
    string strString("HowKteam.com");
    string strString0("");                // Khởi tạo chuỗi strString0 rỗng
    string strString1("Kteam");           // Khởi tạo chuỗi "Kteam" cho strString1
    string strString2{"Free Education!"}; // Khởi tạo chuỗi "Kteam" cho strString2
    string strString3 = "HowKteam.com";   // Khởi tạo chuỗi "HowKteam.com" cho strString3
    string strString4 = strString1;       // Gán giá trị chuỗi strString1 cho strString4

    /* Khởi tạo một chuỗi số */
    string strNumber = "88"; // Khởi tạo chuỗi "88" cho strNumber, không phải số
    /* Xuất chuỗi HowKteam.com lên console */
    cout << strString << endl;
    cout << "Enter your full name: ";
    string strName;
    cin >> strName;

    cout << "Enter your age: ";
    string strAge;
    cin >> strAge;

    cout << "Your name is " << strName << endl;
    cout << "Your age is " << strAge << endl;
    // getline
    cout << "Enter your age: ";
    int nAge;
    cin >> nAge;
    cin.ignore(32767, '\n');
    cout << "Enter your name: ";
    getline(cin, strName);

    cout << "Hello, " << strName << endl;
    cout << "Your age " << nAge << endl;
    cout << "Enter your text: ";
    string strText;
    getline(cin, strText, '_');

    cout << "Your text: " << endl;
    cout << strText << endl;
    string a("69");
    string b("96");
    string c = a + b; // a and b will be appended, not added

    cout << c << endl;
    a += " string";
    cout << a << endl;

    string myName("Hello HowKteam.com!");

    cout << myName << " has " << myName.length() << " characters\n";
    cout << myName << " has " << myName.size() << " characters\n";
}