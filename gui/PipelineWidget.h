#pragma once

#include <QWidget>

class QGraphicsView;

namespace maverick {
namespace gui {

class PipelineScene;

class PipelineWidget : public QWidget
{
public:
    explicit PipelineWidget(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~PipelineWidget() override = default;
private:
    PipelineScene* m_scene;
    QGraphicsView* m_view;
};

}
}
