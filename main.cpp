#include <iostream>
#include <cctype>
#include <locale>
using namespace std;


bool hasUpperCase(const string &password) {
    for (char ch : password)
        if (isupper(ch)) return true;
    return false;
}

bool hasLowerCase(const string &password) {
    for (char ch : password)
        if (islower(ch)) return true;
    return false;
}

bool hasDigit(const string &password) {
    for (char ch : password)
        if (isdigit(ch)) return true;
    return false;
}

bool hasSpecialChar(const string &password) {
    string specialChars = "!@#$%^&*()-_+=<>?/{}[]";
    for (char ch : password)
        if (specialChars.find(ch) != string::npos) return true;
    return false;
}

string checkPasswordStrength(const string &password) {
    int length = password.length();

    bool upper = hasUpperCase(password);
    bool lower = hasLowerCase(password);
    bool digit = hasDigit(password);
    bool special = hasSpecialChar(password);

    int strength = upper + lower + digit + special;

    if (length < 8)
        return "Juda kuchsiz ";
    else if (strength == 1)
        return "Kuchsiz ";
    else if (strength == 2)
        return "O‘rtacha ";
    else if (strength == 3)
        return "Kuchli ";
    else
        return "Juda kuchli ";
}

int main() {
    setlocale(LC_ALL,"");
    string password;

    cout << "Parol kiriting: ";
    cin >> password;

    cout << "Parol kuchliligi: " << checkPasswordStrength(password) << endl;

    return 0;
}
