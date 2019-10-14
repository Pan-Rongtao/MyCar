#include "LayerManager.h"
#include "Account.h"

LayerManager *LayerManager::instance()
{
    static LayerManager *p = nullptr;
    if(!p)  p = new LayerManager();
    return p;
}

void LayerManager::setnotLoginWarn(bool notLoginWarn)
{
    if(m_notLoginWarn != notLoginWarn)
    {
        m_notLoginWarn = notLoginWarn;
    }
    emit notLoginWarnChanged();
}

bool LayerManager::notLoginWarn()
{
    return m_notLoginWarn;
}

void LayerManager::setcurrentPage(Type::PageE currentPage)
{
    if(m_curPage != currentPage)
    {
        m_curPage = currentPage;
        emit currentPageChanged();
    }
}

Type::PageE LayerManager::currentPage()
{
    return m_curPage;
}

void LayerManager::setcurrentPop(Type::PopE currentPop)
{
    if(m_curPop != currentPop)
    {
        m_curPop = currentPop;
        emit currentPopChanged();
    }
}

Type::PopE LayerManager::currentPop()
{
    return m_curPop;
}

void LayerManager::switchPage(int page)
{
    switch (page) {
    case Type::Page_Account:
    case Type::Page_Car:
    case Type::Page_Cellphone:
    case Type::Page_Contacts:
    case Type::Page_GroupChat:
    case Type::Page_Message:
    case Type::Page_P2PChat:
    case Type::Page_PC:
        if(Account::instance()->islogin())
            setcurrentPage((Type::PageE)page);
        else
            setnotLoginWarn(true);
        break;
    case Type::Page_Regist:
    case Type::Page_Login:
        setcurrentPage((Type::PageE)page);
        break;
    default:
        break;
    }
}

void LayerManager::switchPop(int pop)
{
    setcurrentPop((Type::PopE)pop);
}

LayerManager::LayerManager()
{

}
