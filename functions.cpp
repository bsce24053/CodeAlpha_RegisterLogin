#include "functions.h"

UserSystem::UserSystem()
{
    usernames = nullptr;
    passwords = nullptr;
    userCount = 0;
    filename = "users.txt";

    loadUsers();
}

UserSystem::~UserSystem()
{
    delete[] usernames;
    delete[] passwords;
}

void UserSystem::loadUsers()
{
    ifstream fin(filename);

    if (!fin)
        return;

    string user, pass;

    while (fin >> user >> pass)
    {
        string *newUsers = new string[userCount + 1];
        string *newPasswords = new string[userCount + 1];

        for (int i = 0; i < userCount; i++)
        {
            newUsers[i] = usernames[i];
            newPasswords[i] = passwords[i];
        }

        newUsers[userCount] = user;
        newPasswords[userCount] = pass;

        delete[] usernames;
        delete[] passwords;

        usernames = newUsers;
        passwords = newPasswords;

        userCount++;
    }

    fin.close();
}

void UserSystem::saveUsers()
{
    ofstream fout(filename);

    for (int i = 0; i < userCount; i++)
    {
        fout << usernames[i] << " "
             << passwords[i] << endl;
    }

    fout.close();
}

bool UserSystem::usernameExists(string username)
{
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == username)
            return true;
    }

    return false;
}

void UserSystem::registerUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "Username already exists.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    string *newUsers = new string[userCount + 1];
    string *newPasswords = new string[userCount + 1];

    for (int i = 0; i < userCount; i++)
    {
        newUsers[i] = usernames[i];
        newPasswords[i] = passwords[i];
    }

    newUsers[userCount] = username;
    newPasswords[userCount] = password;

    delete[] usernames;
    delete[] passwords;

    usernames = newUsers;
    passwords = newPasswords;

    userCount++;

    saveUsers();

    cout << "Registration Successful.\n";
}

bool UserSystem::loginUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == username &&
            passwords[i] == password)
        {
            cout << "\nLogin Successful.\n";
            return true;
        }
    }

    cout << "\nInvalid Username or Password.\n";
    return false;
}

void UserSystem::displayUsers()
{
    if (userCount == 0)
    {
        cout << "No users found.\n";
        return;
    }

    cout << "\nRegistered Users\n";

    for (int i = 0; i < userCount; i++)
    {
        cout << i + 1 << ". "
             << usernames[i]
             << endl;
    }
}