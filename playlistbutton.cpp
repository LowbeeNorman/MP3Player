#include "playlistbutton.h"
#include "ui_playlistbutton.h"

playlistButton::playlistButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::playlistButton)
{
    ui->setupUi(this);
    QPixmap pixmap(":/images/notloadedpic.png");
    ui->icon->setScaledContents(true);
    ui->icon->setPixmap(pixmap);
    ui->icon->setMask(pixmap.mask());
    ui->icon->show();
    ui->playlistName->setText("New Playlist");
}

playlistButton::~playlistButton()
{
    delete ui;
}
