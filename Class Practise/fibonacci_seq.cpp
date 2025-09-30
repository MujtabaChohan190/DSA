#include <iostream>

int fib(int n) {
    if(n == 0 || n == 1) {
        return n;
    }

    return fib(n-1) + fib(n-2);
}

int main() {
    int index = 8; 
    
    int result = fib(index);
    
    std::cout << "The Fibonacci number at index " << index << " is: " << result << std::endl;
    
    std::cout << "First 10 Fibonacci numbers: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
