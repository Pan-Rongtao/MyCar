#pragma once
#include <QObject>
#include "Type.h"

class LayerManager : public QObject
{
    Q_OBJECT
public:
    LayerManager();

    static LayerManager *get();

    Q_PROPERTY(bool notLoginWarn READ notLoginWarn WRITE setnotLoginWarn NOTIFY notLoginWarnChanged)
    Q_PROPERTY(Type::PageE currentPage READ currentPage WRITE setcurrentPage NOTIFY currentPageChanged)
    Q_PROPERTY(Type::PopE currentPop READ currentPop WRITE setcurrentPop NOTIFY currentPopChanged)

    void setnotLoginWarn(bool notLoginWarn);
    bool notLoginWarn();

    void setcurrentPage(Type::PageE currentPage);
    Type::PageE currentPage();

    void setcurrentPop(Type::PopE currentPop);
    Type::PopE currentPop();


signals:
    void notLoginWarnChanged();
    void currentPageChanged();
    void currentPopChanged();

public slots:
    void switchPage(int page);
    void switchPop(int pop);

private:
    bool          m_notLoginWarn{false};
    Type::PageE   m_curPage{Type::Page_Regist};
    Type::PopE    m_curPop{Type::Pop_None};
};
