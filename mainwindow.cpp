#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"
#include "ui_file.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile(const QString &filePath)
{
    QFile file(filePath);
    path = filePath;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File no open");
    }
    QTextStream stream(&file);
    QString buffer = stream.readAll();
    ui->textEdit->setText(buffer);
    file.flush();
    file.close();
}

void MainWindow::saveFile(const QString &filePath)
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File no save");
    }
    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();
}

void MainWindow::on_actionOpen_triggered()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd,SIGNAL(filePath(QString)),this,SLOT(openFile(QString)));
}

void MainWindow::on_actionSave_in_file_triggered()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd,SIGNAL(filePath(QString)),this,SLOT(saveFile(QString)));
}

void MainWindow::on_actionSave_triggered()
{
    saveFile(path);
}

void MainWindow::on_actionSet_Font_triggered()
{
    QFont Font = QFontDialog::getFont(0);
    ui->textEdit->setFont(Font);
}

void MainWindow::on_actionRussian_triggered()
{
    double tmp = rand()%10;
    ui->lcdNumber->display(tmp);
}
