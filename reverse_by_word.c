#include <stdio.h>
#include <string.h>
#include <ctype.h>

// main function

int main() {
    char str[] = "Carnegie Mellon University";
    
    printf("our main string: %s\n", str);
    reverse_by_word(str);
    printf("reversed string by each word: %s\n", str);
    
    return 0;
}

// function to reverse each word in a string
void reverse_by_word(char *str) {
    int starting = 0;
    int ending = 0;
    int length = strlen(str);
    
    while (ending <= length) {
        if (isspace(str[ending]) || str[ending] == '\0') {
            int left_side = starting;
            int right_side = ending - 1;
            
            while (left_side < right_side) {
                char temp = str[left_side];
                str[left_side] = str[right_side];
                str[right_side] = temp;
                left_side++;
                right_side--;
            }
            starting = ending + 1;
        }
        ending++;
    }
}


