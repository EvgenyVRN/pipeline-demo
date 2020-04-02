#pragma once

#include <QGraphicsRectItem>

namespace maverick {
namespace gui {

class NodeItem : public QGraphicsRectItem
{
public:
    explicit NodeItem(QGraphicsItem *parent = nullptr);
    ~NodeItem() override = default;
};

}
}
