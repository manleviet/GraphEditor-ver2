/********************************************************************************
** Form generated from reading ui file 'taskdialog.ui'
**
** Created: Wed Dec 9 19:26:52 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idLine;
    QLabel *label_2;
    QLineEdit *weightLine;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TaskDialog)
    {
        if (TaskDialog->objectName().isEmpty())
            TaskDialog->setObjectName(QString::fromUtf8("TaskDialog"));
        TaskDialog->resize(319, 146);
        verticalLayout = new QVBoxLayout(TaskDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TaskDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idLine = new QLineEdit(TaskDialog);
        idLine->setObjectName(QString::fromUtf8("idLine"));

        gridLayout->addWidget(idLine, 0, 1, 1, 1);

        label_2 = new QLabel(TaskDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        weightLine = new QLineEdit(TaskDialog);
        weightLine->setObjectName(QString::fromUtf8("weightLine"));

        gridLayout->addWidget(weightLine, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(TaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(idLine, weightLine);
        QWidget::setTabOrder(weightLine, buttonBox);

        retranslateUi(TaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TaskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TaskDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskDialog)
    {
        TaskDialog->setWindowTitle(QApplication::translate("TaskDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskDialog", "Id:", 0, QApplication::UnicodeUTF8));
        idLine->setInputMask(QApplication::translate("TaskDialog", ">Aa; ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskDialog", "Weight:", 0, QApplication::UnicodeUTF8));
        weightLine->setInputMask(QApplication::translate("TaskDialog", "900; ", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TaskDialog);
    } // retranslateUi

};

namespace Ui {
    class TaskDialog: public Ui_TaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
