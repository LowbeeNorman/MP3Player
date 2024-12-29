#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class clickableLabel;
}

class clickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit clickableLabel(QWidget *parent = nullptr, QString name = "");
    ~clickableLabel();

private:
    Ui::clickableLabel *ui;

signals:
    void clicked();

private slots:
    void slotClicked();
    void mousePressEvent (QMouseEvent * event );

};

#endif // CLICKABLELABEL_H
