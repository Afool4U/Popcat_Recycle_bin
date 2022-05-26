#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QDir>

const QString resFiles[] ={"cat_empty.dll","cat_full.dll"};
const QString dirName = "C:/小猫图标/";  // 图标保存路径

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void saveResourecFile(QString resFileName,QString destFullPathFileName);
    Ui::MainWindow *ui;
    QSettings *settings;
};

#endif // MAINWINDOW_H
