#pragma once
#include <QWidget>

class QLabel;

class MessageBubble : public QWidget {
    Q_OBJECT
public:
    explicit MessageBubble(const QString& text, bool outgoing, QWidget* parent = nullptr);

    // 用于给 QListWidgetItem 设置合适高度
    int preferredHeight(int maxWidth) const;

private:
    QLabel* _textLabel{};
    bool _outgoing{};
};
