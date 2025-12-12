#include"filemanager.h"
#include"passwordmanager.h"
#include<fstream>
#include<QString>
#include<sstream>

FileManager::FileManager(PasswordManager& obj): m_obj(obj) {}

void FileManager::setPathToFile(const std::string& path){
    m_pathToFile = path;
}
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
