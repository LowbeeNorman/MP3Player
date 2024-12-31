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
    void setInsideText(const QString s);

private:
    Ui::clickableLabel *ui;
    QString insideText = "";

signals:
    void clicked(std::string name);

private slots:
    void mousePressEvent (QMouseEvent * event );


};

#endif // CLICKABLELABEL_H
