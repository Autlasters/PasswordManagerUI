/*
 * filemanager.h
 *
 * In this header file the FileManager is implemented, its saves all application's data in the .txt file format
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
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
