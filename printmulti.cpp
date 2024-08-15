#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex print_mutex;

void print_numbers(int start, int end) {
    for (int i = start; i < end; ++i) {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << i << std::endl;
    }
}

int main() {
    const int num_threads = 10;
    const int range = 100 / num_threads;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(print_numbers, i * range, (i + 1) * range);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
