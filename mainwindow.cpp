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
    slot_press_value("-0.01364");
}


void MainWindow::slot_press_value(QString message)
{
    for (int i = 0; i<message.size();++i)
    {
    char char_buffer =  message.toStdString()[i];
    if (char_buffer == '.')
    {
        keybd_event(VK_DECIMAL, 0,0,0);
        keybd_event(VK_DECIMAL, 0,KEYEVENTF_KEYUP,0);
    }
    else if (char_buffer == '-')
        {
        keybd_event(VK_SUBTRACT, 0,0,0);
        keybd_event(VK_SUBTRACT, 0,KEYEVENTF_KEYUP,0);
        }
    else
        {
        keybd_event(char_buffer, 0,0,0);
        keybd_event(char_buffer, 0,KEYEVENTF_KEYUP,0);
        }
    }
    keybd_event(VK_RETURN, 0,0,0);
    keybd_event(VK_RETURN, 0,KEYEVENTF_KEYUP,0);
}

void MainWindow::on_btn_start_execute_pressed()
{
    slot_move_and_click(ui->line_x->text().toInt(),ui->line_y->text().toInt());
    slot_press_value(ui->line_1->text());
    slot_press_value(ui->line_2->text());
    slot_press_value(ui->line_3->text());
    slot_press_value("1");
}
