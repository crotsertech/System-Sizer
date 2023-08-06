#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <cmath>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculate); //Do the shit
    connect(ui->helpButton, &QPushButton::clicked, this, &MainWindow::showHelp); //Warranty disclaimer
    connect(ui->licenseButton, &QPushButton::clicked, this, &MainWindow::showLicense); // GPLv3
    connect(ui->webButton, &QPushButton::clicked, this, &MainWindow::openWebUrl); // Button to file bug report
    connect(ui->donateButton, &QPushButton::clicked, this, &MainWindow::openDonateUrl); // Button to donate to the author on Ko-Fi
    connect(ui->donateButton2, &QPushButton::clicked, this, &MainWindow::openDonateUrl2); // Button to donate to the author on Paypal

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showHelp()
{
    QString helpText = "This program is provied AS-IS with NO WARRANTY OF ANY KIND, "
                       "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS "
                       "FOR A PARTICULAR PURPOSE. ";

    QMessageBox::information(this, "Help", helpText);
}

void MainWindow::showLicense()
{
    QString LicenseText = "This program is licensed under GNU GPLv3. "
                          "For more information, consult LICENSE.TXT "
                          "that accompanied this program.";

    QMessageBox::information(this, "License", LicenseText);
}
void MainWindow::openWebUrl()
{
    QDesktopServices::openUrl(QUrl("https://github.com/crotsertech/System-Sizer/issues/new")); // URL to file a bug report
}

void MainWindow::openDonateUrl()
{
    QDesktopServices::openUrl(QUrl("https://ko-fi.com/ntcrotser")); // URL to donate to the author
}

void MainWindow::openDonateUrl2()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/paypalme/crotsertech")); // URL to donate to the author
}



void MainWindow::calculate()
{
    double multiply;
    double capacity;
    double f3;
    double hardness;
    double salt;
    double fe;
    double mg;

    f3 = ui->f3LineEdit->text().toDouble();
    QString salt_mode = ui->saltLineEdit->currentText(); // Corrected: Use QLineEdit, not QComboBox

    if (salt_mode == "High Efficiency (3lb)")
        salt = 15000;
    else if (salt_mode == "Standard (6lb)")
        salt = 25000;
    else if (salt_mode == "High Capacity (12lb)")
        salt = 30000;
    else
    {
        QMessageBox::critical(this, "Error", "Invalid salt mode setting. Please choose from the provided options.");
        return;
    }

    fe = ui->ironResultLineEdit->text().toDouble();
    mg = ui->manganeseResultLineEdit->text().toDouble();

    hardness = ui->rawHardnessLineEdit->text().toDouble();
    multiply = f3 * salt / hardness + fe * 4 + mg * 8 * 0.10;

    capacity = f3 * salt;
    multiply = hardness + fe * 4 + mg * 8;
    float gal = (capacity / multiply * 0.90);

    QMessageBox::information(this, "Result", "This system's capacity is: " + QString::number(std::round(gal)) + " gallons.");
}
