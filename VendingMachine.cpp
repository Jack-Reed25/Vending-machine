#include <iostream>
#include <string>
using namespace std;

void viewMenu();
bool selectItem(string &itemName, double &price);
bool confirmItem(const string &itemName);
void handlePayment(double price);
bool askAnotherPurchase();

int main() {
    while (true) {
        string itemName;
        double price;

        if (selectItem(itemName, price)) {
            cout << "Thank you for using the vending machine. Goodbye!\n";
            break;
        }

        handlePayment(price);
        cout << itemName << " item dispensed!\n";

        if (askAnotherPurchase()) {
            cout << "Thank you for using the vending machine. Goodbye!\n";
            break;
        }
    }
    return 0;
}

void viewMenu() { 
    cout << "\n"; 
    cout << "========= Welcome to the utility vending machine =========\n"; 
    cout << "\n"; 
    cout << "           1               2               3\n"; 
    cout << "\n"; 
    cout << "A     Water (£1.00)   Juice (£1.50)   Cola (£1.25)\n"; 
    cout << "\n"; 
    cout << "B     Crisps (£1.75)  Gum (£0.75)    Chocolate (£2.00)\n"; 
    cout << "\n"; 
    cout << "C     Mints (£0.80)   Gummies (£1.60) Biscuits (£1.40)\n\n";
}

bool selectItem(string &itemName, double &price) {
    while (true) {
        viewMenu();

        string code;
        cout << "Enter item code or X to exit: ";
        cin >> code;

        if (code == "X" || code == "x") return false;

        if (code.length() != 2) {
            cout << "Invalid code.\n";
            continue;
        }

        char letter = code[0]; // row
        char number = code[1]; // column

        if (letter == 'a') letter = 'A';
        else if (letter == 'b') letter = 'B';
        else if (letter == 'c') letter = 'C';

        switch (letter) {
            case 'A':
                switch (number) {
                    case '1': itemName = "Water"; price = 1.00; break;
                    case '2': itemName = "Juice"; price = 1.50; break;
                    case '3': itemName = "Cola"; price = 1.25; break;
                    default: cout << "Invalid code.\n\n"; continue;
                }
                break;

            case 'B':
                switch (number) {
                    case '1': itemName = "Crisps"; price = 1.75; break;
                    case '2': itemName = "Gum"; price = 0.75; break;
                    case '3': itemName = "Chocolate"; price = 2.00; break;
                    default: cout << "Invalid code.\n\n"; continue;
                }
                break;

            case 'C':
                switch (number) {
                    case '1': itemName = "Mints"; price = 0.80; break;
                    case '2': itemName = "Gummies"; price = 1.60; break;
                    case '3': itemName = "Biscuits"; price = 1.40; break;
                    default: cout << "Invalid code.\n\n"; continue;
                }
                break;

            default:
                cout << "Invalid code.\n";
                continue;
        }

        cout << "You selected: " << itemName << " (£" << price << ")\n";

        if (confirmItem(itemName)) return true;

        cout << "Please try again.\n";
    }
}

bool confirmItem(const string &itemName) {
    char answer;
    cout << "Is this correct? (Y/N): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') return true;
    return false;
}

void handlePayment(double price) {
    double total = 0.0;
    double money;

    cout << "Please insert £" << price << endl;

    while (total < price) {
        cout << "Insert value (£ remaining " << price - total << "): ";
        cin >> money;

        if (cin.fail() || money <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid amount.\n";
            continue;
        }

        total += money;
    }

    if (total > price) {
        cout << "Change returned: £" << total - price << endl;
    }
}

bool askAnotherPurchase() {
    char choice;
    cout << "Would you like to make another purchase? (Y/N): ";
    cin >> choice;
    cout << endl;

    if (choice == 'y' || choice == 'Y') return true;
    return false;
}
