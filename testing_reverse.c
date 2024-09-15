#include <stdio.h>
#include <string.h>
#include <ctype.h>  //for allowing us string manipulation specifically for lower case part

// Function to reverse a string and turn it into lower case
void reverse_string(char *str) {
    int length_of_string = strlen(str);
    int left_side = 0, right = length_of_string - 1;
    
    while (left_side < right) {
        char temp = tolower(str[left_side]);
        str[left_side] = tolower(str[right]);
        str[right] = temp;
        left_side++;
        right--;
    }
    
    if (left_side == right) {
        str[left_side] = tolower(str[left_side]);
    }
}

int main() {
    char str[] = "Carnegie Mellon";
    
    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed and lowercase string: %s\n", str);
    
    return 0;
}
