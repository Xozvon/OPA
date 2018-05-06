#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString path = "";
    ~MainWindow();
public slots:
    void openFile(const QString &filePath);
    void saveFile(const QString &filePath);
private slots:
    void on_actionOpen_triggered();

    void on_actionSave_in_file_triggered();

    void on_actionSave_triggered();

    void on_actionSet_Font_triggered();

    void on_actionRussian_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
