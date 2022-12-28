#pragma execution_character_set("utf-8")

#include "UIBasePlatformFrame.h"
#include "ui_UIBasePlatformFrame.h"
#include "iconhelper.h"
#include <QDateTime>


UIBasePlatformFrame::UIBasePlatformFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIBasePlatformFrame),
    m_ptrrtSql(nullptr),
    m_ptrSonSql(nullptr),
    m_prtCreSql(nullptr)
{
    ui->setupUi(this);
    //跑马灯start
    timer = new QTimer();
    this->width = ui->label->size().width();
    this->hight=ui->label->size().height();
    ui->label->clear();
    ui->label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    text="欢迎使用接收处置综合服务保障信息采集系统";
    text_width=fontMetrics().width(text);
    d_text_width=0;
    d_index=0;
    space_count=0;

    //方式一 通过定时器 定时修改显示文本
    connect(timer,SIGNAL(timeout()),this,SLOT(display_text()));
    timer->start(800);
    //跑马灯end

    this->initForm();
    this->initLeftMain();
    this->initLeftConfig();
    this->initLeft1();
    this->initPage4();
    this->initPage5();
    this->Time();
    resize(1720, 950);
    setWindowIcon(QIcon(":/image/logo.png"));
    QFile fread;
    fread.setFileName(":/qss/psblack.css");
    fread.open(QIODevice::ReadOnly);
    QString strQss=fread.readAll();
    this->setStyleSheet(strQss);
    fread.close();
    m_ptrrtSql=rtSql::getinstance();
    m_ptrrtSql->init();
    m_ptrSonSql=sonSql::getinstance();
    m_ptrSonSql->init();
    m_prtCreSql=CreditSql::getinstance();
    m_prtCreSql->init();
    m_lNames<<"隗聪洛"<<"令访梅"<<"启沛柔"<<"闾韵菲"<<"笪怀梦"<<"二初之"<<"仵云烟"<<"鄂绿柳"<<"令雁竹"<<"光山云"
            <<"谯涵"<<"荷希辰"<<"希言"<<"可馨鄂"<<"初筠遥"<<"紫筠"<<"盘曼梦"<<"有从"<<"萍光振"<<"国贝乐"<<"安盘浔"
          <<"剑蓟冷"<<"旋盖如"<<"凡谯元"<<"瑶之"<<"语达奚"<<"傲夏"<<"邓映"<<"珍桓灵"<<"兰袁允"<<"颜璎珞"<<"谌靖琪"
         <<"华问薇"<<"养静丝"<<"兔昊天"<<"厉怀薇"<<"勾云鸣"<<"卞春竹"<<"雅奇月"<<"苗紫霜"<<"师宁"<<"曦查平"<<"柳柱"
        <<"冬莲潭"<<"墨辰雅"<<"令仪"<<"合诗菲"<<"养新"<<"霜万醉"<<"柔养向"<<"南孛幼"<<"枫常青"<<"芙黎少"<<"轩太叔"
       <<"伯谌"<<"丹烟单"<<"书琴"<<"查修"<<"明苗海"<<"诺闲承"<<"辞承宣"<<"戴深子"<<"清明修"<<"清容爵"<<"缑德逸"
      <<"南门睿"<<"诚严墨"<<"然太泽"<<"宇公坚"<<"灼光完"<<"慕寒"<<"牟浩壤"<<"台兴"<<"发牟同"<<"光百思"<<"智南"
     <<"门辰扬"<<"戴锦"<<"宇皮景"<<"瑜测光"<<"明晏德"<<"昌陕彬"<<"庆杂弘"<<"白少轩"<<"白振"<<"学清尚"<<"江仲"
    <<"修真"<<"賴英虑"<<"暴凯风"<<"弦房辰"<<"铭笪"<<"秋瑶"<<"测正青令"<<"书文测"<<"冠贤璎"<<"元瑶"<<"桓白"<<"凝越宛"
    <<"云仵"<<"诗珊"<<"孝水蕊"<<"越访曼"<<"荣曼"<<"青焱"<<"安兰有"<<"又旋瑶"<<"嘉铭"<<"志养又"<<"萱师"<<"笑卉"
    <<"颜冷荷颜"<<"恨琴雅"<<"静安费"<<"灵蕊"<<"颜若"<<"琳费祁"<<"煊骆"<<"碧巧"<<"卞斯民"<<"陕涵采"<<"闲妙"<<"蕊潭"
    <<"冬萱晏"<<"沛海姚"<<"英武"<<"台国源"<<"曳旭"<<"木仲"<<"鸿朗施黎"<<"枫牟英"<<"逸杂文"<<"石仲"<<"玉羽"<<"东方运"
    <<"杰南"<<"宫启"<<"明缑雅"<<"枫皮亦"<<"翌皮"<<"鹤轩"<<"面杰玮"<<"印起伯"<<"晚明"<<"桂紫"<<"茵桓"<<"春蕾"
    <<"谯修贤"<<"鄂冥华"<<"武慕玉"<<"房碧凡"<<"易之薇"<<"令雨安"<<"遥千"<<"凡二"<<"傲萱孝"<<"安瑶"<<"测恨珍"
    <<"易振凯"<<"巫马平文"<<"渠景明"<<"盖灼光"<<"隗思"<<"霆清"<<"容爵巫"<<"马秋莉"<<"易静卉"<<"武水莲"<<"景醉梅"
    <<"隗翠夏"<<"阙忆曼"<<"仵晓丝"<<"阙彬"<<"郁隗怀"<<"绿袁梦"<<"蕾花修"<<"真微生"<<"雪柔测"<<"嘉微盘"<<"幼青苟"
    <<"博延荣"<<"凌凡希"<<"向菱测"<<"思辰景"<<"半槐房"<<"蒹葭焱"<<"奇月"<<"袁修尧"<<"希雁"<<"柳易问"<<"孟初"<<"柳娜"
    <<"芸灀"<<"罗冰绿"<<"黎韵洁"<<"繁绮烟"<<"苗元勋"<<"许念汐"<<"卞香凝"<<"孟飞"<<"菱苗"<<"横波韦"<<"耘志"<<"潭翠柏"
    <<"昊天云"<<"潭迎梅罗"<<"凌玉单"<<"怜雁潭"<<"易蝶"<<"颜霄"<<"翎卞泽"<<"语解楚"<<"薰沐兴"<<"为陕紫"<<"夏闲盼"
    <<"玉闲史"<<"宇罗睿"<<"德师小"<<"蕊师"<<"凌文芥"<<"以松孛"<<"新丹谌"<<"怜岚妳"<<"珏麟单"<<"又珊沐"<<"雅枫万"
    <<"书容闲"<<"妙蓝单"<<"飞柏影"<<"慕山昊"<<"修博飞"<<"之卉静"<<"巧之"<<"黎春南"<<"合辰"<<"岩黎泰"<<"诚太"<<"史寒"
    <<"寻黑"<<"玉坤陕"<<"言宇贡"<<"无麟缑"<<"和昶缑"<<"乐生陕"<<"皓君瑶"<<"昆颉"<<"晏承"<<"辰宁茂"<<"学夜"<<"元魁晏"
    <<"咏志宿"<<"展阳战司"<<"羽黑鸿"<<"信公仲"<<"温韦"<<"夜博"<<"瀚賴尧"<<"宸戴尧"<<"墨晚承"<<"澈施少"<<"言太史"
    <<"翊枫咸"<<"春竹扶"<<"中震辞"<<"哲深"<<"缑伟懋"<<"白天萧"<<"完玉宇"<<"牟泽语"<<"佩华晖"<<"面希文"<<"战云鸣"
    <<"台学中"<<"白鸿才"<<"完康适"<<"南门瑞"<<"渊滕伟"<<"才戴金"<<"鑫陶"<<"绍钧夜"<<"元纬"<<"面令飒"<<"萱苟惜"
    <<"芹测访冬"<<"清玥昕"<<"隗暮晨"<<"巫马"<<"芷天渠"<<"凌双"<<"袁凌菡"<<"鄂隐吟"<<"启墨深"<<"鄂德明"<<"鄂涵柔";

    updateTable();
    UpdateTable();
    init_tableWidget_4();

}

