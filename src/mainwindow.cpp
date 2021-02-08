#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QPushButton>
#include <QClipboard>
#include <QStatusBar>
#include <QAction>
#include <QMessageBox>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->preview->setStyleSheet("#preview{background-color: black;}");
    this->setWindowTitle("ColorPicker by akd");

    this->setWindowIcon(QIcon(":/img/palette.svg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int r=0,g=0,b=0;
QString s=0;


void MainWindow::update(){
    QString rhex=0, ghex=0, bhex=0;
    r = ui->red->value();
    g = ui->green->value();
    b = ui->blue->value();

    rhex=QString("%1").arg(r,0,16);
    ghex=QString("%1").arg(g,0,16);
    bhex=QString("%1").arg(b,0,16);

    if(r<=15) rhex="0"+rhex;
    if(g<=15) ghex="0"+ghex;
    if(b<=15) bhex="0"+bhex;

    s="#"+rhex+ghex+bhex;

    ui->textpreview->setText(s);
    ui->textpreview->setStyleSheet("#textpreview{color: "+s+";}");
    ui->preview->setStyleSheet("#preview{background-color: "+s+";}");

}

void MainWindow::on_pushButton_clicked()
{
    QClipboard *Clipboard = QApplication::clipboard();
    Clipboard->setText(s);
    statusBar()->showMessage(tr("Скопировано!!"), 2000);
}

void MainWindow::on_blue_textChanged(const QString &arg1)
{
    update();
}

void MainWindow::on_green_textChanged(const QString &arg1)
{
    update();
}

void MainWindow::on_red_textChanged(const QString &arg1)
{
    update();
}

void MainWindow::on_actioninfo_triggered()
{
    QMessageBox::information(this, "ColorPicker's info", "Подбирает цвета 24/7\nby Артем Резниченко\n");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Закрыть?",
                          "Точно?\nУверены?\nСогласны?",
                          QMessageBox::Yes|QMessageBox::No))
    {
    event->accept();
    }

}
