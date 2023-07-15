#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "prettyprint.hpp"
#include <QDebug>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QVBoxLayout>
#include <iostream>

#define BOARD_SIZE 5

// int state_current_x = 0;
// int state_current_y = 0;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
//    , ui(new Ui::MainWindow)
{
  //    ui->setupUi(this);

  QVBoxLayout *vlayout = new QVBoxLayout;
  for (int i = 0; i < BOARD_SIZE; i++) {
    //        v.push_back(25);
    std::vector<QCheckBox *> row;
    QHBoxLayout *hlayout = new QHBoxLayout;
    for (int j = 0; j < BOARD_SIZE; j++) {
      QCheckBox *checkbox =
          new QCheckBox(QString::number(j) + ":" + QString::number(i));
      row.push_back(checkbox);
      checkbox->setEnabled(false);
      hlayout->addWidget(checkbox);
    }
    this->checkboxes.push_back(row);
    vlayout->addLayout(hlayout);
  }
  this->setLayout(vlayout);

  this->render();

  //    layout->addWidget(checkbox);
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
  QMessageBox msgBox;

  //   msgBox.setText(QString::number(e->key()));
  //   msgBox.exec();

  //   qDebug() << "key: " << e->key();

  //   qDebug() << "this->current:" << this->current;
  qDebug() << "My vector: " << this->current.x;

  if (e->key() == Qt::Key_Left) {
    if (this->current.x >= 1) {
      this->current.x--;
    } else {
      this->current.x = BOARD_SIZE - 1;
    }
  }

  if (e->key() == Qt::Key_Right) {
    if (this->current.x < BOARD_SIZE - 1) {
      this->current.x++;
    } else {
      this->current.x = 0;
    }
  }

    if (e->key() == Qt::Key_Up) {
    if (this->current.y >= 1) {
      this->current.y--;
    } else {
      this->current.y = BOARD_SIZE - 1;
    }
  }

  if (e->key() == Qt::Key_Down) {
    if (this->current.y < BOARD_SIZE - 1) {
      this->current.y++;
    } else {
      this->current.y = 0;
    }
  }


  this->render();

  //    QTextEdit::keyPressEvent(e);
}

void MainWindow::render() {
  for (int y = 0; y < this->checkboxes.size(); y++) {
    //       vector[i].doSomething();

    for (int x = 0; x < this->checkboxes.size(); x++) {
      //       vector[i].doSomething();
      if (x == current.x && y == current.y) {
        // this->checkboxes[y][x]->setEnabled(true);
        this->checkboxes[y][x]->setStyleSheet("background: #fff");
      } else {
        // this->checkboxes[y][x]->setEnabled(false);
        this->checkboxes[y][x]->setStyleSheet("background: #ccc");
      }
    }
  }
}

MainWindow::~MainWindow() { delete ui; }
