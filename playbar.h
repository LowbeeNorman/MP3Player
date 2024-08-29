#ifndef PLAYBAR_H
#define PLAYBAR_H

#include <QWidget>

namespace Ui {
class Playbar;
}

class Playbar : public QWidget
{
    Q_OBJECT

public:
    explicit Playbar(QWidget *parent = nullptr);
    ~Playbar();

private:
    Ui::Playbar *ui;
    bool playing = false;
    int looping = 0; // 0 means no looping, 1 means looping through queue, 2 means looping through song
    bool shuffling = false;



public slots:
    void playButtonToggle();
    void loopButtonToggle();
    void shuffleButtonToggle();

signals:
    void playPressed();
    void loopPressed();
    void shufflePressed();
};




#endif // PLAYBAR_H
