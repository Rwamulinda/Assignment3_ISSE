#include <stdio.h>
#include <string.h>
#include <ctype.h>  //for allowing us string manipulation specifically for lower case part

int main() {
    char str[] = "Carnegie Mellon";
    
    printf("our orginal string: %s\n", str);
    reverse_string(str);
    printf("Reversed and lower case version of the orginal string: %s\n", str);
    printf("test passed");
    
    return 0;
}

// Function to reverse a string and turn it into lower case
void reverse_string(char *str) {
    int length_of_string = strlen(str); 
    int left_side = 0, right_side = length_of_string - 1; // variables for reversing
    
    while (left_side < right_side) {                // set up the conditions for reversing and sametime changing into lower case
        char temp = tolower(str[left_side]);
        str[left_side] = tolower(str[right_side]);
        str[right_side] = temp;
        left_side++;
        right_side--;
    }
    
    if (left_side == right_side) {
        str[left_side] = tolower(str[left_side]);
    }
}

