#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include"passwordentry.h"
#include<memory>
#include<vector>
#include<QObject>
#include<QStringList>
class PasswordManager: public QObject {
    Q_OBJECT
private:
    std::vector<std::unique_ptr<PasswordEntry>> m_data;
public:
    explicit PasswordManager(QObject* parent = nullptr);
    void addObj(const QString& webSiteName, const QString& webSiteURL, const QString& login, const QString& password);
    void removeObj(int index);
    PasswordEntry* searchObj(const QString& webSiteName) const;
    void changeObj(int index, FeildType type, const QString& value);
    const std::vector<std::unique_ptr<PasswordEntry>>& getDataVector() const;
    void clearData();
signals:
    void updateList(const QStringList&);
    void objectEdited();
};

#endif // PASSWORDMANAGER_H
