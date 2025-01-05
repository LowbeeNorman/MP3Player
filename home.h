#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "playlistButton.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();


private:
    Ui::Home *ui;
    bool repeat = false;

signals:
    void removeButtonClicked(std::string name);
    void upButtonClicked(std::string name);
    void downButtonClicked(std::string name);
    void nextSongToPlay(std::string songName);

public slots:
    // void removeButtonPressed();
    // void upButtonPressed();
    // void downButtonPressed();
    void needToPlayNext();
    void addToQueue(QString name);

};



#endif // HOME_H
