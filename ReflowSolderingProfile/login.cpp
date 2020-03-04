#include "login.h"

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	uiLog = new Ui::Login();
	uiLog->setupUi(this);

	settings = new QSettings("config.ini",QSettings::IniFormat);
	loginName = settings->value("/LoginManager/username").toString();
	loginPassword = settings->value("/LoginManager/password").toString();
	uiLog->lineEditUsername->setText(loginName);
	uiLog->lineEditPassword->setFocus();

	//连接信号和槽
	connect(uiLog->buttonBoxLogin,static_cast<void (QDialogButtonBox::*)(QAbstractButton *)>(&QDialogButtonBox::clicked),this,&Login::OnButtonBoxLoginClicked);
}

Login::~Login()
{
	delete uiLog;
}

void Login::OnButtonBoxLoginClicked(QAbstractButton *button)
{
	QString strUsername = uiLog->lineEditUsername->text().trimmed();
	QString strPassword = uiLog->lineEditPassword->text().trimmed();
	if (button == uiLog->buttonBoxLogin->button(QDialogButtonBox::Reset))
	{
		uiLog->lineEditUsername->setText("");
		uiLog->lineEditPassword->setText("");
	}else
		if (strUsername.isEmpty() || strPassword.isEmpty())
		{
			QMessageBox mb;
			mb.setIcon(QMessageBox::Warning);
			mb.setText(QString(QStringLiteral("用户名或密码为空，请重新输入")));
			mb.exec();

		} 
		else
		{
			if (strUsername == loginName && strPassword == loginPassword)
			{
				accept();
			}
			else 
			{
				QMessageBox::warning(this,QStringLiteral("警告！"),QStringLiteral("用户名或者密码错误"),QMessageBox::Yes);
			}
		}

}
