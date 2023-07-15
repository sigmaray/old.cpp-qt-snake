#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //    , ui(new Ui::MainWindow)
{
    //    ui->setupUi(this);


    QVBoxLayout *vlayout = new QVBoxLayout;
    for ( int i = 0; i < 5; i++ ) {
        QHBoxLayout *hlayout = new QHBoxLayout;
        for ( int i = 0; i < 5; i++ ) {
            QCheckBox *checkbox = new QCheckBox(QString::number(i));
            hlayout->addWidget(checkbox);
        }
        vlayout->addLayout(hlayout);
    }
    this->setLayout(vlayout);


//    layout->addWidget(checkbox);

}

MainWindow::~MainWindow()
{
    delete ui;
}

