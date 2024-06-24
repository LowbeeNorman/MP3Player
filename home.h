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
};



#endif // HOME_H
