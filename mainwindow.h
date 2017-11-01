#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCursor>
#include <windows.h>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots :
    void slot_move_and_click(int x, int y);
    void on_btn_set_pos_pressed();
    void on_pushButton_pressed();
    void slot_press_value(QString message);
};

#endif // MAINWINDOW_H
