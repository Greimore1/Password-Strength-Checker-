#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

// Function declarations
int checkLength(const char* password);
int hasUpperCase(const char* password);
int hasLowerCase(const char* password);
int hasNumber(const char* password);
int hasSpecialChar(const char* password);

// Function to check password length
int checkLength(const char* password) {
    return (strlen(password) >= 8) ? 2 : 0;
}

// Function to check for uppercase letters
int hasUpperCase(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i]))
            return 1;
    }
    return 0;
}

// Function to check for lowercase letters
int hasLowerCase(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i]))
            return 1;
    }
    return 0;
}

// Function to check for numbers
int hasNumber(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i]))
            return 1;
    }
    return 0;
}

// Function to check for special characters
int hasSpecialChar(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i]))
            return 1;
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int score = 0;
    
    // Get password from user
    printf("Enter a password to check its strength: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    
    // Remove newline character if present
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }
    
    // Calculate score based on different criteria
    score += checkLength(password);
    score += hasUpperCase(password) * 2;
    score += hasLowerCase(password) * 2;
    score += hasNumber(password) * 2;
    score += hasSpecialChar(password) * 2;
    
    // Display results
    printf("\nPassword Strength Analysis:\n");
    printf("---------------------------\n");
    
    // Prints feedback
    printf("Length check: %s\n", 
           checkLength(password) ? "✓ Good length" : "✗ Too short (should be at least 8 characters)");
    printf("Uppercase letters: %s\n", 
           hasUpperCase(password) ? "✓ Present" : "✗ Missing (include at least one uppercase letter)");
    printf("Lowercase letters: %s\n", 
           hasLowerCase(password) ? "✓ Present" : "✗ Missing (include at least one lowercase letter)");
    printf("Numbers: %s\n", 
           hasNumber(password) ? "✓ Present" : "✗ Missing (include at least one number)");
    printf("Special characters: %s\n", 
           hasSpecialChar(password) ? "✓ Present" : "✗ Missing (include at least one special character)");
    
    printf("\nOverall strength score: %d/10\n", score);
    
    // Provide overall assessment
    if (score < 4) {
        printf("Verdict: Very Weak Password\n");
    }
    else if (score < 6) {
        printf("Verdict: Weak Password\n");
    }
    else if (score < 8) {
        printf("Verdict: Moderate Password\n");
    }
    else if (score < 10) {
        printf("Verdict: Strong Password\n");
    }
    else {
        printf("Verdict: Very Strong Password\n");
    }
    
    return 0;
}