#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_zero_button_clicked();

    void on_one_button_clicked();

    void on_two_button_clicked();

    void on_three_button_clicked();

    void on_four_button_clicked();

    void on_five_button_clicked();

    void on_six_button_clicked();

    void on_seven_button_clicked();

    void on_eight_button_clicked();

    void on_nine_button_clicked();


    void on_point_button_clicked();

    void on_clear_button_clicked();

    void on_delete_button_clicked();

    void on_plus_button_clicked();

    void on_equal_button_clicked();

private:
    Ui::MainWindow *ui;
    double firstNum;
    bool secondNumberFlag;
    QString currentOperator;

    void calculate(double secondNum);
};
#endif // MAINWINDOW_H
