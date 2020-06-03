#include "reflowsolderingprofile.h"

ReflowSolderingProfile::ReflowSolderingProfile(QWidget *parent)
	: QMainWindow(parent)
	,currentDrawImageIndex(0)
{
	ui.setupUi(this);
	ReadSettings();
	//log = nullptr;
	//scanDMC = nullptr;

	//添加ImageOpacity属性;
	this->setProperty("ImageOpacity", 1.0);
	
	//动画切换类;
	opacityAnimation = new QPropertyAnimation(this, "ImageOpacity");
	//这里要设置的动画时间小于图片切换时间;
	opacityAnimation->setDuration(1000);

	//设置ImageOpacity属性值的变化范围;
	opacityAnimation->setStartValue(1.0);
	opacityAnimation->setEndValue(0.0);
	//透明度变化及时更新绘图;
	connect(opacityAnimation, SIGNAL(valueChanged(const QVariant&)), this, SLOT(update()));
	//设置图片切换时钟槽函数;
	connect(&imageChangeTimer, &QTimer::timeout, this, &ReflowSolderingProfile::OnImageChangeTimeout);

	//点击登录注销菜单
	connect(ui.actionLogin,&QAction::triggered,this,&ReflowSolderingProfile::OnActionLoginClicked);
	connect(ui.actionLogout,&QAction::triggered,this,&ReflowSolderingProfile::OnActionLogoutClicked);

	//点击明细菜单
	connect(ui.actionFolder,&QAction::triggered,this,&ReflowSolderingProfile::OnActionFolderClicked);
	connect(ui.actionGrabScreen,&QAction::triggered,this,&ReflowSolderingProfile::OnActionGrabScreenClicked);
	this->setFixedSize(QSize(widgetWidth, widgetHigth));

	this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint); //设置窗口为最前端显示以及隐藏窗口边框
	ui.menuBar->setVisible(false); //隐藏菜单栏
}

ReflowSolderingProfile::~ReflowSolderingProfile()
{

}

void ReflowSolderingProfile::ReadSettings()
{
	settings = new QSettings("config.ini",QSettings::IniFormat);
	widgetWidth = settings->value("/Window/width").toInt();
	widgetHigth = settings->value("/Window/higth").toInt();
	imageDir = settings->value("/Dir/imageDir").toString();
	screenDir = settings->value("/Dir/screenDir").toString();
	interval = settings->value("/Interval/interval").toInt();
}
void ReflowSolderingProfile::SetImageList(QStringList imageFileNameList)
{
	this->imageFileNameList = imageFileNameList;
}

void ReflowSolderingProfile::AddImage(QString imageFileName)
{
	imageFileNameList.append(imageFileName);
}

void ReflowSolderingProfile::StartPlay()
{
	//添加完图片之后，根据图片多少设置图片切换按钮
	InitChangeImageButton();
	if (imageFileNameList.count() == 1)
	{
		pushButtonChangeImageList[currentDrawImageIndex]->setChecked(true);
	}
	else if (imageFileNameList.count() > 1)
	{
		pushButtonChangeImageList[currentDrawImageIndex]->setChecked(true);
		currentPixmap = QPixmap(imageFileNameList.at(currentDrawImageIndex));
		imageChangeTimer.start(interval * 1000);
		update();
	}   
}

QString ReflowSolderingProfile::GetImageDir()
{
	return this->imageDir;
}
void ReflowSolderingProfile::OnActionLoginClicked()
{
	log = new Login(this);
	log->setModal(true);
	log->show();
	if (log->exec() == QDialog::Accepted)
	{
		this->setWindowFlags(Qt::Window); //恢复窗口边框
		this->show();
	}
}

void ReflowSolderingProfile::OnActionLogoutClicked()
{
	this->setWindowFlags(Qt::FramelessWindowHint); //隐藏窗口边框
	this->show();
}

void ReflowSolderingProfile::OnActionFolderClicked()
{
	QDesktopServices::openUrl(QUrl(imageDir));
}

void ReflowSolderingProfile::OnActionGrabScreenClicked()
{
	scanDMC = new ScanDMC(this);
	//connect(scanDMC,&ScanDMC::SendString,[=](QString typeNo){typeNumber = typeNo;});
	connect(scanDMC,&ScanDMC::SendString,this,&ReflowSolderingProfile::ReceiveTypeNo);
	scanDMC->setModal(true);
	scanDMC->show();

}

