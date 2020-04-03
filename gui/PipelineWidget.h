#pragma once

#include <QWidget>

#include "core/IPipeline.h"

class QGraphicsView;

namespace maverick
{
namespace gui
{

class PipelineScene;

class PipelineWidget : public QWidget
{
public:
  explicit PipelineWidget(
    core::IPipeline& pipeline, QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  ~PipelineWidget() override = default;

private:
  core::IPipeline& m_pipeline;
  PipelineScene* m_scene;
  QGraphicsView* m_view;
};
}
}
