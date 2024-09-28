#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char szTeam[20] = "Kteam"; // mảng có 20 phần tử (5 ký tự thường, 15 ký tự '\0')
    cout << "Team cua tui: " << szTeam << endl;
    cout << szTeam << " co " << strlen(szTeam) << " ky tu." << endl;
    cout << szTeam << " co " << sizeof(szTeam) << " phan tu trong mang." << endl;

    /* Để chuyển 1 chuỗi từ chữ thường sang chữ in hoa và ngược lại, bạn có thể sử dụng 2 hàm:

    strlwr(): chuyển chuỗi s thành chuỗi thường (‘A’ thành ‘a’, ‘B’ thành ‘b’, …, ‘Z’ thành ‘z’).
    strupr(): chuyển chuỗi s thành chuỗi IN hoa (‘a thành ‘A’, ‘b’ thành ‘B’, …, ‘z’ thành ‘Z’). */
    char szString1[] = "Hello Howkteam.com!";
    char szString2[] = "Hello Howkteam.com!";

    cout << "s1: " << szString1 << endl;
    cout << "s2: " << szString2 << endl;

    strlwr(szString1);
    strupr(szString2);
    cout << "s1: " << szString1 << endl;
    cout << "s2: " << szString2 << endl;
    // Để sao chép 1 chuỗi ký tự sang 1 chuỗi ký tự khác, bạn có thể sử dụng hàm strcpy().
    char szSource[] = "Kteam";
    char szDest[20];

    // sao chép chuỗi szSource sang chuỗi szDest
    strcpy(szDest, szSource);
    cout << "Source: " << szSource << endl;
    cout << "Dest: " << szDest << endl;
    // Chú ý: Khi sử dụng hàm này, chuỗi đích phải đủ lớn để chứa được chuỗi nguồn. Nếu không, vấn đề tràn mảng sẽ xảy ra.
    // Để nối 1 chuỗi vào sau chuỗi khác, bạn có thể sử dụng hàm strcat().
    //  nối chuỗi
    strcat(szDest, " ");      // "Hello "
    strcat(szDest, szSource); // "Hello Howkteam.com!"
    cout << "Dest: " << szDest << endl;

    // so sánh 2 chuỗi
    int result = strcmp(szString1, szString2);
    if (result < 0)
        cout << "s1 < s2" << endl;
    else if (result > 0)
        cout << "s1 > s2" << endl;
    else
        cout << "s1 == s2" << endl;

    if (strstr(szString1, szString2) != NULL)
        cout << "Tim thay " << szString2 << " trong " << szString1 << endl;
    else
        cout << "Khong tim thay!" << endl;
    return 0;
}