void ReflowSolderingProfile::ReceiveTypeNo(QString typeNo)
{
	typeNumber = typeNo;
	QScreen *screen = QGuiApplication::primaryScreen();
	QString filePathName = screenDir.append("/%1").arg(typeNumber);
	QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");
	filePathName.append(QString(" %1.jpg").arg(currentTime));
	if(!screen->grabWindow(0).save(filePathName, "jpg"))
	{
		QMessageBox *mb = new QMessageBox(this);
		mb->setIcon(QMessageBox::Critical);
		mb->setText(QStringLiteral("<font size = 6>保存截图失败</font>"));
		mb->exec();
	}else
	{
		QMessageBox *mb = new QMessageBox(this);
		mb->setIcon(QMessageBox::Information);
		mb->setText(QStringLiteral("<font size = 6>保存截图成功</font>"));
		mb->exec();
	}
}

void ReflowSolderingProfile::OnImageChangeTimeout()
{
	//设置前后的图片
	currentPixmap = QPixmap(imageFileNameList.at(currentDrawImageIndex));
	currentDrawImageIndex++;
	if (currentDrawImageIndex >= imageFileNameList.count())
	{
		currentDrawImageIndex = 0;
	}
	nextPixmap = QPixmap(imageFileNameList.at(currentDrawImageIndex));

	pushButtonChangeImageList[currentDrawImageIndex]->setChecked(true);

	ui.menuBar->setVisible(false); //隐藏菜单栏
	//动画类重新开始
	opacityAnimation->start();
}

void ReflowSolderingProfile::OnImageSwitchButtonClicked(int buttonId)
{
	currentDrawImageIndex = buttonId - 1;
	if (currentDrawImageIndex == -1)
	{
		currentDrawImageIndex = imageFileNameList.count() - 1;
	}

	OnImageChangeTimeout();
	imageChangeTimer.start(interval * 1000);
	update();
}

void ReflowSolderingProfile::InitChangeImageButton()
{
	//注意图片过多按钮可能放置不下;
	QButtonGroup *changeButtonGroup = new QButtonGroup;
	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addStretch();
	for (int i = 0; i < imageFileNameList.count(); i++)
	{
		QPushButton *pButton = new QPushButton;
		pButton->setFixedSize(QSize(16, 16));
		pButton->setCheckable(true);
		//pButton->setStyleSheet("QPushButton{border-image:url(:/Resources/select1.png);}\
		//QPushButton:checked{border-image:url(:/Resources/select2.png);}");
		changeButtonGroup->addButton(pButton, i);
		pushButtonChangeImageList.append(pButton);
		hLayout->addWidget(pButton);
	}
	hLayout->addStretch();
	hLayout->setSpacing(10);
	hLayout->setMargin(0);

	//connect(changeButtonGroup, SIGNAL(buttonClicked(int))c, this, SLOT(OnImageSwitchButtonClicked(int)));
	connect(changeButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &ReflowSolderingProfile::OnImageSwitchButtonClicked);

	QVBoxLayout *mainLayout = new QVBoxLayout(ui.imageWidget);
	mainLayout->addStretch();
	mainLayout->addLayout(hLayout);
	mainLayout->setContentsMargins(0, 0, 0, 20);
}

void ReflowSolderingProfile::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect imageRect = this->rect();
	painter.fillRect(this->rect(), QColor(0, 0, 0, 0x20)); //设置透明颜色

	//如果图片列表为空，显示默认图片;
	if (imageFileNameList.isEmpty())
	{
		QPixmap backPixmap = QPixmap(":/ReflowSolderingProfile/Resources/Login.JPG");
		painter.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
	}
	//如果只有一张图片;
	else if (imageFileNameList.count() == 1)
	{
		QPixmap backPixmap = QPixmap(imageFileNameList.first());
		painter.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
	}
	//多张图片;
	else if (imageFileNameList.count() > 1)
	{
		float imageOpacity = this->property("ImageOpacity").toFloat();
		painter.setOpacity(1);
		painter.drawPixmap(imageRect, nextPixmap.scaled(imageRect.size()));
		painter.setOpacity(imageOpacity);
		painter.drawPixmap(imageRect, currentPixmap.scaled(imageRect.size()));
	}
}

void ReflowSolderingProfile::mousePressEvent(QMouseEvent *event)
{
	//这里可以对当前图片进行点击然后触发每个图片对应的效果;
	//比如web上好多类似的弹出对应的广告页面等功能;
	qDebug() << currentDrawImageIndex;
	if (event->button() == Qt::LeftButton) 
	{
		startPoint = frameGeometry().topLeft() - event->globalPos(); //捕获按下时坐标
		
	}
	ui.menuBar->setVisible(true); //显示菜单栏
	return __super::mousePressEvent(event);
}

void ReflowSolderingProfile::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() + startPoint);
}