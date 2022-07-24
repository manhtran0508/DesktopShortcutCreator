#ifndef DESKTOPSHORTCUTCREATOR_H
#define DESKTOPSHORTCUTCREATOR_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class DesktopShortcutCreator; }
QT_END_NAMESPACE

class DesktopShortcutCreator : public QWidget
{
    Q_OBJECT

public:
    DesktopShortcutCreator(QWidget *parent = nullptr);
    ~DesktopShortcutCreator();

private slots:

    void on_m_selectExecButton_clicked();

    void on_m_selectIconButton_clicked();

    void on_m_quitButton_clicked();

    void on_m_createButton_clicked();

private:
    Ui::DesktopShortcutCreator *ui;
};
#endif // DESKTOPSHORTCUTCREATOR_H
