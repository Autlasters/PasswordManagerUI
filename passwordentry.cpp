/*
 * passwordentry.cpp
 *
 * In this .cpp file, the PasswordEntry class logic is implemented, including methods to handle the data
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#include"passwordentry.h"
#include<QString>
#include<QDebug>

//The Constructor of the calss
PasswordEntry::PasswordEntry(const QString& webSiteName, const QString& webSiteURL, const QString& login, const QString& password):
                                                                                                        m_webSiteName(webSiteName),
                                                                                                        m_webSiteURL(webSiteURL),
                                                                                                        m_login(login),
                                                                                                        m_password(password)
{}

//Method to set the name of a website
void PasswordEntry::setWebSiteName(const QString& webSiteName){
    m_webSiteName = webSiteName;
}

//Method to set the URL of a website
void PasswordEntry::setWebSiteURL(const QString& webSiteURL){
    m_webSiteURL = webSiteURL;
}

//Method to set the login of a website
void PasswordEntry::setLogin(const QString& login){
    m_login = login;
}

//Method to set the password of a website
void PasswordEntry::setPassword(const QString& password){
    m_password = password;
}

//Method to get the name of a website
QString PasswordEntry::getWebSiteName() const{
    return m_webSiteName;
}

//Method to get the URL of a website
QString PasswordEntry::getWebSiteURL() const{
    return m_webSiteURL;
}

//Method to get the login of a website
QString PasswordEntry::getLogin() const{
    return m_login;
}

//Method to get the password of a website
QString PasswordEntry::getPassword() const{
    return m_password;
}
