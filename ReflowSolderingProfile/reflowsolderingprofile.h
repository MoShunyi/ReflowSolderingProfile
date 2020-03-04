#ifndef REFLOWSOLDERINGPROFILE_H
#define REFLOWSOLDERINGPROFILE_H

#include <QtWidgets/QMainWindow>
#include <QScrollArea>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QSettings>
#include <QDesktopServices>
#include "login.h"
#include "ui_reflowsolderingprofile.h"

class ReflowSolderingProfile : public QMainWindow
{
	Q_OBJECT

public:
	ReflowSolderingProfile(QWidget *parent = 0);
	~ReflowSolderingProfile();

	//读取配置文件
	void ReadSettings();

	//设置图片列表
	void SetImageList(QStringList imageFileNameList);
	//添加图片
	void AddImage(QString imageFileName);
	//开始播放
	void StartPlay();
	//获取图片路径
	QString GetImageDir();

//槽函数
public slots:
	//登录注销按钮点击
	void OnActionLoginClicked();
	void OnActionLogoutClicked();
	//明细按钮点击
	void OnActionFolderClicked();

	//图片切换时钟
	void OnImageChangeTimeout();
	//图片切换按钮点击
	void OnImageSwitchButtonClicked(int buttonId);

private:
	//初始化图片切换按钮
	void InitChangeImageButton();
	//重写绘图事件
	void paintEvent(QPaintEvent *event);

	//重写鼠标点击事件
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	Ui::ReflowSolderingProfileClass ui;
	Login *log;
	QPoint startPoint;

	QSettings *settings;
	QString imageDir;

	//窗口尺寸
	int widgetWidth;
	int widgetHigth;

	//图片切换间隔
	int interval;
	//用来做图片切换滑动效果，目前以透明度作为切换效果
	QScrollArea *imagePlayWidget;
	//图片列表
	QList<QString> imageFileNameList;

	//图片切换时钟
	QTimer imageChangeTimer;
	//当前显示图片index
	int currentDrawImageIndex;

	//切换图片
	QPixmap currentPixmap;
	QPixmap nextPixmap;
	//图片切换动画类
	QPropertyAnimation *opacityAnimation;
	//按钮列表
	QList<QPushButton*> pushButtonChangeImageList;
};

#endif // REFLOWSOLDERINGPROFILE_H