UIBasePlatformFrame::~UIBasePlatformFrame()
{
    delete ui;
}
void UIBasePlatformFrame::initResize()
{

}
void UIBasePlatformFrame::Time()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UIBasePlatformFrame::showTime);
    timer->start(1000);
    showTime();
}
void UIBasePlatformFrame::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("HH:mm:ss");
    ui->lcdTime->setDigitCount(8);
    ui->lcdTime->setSegmentStyle(QLCDNumber::Flat);
//    ui->lcdTime->setStyleSheet("QLCDNumber{color: #00c3a4;border:None}");
    ui->lcdTime->display(text);
}

/**
 * 跑马灯
 * @brief UIBasePlatformFrame::scrollCation
 */
void UIBasePlatformFrame::display_text(){
    if(d_text_width-text_width > this->width){//当文本像素宽度大于label的宽度时，则重新初始化
        ui->label->clear();
        d_text.clear();
        d_index=0;
        d_text_width=0;
    }

    if(space_count>=30){//当填充的空格大于10个时，开始继续填充文本
        space_count=0;
        d_index=0;
    }

    if(d_index < text.length()){
        d_text+=text.at(d_index);
        d_index++;
    }
    else{
        d_text += " ";
        space_count++;
    }

    d_text_width=fontMetrics().width(d_text);

    //    qDebug()<<d_text_width<<" "<< text_width<<" "<<d_index<<" "<<d_text;
    ui->pmd_48->setText(d_text);
}
void UIBasePlatformFrame::initForm()
{   
    this->setProperty("form", true);

    this->setProperty("canMove", true);

//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

//    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));


    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");

    ui->labTitle->setText("中国融通资源开发集团有限公司");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 20));

    this->setWindowTitle(ui->labTitle->text());

    QSize icoSize(32, 32);
    int icoWidth = 85;


    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnMain->click();

    ui->widgetLeftMain->setProperty("flag", "left");

    ui->widgetLeftConfig->setProperty("flag", "left");

    ui->widgetLeft1->setProperty("flag", "left");

    ui->page1->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));
    ui->page2->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));
    ui->page3->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));

    ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);

    ui->stackedWidget_2->widget(4)->layout()->setContentsMargins(0,0,0,0);

    ui->select_sex->setCurrentIndex(-1);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setAlternatingRowColors(true);
    connect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,[=]()
    {
        on_btn_update_clicked();
    });



    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setAlternatingRowColors(true);

//    connect(ui->tableWidget_2,&QTableWidget::itemDoubleClicked,this,[=]()
//    {
//        on_pushButton_2_clicked();
//    });
    connect(ui->tableWidget_2,&QTableWidget::itemClicked,this,[=]()
    {
        showRightInfo();
    });


}

