#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMessageBox>

#define BOARD_SIZE 5

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //    , ui(new Ui::MainWindow)
{
    //    ui->setupUi(this);


    QVBoxLayout *vlayout = new QVBoxLayout;
    for ( int i = 0; i < BOARD_SIZE; i++ ) {
        QHBoxLayout *hlayout = new QHBoxLayout;
        for ( int j = 0; j < BOARD_SIZE; j++ ) {
            QCheckBox *checkbox = new QCheckBox(QString::number(j) + ":" + QString::number(i));
            checkbox->setEnabled(false);
            hlayout->addWidget(checkbox);
        }
        vlayout->addLayout(hlayout);
    }
    this->setLayout(vlayout);


//    layout->addWidget(checkbox);

}

void MainWindow::keyPressEvent( QKeyEvent * e)
{
   QMessageBox msgBox;

   msgBox.setText(QString::number(e->key()));
   msgBox.exec();

    if(e->key()==Qt::Key_Left)
    {
        msgBox.setText("OK");
        msgBox.exec();
    }

//    QTextEdit::keyPressEvent(e);
}

MainWindow::~MainWindow()
{
    delete ui;
}

