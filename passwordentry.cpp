#include"passwordentry.h"
#include<QString>
#include<QDebug>
PasswordEntry::PasswordEntry(const QString& webSiteName, const QString& webSiteURL, const QString& login, const QString& password):
                                                                                                        m_webSiteName(webSiteName),
                                                                                                        m_webSiteURL(webSiteURL),
                                                                                                        m_login(login),
                                                                                                        m_password(password)
{}

void PasswordEntry::setWebSiteName(const QString& webSiteName){
    m_webSiteName = webSiteName;
}

void PasswordEntry::setWebSiteURL(const QString& webSiteURL){
    m_webSiteURL = webSiteURL;
}

void PasswordEntry::setLogin(const QString& login){
    m_login = login;
}

void PasswordEntry::setPassword(const QString& password){
    m_password = password;
}

QString PasswordEntry::getWebSiteName() const{
    return m_webSiteName;
}

QString PasswordEntry::getWebSiteURL() const{
    return m_webSiteURL;
}

QString PasswordEntry::getLogin() const{
    return m_login;
}

QString PasswordEntry::getPassword() const{
    return m_password;
}
