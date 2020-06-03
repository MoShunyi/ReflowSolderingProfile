#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QPushButton>
#include "ui_login.h"

//namespace Ui {class Login;};

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	~Login();

	void OnButtonBoxLoginClicked(QAbstractButton *button);

private:
	Ui::Login *uiLog;

	QSettings *settings;

	QString loginName;
	QString loginPassword;
};

#endif // LOGIN_H
