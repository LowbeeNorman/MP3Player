#include "clickablelabel.h"
#include "ui_clickablelabel.h"

clickableLabel::clickableLabel(QWidget *parent, QString name)
    : QLabel(parent)
    , ui(new Ui::clickableLabel)
{
    ui->setupUi(this);
    ui->name->setText(name);
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void clickableLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void clickableLabel::slotClicked()
{
    qDebug()<<"Clicked";
}

clickableLabel::~clickableLabel()
{
    delete ui;
}
