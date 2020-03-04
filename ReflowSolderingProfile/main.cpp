#include "reflowsolderingprofile.h"
#include <QtWidgets/QApplication>
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ReflowSolderingProfile w;
	
	w.AddImage(w.GetImageDir().append("/B.jpg"));
	w.AddImage(w.GetImageDir().append("/T.jpg"));
	w.AddImage(w.GetImageDir().append("/P.jpg"));
	w.StartPlay();
	w.move((QApplication::desktop()->width() - w.width()),0); //窗口移动到屏幕右上角
	//w.move((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2); //窗口移动到屏幕中间
	w.setWindowTitle(QStringLiteral("炉温曲线"));
	
	w.show();
	return a.exec();
}
