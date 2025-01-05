#include "playlistbutton.h"
#include "ui_playlistbutton.h"

playlistButton::playlistButton(QWidget *parent, QString name)
    : QWidget(parent)
    , ui(new Ui::playlistButton)
{
    ui->setupUi(this);
    ui->playlistName->setText(name);
}

playlistButton::~playlistButton()
{
    delete ui;
}
