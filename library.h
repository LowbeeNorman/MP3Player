#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>

namespace Ui {
class Library;
}

class Library : public QWidget
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = nullptr);
    ~Library();

private:
    Ui::Library *ui;
};

#endif // LIBRARY_H
