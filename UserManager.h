#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"

using namespace std;

class UserManager
{
    int currentUserId;
    vector<User> users;

    User provideNewUserData();
    int getNewUserId();
    bool isUsernameAvailable(string login);

public:
    UserManager(string usersFilename)
    {
        currentUserId = 0;
    };
    void userSignUp();
    void userSignIn();
    void userSignOut();
    void viewAllUsers();
};

#endif // USERMANAGER_H
