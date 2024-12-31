#include "libraryitem.h"
#include "ui_libraryitem.h"
#include "clickablelabel.h"

libraryItem::libraryItem(QWidget *parent, QString name)
    : QWidget(parent)
    , ui(new Ui::libraryItem)
{
    ui->setupUi(this);
    ui->label->setInsideText(name);
    ui->label->setText(name);

    connect(ui->label, &clickableLabel::clicked, this, &libraryItem::itemClicked);
}

libraryItem::~libraryItem()
{
    delete ui;
}

void libraryItem::itemClicked(std::string name){
    qDebug() << name;
}
