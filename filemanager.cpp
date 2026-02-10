/*
 * filemanager.cpp
 *
 * This .cpp file represents the logic of the FileManager class, with data saving/reading, and file path setting
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#include"filemanager.h"
#include"passwordmanager.h"
#include<fstream>
#include<QString>
#include<sstream>

//The Constructor of the class
FileManager::FileManager(PasswordManager& obj): m_obj(obj) {}

//Method to set the file path
void FileManager::setPathToFile(const std::string& path){
    m_pathToFile = path;
}

//Method to save data to the file
void FileManager::saveToFile() const{
    std::ofstream fileToSave(m_pathToFile);
    if(fileToSave.is_open()){
        for(const auto& it : m_obj.getDataVector()){
            fileToSave << it->getWebSiteName().toStdString() << "|"
                       << it->getWebSiteURL().toStdString() << "|"
                       << it->getLogin().toStdString() << "|"
                       << it->getPassword().toStdString() << std::endl;
        }
    }
    fileToSave.close();
}

//Method to read data from the file
void FileManager::loadFromFile(){
    std::ifstream fileToLoad(m_pathToFile);
    if(!fileToLoad.is_open()){
        return;
    }

    m_obj.clearData();
    std::string lineToRead;
    QStringList listOfNames;
    while(std::getline(fileToLoad, lineToRead)){

        std::stringstream ss(lineToRead);
        std::string webSiteName, webSiteURL, login, password;

        if(std::getline(ss, webSiteName, '|'),
            std::getline(ss, webSiteURL, '|'),
            std::getline(ss, login, '|'),
            std::getline(ss, password, '|'))
        {
            m_obj.addObj(QString::fromStdString(webSiteName),
                        QString::fromStdString(webSiteURL),
                        QString::fromStdString(login),
                        QString::fromStdString(password));
        }
    }
}
