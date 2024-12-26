#include <iostream>
#include <string>
using namespace std;

string formatText(const string &input)
{
    string result;
    int n = input.size();
    bool in_space = false; // Để kiểm tra khoảng cách dư thừa

    for (int i = 0; i < n; ++i)
    {
        if (input[i] == ' ')
        {
            if (!result.empty() && result.back() != ' ' && input[i - 1] != '.')
            {
                // Chỉ thêm 1 dấu cách nếu không có trước đó và không nằm sau dấu chấm
                result += ' ';
            }
            in_space = true;
        }
        else if (input[i] == '.')
        {
            // Xóa dấu cách trước dấu chấm nếu có
            if (!result.empty() && result.back() == ' ')
            {
                result.pop_back();
            }
            // Thêm dấu chấm vào kết quả
            result += '.';
            // Bỏ qua dấu cách sau dấu chấm nếu có
            while (i + 1 < n && input[i + 1] == ' ')
            {
                ++i;
            }
            // Thêm dấu cách sau dấu chấm, nếu không phải dấu chấm cuối
            if (i + 1 < n)
            {
                result += ' ';
            }
            in_space = false;
        }
        else
        {
            // Thêm ký tự bình thường
            result += input[i];
            in_space = false;
        }
    }

    return result;
}

int main()
{
    string input;
    getline(cin, input);
    cout << input << endl;
    string output = formatText(input);
    cout << output << endl;
    return 0;
}