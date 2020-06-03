#include "scandmc.h"

ScanDMC::ScanDMC(QWidget *parent)
	: QDialog(parent)
{
	scanUi = new Ui::ScanDMC();
	scanUi->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose); //设置窗口在关闭时销毁
	scanUi->lineEditDMC->setFocus();
	scanUi->buttonBoxSend->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定")); //将buttonbox中的ok汉化
	scanUi->buttonBoxSend->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("取消"));
	qDebug()<<"new instant";
	connect(scanUi->lineEditDMC,&QLineEdit::editingFinished,this,&ScanDMC::CheckInputTypeNo);
	connect(scanUi->buttonBoxSend,static_cast<void (QDialogButtonBox::*)(QAbstractButton *)>(&QDialogButtonBox::clicked),this,&ScanDMC::OnButtonBoxSendClicked);
}

ScanDMC::~ScanDMC()
{
	delete scanUi;
}

void ScanDMC::CheckInputTypeNo()
{
	if (scanUi->lineEditDMC->text().length() == 10 || scanUi->lineEditDMC->text().length() == 23)
	{
		scanUi->lineEditDMC->setStyleSheet("background-color:rgb(0,255,0)");
	}else
	{
		scanUi->lineEditDMC->setStyleSheet("background-color:rgb(255,0,0)");
	}
}

void ScanDMC::OnButtonBoxSendClicked(QAbstractButton *button)
{
	if (button ==scanUi->buttonBoxSend->button(QDialogButtonBox::Cancel))
	{
		this->close();
		//this->destroy(true);
		return;
	}
	if (button ==scanUi->buttonBoxSend->button(QDialogButtonBox::Ok))
	{
		if (!(scanUi->lineEditDMC->text().length() == 10 || scanUi->lineEditDMC->text().length() == 23))
		{
			QMessageBox *mb = new QMessageBox(this);
			mb->setIcon(QMessageBox::Warning);
			mb->setText(QStringLiteral("<font size = 6>请输入正确的产品型号！</font>"));
			mb->exec();
			return;
		}
		
		QString typeNo;
		if (scanUi->lineEditDMC->text().length() == 10)
		{
			typeNo = scanUi->lineEditDMC->text();
		}
		if (scanUi->lineEditDMC->text().length() == 23)
		{
			typeNo = scanUi->lineEditDMC->text().mid(2,10);
		}

		qDebug()<<typeNo;
		this->close();
		emit SendString(typeNo);
		
	}
}