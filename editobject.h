/*
 * editobject.h
 *
 * In this header file the EditObject class is declared, it is the additional window for object editing
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#ifndef EDITOBJECT_H
#define EDITOBJECT_H

#include <QDialog>
#include"passwordmanager.h"
namespace Ui {
class EditObject;
}

class EditObject : public QDialog
{
    Q_OBJECT

public:
    explicit EditObject(QWidget *parent = nullptr, int index = -1, PasswordManager *passwordManager = nullptr);
    ~EditObject();

private:
    Ui::EditObject *ui;
    PasswordManager *passwordManager;
    int objInt;
public slots:
    void callCancelEdit();
    void setRandomPassword();
    void saveChanges();
};

#endif // EDITOBJECT_H
