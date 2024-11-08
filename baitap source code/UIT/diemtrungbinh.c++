#include <iostream>
#include <iomanip> // For setprecision

using namespace std;

int main()
{
    float toan, ly, hoa, dtb;
    string loai;

    // Input
    cin >> toan;
    cin >> ly;
    cin >> hoa;

    // Calculate the average score
    dtb = (toan + ly + hoa) / 3;

    // Determine the classification
    if (dtb >= 9 && dtb <= 10)
    {
        loai = "XUAT SAC";
    }
    else if (dtb >= 8 && dtb < 9)
    {
        loai = "GIOI";
    }
    else if (dtb >= 7 && dtb < 8)
    {
        loai = "KHA";
    }
    else if (dtb >= 6 && dtb < 7)
    {
        loai = "TB KHA";
    }
    else if (dtb >= 5 && dtb < 6)
    {
        loai = "TB";
    }
    else if (dtb >= 4 && dtb < 5)
    {
        loai = "YEU";
    }
    else
    {
        loai = "KEM";
    }

    // Output the average score and classification
    cout << fixed << setprecision(2) << "DTB = " << dtb << endl;
    cout << "Loai: " << loai << endl;

    return 0;
}
