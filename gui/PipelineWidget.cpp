#include "PipelineWidget.h"

// Qt
#include <QGLWidget>
#include <QGraphicsView>
#include <QGridLayout>

// maverick project
#include "core/IPipeline.h"

#include "gui/ConnectionItem.h"
#include "gui/NodeItem.h"
#include "gui/PipelineScene.h"

using namespace maverick::gui;
using namespace maverick::core;

PipelineWidget::PipelineWidget(
  IPipeline& pipeline, INodeFactory& factory, QWidget* parent, Qt::WindowFlags f)
  : QWidget(parent, f)
  , m_pipeline(pipeline)
  , m_factory(factory)
  , m_scene(new PipelineScene(this))
  , m_view(new QGraphicsView(m_scene, this))
{
  constexpr int sceneRes = 8192;
  m_scene->setSceneRect(QRectF(0, 0, sceneRes, sceneRes));
  // TODO: remove this
  m_scene->addText("Hello, world!");
  NodeItem* nodeItem = new NodeItem;
  nodeItem->setPos(0, 0);
  nodeItem->setRect(0, 0, 50, 100);
  m_scene->addItem(nodeItem);
  NodeItem* nodeItem2 = new NodeItem;
  nodeItem2->setPos(100, 0);
  nodeItem2->setRect(0, 0, 50, 100);
  m_scene->addItem(nodeItem2);
  ConnectionItem* connectionItem = new ConnectionItem;
  connectionItem->setLine(50, 50, 100, 50);
  m_scene->addItem(connectionItem);
  //

  m_view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers | QGL::DirectRendering)));
  m_view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(m_view);

  setLayout(layout);
}