void UIBasePlatformFrame::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    if (name == "物资接收") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "现地处置") {
        ui->stackedWidget->setCurrentIndex(4);
    } else if (name == "物流运输") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "人员考勤") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "基础资源") {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (name == "用户退出") {
        exit(0);
    }
}
//基础资源树形结构的切换功能
void UIBasePlatformFrame::on_treeWidget_itemClicked(QTreeWidgetItem* item,int column)
{
    QString curItem_text=item->text(column);

    if(curItem_text=="简单模板")
    {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else if(curItem_text=="授权备案")
    {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(curItem_text=="人员准入")
        {
            ui->stackedWidget_2->setCurrentIndex(2);
        }
    else if(curItem_text=="办公申请")
        {
            ui->stackedWidget_2->setCurrentIndex(3);
        }
    else if(curItem_text=="Tab布局")
        {
            ui->stackedWidget_2->setCurrentIndex(4);
        }
    else if(curItem_text=="库房租赁")
        {
            ui->stackedWidget_2->setCurrentIndex(5);
        }
    else if(curItem_text=="运输费")
        {
            ui->stackedWidget_2->setCurrentIndex(6);
        }
    else if(curItem_text=="仓储费")
        {
            ui->stackedWidget_2->setCurrentIndex(7);
        }
    else if(curItem_text=="人工费")
        {
            ui->stackedWidget_2->setCurrentIndex(8);
        }
    else if(curItem_text=="数据交互")
        {
            ui->stackedWidget_2->setCurrentIndex(9);
        }
    else if(curItem_text=="用户管理")
        {
            ui->stackedWidget_2->setCurrentIndex(10);
        }
    else if(curItem_text=="角色管理")
        {
            ui->stackedWidget_2->setCurrentIndex(11);
        }
    else if(curItem_text=="权限管理")
        {
            ui->stackedWidget_2->setCurrentIndex(12);
        }
}

void UIBasePlatformFrame::initLeftMain()
{
    pixCharMain << 0xf030 << 0xf03e << 0xf247;
    btnsMain << ui->tbtnMain1 << ui->tbtnMain2 << ui->tbtnMain3;
    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        btnsMain.at(i)->setCheckable(true);
        btnsMain.at(i)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btnsMain.at(i), SIGNAL(clicked(bool)), this, SLOT(leftMainClick()));
    }
    /**
        ui->widgetLeftMain:左侧菜单
        btnsMain：菜单按钮
        pixCharMain：图标
        15：大小，35：iconWidth，25：iconHeight
        left:标识
        4：border
    **/
    IconHelper::Instance()->setStyle(ui->widgetLeftMain, btnsMain, pixCharMain, 15, 35, 25, "left", 4);

    ui->tbtnMain1->click();
}

void UIBasePlatformFrame::initLeftConfig()
{
    pixCharConfig << 0xf031 << 0xf036 << 0xf249 << 0xf055 << 0xf05a << 0xf249;
    btnsConfig << ui->tbtnConfig1 << ui->tbtnConfig2 << ui->tbtnConfig3 << ui->tbtnConfig4 << ui->tbtnConfig5 << ui->tbtnConfig6;

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(leftConfigClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftConfig, btnsConfig, pixCharConfig, 10, 20, 15, "left", 4);

    ui->tbtnConfig1->click();
}

void UIBasePlatformFrame::initLeft1()
{
    pixChar1 << 0xf055 << 0xf05a << 0xf249;
    btnsLeft1 << ui->tbtnConLeft1 << ui->tbtnConLeft2;

    int count = btnsLeft1.count();
    for (int i = 0; i < count; i++) {
        btnsLeft1.at(i)->setCheckable(true);
        btnsLeft1.at(i)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btnsLeft1.at(i), SIGNAL(clicked(bool)), this, SLOT(leftClick1()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeft1, btnsLeft1, pixChar1,15, 35, 25, "left", 4);

    ui->tbtnConLeft1->click();
}
/**
 * 初始化二级树形菜单
 * @brief UIBasePlatformFrame::initPage4
 */
void UIBasePlatformFrame::initPage4()
{
    ui->treeWidget->setHeaderLabel(tr("表格"));

    QTreeWidgetItem *tabList=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("人员综合管理")));
    QTreeWidgetItem *tabList1=new QTreeWidgetItem(tabList,QStringList(QString("授权备案")));
    QTreeWidgetItem *tabList2=new QTreeWidgetItem(tabList,QStringList(QString("人员准入")));
    QTreeWidgetItem *tabList3=new QTreeWidgetItem(tabList,QStringList(QString("办公申请")));
    tabList->addChild(tabList1);
    tabList->addChild(tabList2);
    tabList->addChild(tabList3);

    QTreeWidgetItem *tabhome=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("库房租赁")));

    QTreeWidgetItem *costsum=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("费用核算")));
    QTreeWidgetItem *costsum1=new QTreeWidgetItem(costsum,QStringList(QString("运输费")));
    QTreeWidgetItem *costsum2=new QTreeWidgetItem(costsum,QStringList(QString("仓储费")));
    QTreeWidgetItem *costsum3=new QTreeWidgetItem(costsum,QStringList(QString("人工费")));
    costsum->addChild(costsum1);
    costsum->addChild(costsum2);
    costsum->addChild(costsum3);

    QTreeWidgetItem *dataintel=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("数据交互")));

    QTreeWidgetItem *control=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("权限设定")));
    QTreeWidgetItem *control1=new QTreeWidgetItem(control,QStringList(QString("用户管理")));
    QTreeWidgetItem *control2=new QTreeWidgetItem(control,QStringList(QString("角色管理")));
    QTreeWidgetItem *control3=new QTreeWidgetItem(control,QStringList(QString("权限管理")));
    control->addChild(control1);
    control->addChild(control2);
    control->addChild(control3);

    QTreeWidgetItem *multiList=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("复杂表格")));
    QTreeWidgetItem *multiList1=new QTreeWidgetItem(multiList,QStringList(QString("Tab布局")));
    multiList->addChild(multiList1);
    QTreeWidgetItem *sampleList=new QTreeWidgetItem(ui->treeWidget,QStringList(QString("简单表格")));
    QTreeWidgetItem *sampleList1=new QTreeWidgetItem(sampleList,QStringList(QString("简单模板")));
    sampleList->addChild(sampleList1);
}

