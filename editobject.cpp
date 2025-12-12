#include "editobject.h"
#include "ui_editobject.h"
#include"passwordgenerator.h"
#include"passwordmanager.h"

EditObject::EditObject(QWidget *parent, int index, PasswordManager *passwordManager): QDialog(parent), ui(new Ui::EditObject), objInt(index),
    passwordManager(passwordManager)
{
    ui->setupUi(this);
    connect(ui->CancelButton, &QPushButton::clicked, this, &EditObject::callCancelEdit);
    connect(ui->PasswordGenerateButton, &QPushButton::clicked, this, &EditObject::setRandomPassword);
    connect(ui->EditButton, &QPushButton::clicked, this, &EditObject::saveChanges);

    const auto& data = passwordManager->getDataVector();
    ui->WebSiteField->setText(data[objInt]->getWebSiteName());
    ui->UrlField->setText(data[objInt]->getWebSiteURL());
    ui->LoginField->setText(data[objInt]->getLogin());
    ui->PasswordField->setText(data[objInt]->getPassword());
}

EditObject::~EditObject()
{
    delete ui;
}

void EditObject::callCancelEdit(){
    close();
}

void EditObject::setRandomPassword(){
    ui->PasswordField->clear();
    ui->PasswordField->append(PasswordGenerator::generateRandomPassword());
}

void EditObject::saveChanges(){
    passwordManager->changeObj(objInt, WebSiteName, ui->WebSiteField->toPlainText());
    passwordManager->changeObj(objInt, WebSiteURL, ui->UrlField->toPlainText());
    passwordManager->changeObj(objInt, Login, ui->LoginField->toPlainText());
    passwordManager->changeObj(objInt, Password, ui->PasswordField->toPlainText());
    emit passwordManager->objectEdited();
    close();
}
