#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"
#include "AdjuvantMethods.h"

using namespace std;

class UserManager
{
    int currentUserId;
    vector<User> users;
    UsersFile usersFile;

    User provideNewUserData();
    int getNewUserId();
    bool isUsernameAvailable(string login);

public:
    UserManager(string usersFilename):usersFile(usersFilename)
    {
        currentUserId = 0;
        users = usersFile.loadUsersFromXmlFile();
    };
    void userSignUp();
    void userSignIn();
    void userSignOut();
    void viewAllUsers();
    bool isUserLoggedIn();
    char selectFromMainMenu();
    char selectFromUserMenu();
    int getCurrentUserId();
    void changeCurrentUserPassword();
};

#endif // USERMANAGER_H
