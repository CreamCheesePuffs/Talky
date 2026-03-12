#include "ChatItem.h"
#include <QDebug>
#include <QPainter>

ChatItem::ChatItem(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //setAttribute(Qt::WA_StyledBackground, true);
    //setAutoFillBackground(false);

    //// 让里面的 label 一定可见（先用于排查）
    //ui.nameLabel->setStyleSheet("background: transparent; color: #222;");
    //ui.previewLabel->setStyleSheet("background: transparent; color: rgba(0,0,0,0.55);");
    //ui.timeLabel->setStyleSheet("background: transparent; color: rgba(0,0,0,0.45);");
}

ChatItem::~ChatItem()
{}

void ChatItem::setData(const QString& name,
    const QString& preview,
    const QString& timeText,
    int unreadCount,
    const QPixmap& avatar)
{
    ui.nameLabel->setText(name);
    ui.previewLabel->setText(preview);
    ui.timeLabel->setText(timeText);

    // unread badge
    if (unreadCount <= 0) {
        ui.unreadBadge->hide();
    }
    else {
        ui.unreadBadge->show();
        ui.unreadBadge->setText(unreadCount > 99 ? "99+" : QString::number(unreadCount));
    }

    QPixmap p = avatar;
    if (p.isNull()) {
        p = QPixmap(40, 40);
        p.fill(QColor("#CFCFCF"));
    }

    //p = p.scaled(40, 40, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // 做圆形遮罩
 /*   QPixmap circle(40, 40);
    circle.fill(Qt::transparent);
    QPainter painter(&circle);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath path;
    path.addEllipse(0, 0, 40, 40);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, p);
    painter.end();*/

    //ui.avatarLabel->setPixmap(circle);


    qDebug() << "ChatItemWidget::setData" << name << preview << timeText << unreadCount;
    qDebug() << ui.nameLabel << ui.previewLabel << ui.timeLabel << ui.avatarLabel;
}