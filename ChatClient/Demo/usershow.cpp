#include "usershow.h"
#include "ui_usershow.h"

UserShow::UserShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserShow),m_id(0)
{
    ui->setupUi(this);
    m_defaultImg.load(":/tx/26.png");
    connect(&m_timer,SIGNAL(timeout()),
            this,SLOT(slot_checkTimeOut()));
    //开启定时器
    m_timer.start(1000);
    slot_setImage(m_defaultImg);
}

UserShow::~UserShow()
{
    delete ui;
}

void UserShow::slot_setInfo(int id, QString name)
{
    m_id=id;
    m_name=name;
    ui->lb_name->setText(QString("用户[%1]").arg(m_name));
}

void UserShow::slot_setImage(QImage &img)
{
    m_lastTime=QTime::currentTime();
    m_img=img;
    //update();//会触发绘图事件
    repaint();
}
#include<QPainter>
void UserShow::paintEvent(QPaintEvent *event)
{
    //画背景
    QPainter painter(this);//把要在哪个控件上画给他
    painter.setBrush(Qt::black);//设置黑色画刷
    //画一个矩形,会按照画刷填充
    painter.drawRect(-1,0,this->width()+1,this->height());

    //画图（人物、桌面）
    //画图片
    if( m_img.size().height()<= 0 ) return;
    // 加载图片用 QImage , 画图使用 QPixmap
    // 图片缩放 scaled
    QPixmap pixmap = QPixmap::fromImage( m_img.scaled( QSize( this->width() ,
    this->height() - ui->lb_name->height()), Qt::KeepAspectRatio ));
    //画的位置
    int x = this->width() - pixmap.width();
    int y = this->height() - pixmap.height() - ui->lb_name->height();
    x = x /2;
    y = ui->lb_name->height() + y/2;
    painter.drawPixmap( QPoint(x,y) , pixmap );
    painter.end();

    //event->accept();

}

void UserShow::mousePressEvent(QMouseEvent *event)
{
    //点击右侧的控件，就给左侧的大图控件发一个信号
    Q_EMIT SIG_userClicked(m_id,m_name);

}

void UserShow::slot_checkTimeOut()
{

    if(m_lastTime.secsTo(QTime::currentTime())>5){
        slot_setImage(m_defaultImg);
    }

}
