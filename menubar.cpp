#include "menubar.h"
#include "ui_menubar.h"

MenuBar::MenuBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuBar)
{
    ui->setupUi(this);
    connect(ui->homeButton, &QPushButton::clicked, this, &MenuBar::receiveHomeClicked);
    connect(ui->libraryButton, &QPushButton::clicked, this, &MenuBar::receiveLibraryClicked);
}

MenuBar::~MenuBar()
{
    delete ui;
}

void MenuBar::receiveHomeClicked(){
    emit homeClicked(0);
}

void MenuBar::receiveLibraryClicked(){
    emit libraryClicked(1);
}

void MenuBar::receiveToggleButtons(){
    if(ui->homeButton->isEnabled()){
        ui->homeButton->setDisabled(true);
    }
    else{
        ui->homeButton->setDisabled(false);
    }
    if(ui->libraryButton->isEnabled()){
        ui->libraryButton->setDisabled(true);
    }
    else{
        ui->libraryButton->setDisabled(false);
    }
}
