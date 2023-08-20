#include "qwmainwind.h"
#include "ui_qwmainwind.h"

#include <QTextCharFormat>


// 部分UI初始化
void QWMainWind::initUI()
{
    // 状态栏上添加组件
    currentFileLabel = new QLabel();
    currentFileLabel->setMinimumWidth(400);
    currentFileLabel->setText("当前文件: ");
    ui->statusBar->addWidget(currentFileLabel);

    // 进度条
    progressBar = new QProgressBar();
    progressBar->setMaximumWidth(150);
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->txtEdit->font().pointSize());
    ui->statusBar->addWidget(progressBar);

    // 工具栏上添加组件

    ui->mainToolBar->addSeparator(); // 分隔条
    spinBox = new QSpinBox();
    spinBox->setMinimum(5);
    spinBox->setMaximum(50);
    spinBox->setValue(ui->txtEdit->font().pointSize());
    spinBox->setMinimumWidth(100);

    ui->mainToolBar->addWidget(new QLabel("字体大小"));
    ui->mainToolBar->addWidget(spinBox);

    ui->mainToolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox();
    comboFont->setMinimumWidth(100);
    comboFont->setMaximumWidth(100);
    ui->mainToolBar->addWidget(comboFont); // 添加到工具栏

    setCentralWidget(ui->txtEdit);
}


QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    initUI();
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

// 粗体
void QWMainWind::on_action_bold_triggered(bool checked)
{
    QTextCharFormat fmt = ui->txtEdit->currentCharFormat();
    if(checked) {
        fmt.setFontWeight(QFont::Bold);
    } else {
        fmt.setFontWeight(QFont::Normal);
    }
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

// 在有内容被复制时出发
void QWMainWind::on_txtEdit_copyAvailable(bool b)
{
    // 更新cut, copy, paste的enabled属性
    ui->action_cut->setEnabled(b);
    ui->action_copy->setEnabled(b);
    ui->action_paste->setEnabled(ui->txtEdit->canPaste());

}

void QWMainWind::on_txtEdit_selectionChanged()
{
    // 更新粗体、斜体和下划线3种action的checked属性
    QTextCharFormat fmt = ui->txtEdit->currentCharFormat();
    ui->action_italic->setChecked(fmt.fontItalic());
    ui->action_bold->setChecked(fmt.font().bold());
    ui->action_underline->setChecked(fmt.fontUnderline());
}
