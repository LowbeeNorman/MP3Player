#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bass24\c\bass.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void changeScreenIndex(int index);
    void startSong(std::string* filepath, std::string songname);
    void pauseSong();
    void resumeSong();
    void playSongAtTime(double time);
    // void skipSong();

signals:
    void toggleMenuButton();
    void songStarted();
    void songStopped();
    void songSkipped();
    void currentSongName(QString songname);
    void playNext();
    void currentSongFinished();

private:
    Ui::MainWindow *ui;
    void songCheck(HSYNC handle, DWORD channel, DWORD data, void *user);
};
#endif // MAINWINDOW_H
