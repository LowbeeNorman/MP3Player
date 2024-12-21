#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menubar, &MenuBar::homeClicked, this, &MainWindow::changeScreenIndex);
    connect(ui->menubar, &MenuBar::libraryClicked, this, &MainWindow::changeScreenIndex);
    connect(this, &MainWindow::toggleMenuButton, ui->menubar, &MenuBar::receiveToggleButtons);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeScreenIndex(int index){
    ui->stackedWidget->setCurrentIndex(index);
    emit toggleMenuButton();
}
