#include <iostream>
using namespace std;

int main()
{
    // 0 1 2 3 4  5
    // K t e a m \0
    char szKteam[] = "Kteam";
    cout << szKteam << endl; // "Kteam"

    // 0 1 2 3 4 5 6  7  8  9
    // F r e e E d u \0 \0 \0
    char szFreeEdu[10] = "FreeEdu";
    cout << szFreeEdu << endl; // "FreeEdu"

    // ký tự szFreeEdu[7] là '\0' (null), nên chỉ in chuỗi đến vị trí 6
    // 0 1 2 3 4 5 6  7  8  9
    // F r e e E d u \0 \0  a
    szFreeEdu[9] = 'a';
    cout << szFreeEdu << endl; // "FreeEdu"

    char szFullName[50];

    cout << "Nhap ho ten: ";
    cin >> szFullName;

    cout << "Ho ten cua ban la: " << szFullName << endl;

    /* Giải quyết 2 vấn đề nhập chuỗi bằng phương thức std::cin.getline()
        Hàm std::cin.getline() sẽ đọc tất cả các ký tự từ bàn
        phím(bao gồm khoảng trắng ‘ ‘) cho đến khi gặp ký tự enter ‘\n’(mặc định)
        .Nếu số lượng ký tự nhập vào lớn hơn độ dài truyền vào hàm,
        mọi ký tự dư thừa sẽ bị loại bỏ.return 0; */
    char szAddress[20];

	cout << "Nhap dia chi: ";
	cin.getline(szAddress, 20);

	cout << "Dia chi cua ban la: " << szAddress << endl;

}
