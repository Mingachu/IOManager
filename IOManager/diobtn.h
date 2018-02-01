#ifndef DIOBTN_H
#define DIOBTN_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
//#include <mainwindow.h>
#include <QMouseEvent>

typedef bool(*SetDODel)(const int & ,const bool &);
class DIOBtn :public QPushButton
{
public:
    DIOBtn(QWidget *parent = 0);
    void SetPortIndex(const int &index);
    void SetIsDOType(const bool &state);
    void setChecked(bool state);
    ~DIOBtn()
    {

    }
    //~DIOBtn;
private slots:
    void mousePressEvent(QMouseEvent *e);

private:

    int _PortIndex;
    bool _IsDO;
    bool _state;
//private slots:
    void CheckClick();
};

#endif // DIOBTN_H
