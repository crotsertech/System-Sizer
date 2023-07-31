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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculate(); // Declaration for the calculate() slot

private:
    Ui::MainWindow *ui;

private slots:
    void showHelp();

private slots:
    void showLicense();

private slots:
    void openWebUrl();

};

#endif // MAINWINDOW_H
