#include <bits/stdc++.h>
using namespace std;

struct money_out
{
    double eat, xang, bills, meditation, gara, bonus, dating, internet, spaylater, sum;
};
struct money_in
{
    double month, another;
};
void writetofilefirsttime(const string &filename, const money_out &chitieu, const money_in &nhandc, const int &count, const int &price)
{
    ofstream outFile(filename, ios::app); // read data and insert in the end of file
    if (outFile.is_open() && count == 1)
    {
        outFile << "money in per month: " << nhandc.month;
        outFile << 
        outFile << "basic data outcome per month..." << endl;
        outFile << "eat: " << chitieu.eat;
        outFile << "\n xang: " << chitieu.xang;
        outFile << " \n bills: " << chitieu.bills;
        outFile << "\n dating: " << chitieu.dating;
        outFile << "\n gara: " << chitieu.gara;
        outFile << "\n bonus: " << chitieu.bonus;
        outFile << "\n internet: " << chitieu.internet;
        outFile << "\n spaylater: " << chitieu.spaylater;
        outFile << "\n sum: " << chitieu.sum;
        outFile.close();
    }
    else
    {
        cerr << "cannot open file... file wrongs or do not exist...";
    }
    return;
}

int main()
{
    money_out chitieu;
    money_in nhandc;
    int price;
    double count = 1;
    cout << "welcome! :>" << endl;
    string filename = "/run/media/trung/linuxandwindows/code/CTDLGTVSOOP/projectmanagemoney/data.txt";
    string countfile = "/run/media/trung/linuxandwindows/code/CTDLGTVSOOP/projectmanagemoney/countfile.txt";
    ifstream countInFile(countfile);
    if (countInFile.is_open())
    {
        countInFile >> count;
        countInFile.close();
    }
    if (count == 1 && fileCheck.good())
    {
        chitieu.sum = 0;
        cout << "that's just for predict and overdata..." << endl;
        cout << "please type in basic data..." << endl;
        cout << "money in per month...";
        cin >> nhandc.month;
        cout << "money another...";
        cin >> nhandc.another;
        cout << "needed money for save: ";
        cin >> price;
        cout << "money consumption...";
        cout << "eat: ";
        cin >> chitieu.eat;
        chitieu.sum += chitieu.eat;
        cout << "xang: ";
        cin >> chitieu.xang;
        chitieu.sum += chitieu.xang;
        cout << "bills: ";
        cin >> chitieu.meditation;
        chitieu.sum += chitieu.meditation;
        cout << "dating: ";
        cin >> chitieu.dating;
        chitieu.sum += chitieu.dating;
        cout << "gara: ";
        cin >> chitieu.gara;
        chitieu.sum += chitieu.gara;
        cout << "bonus: ";
        cin >> chitieu.bonus;
        chitieu.sum += chitieu.bonus;
        cout << "internet: ";
        cin >> chitieu.internet;
        chitieu.sum += chitieu.internet;
        cout << "spaylater: ";
        cin >> chitieu.spaylater;
        chitieu.sum += chitieu.spaylater;

        writetofilefirsttime(filename, chitieu, count);
    }

    // logic function

    count++;
    ofstream countoutfile(countfile);
    if (countoutfile.is_open())
    {
        countoutfile << count;
        countoutfile.close();
    }
    return 0;
}