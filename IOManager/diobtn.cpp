#include "diobtn.h"
DIOBtn::DIOBtn(QWidget *parent):QPushButton(parent)
{
    QString _IOBtnStyle="QPushButton { color: rgb(255, 255, 255);background-color: rgb(75, 75, 75); }"
                        "QPushButton:checked { color: rgb(60, 60, 60);background-color: Lime;border-style: none;;}"
                        "QPushButton:disabled  { background-color: rgb(180, 180, 180)}"
                        "QPushButton:hover { background-color: rgb(128, 128, 128)}"
                        "QPushButton:hover:checked { background-color: rgb(120, 255, 96)}";
    setCheckable(true);

    setStyleSheet(_IOBtnStyle);
    _IsDO=true;
    _state=false;
    //connect(this, SIGNAL (QPushButton::clicked()), this, SLOT (CheckClick()));
    ////setText("test111111");
    //setText("Test1");
}
void DIOBtn::SetPortIndex(const int &index)
{

    _PortIndex=index;
}

void DIOBtn::SetIsDOType(const bool &state)
{
    //setCheckable(state);
    _IsDO=state;
}

void DIOBtn::setChecked(bool state)
{
    _state= state;
}

void DIOBtn::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
        emit CheckClick();
}

void DIOBtn::CheckClick()
{
    if(_IsDO)
    {
        _state=!_state;
    }
    QPushButton::setChecked(_state);
}
