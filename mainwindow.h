/*
 * mainwindow.h
 *
 * In this header file the MainWindow class is declared, which defines the GUI of the application
 * This file connects user interactions to the application logic
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include"passwordmanager.h"
#include"filemanager.h"
#include<QCloseEvent>
#include<QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PasswordManager *passwordManager = nullptr;
    FileManager *file = nullptr;
    QClipboard *board = nullptr;
public slots:
    void callAddObject();
    void callEditObject();
    void callExit();
    void callDeleteObject();
    void checkList();
    void showData();
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
