#include "file.h"
#include "ui_file.h"
#include <QFileDialog>
#include <QMessageBox>
File::File(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked(bool)),this,SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked(bool)),this,SLOT(close()));
    setFixedSize(491,70);
}

File::~File()
{
    delete ui;
}

void File::on_pushButton_clicked()
{
    QString file_filter = "All Files (*.*) ;; Txt Files (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this,"open the file","C://",file_filter);
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File no open");
    }
    ui->lineEdit->setText(file_name);
}

void File::okClicked()
{
    emit filePath(ui->lineEdit->text());
    File::close();
}
