#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bass24\c\bass.h"
#include <iostream>

HSAMPLE sample;
HCHANNEL channel;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    BASS_Init(-1, 44100, 0, 0, NULL); // Initialize BASS, should be done once
    // std::cout << "INITIALIZE: " << BASS_ErrorGetCode() << std::endl;


    ui->setupUi(this);
    connect(ui->menubar, &MenuBar::homeClicked, this, &MainWindow::changeScreenIndex);
    connect(ui->menubar, &MenuBar::libraryClicked, this, &MainWindow::changeScreenIndex);
    connect(this, &MainWindow::toggleMenuButton, ui->menubar, &MenuBar::receiveToggleButtons);
    connect(ui->songLibrary, &Library::requestPlaySong, this, &MainWindow::startSong);
    connect(this, &MainWindow::songStarted, ui->playbar, &Playbar::playButtonShowPause);
    connect(ui->playbar, &Playbar::musicPaused, this, &MainWindow::pauseSong);
    connect(ui->playbar, &Playbar::musicPlayed, this, &MainWindow::resumeSong);
    connect(this, &MainWindow::currentSongName, ui->playbar, &Playbar::setCurrentSongName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// This makes the song playing work for some reason, otherwise it will give an error about it not being able to open the file
const void* getFile(std::string* file){
    return file->data();
}

void MainWindow::startSong(std::string* filepath, std::string songname){
    if(BASS_ChannelIsActive(channel)){
        BASS_ChannelStop(sample);
    }
        sample = BASS_SampleLoad(false, getFile(filepath), 0, 0, 1, 0);
        // std::cout << "HSAMPLE: " << BASS_ErrorGetCode() << std::endl;
        channel = BASS_SampleGetChannel(sample, 0);
        // std::cout << "CHANNEL: " << BASS_ErrorGetCode() << std::endl;
        BASS_ChannelPlay(channel, TRUE);
        // std::cout << "CHANNELPLAY: " << BASS_ErrorGetCode() << std::endl;
        BASS_ChannelStart(channel);
        // std::cout << "CHANNELSTART: " << BASS_ErrorGetCode() << std::endl;
        emit songStarted();
        emit currentSongName(QString::fromStdString(songname));

}


void MainWindow::pauseSong(){
    if(BASS_ChannelIsActive(channel)){
        BASS_ChannelPause(channel);
    }
}

void MainWindow::resumeSong(){
    if(BASS_ChannelIsActive(channel)){
        BASS_ChannelStart(channel);
    }
}

void MainWindow::playSongAtTime(double time){
    BASS_ChannelUpdate(sample, BASS_ChannelSeconds2Bytes(sample, time)); // Updates the channel to play at a specific time, but has to convert to bytes
}

void MainWindow::changeScreenIndex(int index){
    ui->stackedWidget->setCurrentIndex(index);
    emit toggleMenuButton();
}
