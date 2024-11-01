#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cctype>

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

int main() {
    std::unordered_set<std::string> compromisedPasswords;

    // Use the absolute path
    std::string filename = "/Users/basiljoy/Documents/Mac/CUJ/Certification and Resume/Projects/Password tester/compromised_passwords.txt";
    
    if (!loadCompromisedPasswords(filename, compromisedPasswords)) {
        return 1;  // Exit if file loading fails
    }

    // Continue with the rest of your password strength checking code
    std::string password;
    std::cout << "Enter the passowrd to be evaluated: ";
    std::getline(std::cin, password);

    // Check if the password is in the compromised list
    if (compromisedPasswords.find(password) != compromisedPasswords.end()) {
        std::cout << "This password is compromised. Please choose a different password." << std::endl;
        return 1;
    }

    // The rest of the password strength checks go here
    bool upper_case_present=false, lower_case_present=false, digit_present=false, special_char_present=false;


//checking for Upper case
    for (int i=0; i < password.length();i++)
        if(std::isupper((char)password[i])) 
            upper_case_present=true;

//checking for lower case            
    for(auto i :password)
        if(std::islower(i))
            lower_case_present=true;

//checking for digit
    for (int i=0; i < password.length();i++)
        if(std::isdigit((int)password[i]))
             digit_present=true;
    
//checking for special char    
    std::string special_chr="~!@#$%^&*()_+`{}|[]\':,./<>?";
    for(auto i: password)
        if(special_chr.find(i) != std::string::npos)
            special_char_present=true;

    int score = 0;
    if (upper_case_present) score++;
    if (lower_case_present) score++;
    if (digit_present) score++;
    if (special_char_present) score++;
    if (password.length() >= 8) score++;

    std::cout << "Score: " << score << std::endl;

    std::string strength;
    switch (score) 
    {
        case 5: strength = "Very Strong"; break;
        case 4: strength = "Strong"; break;
        case 3: strength = "Moderate"; break;
        case 2: strength = "Weak"; break;
        default: strength = "Very Weak"; break;
    }

    std::cout << "Password strength: " << strength << std::endl;

    return 0;
}
