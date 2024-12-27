#include "playbar.h"
#include "ui_playbar.h"


Playbar::Playbar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Playbar)
{
    ui->setupUi(this);
    connect(ui->playButton, &QPushButton::clicked, this, &Playbar::playButtonToggle);
    connect(ui->loopButton, &QPushButton::clicked, this, &Playbar::loopButtonToggle);
    connect(ui->shuffleButton, &QPushButton::clicked, this, &Playbar::shuffleButtonToggle);
}

Playbar::~Playbar()
{
    delete ui;
}

void Playbar::playButtonToggle(){
    if(playing){
        playing = false;
        ui->playButton->setText("Paused");
        emit musicPlayed();

    }
    else{
        playing = true;
        ui->playButton->setText("Playing");
        emit musicPaused();
    }
    emit playPressed();
}

void Playbar::playButtonShowPlay(){
    playing = true;
    ui->playButton->setText("Playing");
    emit musicPaused();
}

void Playbar::setCurrentSongName(QString songname){
    ui->songName->setText(songname);
}

void Playbar::playButtonShowPause(){
    playing = false;
    ui->playButton->setText("Paused");
    emit musicPlayed();
}

void Playbar::loopButtonToggle(){
    if(looping == 0){
        looping++;
        ui->loopButton->setText("Looping Queue");
    }
    else if(looping == 1){
        looping++;
        ui->loopButton->setText("Looping Song");
    }
    else{
        looping = 0;
        ui->loopButton->setText("Not Looping");
    }
    emit loopPressed();
}

void Playbar::shuffleButtonToggle(){
    if(shuffling){
        shuffling = false;
        ui->shuffleButton->setText("Not Shuffling");

    }
    else{
        shuffling = true;
        ui->shuffleButton->setText("Shuffling");
    }
    emit shufflePressed();
}