void UIBasePlatformFrame::initPage5()
{
    ui->treeWidget_2->setHeaderLabel(tr("表格1"));

    QTreeWidgetItem *tabList=new QTreeWidgetItem(ui->treeWidget_2,QStringList(QString("线上拍卖")));
    QTreeWidgetItem *tabList1=new QTreeWidgetItem(tabList,QStringList(QString("资产拍卖起稿")));
    QTreeWidgetItem *tabList2=new QTreeWidgetItem(tabList,QStringList(QString("价值评估")));
    QTreeWidgetItem *tabList3=new QTreeWidgetItem(tabList,QStringList(QString("估值确认")));
    QTreeWidgetItem *tabList4=new QTreeWidgetItem(tabList,QStringList(QString("拍卖资产申请")));
    QTreeWidgetItem *tabList5=new QTreeWidgetItem(tabList,QStringList(QString("线上交易登记")));
    QTreeWidgetItem *tabList6=new QTreeWidgetItem(tabList,QStringList(QString("退货申请")));
    QTreeWidgetItem *tabList7=new QTreeWidgetItem(tabList,QStringList(QString("退货审批")));
    QTreeWidgetItem *tabList8=new QTreeWidgetItem(tabList,QStringList(QString("合同签订")));
    QTreeWidgetItem *tabList9=new QTreeWidgetItem(tabList,QStringList(QString("费用到账")));
    tabList->addChild(tabList1);
    tabList->addChild(tabList2);
    tabList->addChild(tabList3);
    tabList->addChild(tabList4);
    tabList->addChild(tabList5);
    tabList->addChild(tabList6);
    tabList->addChild(tabList7);
    tabList->addChild(tabList8);
    tabList->addChild(tabList9);

    QTreeWidgetItem *costsum=new QTreeWidgetItem(ui->treeWidget_2,QStringList(QString("线下交易")));
    QTreeWidgetItem *costsum1=new QTreeWidgetItem(costsum,QStringList(QString("线下交易起稿")));
    QTreeWidgetItem *costsum2=new QTreeWidgetItem(costsum,QStringList(QString("线下比价")));
    QTreeWidgetItem *costsum3=new QTreeWidgetItem(costsum,QStringList(QString("线下处置提报")));
    QTreeWidgetItem *costsum4=new QTreeWidgetItem(costsum,QStringList(QString("中标通知")));
    QTreeWidgetItem *costsum5=new QTreeWidgetItem(costsum,QStringList(QString("线下交易登记")));
    QTreeWidgetItem *costsum6=new QTreeWidgetItem(costsum,QStringList(QString("退货申请")));
    QTreeWidgetItem *costsum7=new QTreeWidgetItem(costsum,QStringList(QString("退货审批")));
    QTreeWidgetItem *costsum8=new QTreeWidgetItem(costsum,QStringList(QString("合同签订")));
    QTreeWidgetItem *costsum9=new QTreeWidgetItem(costsum,QStringList(QString("费用到账")));

    costsum->addChild(costsum1);
    costsum->addChild(costsum2);
    costsum->addChild(costsum3);
    costsum->addChild(costsum4);
    costsum->addChild(costsum5);
    costsum->addChild(costsum6);
    costsum->addChild(costsum7);
    costsum->addChild(costsum8);
    costsum->addChild(costsum9);

    QTreeWidgetItem *dataintel=new QTreeWidgetItem(ui->treeWidget_2,QStringList(QString("公益捐赠")));
}

//现地处置树形结构的切换功能
void UIBasePlatformFrame::on_treeWidget_2_itemClicked(QTreeWidgetItem *item, int column)
{
    QString curItem_text=item->text(column);

    if(curItem_text=="资产拍卖起稿")
    {
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else if(curItem_text=="价值评估")
    {
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(curItem_text=="估值确认")
        {
            ui->stackedWidget_3->setCurrentIndex(2);
        }
    else if(curItem_text=="拍卖资产申请")
        {
            ui->stackedWidget_3->setCurrentIndex(3);
        }
    else if(curItem_text=="线上交易登记")
        {
            ui->stackedWidget_3->setCurrentIndex(4);
        }
    else if(curItem_text=="退货申请")
        {
            ui->stackedWidget_3->setCurrentIndex(5);
        }
    else if(curItem_text=="退货审批")
        {
            ui->stackedWidget_3->setCurrentIndex(6);
        }
    else if(curItem_text=="合同签订")
        {
            ui->stackedWidget_3->setCurrentIndex(7);
        }
    else if(curItem_text=="费用到账")
        {
            ui->stackedWidget_3->setCurrentIndex(8);
        }
    else if(curItem_text=="线下交易起稿")
        {
            ui->stackedWidget_3->setCurrentIndex(9);
        }
    else if(curItem_text=="线下比价")
        {
            ui->stackedWidget_3->setCurrentIndex(10);
        }
    else if(curItem_text=="线下处置提报")
        {
            ui->stackedWidget_3->setCurrentIndex(11);
        }
    else if(curItem_text=="中标通知")
        {
            ui->stackedWidget_3->setCurrentIndex(12);
        }
    else if(curItem_text=="线下交易登记")
        {
            ui->stackedWidget_3->setCurrentIndex(13);
        }
    else if(curItem_text=="退货申请")
        {
            ui->stackedWidget_3->setCurrentIndex(14);
        }
    else if(curItem_text=="退货审批")
        {
            ui->stackedWidget_3->setCurrentIndex(15);
        }
    else if(curItem_text=="合同签订")
        {
            ui->stackedWidget_3->setCurrentIndex(16);
        }
    else if(curItem_text=="费用到账")
        {
            ui->stackedWidget_3->setCurrentIndex(17);
        }
    else if(curItem_text=="公益捐赠")
        {
            ui->stackedWidget_3->setCurrentIndex(18);
        }
}


void UIBasePlatformFrame::leftMainClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        if (btnsMain.at(i) == b) {
            btnsMain.at(i)->setChecked(true);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), false)));
        } else {
            btnsMain.at(i)->setChecked(false);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), true)));
        }
    }

}

