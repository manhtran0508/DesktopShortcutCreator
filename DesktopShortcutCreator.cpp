#include "DesktopShortcutCreator.h"
#include "ui_DesktopShortcutCreator.h"

DesktopShortcutCreator::DesktopShortcutCreator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DesktopShortcutCreator)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Images/AppIcon.png"));
}

DesktopShortcutCreator::~DesktopShortcutCreator()
{
    delete ui;
}

void DesktopShortcutCreator::on_m_selectExecButton_clicked()
{
    ui->m_execPath->setText(QFileDialog::getOpenFileName(this, "Select file"));
}


void DesktopShortcutCreator::on_m_selectIconButton_clicked()
{
    ui->m_iconPath->setText(QFileDialog::getOpenFileName(this, "Select icon", QString(), "Image file (*.png *.ico *.svg);; All files (*.*)"));
}


void DesktopShortcutCreator::on_m_quitButton_clicked()
{
    qApp->quit();
}


void DesktopShortcutCreator::on_m_createButton_clicked()
{
    if (ui->m_execPath->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "You have to choose app will be linked with shortcut!");
        return;
    }

    if (ui->m_nameDisplay->text().isEmpty()) {
        QMessageBox::StandardButton button = QMessageBox::question(this, "Warning", "The shortcut will not have a display name! Are you sure to continue?");

        if (button == QMessageBox::No) {
            return;
        }
    }

    QString content = "# Created by Desktop Shortcut Creator at " + QDateTime::currentDateTime().toString() + "\n";
    content += "# Tool can be found at: https://github.com/manhtran0508/DesktopShortcutCreator\n\n";
    content += "[Desktop Entry]\n";
    content += "Name=" + ui->m_nameDisplay->text() + "\n";
    content += "Comment=" + ui->m_comment->text() + "\n";
    content += "Exec=" + ui->m_execPath->text() + "\n";
    content += "Icon=" + ui->m_iconPath->text() + "\n";
    content += "Terminal=" + (ui->m_terminalOn->isChecked() ? QString("true") : QString("false")) + "\n";
    content += "Type=Application\n";
    content += "StartupNotify=" + (ui->m_startupNotify->isChecked() ? QString("true") : QString("false"));

    QFile file(QDir::homePath() + "/Desktop/" + ui->m_nameDisplay->text().toLower().replace(" ", "_") + ".desktop");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Can't write file in Desktop!\nRun this program with root may fix it!");
        return;
    }

    QTextStream out(&file);
    out << content;

    file.close();

    QMessageBox::information(this, "Result", "The shortcut is created!\nTo keep you safe, Linux doesn't allow launching program by shortcut. To use the shortcut, you have to right click on this then select \"Allow Launching\"");
}

