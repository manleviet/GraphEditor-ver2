#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class TaskDialog;
}

class TaskDialog : public QDialog {
    Q_OBJECT
public:
    TaskDialog(QString id, QString weight, QWidget *parent = 0);
    ~TaskDialog();

    QString getId();
    void setId(QString id);
    QString getWeight();
    void setWeight(QString weight);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TaskDialog *m_ui;
};

#endif // TASKDIALOG_H
