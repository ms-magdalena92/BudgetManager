#include "XmlFile.h"

bool XmlFile::fileExist(CMarkup &xml)
{
    return xml.Load(getFilename());
}
string XmlFile::getFilename()
{
    return FILENAME;
}
