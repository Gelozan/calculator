#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    if (currentText != "0") {
        ui->input_line->setText(currentText + "0");
    }
}

void MainWindow::on_one_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("1");
    } else {
        ui->input_line->setText(currentText + "1");
    }
}


void MainWindow::on_two_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("2");
    } else {
        ui->input_line->setText(currentText + "2");
    }
}


void MainWindow::on_three_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("3");
    } else {
        ui->input_line->setText(currentText + "3");
    }
}


void MainWindow::on_four_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("4");
    } else {
        ui->input_line->setText(currentText + "4");
    }
}


void MainWindow::on_five_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("5");
    } else {
        ui->input_line->setText(currentText + "5");
    }
}


void MainWindow::on_six_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("6");
    } else {
        ui->input_line->setText(currentText + "6");
    }
}


void MainWindow::on_seven_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("7");
    } else {
        ui->input_line->setText(currentText + "7");
    }
}


void MainWindow::on_eight_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("8");
    } else {
        ui->input_line->setText(currentText + "8");
    }
}


void MainWindow::on_nine_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText == "0") {
        ui->input_line->setText("9");
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
    ui->input_line->setText("0");
}


void MainWindow::on_delete_button_clicked()
{
    QString currentText = ui->input_line->text();
    if (currentText.length() > 1) {
        currentText.chop(1);
        ui->input_line->setText(currentText);
    }
    else
        ui->input_line->setText("0");
}

