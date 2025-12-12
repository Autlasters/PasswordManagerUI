#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include"passwordmanager.h"

class FileManager {
private:
    std::string m_pathToFile;
    PasswordManager& m_obj;
public:
    FileManager(PasswordManager& obj);
    void setPathToFile(const std::string& path);
    void saveToFile() const;
    void loadFromFile();
};

#endif // FILEMANAGER_H
