#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _DAQIO=new IOManager();
    testcomplier=new CommandSetDO(_DAQIO);
    ///delete testpp;
    if(_DAQIO->Init())
    {
        InitUI();
    }
    //DIOOperator ppp;
    //std::function<bool()>  ppp;
//    DIOOperator ppp;
//    string emsg("1");
//    vector<string> command;
//    string resstr;
//    //command=new vector<string>();
//    command.push_back(string("0"));
//    command.push_back(string("0"));
//    command.push_back(string("ON"));
    //command.push_back(string("0"));
//    bool test =testcomplier->Complier(command,emsg,ppp);
//    qDebug() <<test<<emsg.data();
//    bool tt1=ppp(resstr);
//    qDebug() <<tt1<<resstr.data();
//    command.clear();
//    command.push_back(string("0"));
//    command.push_back(string("1"));
//    command.push_back(string("ON"));
//    command.push_back(string("100"));
//    //DIOOperator *ppp2=new DIOOperator;
//    test =testcomplier->Complier(command,emsg,ppp);
//    qDebug() <<test<<emsg.data();
//    resstr.assign("");
//    tt1=ppp(resstr);
//    //delete ppp2;
//    //qDebug() <<resstr.data();
//    qDebug() <<tt1<<resstr.data();
    //testpass(command,emsg,ppp);
    //string showname=testpp->GetCommandName();
    //testpp->
    //qDebug() << showname.data();
    //qDebug() << showname.data()<<showname.c_str();
    //printf(showname.c_str());
}

void MainWindow::testpass(vector<string> &command ,string &ss, std::function<bool()> &pptr)
{

}
void MainWindow::InitUI()
{
    QGridLayout *iolayout=dynamic_cast<QGridLayout*>(ui->MiddleWidget->layout());
    QPushButton a;
    a.setChecked(true);
    for(int i=0 ;i<pagecount ;i++)
    {
        //int setrow=(int)_btnDIBtn.size();
        DIOBtn *newDIbtn=new DIOBtn();
        DIOBtn *newDObtn=new DIOBtn();
        newDIbtn->setText(tr("I %1").arg(i + 1));
        newDObtn->setText(tr("O %1").arg(i + 1));
        newDIbtn->SetIsDOType(false);

        _btnDIBtn.push_back(newDIbtn);
        _btnDOBtn.push_back(newDObtn);
        iolayout->addWidget(newDIbtn,0,i);
        iolayout->addWidget(newDObtn,1,i);
    }

    vector<string> cardnamelist=_DAQIO->GetCardName();
    int length=cardnamelist.size();
    for(int i =0 ;  i<length ; i++)
    {
        QString qstr = QString::fromStdString(cardnamelist[i]);
        ui->comboBox->addItem(qstr);
    }

    ui->comboBox->setCurrentIndex(0);
    selectCardindex=0;
    PageStartIndex=1;
    ui->labelPageNum->setText(tr("%1").arg(PageStartIndex));
    //ui->BtnPreviousPage->setEnabled(false);
    checkpages();
}

void MainWindow::RefreshIOState()
{

}
MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_BtnTest1_clicked()
//{
//    //ui->IOLayout->addLayout();
//    //std::string str = std::to_string(_btnDIBtn.size());

//    int setrow=(int)_btnDIBtn.size();
//    QPushButton *newbtn;
//    newbtn=new QPushButton(tr("Button %1").arg(setrow + 1));
//    newbtn->setStyleSheet(_IOBtnStyle);
//    newbtn->setCheckable(true);
//    _btnDIBtn.push_back(newbtn);

//    //ui->IOLayout->addWidget(newbtn,0,setrow);
//    //setLayout(ui->IOLayout);
//}
void MainWindow::on_BtnPreviousPage_clicked()
{
    PageStartIndex--;
    checkpages();
}
void MainWindow::on_BtnNextPage_clicked()
{
    PageStartIndex++;
    checkpages();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    selectCardindex=index;
    PageStartIndex=1;
    checkpages();
}



void MainWindow::checkpages()
{
    ui->labelPageNum->setText(tr("%1").arg(PageStartIndex));
    int stratindex=(PageStartIndex-1)*pagecount;

    int inum=_DAQIO->GetCardProperty(IOCardProperty::DICount,selectCardindex);
    int Onum=_DAQIO->GetCardProperty(IOCardProperty::DOCount,selectCardindex);

    //int enablecount=Onum>(stratindex+pagecount)?pagecount:Onum;


    for(int i=0 ;i<pagecount ;i++)
    {
        int oi=stratindex+i;
        bool readdistate;
        bool readdostate;
        if(Onum>oi)
        {
            //            _btnDIBtn[i]->setEnabled(true);
            //            _btnDOBtn[i]->setEnabled(true);

             _DAQIO->ReadDI(selectCardindex,oi,readdistate);

             _DAQIO->ReadDO(selectCardindex,oi,readdostate);
            _btnDIBtn[i]->setText(tr("I %1").arg(oi+1));
            _btnDOBtn[i]->setText(tr("O %1").arg(oi+1));
            _btnDOBtn[i]->setChecked(readdostate);
            _btnDIBtn[i]->setChecked(readdistate);
            _btnDIBtn[i]->setVisible(true);
            _btnDOBtn[i]->setVisible(true);
            //qDebug() << stratindex+i+1;
        }
        else
        {
            //            _btnDIBtn[i]->setText(tr("Null").arg(stratindex+i+1));
            //            _btnDOBtn[i]->setText(tr("Null").arg(stratindex+i+1));
            //            _btnDIBtn[i]->setEnabled(false);
            //            _btnDOBtn[i]->setEnabled(false);
            _btnDIBtn[i]->setVisible(false);
            _btnDOBtn[i]->setVisible(false);
        }
    }
    if(Onum<=stratindex+pagecount)
    {
        ui->BtnNextPage->setEnabled(false);
    }
    else
    {
        ui->BtnNextPage->setEnabled(true);
    }
    if(0>=stratindex)
    {
        ui->BtnPreviousPage->setEnabled(false);
    }
    else
    {
        ui->BtnPreviousPage->setEnabled(true);

    }
}

void MainWindow::on_BtnOperation_clicked()
{
    QString str=ui->textInput->text();
    QStringList strlist=str.split(",");
    int length=strlist.length();
    vector<string> comlist;
    DIOOperator optr;
    string emsg("entry");
    for (int i =0 ;i<length ;i++)
    {
        str=strlist.at(i);
        comlist.push_back(str.toStdString());
        //qDebug() <<str;
    }
    if(testcomplier->Complier(comlist,emsg,optr))
    {
        string msg;
        optr(msg);
        checkpages();
    }
    qDebug() <<emsg.data();

    //qDebug() <<length;


}
