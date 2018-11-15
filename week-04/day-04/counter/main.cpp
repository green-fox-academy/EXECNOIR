#include <iostream>

int counter(int n);

int main() {
    counter(10);
    return 0;
}

int counter(int n){
    if( n <= -1){
    return 0;
    }else{
        std::cout << n << std::endl;
        return counter(n-1);
    }
}