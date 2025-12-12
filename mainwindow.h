#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include"passwordmanager.h"
#include"filemanager.h"
#include<QCloseEvent>

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
