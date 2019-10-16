#include "Car.h"
#include <iostream>
#include <QDebug>
#include "Account.h"

Car *Car::instance()
{
    static Car *p = nullptr;
    if(!p)  p = new Car();
    return p;
}

void Car::setavailableFuel(float availableFuel)
{
    if(m_availableFuel != availableFuel)
    {
        m_availableFuel = availableFuel;
        emit availableFuelChanged();
    }
}

float Car::availableFuel() const
{
    return m_availableFuel;
}

void Car::setaverageFuel(float averageFuel)
{
    if(m_averageFuel != averageFuel)
    {
        m_averageFuel = averageFuel;
        emit averageFuelChanged();
    }
}

float Car::averageFuel() const
{
    return m_averageFuel;
}

void Car::settotalKm(float totalKm)
{
    if(m_totalKm != totalKm)
    {
        m_totalKm = totalKm;
        emit totalKmChanged();
    }
}

float Car::totalKm() const
{
    return m_totalKm;
}

void Car::setsubKmA(float subKmA)
{
    if(m_subKmA != subKmA)
    {
        m_subKmA = subKmA;
        emit subKmAChanged();
    }
}

float Car::subKmA() const
{
    return m_subKmA;
}

void Car::setsubKmB(float subKmB)
{
    if(m_subKmB != subKmB)
    {
        m_subKmB = subKmB;
        emit subKmBChanged();
    }
}

float Car::subKmB() const
{
    return m_subKmB;
}

void Car::setleftFrontDoor(bool leftFrontDoor)
{
    if(m_leftFrontDoor != leftFrontDoor)
    {
        m_leftFrontDoor = leftFrontDoor;
        emit leftFrontDoorChanged();
    }
}

bool Car::leftFrontDoor() const
{
    return m_leftFrontDoor;
}

void Car::setrightFrontDoor(bool rightFrontDoor)
{
    if(m_rightFrontDoor != rightFrontDoor)
    {
        m_rightFrontDoor = rightFrontDoor;
        emit rightFrontDoorChanged();
    }
}

bool Car::rightFrontDoor() const
{
    return m_rightFrontDoor;
}

void Car::setleftRearDoor(bool leftRearDoor)
{
    if(m_leftRearDoor != leftRearDoor)
    {
        m_leftRearDoor = leftRearDoor;
        emit leftRearDoorChanged();
    }
}

bool Car::leftRearDoor() const
{
    return m_leftRearDoor;
}

void Car::setrightRearDoor(bool rightRearDoor)
{
    if(m_rightRearDoor != rightRearDoor)
    {
        m_rightRearDoor = rightRearDoor;
        emit rightRearDoorChanged();
    }
}

bool Car::rightRearDoor() const
{
    return m_rightRearDoor;
}

void Car::setleftFrontWindow(bool leftFrontWindow)
{
    if(m_leftFrontWindow != leftFrontWindow)
    {
        m_leftFrontWindow = leftFrontWindow;
        emit leftFrontWindowChanged();
    }
}

bool Car::leftFrontWindow() const
{
    return m_leftFrontWindow;
}

void Car::setrightFrontWindow(bool rightFrontWindow)
{
    if(m_rightFrontWindow != rightFrontWindow)
    {
        m_rightFrontWindow = rightFrontWindow;
        emit rightFrontWindowChanged();
    }
}

bool Car::rightFrontWindow() const
{
    return m_rightFrontWindow;
}

void Car::setleftRearWindow(bool leftRearWindow)
{
    if(m_leftRearWindow != leftRearWindow)
    {
        m_leftRearWindow = leftRearWindow;
        emit leftRearWindowChanged();
    }
}

bool Car::leftRearWindow() const
{
    return m_leftRearWindow;
}

void Car::setrightRearWindow(bool rightRearWindow)
{
    if(m_rightRearWindow != rightRearWindow)
    {
        m_rightRearWindow = rightRearWindow;
        emit rightRearWindowChanged();
    }
}

bool Car::rightRearWindow() const
{
    return m_rightRearWindow;
}

void Car::setAC(bool AC)
{
    if(m_AC != AC)
    {
        m_AC = AC;
        emit ACChanged();
    }
}

bool Car::AC() const
{
    return m_AC;
}

