#pragma once

#include <QtWidgets/QGraphicsScene>

namespace maverick {
namespace gui {

class PipelineScene : public QGraphicsScene
{
public:
    explicit PipelineScene(QObject *parent = nullptr);
};
}
}
