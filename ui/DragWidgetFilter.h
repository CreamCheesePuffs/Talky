#pragma once
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>

class DragWidgetFilter : public QObject {
public:
    DragWidgetFilter(QObject* parent) : QObject(parent) {}
    //    ~DragWidgetFilter();

    bool eventFilter(QObject* object, QEvent* event)
    {
        auto w = dynamic_cast<QWidget*>(object);
        if (w == nullptr)
        {
            return false;
        }
        if (event->type() == QEvent::MouseButtonPress)
        {
            auto evt = dynamic_cast<QMouseEvent*>(event);
            if (evt == nullptr)
            {
                return false;
            }
            pos = evt->pos();
        }

        if (event->type() == QEvent::MouseMove)
        {
            auto evt = dynamic_cast<QMouseEvent*>(event);
            if (evt == nullptr)
            {
                return false;
            }
            if (evt->buttons() & Qt::MouseButton::LeftButton) // 左键事件
            {
                w->move(evt->globalPos() - pos);
            }
        }
        return QObject::eventFilter(object, event);
    }

private:
    QPoint pos;

};
