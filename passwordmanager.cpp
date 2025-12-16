#include"passwordmanager.h"
#include"passwordentry.h"
#include<memory>
#include<vector>
#include<QDebug>
PasswordManager::PasswordManager(QObject *parent): QObject(parent){}

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

void PasswordManager::removeObj(int index){
    if(index >= 0 && index < m_data.size()) {
        m_data.erase(m_data.begin()+index);
    }
}

PasswordEntry* PasswordManager::searchObj(const QString& webSiteName) const {
    for(auto& obj : m_data){
        if(obj->getWebSiteName() == webSiteName){
            return obj.get();
        }
    }
    return nullptr;
}

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

    /*
        switch(type){
        case WebSiteName:
            m_data[index]->setWebSiteName(value);
            break;
        case WebSiteURL:
            m_data[index]->setWebSiteURL(value);
            break;
        case Login:
            m_data[index]->setLogin(value);
            break;
        case Password:
            m_data[index]->setPassword(value);
            break;
        default:
            break;
        }
     */
}

const std::vector<std::unique_ptr<PasswordEntry>>& PasswordManager::getDataVector() const{
    return m_data;
}

void PasswordManager::clearData(){
    m_data.clear();
}
