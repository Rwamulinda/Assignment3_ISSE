#include <stdio.h>
#include <stdbool.h>

// Function to strip specific characters from a string
void strip_chars(char *str, const char *remove_chars) {
    int write_pos = 0;
    
    // Loop through each character in the original string
    for (int read_pos = 0; str[read_pos] != '\0'; read_pos++) {
        bool found = false;
        
        // Check if the current character is in the remove_chars array
        for (int i = 0; remove_chars[i] != '\0'; i++) {
            if (str[read_pos] == remove_chars[i]) {
                found = true;  // Mark the character for removal
                break;
            }
        }
        
        // If the character isn't found in remove_chars, keep it in the string
        if (!found) {
            str[write_pos++] = str[read_pos];
        }
    }
    
    // Null-terminate the modified string
    str[write_pos] = '\0';
}

int main() {
    char str[] = "Carnegie Mellon";
    char remove_chars[] = "l ";
    
    printf("Original string: %s\n", str);
    strip_chars(str, remove_chars);
    printf("String after removing '%s': %s\n", remove_chars, str);
    
    return 0;
}
