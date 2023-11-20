#include <iostream>

int main(){
    std::cout << "std::sizeof(short): " << sizeof(short) << std::endl;
    std::cout << "std::sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "std::sizeof(long): " << sizeof(long) << std::endl;
    std::cout << "std::sizeof(long long): " << sizeof(long long) << std::endl;
    std::cout << "std::sizeof(void*): " << sizeof(void*) << std::endl;
    return 0;
}