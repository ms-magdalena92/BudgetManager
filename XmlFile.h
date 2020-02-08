#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILENAME;

public:
    XmlFile(string filename):FILENAME(filename){}
    bool fileExist(CMarkup &xml);
    string getFilename();
};

#endif // XMLFILE_H
