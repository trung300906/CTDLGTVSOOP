#include <iostream>
#include <new>

int main()
{
    while (true)
    {
        try
        {
            int *p = new int[100000000]; // Attempt to allocate a large array
            if (p == nullptr)
            {
                std::cerr << "////" << std::endl;
            }
            else
            {
                std::cerr << "///" << std::endl;
            }
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "//////" << e.what() << std::endl;
        }
    }
    return 0;
}
