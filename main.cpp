#include <iostream>
#include <experimental/random>
int main() {
    std::cout << std::to_string(std::experimental::randint(1, 10000)) << std::endl;
    return 0;
}
