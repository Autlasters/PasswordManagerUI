#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"passwordmanager.h"
#include"addobject.h"
#include"editobject.h"
#include"filemanager.h"
#include<QCloseEvent>
#include<QClipboard>
#include<QGuiApplication>
#include<QToolTip>
#include<QRegularExpression>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                            ui(new Ui::MainWindow),
                                            passwordManager(new PasswordManager),
                                            file(new FileManager(*passwordManager)),
                                            board(QGuiApplication::clipboard())
{

    ui->setupUi(this);

    QFont font = ui->DisplayField->font();
    font.setPointSize(12);
    ui->DisplayField->setFont(font);
    ui->EditButton->setEnabled(false);
    ui->DeleteButton->setEnabled(false);
    ui->CopyLoginButton->setEnabled(false);
    ui->CopyPasswordButton->setEnabled(false);
    connect(ui->CloseWindowButton, &QPushButton::clicked, this, &MainWindow::callExit);
    connect(ui->AddNewButton, &QPushButton::clicked, this, &MainWindow::callAddObject);
    connect(ui->EditButton, &QPushButton::clicked, this, &MainWindow::callEditObject);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &MainWindow::callDeleteObject);
    connect(ui->CopyLoginButton, &QPushButton::clicked, this, [this](){
        int currentIndex = ui->ObjectBox->currentIndex();
        auto& obj = passwordManager->getDataVector();
        if(currentIndex < 0 || currentIndex > obj.size() - 1){
            return;
        }
        board->setText(obj[currentIndex]->getLogin());
        QToolTip::showText(QCursor::pos(), "Login Copied");
    });
    connect(ui->CopyPasswordButton, &QPushButton::clicked, this, [this](){
        int currentIndex = ui->ObjectBox->currentIndex();
        auto& obj = passwordManager->getDataVector();
        if(currentIndex < 0 || currentIndex > obj.size() - 1){
            return;
        }
        board->setText(obj[currentIndex]->getPassword());
        QToolTip::showText(QCursor::pos(), "Password Copied");
    });

    connect(passwordManager, &PasswordManager::updateList, this, [this](const QStringList& list){ui->ObjectBox->clear(); ui->ObjectBox->addItems(list);});
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
    ui->CopyLoginButton->setEnabled(currentIndex>=0);
    ui->CopyPasswordButton->setEnabled(currentIndex>=0);
}

void MainWindow::showData(){
    int currentIndex = ui->ObjectBox->currentIndex();
    auto& obj = passwordManager->getDataVector();
    if(currentIndex < 0 || currentIndex > obj.size() - 1){
        ui->DisplayField->clear();
        return;
    }
    ui->DisplayField->clear();
    ui->DisplayField->append("Website: " + obj[currentIndex]->getWebSiteName());

    QRegularExpression regExp(R"(^(https?:\/\/)[^\s]+$)");
    (regExp.match(obj[currentIndex]->getWebSiteURL()).hasMatch()) ? ui->DisplayField->append("URL: " "<a href=\""
                                                                                                + obj[currentIndex]->getWebSiteURL() + "\">"
                                                                                                + obj[currentIndex]->getWebSiteURL() + "</a>") :
    ui->DisplayField->append("URL: " + obj[currentIndex]->getWebSiteURL());

    ui->DisplayField->append("Login: " + obj[currentIndex]->getLogin());
    ui->DisplayField->append("Password: " + obj[currentIndex]->getPassword());

}

void MainWindow::closeEvent(QCloseEvent *event){
    file->saveToFile();
    event->accept();
}
