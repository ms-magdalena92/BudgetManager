#include "UsersFile.h"

vector <User> UsersFile::loadUsersFromXmlFile()
{
    vector <User> users;
    CMarkup xml;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            User user;
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(AdjuvantMethods::stringToIntConversion(xml.GetElemContent()));
            xml.FindElem("Name");
            user.setName(xml.GetElemContent());
            xml.FindElem("Surname");
            user.setSurname(xml.GetElemContent());
            xml.FindElem("Login");
            user.setLogin(xml.GetElemContent());
            xml.FindElem("Password");
            user.setPassword(xml.GetElemContent());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}
bool UsersFile::addUserToXmlFile(User user)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.OutOfElem();
    xml.Save(getFilename());
    if (!fileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
        return false;
    }
    return true;
}
bool UsersFile::changeUserPassword(vector <User>::iterator itr)
{
    CMarkup xml;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            int userId = AdjuvantMethods::stringToIntConversion(xml.GetElemContent());
            if (userId == itr -> getUserId())
            {
                xml.FindElem("Password");
                xml.SetData(itr -> getPassword());
                xml.Save(getFilename());
                return true;
            }
            xml.OutOfElem();
        }
    }
    else
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
        return false;
    }

}
