#pragma once
#include <QObject>

class Type : public QObject
{
    Q_OBJECT
    Q_ENUMS(TerminalType)
    Q_ENUMS(PageE)
    Q_ENUMS(PopE)

public:
    enum TerminalType
    {
        Terminal_PC,
        Terminal_Vehicle,
        Terminal_CellPhone,
        Terminal_Pad,
    };

    enum PageE
    {
        Page_Account = 0,
        Page_Regist,
        Page_Login,
        Page_Car,
        Page_PC,
        Page_Cellphone,
        Page_Message,
        Page_Contacts,
        Page_P2PChat,
        Page_GroupChat,
    };
    enum PopE
    {
        Pop_None = 0,
        Pop_AddFriend,
        Pop_CreateGroup,
        Pop_GroupInfo,
        Pop_AddGroupMember,
    };

};
