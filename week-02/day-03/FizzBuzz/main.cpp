#include <iostream>

int main(int argc, char* args[]) {

    for (int i = 1; i < 100; ++i) {

        if((i%3==0)&&(i%5==0)){

            std::cout << "FizzBuzz" << std::endl;
        }else{
            if(i % 3 == 0){

                std::cout << "Fizz" << std::endl;
            }
            if(i % 5 ==0){

                std::cout << "Buzz" << std::endl;
            }
            else{
                std::cout << i << std::endl;
            }

        }



    }

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    return 0;
}