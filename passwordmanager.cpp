/*
 * passwordmanager.cpp
 *
 * In this .cpp file, PasswordManager logic is implemented. Including object handling: remove, add, change, search, and other methods
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#include"passwordmanager.h"
#include"passwordentry.h"
#include<memory>
#include<vector>
#include<QDebug>

//The Constructor of the class
PasswordManager::PasswordManager(QObject *parent): QObject(parent){}

//Method to add a new object in the set
void PasswordManager::addObj(const QString& webSiteName, const QString& webSiteURL, const QString& login, const QString& password){
    std::vector<QString> tempVector;
    (webSiteName.isEmpty()) ? tempVector.push_back("Empty") : tempVector.push_back(webSiteName);
    (webSiteURL.isEmpty()) ? tempVector.push_back("Empty") : tempVector.push_back(webSiteURL);
    (login.isEmpty()) ? tempVector.push_back("Empty") : tempVector.push_back(login);
    (password.isEmpty()) ? tempVector.push_back("Empty") : tempVector.push_back(password);
    m_data.emplace_back(std::make_unique<PasswordEntry>(tempVector[0], tempVector[1], tempVector[2], tempVector[3]));
    QStringList listOfNames;
    for(auto& obj : m_data){
        listOfNames << obj->getWebSiteName();
    }
    emit updateList(listOfNames);
}

//Method to delete an object from the set
void PasswordManager::removeObj(int index){
    if(index >= 0 && index < m_data.size()) {
        m_data.erase(m_data.begin()+index);
    }
}

//Method to search for an object in the set
PasswordEntry* PasswordManager::searchObj(const QString& webSiteName) const {
    for(auto& obj : m_data){
        if(obj->getWebSiteName() == webSiteName){
            return obj.get();
        }
    }
    return nullptr;
}

//Method to modify an object in the set
void PasswordManager::changeObj(int index, FeildType type, const QString& value){
    if(index >= 0 && index < m_data.size()){
        switch(type){
        case WebSiteName:
            (value.isEmpty()) ? m_data[index]->setWebSiteName("Empty") : m_data[index]->setWebSiteName(value);
            break;
        case WebSiteURL:
            (value.isEmpty()) ? m_data[index]->setWebSiteURL("Empty") : m_data[index]->setWebSiteURL(value);
            break;
        case Login:
            (value.isEmpty()) ? m_data[index]->setLogin("Empty") : m_data[index]->setLogin(value);
            break;
        case Password:
            (value.isEmpty()) ? m_data[index]->setPassword("Empty") : m_data[index]->setPassword(value);
            break;
        default:
            break;
        }
    }
    else{
        return;
    }
}

//Method to get set of the objects
const std::vector<std::unique_ptr<PasswordEntry>>& PasswordManager::getDataVector() const{
    return m_data;
}

//Method to clear the set of the objects
void PasswordManager::clearData(){
    m_data.clear();
}
