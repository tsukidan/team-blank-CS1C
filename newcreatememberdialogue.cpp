#include "newcreatememberdialogue.h"
#include "ui_newcreatememberdialogue.h"

newCreateMemberDialogue::newCreateMemberDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCreateMemberDialogue)
{
    ui->setupUi(this);
}

newCreateMemberDialogue::~newCreateMemberDialogue()
{
    delete ui;
}
