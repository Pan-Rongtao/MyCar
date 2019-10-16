#pragma once
#include <RCF/Idl.hpp>
#include <SF/vector.hpp>
#include "Types.h"

static void serialize(SF::Archive& ar, UserInfo &info)
{
	ar & info.userID & info.password & info.nickname & info.signaTure & info.photo & info.registTime & info.vehicleOnline & info.pcOnline & info.handeldOnline & info.padOnline;
}

static void serialize(SF::Archive& ar, GroupInfo &info)
{
	ar & info.groupID & info.name & info.photo & info.brief;
}

static void serialize(SF::Archive& ar, ChatMessage &msg)
{
	ar & msg.senderID & msg.receiverID & msg.content & msg.time & msg.p2p;
}

RCF_BEGIN(AccountInterface, "AccountInterface")
RCF_METHOD_R3(bool, regist, const std::string &, const std::string &, const std::string &);
RCF_METHOD_R1(bool, isRegisted, const std::string &);
RCF_METHOD_V2(void, setPassword, const std::string &, const std::string &);
RCF_METHOD_V2(void, setNickname, const std::string &, const std::string &);
RCF_METHOD_V2(void, setSignaTure, const std::string &, const std::string &);
RCF_METHOD_R2(bool, setPhoto, const std::string &, const std::string &);
RCF_METHOD_R3(bool, setVehicleOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setPCOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setHandeldOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setPadOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R1(UserInfo, getUserInfo, const std::string &);
RCF_METHOD_R0(std::vector<UserInfo>, queryUsers);

RCF_METHOD_R2(bool, addFriend, const std::string &, const std::string &);
RCF_METHOD_V2(void, removeFriend, const std::string &, const std::string &);
RCF_METHOD_R1(std::vector<std::string>, getFriends, const std::string &);

RCF_METHOD_R2(std::string, addGroup, const std::string &, const std::string &);
RCF_METHOD_V1(void, removeGroup, const std::string &);
RCF_METHOD_R1(GroupInfo, getGroupInfo, const std::string &);
RCF_METHOD_R1(std::vector<std::string>, getBelongGroups, const std::string &);
RCF_METHOD_V2(void, setGroupName, const std::string &, const std::string &);
RCF_METHOD_V2(void, setGroupBrief, const std::string &, const std::string &);
RCF_METHOD_V2(void, addGroupMember, const std::string &, const std::string &);
RCF_METHOD_V2(void, removeGroupMember, const std::string &, const std::string &);
RCF_METHOD_R1(std::vector<std::string>, getGroupMembers, const std::string &);

RCF_METHOD_V3(void, addP2PMessage, const std::string &, const std::string &, const std::string &);
RCF_METHOD_R2(std::vector<ChatMessage>, getP2PMessages, const std::string &, const std::string &);
RCF_METHOD_V3(void, addGroupMessage, const std::string &, const std::string &, const std::string &);
RCF_METHOD_R1(std::vector<ChatMessage>, getGroupMessages, const std::string &);

RCF_END(AccountInterface)

RCF_BEGIN(AccountNotify, "AccountNotify")
RCF_METHOD_V1(void, onAccountChanged, const UserInfo &);
RCF_METHOD_V1(void, onMessageArrived, const ChatMessage &);
RCF_END(AccountNotify)

