#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QToolButton>

#include "diagramscene.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openButtonClicked();
    void newButtonClicked();
    bool saveButtonClicked();
    void pointerButtonClicked();
    void cycleButtonClicked();
    void taskButtonClicked();
    void fictivetaskButtonClicked();
    void sceneScaleChanged(int scale);
    void sceneChanged();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void setCheckedButton(QToolButton *button);
    void setCurrentFile(const QString &fileName);
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    bool saveAs();

    Ui::MainWindow *ui;
    DiagramScene *scene;
    QString curFile;
    QString curPath;
};

#endif // MAINWINDOW_H
