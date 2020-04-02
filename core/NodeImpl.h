#pragma once

#include <QObject>

namespace maverick
{
namespace core
{
class NodeImpl : public QObject
{
    Q_OBJECT
public:
    NodeImpl();

    bool IsModified() const;
    void Modified(bool modified);

signals:
    void Modified();

private:
    bool m_modified;
};

}
}
