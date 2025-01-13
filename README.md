# Password Strength Checker

A CLI tool to check the strength of inputted passswords. Checks against a criteria (listed below) and gives a score.

## Features

- Checks password length (minimum 8 characters)
- Verifies presence of uppercase letters
- Verifies presence of lowercase letters
- Checks for numbers
- Validates special character usage
- Provides a comprehensive strength score out of 10
- Offers detailed feedback for each criterion
- Includes an overall password strength verdict

## Requirements

- C compiler (gcc recommended)
- Standard C libraries (stdio.h, string.h, ctype.h)

## Compilation

To compile the program, use:

```bash
gcc passcheck.c -o passcheck
```

## Usage

1. Run the compiled program:
```bash
./passcheck
```

2. Enter your password when prompted
3. Review the detailed analysis, including:
   - Individual criteria checks
   - Overall strength score
   - Final password strength verdict

## Scoring System

The program uses the following scoring criteria:
- Length (≥8 characters): 2 points
- Uppercase letters: 2 points
- Lowercase letters: 2 points
- Numbers: 2 points
- Special characters: 2 points

Total possible score: 10 points

### Verdict Categories:
- 0-3: Very Weak Password
- 4-5: Weak Password
- 6-7: Moderate Password
- 8-9: Strong Password
- 10: Very Strong Password
