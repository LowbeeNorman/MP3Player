#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QWidget>

namespace Ui {
class libraryItem;
}

class libraryItem : public QWidget
{
    Q_OBJECT

public:
    explicit libraryItem(QWidget *parent = nullptr, QString name = "");
    ~libraryItem();

private:
    Ui::libraryItem *ui;
};

#endif // LIBRARYITEM_H
