#include "functions.h"

int main()
{
    UserSystem system;
    int choice;

    do
    {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Display Users\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.registerUser();
            break;

        case 2:
            system.loginUser();
            break;

        case 3:
            system.displayUsers();
            break;

        case 4:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}