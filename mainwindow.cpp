#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"passwordmanager.h"
#include"addobject.h"
#include"editobject.h"
#include"filemanager.h"
#include<QCloseEvent>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                            ui(new Ui::MainWindow),
                                            passwordManager(new PasswordManager),
                                            file(new FileManager(*passwordManager))
{

    ui->setupUi(this);

    QFont font = ui->DisplayField->font();
    font.setPointSize(12);
    ui->DisplayField->setFont(font);

    ui->EditButton->setEnabled(false);
    ui->DeleteButton->setEnabled(false);
    connect(ui->CloseWindowButton, &QPushButton::clicked, this, &MainWindow::callExit);
    connect(ui->AddNewButton, &QPushButton::clicked, this, &MainWindow::callAddObject);
    connect(ui->EditButton, &QPushButton::clicked, this, &MainWindow::callEditObject);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &MainWindow::callDeleteObject);

    connect(passwordManager, &PasswordManager::updateList, this, [&](const QStringList& list){ui->ObjectBox->clear(); ui->ObjectBox->addItems(list);});
    connect(passwordManager, &PasswordManager::objectEdited, this, &MainWindow::showData);
    connect(ui->ObjectBox, &QComboBox::currentIndexChanged, this, &MainWindow::checkList);
    connect(ui->ObjectBox, &QComboBox::currentIndexChanged, this, &MainWindow::showData);

    file->setPathToFile("Data.txt");
    file->loadFromFile();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::callAddObject(){
    AddObject *addObj = new AddObject(this, passwordManager);
    addObj->setAttribute(Qt::WA_DeleteOnClose);
    addObj->show();
}

void MainWindow::callEditObject(){
    int currentIndex = ui->ObjectBox->currentIndex();
    EditObject *editObj = new EditObject(this, currentIndex, passwordManager);
    editObj->setAttribute(Qt::WA_DeleteOnClose);
    editObj->show();
}

void MainWindow::callExit(){
    close();
}

void MainWindow::callDeleteObject(){
    int currentIndex = ui->ObjectBox->currentIndex();
    passwordManager->removeObj(currentIndex);
    QStringList listOfNames;
    for(auto& obj : passwordManager->getDataVector()){
        listOfNames << obj->getWebSiteName();
    }
    emit passwordManager->updateList(listOfNames);
}

void MainWindow::checkList(){
    int currentIndex = ui->ObjectBox->currentIndex();
    ui->DeleteButton->setEnabled(currentIndex>=0);
    ui->EditButton->setEnabled(currentIndex>=0);
}

void MainWindow::showData(){
    int currentIndex = ui->ObjectBox->currentIndex();
    auto& obj = passwordManager->getDataVector();
    if(currentIndex < 0 || currentIndex > obj.size()){
        ui->DisplayField->clear();
        return;
    }
    ui->DisplayField->clear();
    ui->DisplayField->append("Website: " + obj[currentIndex]->getWebSiteName());
    ui->DisplayField->append("URL: " + obj[currentIndex]->getWebSiteURL());
    ui->DisplayField->append("Login: " + obj[currentIndex]->getLogin());
    ui->DisplayField->append("Password: " + obj[currentIndex]->getPassword());

}

void MainWindow::closeEvent(QCloseEvent *event){
    file->saveToFile();
    event->accept();
}
