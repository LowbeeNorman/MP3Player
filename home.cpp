#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->playlists);
    playlistButton *testButton = new playlistButton;
    listWidgetItem->setSizeHint(testButton->sizeHint());
    ui->playlists->setItemWidget(listWidgetItem, testButton);
}

Home::~Home()
{
    delete ui;
}
