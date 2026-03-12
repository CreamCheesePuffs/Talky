#pragma once

#include <QWidget>
#include "ui_ChatItem.h"

class ChatItem : public QWidget
{
    Q_OBJECT

public:
    ChatItem(QWidget *parent = nullptr);
    ~ChatItem();

    void setData(const QString& name,
        const QString& preview,
        const QString& timeText,
        int unreadCount,
        const QPixmap& avatar);


private:
    Ui::ChatItemClass ui;
};

