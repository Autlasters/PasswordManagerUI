#ifndef PASSWORDENTRY_H
#define PASSWORDENTRY_H

#include<QString>
enum FeildType{WebSiteName, WebSiteURL, Login, Password };
class PasswordEntry {
private:
    QString m_webSiteName;
    QString m_webSiteURL;
    QString m_login;
    QString m_password;
public:
    explicit PasswordEntry(const QString& webSiteName, const QString& webSiteURL, const QString& login, const QString& password);
    void setWebSiteName(const QString& webSiteName);
    void setWebSiteURL(const QString& webSiteURL);
    void setLogin(const QString& login);
    void setPassword(const QString& password);
    QString getWebSiteName() const;
    QString getWebSiteURL() const;
    QString getLogin() const;
    QString getPassword() const;
};

#endif // PASSWORDENTRY_H