void UIBasePlatformFrame::leftConfigClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        if (btnsConfig.at(i) == b) {
            btnsConfig.at(i)->setChecked(true);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), false)));
        } else {
            btnsConfig.at(i)->setChecked(false);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), true)));
        }
    }

    ui->lab2->setText(name);
}

void UIBasePlatformFrame::leftClick1()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsLeft1.count();
    for (int i = 0; i < count; i++) {
        if (btnsLeft1.at(i) == b) {
            btnsLeft1.at(i)->setChecked(true);
            btnsLeft1.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsLeft1.at(i), false)));
        } else {
            btnsLeft1.at(i)->setChecked(false);
            btnsLeft1.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsLeft1.at(i), true)));
        }
    }

    ui->lab3->setText(name);
}

void UIBasePlatformFrame::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void UIBasePlatformFrame::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void UIBasePlatformFrame::on_btnMenu_Close_clicked()
{
    close();
}
//模拟数据
void UIBasePlatformFrame::on_pushButton_3_clicked()
{
    QList<PerInfo> l;
    for(int i=0;i<m_lNames.size();i++)
    {
        PerInfo info;
        info.name=m_lNames[i];
        if(i%3)
        {
           info.age=16;
           info.gender="男";
        };
        if(i%2)
        {
            info.age=17;
            info.gender="女";
        };
        if(i%7)
        {
            info.age=18;
            info.gender="男";
        };
        info.time="2022.7.1";
        info.school="第一中学";
        info.phone="12999999"+QString::number(i);
        info.email=m_lNames[i]+"@qq.com";
        l.append(info);
   }
   m_ptrrtSql->addPer(l);
   updateTable();

}
/**
*  加载数据库list data
 * @brief UIBasePlatformFrame::updateTable
 */
void UIBasePlatformFrame::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);

    QStringList lis;
    lis<<"序号"<<"ID"<<"姓名"<<"性别"<<"年龄"<<"学校"<<"入学时间"<<"电话"<<"Email";
    ui->tableWidget->setHorizontalHeaderLabels(lis);


    auto cnt =m_ptrrtSql->getPerCnt();
    ui->lb_cnt->setText(QString("总数:%1").arg(cnt));
    QList<PerInfo> lPer=m_ptrrtSql->getPagePer(0,cnt);
    ui->tableWidget->setRowCount(cnt);
    for(int i=0; i<lPer.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lPer[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lPer[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lPer[i].gender));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lPer[i].age)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(lPer[i].school));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(lPer[i].time));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(lPer[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lPer[i].email));
    }
}

