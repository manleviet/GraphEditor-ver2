/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Dec 23 11:49:16 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *newButton;
    QToolButton *openButton;
    QToolButton *saveButton;
    QFrame *line;
    QToolButton *pointerButton;
    QToolButton *cycleButton;
    QToolButton *taskButton;
    QToolButton *fictivetaskButton;
    QSpacerItem *horizontalSpacer;
    QSlider *scaleSlider;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(726, 490);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon/creator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newButton = new QToolButton(centralWidget);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon/new.ico"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon1);
        newButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(newButton);

        openButton = new QToolButton(centralWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icon/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon2);
        openButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(openButton);

        saveButton = new QToolButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icon/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon3);
        saveButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(saveButton);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        pointerButton = new QToolButton(centralWidget);
        pointerButton->setObjectName(QString::fromUtf8("pointerButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icon/pointer.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pointerButton->setIcon(icon4);
        pointerButton->setIconSize(QSize(32, 32));
        pointerButton->setCheckable(true);

        horizontalLayout->addWidget(pointerButton);

        cycleButton = new QToolButton(centralWidget);
        cycleButton->setObjectName(QString::fromUtf8("cycleButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icon/cycle.ico"), QSize(), QIcon::Normal, QIcon::Off);
        cycleButton->setIcon(icon5);
        cycleButton->setIconSize(QSize(32, 32));
        cycleButton->setCheckable(true);

        horizontalLayout->addWidget(cycleButton);

        taskButton = new QToolButton(centralWidget);
        taskButton->setObjectName(QString::fromUtf8("taskButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icon/task.ico"), QSize(), QIcon::Normal, QIcon::Off);
        taskButton->setIcon(icon6);
        taskButton->setIconSize(QSize(32, 32));
        taskButton->setCheckable(true);

        horizontalLayout->addWidget(taskButton);

        fictivetaskButton = new QToolButton(centralWidget);
        fictivetaskButton->setObjectName(QString::fromUtf8("fictivetaskButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icon/fictivetask.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fictivetaskButton->setIcon(icon7);
        fictivetaskButton->setIconSize(QSize(32, 32));
        fictivetaskButton->setCheckable(true);

        horizontalLayout->addWidget(fictivetaskButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scaleSlider = new QSlider(centralWidget);
        scaleSlider->setObjectName(QString::fromUtf8("scaleSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scaleSlider->sizePolicy().hasHeightForWidth());
        scaleSlider->setSizePolicy(sizePolicy);
        scaleSlider->setMinimum(20);
        scaleSlider->setMaximum(200);
        scaleSlider->setSingleStep(10);
        scaleSlider->setValue(110);
        scaleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(scaleSlider);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(newButton, SIGNAL(clicked()), MainWindow, SLOT(newButtonClicked()));
        QObject::connect(openButton, SIGNAL(clicked()), MainWindow, SLOT(openButtonClicked()));
        QObject::connect(saveButton, SIGNAL(clicked()), MainWindow, SLOT(saveButtonClicked()));
        QObject::connect(pointerButton, SIGNAL(clicked()), MainWindow, SLOT(pointerButtonClicked()));
        QObject::connect(cycleButton, SIGNAL(clicked()), MainWindow, SLOT(cycleButtonClicked()));
        QObject::connect(taskButton, SIGNAL(clicked()), MainWindow, SLOT(taskButtonClicked()));
        QObject::connect(fictivetaskButton, SIGNAL(clicked()), MainWindow, SLOT(fictivetaskButtonClicked()));
        QObject::connect(scaleSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(sceneScaleChanged(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graph Creator", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("MainWindow", "New graph", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        openButton->setToolTip(QApplication::translate("MainWindow", "Open a graph", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        openButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pointerButton->setToolTip(QApplication::translate("MainWindow", "Pointer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pointerButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cycleButton->setToolTip(QApplication::translate("MainWindow", "A Node", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cycleButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        taskButton->setToolTip(QApplication::translate("MainWindow", "Task", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        taskButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fictivetaskButton->setToolTip(QApplication::translate("MainWindow", "Task Fictive", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fictivetaskButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scaleSlider->setToolTip(QApplication::translate("MainWindow", "Scale Slider", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
