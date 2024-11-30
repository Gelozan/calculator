#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , firstNum(0.0)
    , secondNumberFlag(false)
    , currentOperator("")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zero_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText != "0" && !secondNumberFlag) {
        ui->input_line->setText(currentText + "0");
    } else {
        ui->input_line->setText("0");
        secondNumberFlag = false;
    }
}

void MainWindow::on_one_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("1");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "1");
    }
}


void MainWindow::on_two_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("2");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "2");
    }
}


void MainWindow::on_three_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("3");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "3");
    }
}


void MainWindow::on_four_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("4");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "4");
    }
}


void MainWindow::on_five_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("5");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "5");
    }
}


void MainWindow::on_six_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("6");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "6");
    }
}


void MainWindow::on_seven_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("7");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "7");
    }
}


void MainWindow::on_eight_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("8");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "8");
    }
}


void MainWindow::on_nine_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0" || secondNumberFlag) {
        ui->input_line->setText("9");
        secondNumberFlag = false;
    } else {
        ui->input_line->setText(currentText + "9");
    }
}


void MainWindow::on_point_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (!currentText.contains('.')) {
        ui->input_line->setText(currentText + ".");
    }
}


void MainWindow::on_clear_button_clicked()
{
    firstNum = 0.0;
    secondNumberFlag = false;
    currentOperator = "";
    ui->input_line->setText("0");
    ui->label_operation->clear();
}


void MainWindow::on_delete_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText.length() > 1) {
        currentText.chop(1);
        ui->input_line->setText(currentText);
    } else {
        ui->input_line->setText("0");
    }
}

void MainWindow::calculate(double secondNum)
{
    if (currentOperator == "+")
    {
        firstNum += secondNum;
    }
    else if (currentOperator == "*")
    {
        firstNum *= secondNum;
    }
    else if (currentOperator == "/")
    {
        if (secondNum == 0.0) {
            msgBox.setText("Ошибка! На ноль делить нельзя!");
            msgBox.exec();
            ui->input_line->setText("0");
            currentOperator = "";
            secondNumberFlag = false;
            return;
        }
        else {
            firstNum /= secondNum;
        }
    }
    else if (currentOperator == "-")
    {
        firstNum -= secondNum;
    }
    else if (currentOperator == "%")
    {
        if (secondNum == 0.0) {
            msgBox.setText("Ошибка! На ноль делить нельзя!");
            msgBox.exec();
            ui->input_line->setText("0");
            currentOperator = "";
            secondNumberFlag = false;
            return;
        }
        else
        {
            firstNum = std::fmod(firstNum, secondNum);
        }
    }
    else if (currentOperator == "^")
    {
        if ((firstNum < 0) && (int(secondNum) != secondNum))
        {
            msgBox.setText("Ошибка! Не определено.");
            msgBox.exec();
            ui->input_line->setText("0");
            currentOperator = "";
            secondNumberFlag = false;
            return;
        }
        else
        {
            firstNum = std::pow(firstNum, secondNum);
        }
    }
    else
    {
        firstNum = secondNum;
    }

    ui->input_line->setText(QString::number(firstNum));
}

void MainWindow::on_plus_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "+";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}

void MainWindow::on_multiplication_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "*";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}

void MainWindow::on_division_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "/";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}

void MainWindow::on_equal_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();
    if (!currentOperator.isEmpty()) {
        calculate(secondNum);
        currentOperator = "";
        secondNumberFlag = false;
        ui->label_operation->clear();
    }
}

void MainWindow::on_minus_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "-";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}

void MainWindow::on_mod_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "%";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}

void MainWindow::on_power_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();

    if (!currentOperator.isEmpty() && !secondNumberFlag) {
        calculate(secondNum);
    } else if (currentOperator.isEmpty()) {
        firstNum = secondNum;
    }

    currentOperator = "^";
    secondNumberFlag = true;
    ui->label_operation->setText(QString::number(firstNum) + " " + currentOperator);
}


void MainWindow::on_sqrt_button_clicked()
{
    double secondNum = ui->input_line->text().toDouble();
    if (secondNum < 0) {
        msgBox.setText("Ошибка! Не определено.");
        msgBox.exec();
        ui->input_line->setText("0");
    }
    else
    {
        ui->input_line->setText(QString::number(std::sqrt(secondNum)));
        ui->label_operation->setText("√" + QString::number(secondNum));
    }
}

void MainWindow::on_sin_button_clicked()
{
    double secondNum=ui->input_line->text().toDouble();
    ui->input_line->setText(QString::number(std::sin(secondNum)));
    ui->label_operation->setText("sin(" +QString::number(secondNum)+")");
}

void MainWindow::on_cos_button_clicked()
{
    double secondNum=ui->input_line->text().toDouble();
    ui->input_line->setText(QString::number(std::cos(secondNum)));
    ui->label_operation->setText("cos(" +QString::number(secondNum)+")");
}


void MainWindow::on_floor_button_clicked()
{
    ui->input_line->setText(QString::number(std::floor(ui->input_line->text().toDouble())));
}


void MainWindow::on_ceil_button_clicked()
{
    ui->input_line->setText(QString::number(std::ceil(ui->input_line->text().toDouble())));
}