void UIBasePlatformFrame::init_tableWidget_4()
{
//    ui->tableWidget_4->clearContents();
//    ui->tableWidget_4->clear();
    ui->tableWidget_4->setSpan(0, 0, 2, 1);//序号
    ui->tableWidget_4->setSpan(0, 1, 2, 1);//ID
    ui->tableWidget_4->setSpan(0, 2, 2, 1);//组别码
    ui->tableWidget_4->setSpan(0, 3, 2, 1);//接收小组
    ui->tableWidget_4->setSpan(0, 4, 1, 5);//组长
    ui->tableWidget_4->setSpan(0, 9, 1, 5);//副组长
    ui->tableWidget_4->setSpan(0, 14, 2, 1);
    ui->tableWidget_4->setSpan(0, 15, 2, 1);


    ui->tableWidget_4->setItem(0, 0, new QTableWidgetItem(QStringLiteral("序号")));
    ui->tableWidget_4->item(0,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,0)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget_4->setItem(0, 1, new QTableWidgetItem(QStringLiteral("ID")));
    ui->tableWidget_4->item(0,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,1)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget_4->setItem(0, 2, new QTableWidgetItem(QStringLiteral("组别码")));
    ui->tableWidget_4->item(0,2)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,2)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget_4->setItem(0, 3, new QTableWidgetItem(QStringLiteral("接收小组")));
    ui->tableWidget_4->item(0,3)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,3)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget_4->setItem(0, 4, new QTableWidgetItem(QStringLiteral("组长")));
    ui->tableWidget_4->item(0,4)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,4)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget_4->setItem(1, 4, new QTableWidgetItem(QStringLiteral("姓名")));
    ui->tableWidget_4->setItem(1, 5, new QTableWidgetItem(QStringLiteral("性别")));
    ui->tableWidget_4->setItem(1, 6, new QTableWidgetItem(QStringLiteral("政治面貌")));
    ui->tableWidget_4->setItem(1, 7, new QTableWidgetItem(QStringLiteral("联系电话")));
    ui->tableWidget_4->setItem(1, 8, new QTableWidgetItem(QStringLiteral("原单位名称")));
    for (int i = 4; i<9; i++)
    {
        ui->tableWidget_4->item(1,i)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_4->item(1,i)->setFlags(Qt::ItemIsEnabled);
    }

    ui->tableWidget_4->setItem(0, 9, new QTableWidgetItem(QStringLiteral("副组长")));
    ui->tableWidget_4->item(0,9)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_4->item(0,9)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget_4->setItem(1, 9, new QTableWidgetItem(QStringLiteral("姓名")));
    ui->tableWidget_4->setItem(1, 10, new QTableWidgetItem(QStringLiteral("性别")));
    ui->tableWidget_4->setItem(1, 11, new QTableWidgetItem(QStringLiteral("政治面貌")));
    ui->tableWidget_4->setItem(1, 12, new QTableWidgetItem(QStringLiteral("联系电话")));
    ui->tableWidget_4->setItem(1, 13, new QTableWidgetItem(QStringLiteral("原单位名称")));
    for (int i = 9; i<14; i++)
    {
        ui->tableWidget_4->item(1,i)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_4->item(1,i)->setFlags(Qt::ItemIsEnabled);
    }

    ui->tableWidget_4->setItem(0, 14, new QTableWidgetItem(QStringLiteral("人员编制")));
    ui->tableWidget_4->setItem(0, 15, new QTableWidgetItem(QStringLiteral("备注")));
    for (int i = 14; i<16; i++)
    {
        ui->tableWidget_4->item(0,i)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_4->item(0,i)->setFlags(Qt::ItemIsEnabled);
    }
    ui->tableWidget_4->setShowGrid(true); // 显示表格线
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows); // 设置选择模式
    ui->tableWidget_4->setFrameShape(QFrame::NoFrame); // 去掉边框
    ui->tableWidget_4->setSelectionMode(QAbstractItemView::SingleSelection); // 设置单选
    ui->tableWidget_4->horizontalHeader()->setVisible(false); // 隐藏行表头
    ui->tableWidget_4->verticalHeader()->setVisible(false);   // 隐藏列表头
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
    ui->tableWidget_4->setAlternatingRowColors(true);

}

void UIBasePlatformFrame::on_btn_add_clicked()
{
    m_dlgAddPer.setType(true);
    m_dlgAddPer.exec();//模态窗口
    updateTable();
}

void UIBasePlatformFrame::on_btn_delete_clicked()
{
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        int id=ui->tableWidget->item(i,1)->text().toUInt();
        m_ptrrtSql->delPer(id);

         QMessageBox::information(nullptr,"信息","删除成功！");
         updateTable();
    }
}

void UIBasePlatformFrame::on_btn_update_clicked()
{
    PerInfo info;
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        info.id=ui->tableWidget->item(i,1)->text().toUInt();
        info.name=ui->tableWidget->item(i,2)->text();
        info.gender=ui->tableWidget->item(i,3)->text();
        info.age=ui->tableWidget->item(i,4)->text().toUInt();
        info.school=ui->tableWidget->item(i,5)->text();
        info.time=ui->tableWidget->item(i,6)->text();
        info.phone=ui->tableWidget->item(i,7)->text();
        info.email=ui->tableWidget->item(i,8)->text();
        m_dlgAddPer.setType(false,info);
        m_dlgAddPer.exec();
    }
    updateTable();

}

void UIBasePlatformFrame::on_btn_search_clicked()
{
    QList<PerInfo> lPer;
    QString strFilter=ui->lename->text();
    int strFilter1=ui->select_sex->currentIndex();

    if (strFilter=="" && strFilter1==-1)
    {
        QMessageBox::information(nullptr,"警告","查询条件为空！");

    }else if(strFilter!="" && strFilter1==-1)
    {
        updateTable();
        lPer=m_ptrrtSql->searchByName(strFilter);
        Tian(lPer);
    }else if(strFilter=="" && strFilter1!=-1)
    {
        //根据性别查询
        updateTable();
        lPer=m_ptrrtSql->searchByGender(strFilter1);
        Tian(lPer);
    }else if(strFilter!="" && strFilter1!=-1)
    {
        updateTable();
        lPer=m_ptrrtSql->searchByNG(strFilter,strFilter1);
        Tian(lPer);
    }
}

void UIBasePlatformFrame::Tian(QList<PerInfo> l)
{
    int index=0;
    for(int i=0; i<l.size();i++)
    {
        index++;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(l[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(l[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(l[i].gender));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(l[i].age)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(l[i].school));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(l[i].time));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(l[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(l[i].email));
    };
    ui->tableWidget->setRowCount(index);
}



void UIBasePlatformFrame::on_btn_clear_clicked()
{
    updateTable();
    ui->lename->setText("");
    ui->select_sex->setCurrentIndex(-1);
}

void UIBasePlatformFrame::on_btn_clean_all_clicked()
{
    m_ptrrtSql->clearPerTable();
    updateTable();
}
//第二张表
void UIBasePlatformFrame::TianU(QList<UserInfo> u)
{
    int index=0;
    for(int i=0;i<u.size();i++)
    {
        index++;
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(u[i].id)));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(u[i].unit));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(u[i].job));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(u[i].name));
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(u[i].gender));
        ui->tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::number(u[i].age)));
        ui->tableWidget_2->setItem(i,7,new QTableWidgetItem(u[i].phone));
        ui->tableWidget_2->setItem(i,8,new QTableWidgetItem(u[i].address));
    }
    ui->tableWidget_2->setRowCount(index);
}

