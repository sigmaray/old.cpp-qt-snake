#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtWidgets/QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct coordinate{             // Structure declaration
  int x = 0;         // Member (int variable)
  int y = 0;   // Member (string variable)
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void render();

    std::vector<std::vector<coordinate>> matrix;
    std::vector<std::vector<QCheckBox *>> checkboxes;


    coordinate current;

protected:
    virtual void keyPressEvent( QKeyEvent *  e);
};
#endif // MAINWINDOW_H
