#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    setWindowIcon(QIcon(":/logo.ico"));
    settings = new QSettings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CLSID\\{645FF040-5081-101B-9F08-00AA002F954E}\\DefaultIcon", QSettings::NativeFormat);
    QDir dir(dirName);
    if(!dir.exists())
    {
        dir.mkdir(dirName);
        qDebug()<<"文件夹创建成功";
    }
    for(auto res:resFiles)
        this->saveResourecFile(res,dirName + res);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    settings->setValue("full",dirName + "cat_full.dll,0");
    settings->setValue("empty",dirName + "cat_empty.dll,0");
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<settings->allKeys();
    settings->setValue("full","%SystemRoot%\\System32\\imageres.dll,-54");
    settings->setValue("empty","%SystemRoot%\\System32\\imageres.dll,-55");
}

void MainWindow::saveResourecFile(QString resFileName,QString destFullPathFileName) {
    //组装资源文件中的文件
    QString resFile;
    resFile=":/"+resFileName;
    QFile::copy(resFile,destFullPathFileName);
}
