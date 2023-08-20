#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private slots:
    void on_action_bold_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

private:
    Ui::QWMainWind *ui;
private:
    QLabel *currentFileLabel; // 底部状态栏显示当前文件label
    QProgressBar *progressBar; // 状态栏进度条
    QSpinBox *spinBox; // 字体大小选择框
    QFontComboBox *comboFont; // 字体名称comboBox
    void initUI(); // UI初始化，部分必须用代码实现的
private slots:
    // 自定义槽函数
    // 改变字体大小
    void on_spinBoxFontSize_valueChanged(int fontSize);
    // 选择字体
    void on_comboFont_currentIndexChanged(const QString &argl);
};

#endif // QWMAINWIND_H
