#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>

// Function to perform fast doubling method for Fibonacci
std::pair<uint64_t, uint64_t> fibonacci_fast_doubling(uint64_t n)
{
    if (n == 0)
    {
        return {0, 1};
    }
    auto [a, b] = fibonacci_fast_doubling(n >> 1);
    uint64_t c = a * (2 * b - a);
    uint64_t d = a * a + b * b;
    if (n & 1)
    {
        return {d, c + d};
    }
    else
    {
        return {c, d};
    }
}

// Function to calculate part of Fibonacci sequence
uint64_t compute_partial_fib(uint64_t start, uint64_t end)
{
    auto fib_start = fibonacci_fast_doubling(start).first;
    auto fib_end = fibonacci_fast_doubling(end).first;
    return fib_end - fib_start;
}

// Efficient parallel computation of Fibonacci
uint64_t parallel_fibonacci(uint64_t n, int num_workers)
{
    uint64_t segment_size = n / num_workers;
    std::vector<std::pair<uint64_t, uint64_t>> ranges(num_workers);
    for (int i = 0; i < num_workers; ++i)
    {
        ranges[i] = {i * segment_size, (i + 1) * segment_size};
    }
    ranges[num_workers - 1].second = n;

    std::vector<std::future<uint64_t>> futures;
    for (const auto &range : ranges)
    {
        futures.push_back(std::async(std::launch::async, compute_partial_fib, range.first, range.second));
    }

    uint64_t final_result = 0;
    for (auto &future : futures)
    {
        final_result += future.get();
    }
    return final_result;
}

std::string MAIN(const std::string &input_file)
{
    std::ifstream file(input_file);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    uint64_t n, modul;
    file >> n >> modul;
    std::vector<uint64_t> positions(n);
    for (uint64_t i = 0; i < n; ++i)
    {
        file >> positions[i];
    }

    int num_workers = 8;
    std::vector<uint64_t> results;
    for (const auto &pos : positions)
    {
        uint64_t fib_result = parallel_fibonacci(pos, num_workers) % modul;
        results.push_back(fib_result);
    }

    std::string output;
    for (const auto &result : results)
    {
        output += std::to_string(result) + "\n";
    }
    return output;
}

int main(int argc, char *argv[])
{
    try
    {
        std::string output = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt");
        std::cout << output;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
