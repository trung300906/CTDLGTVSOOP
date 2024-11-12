#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

// Sudoku grid size
const int N = 9;

// Synchronization primitives
std::mutex mtx;
std::condition_variable cv;

// Queue to hold pending branches
std::queue<std::vector<std::vector<int>>> task_queue;
bool solving_done = false;

bool is_valid(const std::vector<std::vector<int>> &board, int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num || board[x][col] == num ||
            board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
        {
            return false;
        }
    }
    return true;
}

bool solve_sudoku(std::vector<std::vector<int>> &board)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    if (isEmpty)
    {
        return true;
    }

    for (int num = 1; num <= N; num++)
    {
        if (is_valid(board, row, col, num))
        {
            board[row][col] = num;
            if (solve_sudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void worker_thread()
{
    while (true)
    {
        std::vector<std::vector<int>> board;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []
                    { return !task_queue.empty() || solving_done; });
            if (solving_done && task_queue.empty())
            {
                return;
            }
            board = task_queue.front();
            task_queue.pop();
        }

        if (solve_sudoku(board))
        {
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "Solution found:" << std::endl;
            for (const auto &row : board)
            {
                for (int num : row)
                {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
            solving_done = true;
            cv.notify_all();
            return;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> board = {
        {0, 3, 0, 6, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 7},
        {4, 0, 5, 8, 0, 2, 1, 0, 0},
        {2, 0, 9, 0, 4, 0, 5, 0, 0},
        {0, 0, 7, 0, 1, 0, 0, 0, 0},
        {8, 0, 0, 7, 0, 0, 0, 6, 0},
        {0, 2, 0, 0, 0, 9, 0, 0, 0},
        {6, 0, 0, 0, 5, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int num_threads = std::thread::hardware_concurrency();
    std::cout << num_threads << std::endl;
    std::vector<std::thread> workers;

    {
        std::unique_lock<std::mutex> lock(mtx);
        task_queue.push(board);
    }
    cv.notify_all();

    for (int i = 0; i < num_threads; ++i)
    {
        workers.emplace_back(worker_thread);
    }

    for (auto &worker : workers)
    {
        worker.join();
    }

    if (!solving_done)
    {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
