#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserSystem{
private:
    string* usernames;
    string* passwords;
    int userCount;
    string filename;
    void loadUsers();
    void saveUsers();

public:
    UserSystem();
    ~UserSystem();

    void registerUser();
    bool loginUser();

    void displayUsers();
};

#endif