void Car::setACTemp(int ACTemp)
{
    if(m_ACTemp != ACTemp)
    {
        m_ACTemp = ACTemp;
        emit ACTempChanged();
    }
}

int Car::ACTemp() const
{
    return m_ACTemp;
}

void Car::setshutdownPhoto(QString photo)
{

}

QString Car::shutdownPhoto() const
{
    return m_shutdownPhoto;
}

void Car::setdriving(bool driving)
{
    if(m_driving != driving)
    {
        m_driving = driving;
        emit drivingChanged();
    }
}

bool Car::driving() const
{
    return m_driving;
}

void Car::onCarChanged(const CarInfo &info)
{
    if(info.userID == Account::instance()->userID().toStdString())
    {
        emit signalUpdate();
    }
}

void Car::update()
{
    if(Account::instance()->islogin())
    {
        CarInfo info = Proxy::instance()->carProxy()->getCarInfo(Account::instance()->userID().toStdString());
        setavailableFuel(info.availableFuel);
        setaverageFuel(info.averageFuel);
        settotalKm(info.totalKm);
        setsubKmA(info.subKmA);
        setsubKmB(info.subKmB);
        setleftFrontDoor(info.leftFrontDoor);
        setrightFrontDoor(info.rightFrontDoor);
        setleftRearDoor(info.leftRearDoor);
        setrightRearDoor(info.rightRearDoor);
        setleftFrontWindow(info.leftFrontWindow);
        setrightFrontWindow(info.rightFrontWindow);
        setleftRearWindow(info.leftRearWindow);
        setrightRearWindow(info.rightRearWindow);
        setAC(info.AC);
        setACTemp(info.ACTemp);
        //setshutdownPhoto(info.shutdownPhoto);
        setdriving(info.driving);
    }
    else
    {
        setavailableFuel(0.0);
        setaverageFuel(0.0);
        settotalKm(0.0);
        setsubKmA(0.0);
        setsubKmB(0.0);
        setleftFrontDoor(false);
        setrightFrontDoor(false);
        setleftRearDoor(false);
        setrightRearDoor(false);
        setleftFrontWindow(false);
        setrightFrontWindow(false);
        setleftRearWindow(false);
        setrightRearWindow(false);
        setAC(false);
        setACTemp(20);
        //setshutdownPhoto(info.shutdownPhoto);
        setdriving(false);
    }
}

void Car::switchLeftFrontDoor(bool b)
{
    Proxy::instance()->carProxy()->switchLeftFrontDoor(Account::instance()->userID().toStdString(), b);
}

void Car::switchRightFrontDoor(bool b)
{
    Proxy::instance()->carProxy()->switchRightFrontDoor(Account::instance()->userID().toStdString(), b);
}

void Car::switchLeftRearDoor(bool b)
{
    Proxy::instance()->carProxy()->switchLeftRearDoor(Account::instance()->userID().toStdString(), b);
}

void Car::switchRightRearDoor(bool b)
{
    Proxy::instance()->carProxy()->switchRightRearDoor(Account::instance()->userID().toStdString(), b);
}

void Car::switchLeftFrontWindow(bool b)
{
    Proxy::instance()->carProxy()->switchLeftFrontWindow(Account::instance()->userID().toStdString(), b);
}

void Car::switchRightFrontWindow(bool b)
{
    Proxy::instance()->carProxy()->switchRightFrontWindow(Account::instance()->userID().toStdString(), b);
}

void Car::switchLeftRearWindow(bool b)
{
    Proxy::instance()->carProxy()->switchLeftRearWindow(Account::instance()->userID().toStdString(), b);
}

void Car::switchRightRearWindow(bool b)
{
    Proxy::instance()->carProxy()->switchRightRearWindow(Account::instance()->userID().toStdString(), b);
}

void Car::switchAC(bool b)
{
    Proxy::instance()->carProxy()->switchAC(Account::instance()->userID().toStdString(), b);
}

void Car::switchACTemp(int v)
{
    Proxy::instance()->carProxy()->setACTemp(Account::instance()->userID().toStdString(), v);
}

void Car::switchDriving(bool b)
{
    Proxy::instance()->carProxy()->setDriving(Account::instance()->userID().toStdString(), b);
}

Car::Car()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}
