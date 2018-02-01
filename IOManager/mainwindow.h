#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iomanager.h>
#include <diobtn.h>
#include <commandsetdo.h>
#include <diocommandbase.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_BtnTest1_clicked();


    void on_BtnPreviousPage_clicked();

    void on_BtnNextPage_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_BtnOperation_clicked();

private:

    void testpass(vector<string> &command,string &ss, std::function<bool()> &pptr );
    void checkpages();
    Ui::MainWindow *ui;
    void InitUI();
    const int pagecount=8;
    IOManager *_DAQIO;
    DIOCommandBase *testcomplier;
    void RefreshIOState();
};

#endif // MAINWINDOW_H
