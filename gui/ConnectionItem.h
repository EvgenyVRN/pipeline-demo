#pragma once

#include <QGraphicsLineItem>

namespace maverick {
namespace gui {

class ConnectionItem : public QGraphicsLineItem
{
public:
    explicit ConnectionItem(QGraphicsItem* parent = nullptr);
    ~ConnectionItem() override = default;

};

}
}
