#include "clickablelabel.h"
#include "ui_clickablelabel.h"

clickableLabel::clickableLabel(QWidget *parent, QString name)
    : QLabel(parent)
    , ui(new Ui::clickableLabel)
{
    ui->setupUi(this);
    ui->name->setText(name);
}

void clickableLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked(insideText.toStdString());
}

void clickableLabel::setInsideText(const QString s){
    insideText = s;
}
clickableLabel::~clickableLabel()
{
    delete ui;
}
