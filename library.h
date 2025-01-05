#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include <QListWidgetItem>

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

public slots:
    void listItemClicked(QListWidgetItem *item);
    void playItemConvert(std::string song);

signals:
    void requestPlaySong(std::string * filePath, std::string name);
    void addSongToQueue(QString songName);
};

#endif // LIBRARY_H
