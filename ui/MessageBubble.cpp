#include "MessageBubble.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QFontMetrics>

MessageBubble::MessageBubble(const QString& text, bool outgoing, QWidget* parent)
    : QWidget(parent), _outgoing(outgoing)
{
    setAttribute(Qt::WA_StyledBackground, true);

    _textLabel = new QLabel(text, this);
    _textLabel->setWordWrap(true);
    _textLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // 气泡样式：自己/对方区分
    if (outgoing) {
        _textLabel->setStyleSheet(
            "QLabel {"
            "  padding: 8px 10px;"
            "  border-radius: 12px;"
            "  background: rgba(42,130,255,0.95);"   // 淡蓝色
            "  color: rgba(255,255,255,1.0);"
            "  border: 1px solid rgba(42,130,255,0.90);"
            "}"
        );
    }
    else {
        _textLabel->setStyleSheet(
            "QLabel {"
            "  padding: 8px 10px;"
            "  border-radius: 12px;"
            "  background: rgba(255,255,255,1.0);"   // 接近白色
            "  color: rgba(30,30,30,0.95);"
            "  border: 1px solid rgba(233,234,236,1.0);"
            "}"
        );
    }

    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(12, 4, 12, 4);
    layout->setSpacing(0);

    // 关键：用 stretch 把气泡推到左/右
    if (outgoing) {
        layout->addStretch(1);
        layout->addWidget(_textLabel, 0);
    }
    else {
        layout->addWidget(_textLabel, 0);
        layout->addStretch(1);
    }

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    _textLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

int MessageBubble::preferredHeight(int maxWidth) const
{
    // 让气泡宽度别太宽（否则像一整条横幅）
    int bubbleMax = qMax(120, maxWidth * 60 / 100); // 60% 列表宽
    bubbleMax = qMin(bubbleMax, 420);               // 上限

    _textLabel->setMaximumWidth(bubbleMax);

    // 根据文本计算高度（简单估算足够用）
    QFontMetrics fm(_textLabel->font());
    QRect r = fm.boundingRect(QRect(0, 0, bubbleMax, 10000), Qt::TextWordWrap, _textLabel->text());
    int h = r.height() + 8 + 8; // padding 上下
    return h + 8;               // 再加外层 margins
}
