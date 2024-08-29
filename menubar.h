#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

namespace Ui {
class MenuBar;
}

class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

public slots:
    void receiveHomeClicked();
    void receiveLibraryClicked();
    void receiveToggleButtons();
signals:
    void homeClicked(int index);
    void libraryClicked(int index);

private:
    Ui::MenuBar *ui;
};

#endif // MENUBAR_H