void UIBasePlatformFrame::UpdateTable()
{
    ui->tableWidget_2->setRowCount(9);
    QList<QString> n;
    n<<"序号"<<"ID"<<"单位"<<"职务"<<"姓名"<<"性别"<<"年龄"<<"电话"<<"地址";
    ui->tableWidget_2->setHorizontalHeaderLabels(n);
//改到这里
    auto cnt =m_ptrSonSql->getUserCnt();
    ui->label_21->setText(QString("总数:%1").arg(cnt));
    QList<UserInfo> lUser=m_ptrSonSql->getPageUser(0,cnt);
    ui->tableWidget_2->setRowCount(cnt);
    for(int i=0; i<lUser.size();i++)
    {
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(lUser[i].id)));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(lUser[i].unit));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(lUser[i].job));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(lUser[i].name));
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(lUser[i].gender));
        ui->tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::number(lUser[i].age)));
        ui->tableWidget_2->setItem(i,7,new QTableWidgetItem(lUser[i].phone));
        ui->tableWidget_2->setItem(i,8,new QTableWidgetItem(lUser[i].address));
    }
}

void UIBasePlatformFrame::on_btn_usearch_clicked()
{
    QList<UserInfo> User;
    QString nei=ui->lineEdit->text();
    if(nei=="")
    {
        QMessageBox::information(nullptr,"警告！","搜索框为空！");
    }else
    {
        UpdateTable();
        User=m_ptrSonSql->searchByName(nei);
        TianU(User);
    }
}

void UIBasePlatformFrame::on_btn_uclean_all_clicked()
{
    UpdateTable();
    ui->lineEdit->setText("");
}

void UIBasePlatformFrame::on_btn_usim_clicked()
{
    QList<UserInfo> l;
    QList<QString> sex;
    QList<QString> lj;
    sex<<"男"<<"女";
    lj<<"职员"<<"经理"<<"主任"<<"科长"<<"处长"<<"局长"<<"副局长";
    int indexs=sex.size();
    int indexl=lj.size();
    for(int i=0;i<m_lNames.size();i++)
    {
        UserInfo info;
        info.name=m_lNames[i];
        info.age=QRandomGenerator::global()->bounded(25,55);
        info.gender=sex[QRandomGenerator::global()->bounded(0,indexs)];
        info.job=lj[QRandomGenerator::global()->bounded(0,indexl)];
        info.unit="中国融通资源有限公司";
        info.phone="12999999"+QString::number(i);
        info.address="北京市海淀区北京工业大学创业园区";
        l.append(info);
   }
   m_ptrSonSql->addUser(l);
   UpdateTable();
}

void UIBasePlatformFrame::on_btn_clear_data_clicked()
{
    m_ptrSonSql->clearUserTable();
    UpdateTable();
}

void UIBasePlatformFrame::on_btn_uadd_clicked()
{
    m_dlgAddUser.setType(true);
    m_dlgAddUser.exec();//模态窗口
    UpdateTable();
}

void UIBasePlatformFrame::on_pushButton_2_clicked()
{
    UserInfo info;
    int i=ui->tableWidget_2->currentRow();
    if(i>=0)
    {
        info.id=ui->tableWidget_2->item(i,1)->text().toUInt();
        info.unit=ui->tableWidget_2->item(i,2)->text();
        info.job=ui->tableWidget_2->item(i,3)->text();
        info.name=ui->tableWidget_2->item(i,4)->text();
        info.gender=ui->tableWidget_2->item(i,5)->text();
        info.age=ui->tableWidget_2->item(i,6)->text().toUInt();
        info.phone=ui->tableWidget_2->item(i,7)->text();
        info.address=ui->tableWidget_2->item(i,8)->text();
        m_dlgAddUser.setType(false,info);
        m_dlgAddUser.exec();
    }
    else
    {
//        QMessageBox::information(nullptr,"警告！","没有选中数据！");
    }
    UpdateTable();
}

void UIBasePlatformFrame::showRightInfo()
{
    UserInfo info;
    int i=ui->tableWidget_2->currentRow();
    if(i>=0)
    {
        ui->label_ID->setText(ui->tableWidget_2->item(i,1)->text());
        ui->label_unit->setText(ui->tableWidget_2->item(i,2)->text());
        ui->label_job->setText(ui->tableWidget_2->item(i,3)->text());
        ui->label_name_2->setText(ui->tableWidget_2->item(i,4)->text());
        ui->label_gender->setText(ui->tableWidget_2->item(i,5)->text());
        ui->label_age->setText(ui->tableWidget_2->item(i,6)->text());
        ui->label_phone->setText(ui->tableWidget_2->item(i,7)->text());
        ui->label_address->setText(ui->tableWidget_2->item(i,8)->text());
    }
};

void UIBasePlatformFrame::on_pushButton_clicked()
{
    int i=ui->tableWidget_2->currentRow();
    if(i>=0)
    {
        int id=ui->tableWidget_2->item(i,1)->text().toUInt();
        m_ptrSonSql->delUser(id);

         QMessageBox::information(nullptr,"信息","删除成功！");
         UpdateTable();
    }
}

