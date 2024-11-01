# Password_strength_Tester_2.0
## Project Overview
The Password Strength Checker is a C++ program designed to help users evaluate the strength of their passwords. It assesses various criteria such as length, inclusion of uppercase and lowercase characters, digits, special characters, and (as of version 2) cross-references against a database of compromised passwords. This project is an educational tool to improve user security awareness by guiding them to choose stronger, more secure passwords.

## Features
* Password Strength Evaluation:
      * Checks password length.
      * Ensures inclusion of uppercase and lowercase letters.
      * Validates the presence of digits and special characters.
      * Rates password strength from "Very Weak" to "Very Strong."
* Compromised Password Detection:
      * Version 2 introduces a check against a database of compromised passwords. This feature alerts the user if their password has appeared in known breaches.
## Version History
### Version 1.0
* Basic password strength checker without compromised password detection.
* Strength ratings based on:
      * Password length (minimum of 8 characters).
      * Uppercase and lowercase letters.
      * Digits.
      * Special characters.
### Version 2.0
* **New Feature:** Compromised password detection.
      * Loads a file containing a list of known compromised passwords and compares it against user input.
* Improvements in password validation logic and user interface.
## Installation
1. Clone the repository:
```cpp
git clone https://github.com/username/password-strength-checker.git
```
2. Navigate to the project directory:
```
cd password-strength-checker
```
3. Compile the code:

```
g++ -o password_checker main.cpp
```
## Usage
1. Run the program:
```
./password_checker
```
2. Enter a password when prompted to evaluate its strength.

3. Compromised Passwords Database:

      * Ensure that compromised_passwords.txt (a text file with one password per line) is located in the project directory.
      * You can download commonly compromised passwords from resources like [Have I Been Pwned][https://haveibeenpwned.com/] or the [SecLists GitHub][https://github.com/danielmiessler/SecLists/tree/master/Passwords] repository.

4. Example of running the program:
```
Enter a password to evaluate its strength: myPassword123!
Password strength: Strong
```
```
Enter the password to be evaluated: password
This password is compromised. Please choose a different password.
```
## Code Overview
Here is a breakdown of the main functions used in the program:

* `bool hasUpperCase(const std::string &password)`: Checks if the password contains any uppercase letters.
* `bool hasLowerCase(const std::string &password)`: Checks if the password contains any lowercase letters.
* `bool hasDigit(const std::string &password)`: Checks if the password contains digits.
* `bool hasSpecialChar(const std::string &password)`: Checks if the password contains any special characters.
* `bool loadCompromisedPasswords(const std::string &filename, std::unordered_set<std::string> &passwordSet)`: Loads compromised passwords from a file into a set for fast lookup.
* `std::string evaluatePasswordStrength(const std::string &password)`: Evaluates the overall password strength and assigns a rating.
## Sample Code Snippet
Here’s the core of the compromised password loading feature introduced in version 2:
```cpp
bool loadCompromisedPasswords(const std::string &filename, std::unordered_set<std::string> &passwordSet) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open password file." << std::endl;
        return false;
    }

    std::string password;
    while (std::getline(file, password)) {
        passwordSet.insert(password);
    }

    file.close();
    return true;
}
```
## Language and Libraries
* Language: C++
* Libraries: Standard C++ libraries including
  `<iostream>`, `<stream>`,`<string>`,`<unordered_set>`, and `<cctype>` for character checking functions.
  
## Contribution
Feel free to contribute by submitting issues, making pull requests, or suggesting enhancements.

