#include <stdio.h>
#include <stdbool.h>


// Function prototype
void strip_chars(char *str, const char *remove_chars);

int main() {
    char str[] = "Carnegie Mellon";
    char remove_chars[] = "l ";
    
    printf("Original string: %s\n", str);
    strip_chars(str, remove_chars);
    printf("String after removing l in the string '%s': %s\n", remove_chars, str);
    
    return 0;
}


// Function to strip specific characters from a string
void strip_chars(char *str, const char *remove_chars) {
    int write_pos = 0;
    
    // Logic starts here
    for (int read_pos = 0; str[read_pos] != '\0'; read_pos++) {
        bool found = false;
        
        // Checking  if the current letter is in the array
        for (int i = 0; remove_chars[i] != '\0'; i++) {
            if (str[read_pos] == remove_chars[i]) {
                found = true;  // marking the character for removal
                break;
            }
        }
        
        // If the character is not found in the array, saved in the string
        if (!found) {
            str[write_pos++] = str[read_pos];
        }
    }
    str[write_pos] = '\0';
}

