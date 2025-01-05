#ifndef PLAYLISTBUTTON_H
#define PLAYLISTBUTTON_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class playlistButton;
}

class playlistButton : public QWidget
{
    Q_OBJECT

public:
    explicit playlistButton(QWidget *parent, QString name);
    ~playlistButton();

private:
    Ui::playlistButton *ui;
};

#endif // PLAYLISTBUTTON_H
