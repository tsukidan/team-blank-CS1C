#ifndef NEWCREATEMEMBERDIALOGUE_H
#define NEWCREATEMEMBERDIALOGUE_H

#include <QDialog>

namespace Ui {
class newCreateMemberDialogue;
}

class newCreateMemberDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit newCreateMemberDialogue(QWidget *parent = nullptr);
    ~newCreateMemberDialogue();

private:
    Ui::newCreateMemberDialogue *ui;
};

#endif // NEWCREATEMEMBERDIALOGUE_H
