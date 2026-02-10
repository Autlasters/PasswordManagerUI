/*
 * addobject.cpp
 *
 * This .cpp file implements the logic of the AddObject class, responsible for the new object creation
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#include "addobject.h"
#include "ui_addobject.h"
#include"passwordgenerator.h"
#include"passwordmanager.h"

//The Constructor of the class
AddObject::AddObject(QWidget *parent, PasswordManager *passwordManager): QDialog(parent), ui(new Ui::AddObject), passwordManager(passwordManager)
{
    ui->setupUi(this);
    connect(ui->CencleButton, &QPushButton::clicked, this, &AddObject::callCancelAdd);
    connect(ui->PasswordGenerateButton, &QPushButton::clicked, this, &AddObject::setRandomPassword);
    connect(ui->AddObjButton, &QPushButton::clicked, this, &AddObject::addNewObject);
}

//Method to remove all data from the fields
void AddObject::clearAllFilelds(){
    ui->WebSiteField->clear();
    ui->UrlField->clear();
    ui->LoginField->clear();
    ui->PasswordField->clear();
}

//The Destructor of the class
AddObject::~AddObject()
{
    delete ui;
}

//Method to close the window
void AddObject::callCancelAdd(){
    close();
}

//Method to generate the random password
void AddObject::setRandomPassword(){
    ui->PasswordField->clear();
    ui->PasswordField->setText(PasswordGenerator::generateRandomPassword());
}

//Method to add the new object to the set
void AddObject::addNewObject(){
    passwordManager->addObj(ui->WebSiteField->text(), ui->UrlField->text(), ui->LoginField->text(), ui->PasswordField->text());
    clearAllFilelds();
    close();
}
