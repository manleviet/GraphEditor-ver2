#include "taskdialog.h"
#include "ui_taskdialog.h"

TaskDialog::TaskDialog(QString id, QString weight, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::TaskDialog)
{
    m_ui->setupUi(this);
    m_ui->idLine->setText(id);
    m_ui->idLine->setSelection(0, id.length()-1);
    m_ui->weightLine->setText(weight);
    m_ui->weightLine->setSelection(0, weight.length()-1);
}

TaskDialog::~TaskDialog()
{
    delete m_ui;
}

QString TaskDialog::getId()
{
    return m_ui->idLine->text();
}

void TaskDialog::setId(QString id)
{
    m_ui->idLine->setText(id);
}

QString TaskDialog::getWeight()
{
    return m_ui->weightLine->text();
}

void TaskDialog::setWeight(QString weight)
{
    m_ui->weightLine->setText(weight);
}

void TaskDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
