#include "libraryitem.h"
#include "ui_libraryitem.h"
#include "clickablelabel.h"

libraryItem::libraryItem(QWidget *parent, QString name)
    : QWidget(parent)
    , ui(new Ui::libraryItem)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

libraryItem::~libraryItem()
{
    delete ui;
}
