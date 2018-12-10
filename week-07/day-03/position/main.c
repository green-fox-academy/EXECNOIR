#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int distance(char* sentence);

int main ()
{
    char str[] = "This is a sample string";
    char *first, *last;
    printf("%d", distance(str));
    return 0;
}
int distance(char* sentence)
{   int first = 0;

    for (int i = 0; i < strlen(sentence) ; ++i) {
        if(sentence[i] == 's'){
            first = i+1;
            break;
        }
    }
    int last = 1;
    for (int j = 0; j < strlen(sentence) ; ++j) {
        if(sentence[j] == 's'){
            last = j+1;
        }
    }
    return last-first;
}