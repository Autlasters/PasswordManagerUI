#include "addobject.h"
#include "ui_addobject.h"
#include"passwordgenerator.h"
#include"passwordmanager.h"

AddObject::AddObject(QWidget *parent, PasswordManager *passwordManager): QDialog(parent), ui(new Ui::AddObject), passwordManager(passwordManager)
{
    ui->setupUi(this);
    connect(ui->CencleButton, &QPushButton::clicked, this, &AddObject::callCancelAdd);
    connect(ui->PasswordGenerateButton, &QPushButton::clicked, this, &AddObject::setRandomPassword);
    connect(ui->AddObjButton, &QPushButton::clicked, this, &AddObject::addNewObject);
}

void AddObject::clearAllFilelds(){
    ui->WebSiteField->clear();
    ui->UrlField->clear();
    ui->LoginField->clear();
    ui->PasswordField->clear();
}

AddObject::~AddObject()
{
    delete ui;
}

void AddObject::callCancelAdd(){
    close();
}

void AddObject::setRandomPassword(){
    ui->PasswordField->clear();
    ui->PasswordField->append(PasswordGenerator::generateRandomPassword());
}

void AddObject::addNewObject(){
    passwordManager->addObj(ui->WebSiteField->toPlainText(), ui->UrlField->toPlainText(), ui->LoginField->toPlainText(), ui->PasswordField->toPlainText());
    clearAllFilelds();
    close();
}
