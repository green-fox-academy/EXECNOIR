#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
int janos(int x);

int main() {
    std::cout << janos(16) << std::endl;
    return 0;
}
int janos(int x){

    if(x <= 0){
        return x;
    }else {
        return x%10+janos(x/10);
    }

}