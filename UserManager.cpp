#include "UserManager.h"

void UserManager::userSignUp()
{
    User user = provideNewUserData();
    users.push_back(user);
    usersFile.addUserToXmlFile(user);
    cout << endl << "Your account was successfully created." << endl;
    system("pause");
}
User UserManager::provideNewUserData()
{
    User user;
    user.setUserId(getNewUserId());

    string login;
    do
    {
        system("cls");
        cout << "    >>> SIGN UP <<<" << endl;
        cout << endl <<"Enter username: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isUsernameAvailable(user.getLogin()) == false);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}
int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
bool UserManager::isUsernameAvailable(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Username unavailable" << endl << endl;
            system("pause");
            return false;
        }
    }
    return true;
}
void UserManager::userSignIn()
{
    system("cls");
    cout << "    >>> SIGN IN <<<" << endl;
    string login = "", password = "";
    cout << endl << "Enter username: ";
    cin >> login;
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                if (numberOfAttempts!=1)
                {
                    cout << "Enter password (" << numberOfAttempts << " attempts left): ";
                }
                else
                {
                    cout << "Enter password (" << numberOfAttempts << " attempt left): ";
                }
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    currentUserId = itr -> getUserId();
                    cout << endl << "You have successfully signed in." << endl << endl;
                    system("pause");
                    return;

                }
            }
            cout << endl << "3 unsuccessful login attempts." << endl;
            system("pause");
            return;
        }
        itr++;

    }
    cout << "Username does not exist" << endl << endl;
    system("pause");
    return;
}
void UserManager::viewAllUsers()
{
    if (users.empty()==false)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            cout << itr -> getUserId() << endl;
            cout << itr -> getLogin() << endl;
            cout << itr -> getPassword() << endl;
            cout << itr -> getName() << endl;
            cout << itr -> getSurname() << endl;
        }
        system("pause");
    }
    return;
}
bool UserManager::isUserLoggedIn()
{
    if(currentUserId>0)
        return true;
    else
        return false;
}
char UserManager::selectFromMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    choice = AdjuvantMethods::getChar();

    return choice;
}
char UserManager::selectFromUserMenu()
{
    char choice;
    system("cls");
    cout << "            >>> USER MENU <<<" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. View current month's balance" << endl;
    cout << "4. View last month's balance" << endl;
    cout << "5. View balance of the selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Sign out" << endl;
    cout << "----------------------------------------" << endl;
    choice = AdjuvantMethods::getChar();

    return choice;
}
void UserManager::userSignOut()
{
    currentUserId = 0;
}
int UserManager::getCurrentUserId()
{
    return currentUserId;
}
