#ifndef ADDOBJECT_H
#define ADDOBJECT_H

#include <QDialog>
#include"passwordmanager.h"

namespace Ui {
class AddObject;
}

class AddObject : public QDialog
{
    Q_OBJECT

public:
    explicit AddObject(QWidget *parent = nullptr, PasswordManager *passwordManager = nullptr);
    ~AddObject();

private:
    Ui::AddObject *ui;
    PasswordManager *passwordManager;

public slots:
    void callCancelAdd();
    void setRandomPassword();
    void clearAllFilelds();
    void addNewObject();
};
#endif // ADDOBJECT_H
