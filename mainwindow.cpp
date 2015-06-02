#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "diagramscene.h"
#include "xmlprovider.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    scene = new DiagramScene();
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(sceneChanged()),
            this, SLOT(sceneChanged()));

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    this->setCurrentFile("");
    QDir dir;
    curPath = dir.currentPath();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openButtonClicked()
{
    if (this->okToContinue())
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Graph"), curPath,
                                                        tr("Graph xml (*.xml)"));
        if (!fileName.isEmpty()) loadFile(fileName);
    }
}

void MainWindow::newButtonClicked()
{
    if (this->okToContinue())
    {
        scene->reset();
        this->setCurrentFile("");
    }
}

bool MainWindow::saveButtonClicked()
{
    if (this->curFile.isEmpty())
        return saveAs();
    else
        return saveFile(curFile);
}

void MainWindow::pointerButtonClicked()
{
    setCheckedButton(ui->pointerButton);
    scene->setMode(DiagramScene::Move);
}

void MainWindow::cycleButtonClicked()
{
    setCheckedButton(ui->cycleButton);
    scene->setMode(DiagramScene::InsertCycle);
}

void MainWindow::taskButtonClicked()
{
    setCheckedButton(ui->taskButton);
    scene->setMode(DiagramScene::InsertTask);
}

void MainWindow::fictivetaskButtonClicked()
{
    setCheckedButton(ui->fictivetaskButton);
    scene->setMode(DiagramScene::InsertFictiveTask);
}

void MainWindow::sceneScaleChanged(int scale)
{
    double newScale = scale / 100.0;
    QMatrix oldMatrix = ui->graphicsView->matrix();
    ui->graphicsView->resetMatrix();
    ui->graphicsView->translate(oldMatrix.dx(), oldMatrix.dy());
    ui->graphicsView->scale(newScale, newScale);
}

void MainWindow::sceneChanged()
{
    this->setWindowModified(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (this->okToContinue())
        event->accept();
    else
        event->ignore();
}

void MainWindow::setCheckedButton(QToolButton *button)
{
    ui->cycleButton->setChecked(false);
    ui->taskButton->setChecked(false);
    ui->fictivetaskButton->setChecked(false);
    ui->pointerButton->setChecked(false);
    button->setChecked(true);
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    this->setWindowModified(false);
    QString shownName = "Untitled";
    if (!curFile.isEmpty())
        shownName = QFileInfo(fileName).fileName();

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Graph Editor")));
}

bool MainWindow::okToContinue()
{
    if (this->isWindowModified())
    {
        int r = QMessageBox::warning(this, tr("Warning"),
                                     tr("The graph has been modified.\n"
                                        "Do you want to save your changes?"),
                                     QMessageBox::Yes | QMessageBox::Default,
                                     QMessageBox::No,
                                     QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::Yes)
            return this->saveButtonClicked();
        else if (r == QMessageBox::Cancel)
            return false;
    }
    return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    XMLProvider *read = new XMLProvider(scene, fileName);
    if (!read->readXML()){
        QMessageBox::warning(this, tr("Warning"),
                             tr("Cannot reading file."),
                             QMessageBox::Ok);
        return false;
    }

    this->setCurrentFile(fileName);
    QMessageBox::information(this, tr("Information"),
                             tr("File Loaded"));
    return true;
}

bool MainWindow::saveFile(const QString &fileName)
{
    XMLProvider *write = new XMLProvider(scene, fileName);
    if (!write->writeXML()){
        QMessageBox::warning(this, tr("Warning"),
                             tr("Cannot writing file."),
                             QMessageBox::Ok);
        return false;
    }

    this->setCurrentFile(fileName);
    QMessageBox::information(this, tr("Information"),
                             tr("File Saved"));
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save graph"), curPath,
                                                    tr("Graph xml (*.xml)"));
    fileName = fileName + ".xml";

    if (fileName.isEmpty()) return false;

    QFile file(fileName);
    if (file.exists()){
        int r = QMessageBox::warning(this, tr("Warning"),
                                     tr("File %1 exist.\n"
                                        "Do you want to replace that file?").arg(file.fileName()),
                                     QMessageBox::Yes | QMessageBox::Default,
                                     QMessageBox::No,
                                     QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::No)
            return false;
        else if (r == QMessageBox::Cancel)
            return false;
    }
    return saveFile(fileName);
}
