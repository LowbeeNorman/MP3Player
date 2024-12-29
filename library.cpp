#include "library.h"
#include "ui_library.h"
#include "libraryitem.h"
#include "clickablelabel.h"
#include <filesystem>
namespace fs = std::filesystem;

std::string path = "C:\\Users\\caleb\\Documents\\GitHub\\MP3Player\\songs"; // Hardcoded path to songs folder


std::string getSongPath(std::string name){
    std::string songPath = path;
    songPath.append("\\");
    songPath.append(name);
    songPath.append(".mp3");
    return songPath;
}

std::vector<std::string> getSongNames(){
    std::vector<std::string> songs;

    for (const auto & entry : fs::directory_iterator(path)) {

        std::string currSong = entry.path().string();
        currSong.erase(0, path.length() + 1); // Trim path
        currSong.erase(currSong.length() - 4, currSong.length()); // Trim extension (.mp4)
        songs.push_back(currSong);
    }
    return songs;
}

void Library::listItemClicked(QListWidgetItem *item){
    std::string songName = item->text().toStdString();
    std::string filePath = getSongPath(songName);
    emit requestPlaySong(&filePath, songName);
}

Library::Library(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Library)
{
    std::vector<std::string> songs = getSongNames();
    ui->setupUi(this);



    for(std::string song : songs){
        QString qsong = QString::fromStdString(song);
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->songList);
        libraryItem *item = new libraryItem(parent, qsong);
        listWidgetItem->setSizeHint(item->sizeHint());
        ui->songList->setItemWidget(listWidgetItem, item);

    }
    connect(ui->songList, &QListWidget::itemClicked, this, &Library::listItemClicked);
}





Library::~Library()
{
    delete ui;
}
