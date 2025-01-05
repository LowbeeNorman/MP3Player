#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::addToQueue(QString name){
    bool add = true;
    int c = ui->playlists->count();
    for(int i = 0; i < c; i++){
        QListWidgetItem *item = ui->playlists->item(i);
        if(item->toolTip() == name){
            add = false;
        }
    }
    if(add){
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->playlists);
        playlistButton *testButton = new playlistButton(this, name);
        listWidgetItem->setSizeHint(testButton->sizeHint());
        listWidgetItem->setToolTip(name);
        ui->playlists->setItemWidget(listWidgetItem, testButton);
    }

}

void Home::needToPlayNext(){
    if(ui->playlists->count() > 1){
        if(repeat){
            QListWidgetItem *currentItem = ui->playlists->item(0);
            emit nextSongToPlay(currentItem->toolTip().toStdString());
        }
        else{
            ui->playlists->takeItem(0);
            QListWidgetItem *currentItem = ui->playlists->item(0);
            emit nextSongToPlay(currentItem->toolTip().toStdString());
        }
    }
    else{
        ui->playlists->takeItem(0);
    }

}
