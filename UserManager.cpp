#include "UserManager.h"

void UserManager::userSignUp()
{
    User user = provideNewUserData();
    users.push_back(user);
    system("pause");
}
User UserManager::provideNewUserData()
{
    User user;
    user.setUserId(getNewUserId());

    string login;
    do
    {
        cout << "Enter login: ";
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
            cout << endl << "Username unavailable" << endl;
            return false;
        }
    }
    return true;
}
void UserManager::userSignIn()
{
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
    }
    system("pause");
    return;
}
void UserManager::userSignOut()
{
    currentUserId = 0;
}
