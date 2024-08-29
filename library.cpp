#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->songList->addItem("Song");
}

Library::~Library()
{
    delete ui;
}
