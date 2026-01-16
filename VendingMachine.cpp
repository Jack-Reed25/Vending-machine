#include <iostream>
#include <string>
using namespace std;

void viewMenu();
bool selectItem(string &itemName, double &price);
bool confirmItem(const string &itemName);
void handlePayment(double price);
bool askAnotherPurchase();

int main() {
    string itemName;
    double price;
    bool keepRunning = true; // flag to control the loop

    while (keepRunning) {
       
        if (!selectItem(itemName, price)) { // Display menu and select an item; exit if user chooses X
            keepRunning = false;
            continue;
        }

        handlePayment(price); // this function handles the payment process
        cout << itemName << " dispensed!\n"; // Lets the user know that their item is dispensed 

         // this function asks the user if they want to make another purchase
        if (!askAnotherPurchase()) {
            keepRunning = false;
        }
    }

    cout << "Thank you for using the vending machine. Goodbye!\n";  // Allows the user leave the program
    return 0;
}

void viewMenu() { // Display's the vending machine menu with listed items and their prices
    cout << "\n"; 
    cout << "========= Welcome to the utility vending machine =========\n"; 
    cout << "\n"; 
    cout << "           1               2               3\n"; // Column headers
    cout << "\n"; 
    cout << "A     Water (£.99)    Juice (£1.49)    Cola (£1.25)\n"; // Row A items
    cout << "\n"; 
    cout << "B     Crisps (£1.75)  Gum (£0.75)      Chocolate (£1.99)\n"; // Row B items
    cout << "\n"; 
    cout << "C     Mints (£0.79)   Gummies (£1.59)  Biscuits (£1.39)\n"; // Row C items
}

bool selectItem(string &itemName, double &price) { // Calls viewMenu and allows the user to select an item from the vending machine menu
    while (true) {
        viewMenu();

        string code;
        cout << "Enter item code or X to exit:"; // Asks the user if they want to leave the program
        cin >> code;

        if (code == "X" || code == "x") return false;   // Makes sure that lowercase x and uppercase X both work to exit the program

        char letter = code[0]; // this is the row
        char number = code[1]; // this is the column

        if (letter == 'a') letter = 'A'; // Makes sure that lowercase a and uppercase A both work
        else if (letter == 'b') letter = 'B'; // Makes sure that lowercase b and uppercase B both work
        else if (letter == 'c') letter = 'C'; // Makes sure that lowercase c and uppercase C both work

        switch (letter) {   // Determines which item the user has selected
            case 'A':
                switch (number) {
                    case '1': itemName = "Water"; price = 0.99; break; // Makes sure that if water is selected it charges the correct price
                    case '2': itemName = "Juice"; price = 1.49; break; // Makes sure that if juice is selected it charges the correct price
                    case '3': itemName = "Cola"; price = 1.25; break; // Makes sure that if cola is selected it charges the correct price
                    default: cout << "Invalid code, please try again.\n"; continue; // Makes sure that a valid number is selected for an item code starting with a A
                }
                break;

            case 'B':
                switch (number) {
                    case '1': itemName = "Crisps"; price = 1.75; break; // Makes sure that if crisps is selected it charges the correct price
                    case '2': itemName = "Gum"; price = 0.75; break; // Makes sure that if gum is selected it charges the correct price
                    case '3': itemName = "Chocolate"; price = 1.99; break; // Makes sure that if chocolate is selected it charges the correct price
                    default: cout << "Invalid code, please try again.\n"; continue; // Makes sure that a valid number is selected for an item code starting with a B
                }
                break;

            case 'C':
                switch (number) {
                    case '1': itemName = "Mints"; price = 0.79; break; // Makes sure that if mints is selected it charges the correct price
                    case '2': itemName = "Gummies"; price = 1.59; break; // Makes sure that if gummies is selected it charges the correct price
                    case '3': itemName = "Biscuits"; price = 1.39; break; // Makes sure that if biscuits is selected it charges the correct price
                    default: cout << "Invalid code, please try again.\n"; continue; // Makes sure that a valid number is selected for an item code starting with a C
                }
                break;

            default:
                cout << "Invalid code, please try again.\n"; // Makes sure that a valid letter and number is selected for the item code
                continue;
        }

        cout << "You selected: " << itemName << " (£" << price << ")\n"; // Displays the item selected and its price

        if (confirmItem(itemName)) return true;

        cout << "Please enter code again.\n"; // Asks the user to try again if they did not confirm their item selection
    }
}

bool confirmItem(const string &itemName) { // Asks the user to confirm their item selection
    char answer;
    cout << "Is this correct? Y for yes or any key to retry: "; // Asks the user to confirm their item selection
    cin >> answer;

    if (answer == 'y' || answer == 'Y') return true; // Makes sure that both lowercase y and uppercase Y work to confirm the item selection
    return false;
}

void handlePayment(double price) { // Handles the payment process for the selected item
    double total = 0.0;
    double money;

    while (total < price) {
        cout << "Please enter the value of £ you inserted: "; // Asks the user to insert money for their selected item
        cin >> money;
        if (cin.fail() || money <= 0) {
            cin.clear();           // Clear the error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Sorry, invalid amount. Try again.\n"; // Informs the user that their input was invalid and to try again
            continue;
        }

        total += money;

        if (total < price) {
            cout << "Insufficient funds. Please add £" << (price - total) << " more.\n"; // Tells the user of how much more money they need to insert
        }
    }

    if (total > price) {
        cout << "Change returned: £" << (total - price) << endl; // Gives the user their change if they inserted too much money
    }

    cout << "Payment accepted. Thank you!\n"; // Confirms to the user that their payment was successful
}

bool askAnotherPurchase() { // Asks the user if they want to make another purchase
    char choice;
    cout << "Would you like to make another purchase? Y for yes or any key to exit: ";// Asks the user if they want to make another purchase
    cin >> choice;
    cout << endl;

    if (choice == 'y' || choice == 'Y') return true; // Makes sure that both lowercase y and uppercase Y work to make another purchase
    return false;
}
