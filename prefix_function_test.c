#include <stdio.h>
#include <stdbool.h>

// bool function to check if the string starts with a prefix
bool is_prefix(const char *prefix, const char *str) {
    while (*prefix && *str) {
        if (*prefix != *str) {
            return false;
        }
        prefix++;
        str++;
    }
    return *prefix == '\0';
}

// Function to test the is_prefix function
void test_is_prefix(const char *prefix, const char *str, bool expected) {
    bool result = is_prefix(prefix, str);
    
    printf("Testing if '%s' is a prefix of '%s': ", prefix, str);
    if (result == expected) {
        printf("Test passed!\n");
    } else {
        printf("Test failed. Expected: %s\n", expected ? "True" : "False");
    }
}

int main() {
    // Test cases
    test_is_prefix("Carnegie", "Carnegie Mellon", true);
    test_is_prefix("Mellon", "Carnegie Mellon", false);
    test_is_prefix("Car", "Carnegie Mellon", true);
    test_is_prefix("car", "Carnegie Mellon", false);  // Case-sensitive test
    test_is_prefix("", "Carnegie Mellon", true);      // Empty prefix
    test_is_prefix("Carnegie Mellon", "Carnegie", false);  // Prefix longer than the string
    test_is_prefix("M", "Mellon", true);
    test_is_prefix("Mell", "Mellon", true);
    test_is_prefix("ello", "Hello", false);  // Mismatch

    return 0;
}
