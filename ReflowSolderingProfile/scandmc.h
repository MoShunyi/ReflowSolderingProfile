#ifndef SCANDMC_H
#define SCANDMC_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include "ui_scandmc.h"

//namespace Ui {class ScanDMC;}

class ScanDMC : public QDialog
{
	Q_OBJECT

public:
	explicit ScanDMC(QWidget *parent = 0);
	~ScanDMC();

signals:
	void SendString(QString typeNo);

public slots:
	void CheckInputTypeNo();
	void OnButtonBoxSendClicked(QAbstractButton *button);

private:
	Ui::ScanDMC *scanUi;
};

#endif // SCANDMC_H