/**
 * 双击 简单模板列表 弹出框触发事件
 * @brief UIBasePlatformFrame::on_tableWidget_cellDoubleClicked
 * @param row
 * @param column
 */
//void UIBasePlatformFrame::on_tableWidget_cellDoubleClicked(int row, int column)
//{
//    qDebug()<<"click row and column:" << row << column;
//    on_pushButton_2_clicked();
//}
/**
 * 双击 Tab布局 弹出框触发事件
 * @brief UIBasePlatformFrame::on_tableWidget_cellDoubleClicked
 * @param row
 * @param column
 */
void UIBasePlatformFrame::on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item)
{
     qDebug()<<"tab tableGrid click row and columnm,弹出界面userWinDialog:" << item->row() << item->column();

//      on_pushButton_2_clicked();

//      UserInfo info;
//      int i=ui->tableWidget_2->currentRow();
//      if(i>=0)
//      {
//          info.id=ui->tableWidget_2->item(i,1)->text().toUInt();
//          info.unit=ui->tableWidget_2->item(i,2)->text();
//          info.job=ui->tableWidget_2->item(i,3)->text();
//          info.name=ui->tableWidget_2->item(i,4)->text();
//          info.gender=ui->tableWidget_2->item(i,5)->text();
//          info.age=ui->tableWidget_2->item(i,6)->text().toUInt();
//          info.phone=ui->tableWidget_2->item(i,7)->text();
//          info.address=ui->tableWidget_2->item(i,8)->text();
//          m_dlgAddUser.setType(false,info);

     userWinDialog.exec();


// this->hide();


//      }
//      else
//      {
//  //        QMessageBox::information(nullptr,"警告！","没有选中数据！");
//      }
//      UpdateTable();




}

//2022.12.28更改
int generateRandomNumber()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int test =qrand()%10;
    return test;
}
void UIBasePlatformFrame::on_pushButton_4_clicked()
{
    init_tableWidget_4();
    QList<CreInfo> l;

    for(int i=0;i<m_lNames.size();i++)
    {
        CreInfo info;
        info.group_id="N2022"+QString::number(i);
        info.group_name="N2022";
        info.leader_name=m_lNames[i];
        if(i%3)
        {
           info.leader_politics="团员";
           info.leader_gender="男";


        };
        if(i%2)
        {
            info.leader_politics="群众";
            info.leader_gender="女";

        };
        if(i%7)
        {
            info.leader_politics="党员";
            info.leader_gender="女";



        };
        info.leader_unit="中国融通资源开发有限公司";
        info.leader_phone="12999999"+QString::number(i);


        if(i%3)
        {
           info.deputy_name=m_lNames[i];
           info.deputy_politics="团员";
           info.deputy_gender="女";
           info.deputy_phone="138888"+QString::number(i);

        };
        if(i%2)
        {
            info.deputy_name=m_lNames[i];
            info.deputy_politics="党员";
            info.deputy_gender="男";
            info.deputy_phone="138888"+QString::number(i);
        };
        if(i%7)
        {
            info.deputy_name=m_lNames[i];
            info.deputy_politics="群众";
            info.deputy_gender="女";
            info.deputy_phone="138888"+QString::number(i);
        };
        info.deputy_unit="中国融通资源开发有限公司";
        info.staffing=generateRandomNumber();

        l.append(info);
   }
    m_prtCreSql->addPer(l);
    updateTableWidget4();
}

void UIBasePlatformFrame::updateTableWidget4()
{

    auto cnt =m_prtCreSql->getPerCnt();
    ui->label_48->setText(QString("总数:%1").arg(cnt));
    qDebug()<<cnt;
    QList<CreInfo> lPer=m_prtCreSql->getPagePer(0,cnt);
    ui->tableWidget_4->setRowCount(cnt);
    for(int i=0; i<lPer.size();i++)
    {
        int j=i+2;

        ui->tableWidget_4->setItem(j,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget_4->setItem(j,1,new QTableWidgetItem(QString::number(lPer[i].id)));

        ui->tableWidget_4->setItem(j,2,new QTableWidgetItem(lPer[i].group_id));
        ui->tableWidget_4->setItem(j,3,new QTableWidgetItem(lPer[i].group_name));

        ui->tableWidget_4->setItem(j,4,new QTableWidgetItem(lPer[i].leader_name));
        ui->tableWidget_4->setItem(j,5,new QTableWidgetItem(lPer[i].leader_gender));
        ui->tableWidget_4->setItem(j,6,new QTableWidgetItem(lPer[i].leader_politics));
        ui->tableWidget_4->setItem(j,7,new QTableWidgetItem(lPer[i].leader_phone));
        ui->tableWidget_4->setItem(j,8,new QTableWidgetItem(lPer[i].leader_unit));

        ui->tableWidget_4->setItem(j,9,new QTableWidgetItem(lPer[i].deputy_name));
        ui->tableWidget_4->setItem(j,10,new QTableWidgetItem(lPer[i].deputy_gender));
        ui->tableWidget_4->setItem(j,11,new QTableWidgetItem(lPer[i].deputy_politics));
        ui->tableWidget_4->setItem(j,12,new QTableWidgetItem(lPer[i].deputy_phone));
        ui->tableWidget_4->setItem(j,13,new QTableWidgetItem(lPer[i].deputy_unit));

        ui->tableWidget_4->setItem(j,14,new QTableWidgetItem(lPer[i].staffing));
        ui->tableWidget_4->setItem(j,15,new QTableWidgetItem(lPer[i].remark));
    }


}



















