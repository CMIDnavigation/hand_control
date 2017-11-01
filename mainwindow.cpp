#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_move_and_click(int x, int y)
{
//     QPoint pos_now = QCursor::pos();
//     QCursor::setPos(x,y);

    SetCursorPos(x, y);
    for (int i = 0; i<2; i++)
    {
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);//нажатие левой кнопки мыши
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);//отпускание кнопки
    }
//    QCursor::setPos(pos_now);
}

void MainWindow::on_btn_set_pos_pressed()
{
    slot_move_and_click(ui->line_x->text().toInt(),ui->line_y->text().toInt());
}

void MainWindow::on_pushButton_pressed()
{
    ui->line_x->setText("Pressed");
    int val_spin = ui->spinBox->value();
    ui->spinBox->setValue(val_spin+1);
}

void MainWindow::slot_press_value(QString message)
{

}
