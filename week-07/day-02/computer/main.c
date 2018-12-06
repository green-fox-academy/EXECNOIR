#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

typedef struct computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} computer_t;

typedef struct notebook {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} notebook_t;

int main()
{
    computer_t computer;
    computer.cpu_speed_GHz = 3;
    computer.ram_size_GB = 16;
    computer.bits = 64;

    notebook_t notebook;
    notebook.cpu_speed_GHz = 1.7;
    notebook.ram_size_GB = 4;
    notebook.bits = 64;


    printf("Computer data\nCPU Speed: %.1f\nMemory: %d\nBit: %d\n", computer.cpu_speed_GHz, computer.ram_size_GB, computer.bits);
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Notebook data\nCPU Speed: %.1f\nMemory: %d\nBit: %d\n", notebook.cpu_speed_GHz, notebook.ram_size_GB, notebook.bits);
    return 0;
}