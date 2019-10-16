#ifndef CAR_H
#define CAR_H

#include <QObject>
#include "Proxy.h"

class Car : public QObject
{
    Q_OBJECT
public:
    static Car *instance();

    Q_PROPERTY(float availableFuel READ availableFuel WRITE setavailableFuel NOTIFY availableFuelChanged)
    Q_PROPERTY(float averageFuel READ averageFuel WRITE setaverageFuel NOTIFY averageFuelChanged)
    Q_PROPERTY(float totalKm READ totalKm WRITE settotalKm NOTIFY totalKmChanged)
    Q_PROPERTY(float subKmA READ subKmA WRITE setsubKmA NOTIFY subKmAChanged)
    Q_PROPERTY(float subKmB READ subKmB WRITE setsubKmB NOTIFY subKmBChanged)
    Q_PROPERTY(bool leftFrontDoor READ leftFrontDoor WRITE setleftFrontDoor NOTIFY leftFrontDoorChanged)
    Q_PROPERTY(bool rightFrontDoor READ rightFrontDoor WRITE setrightFrontDoor NOTIFY rightFrontDoorChanged)
    Q_PROPERTY(bool leftRearDoor READ leftRearDoor WRITE setleftRearDoor NOTIFY leftRearDoorChanged)
    Q_PROPERTY(bool rightRearDoor READ rightRearDoor WRITE setrightRearDoor NOTIFY rightRearDoorChanged)
    Q_PROPERTY(bool leftFrontWindow READ leftFrontWindow WRITE setleftFrontWindow NOTIFY leftFrontWindowChanged)
    Q_PROPERTY(bool rightFrontWindow READ rightFrontWindow WRITE setrightFrontWindow NOTIFY rightFrontWindowChanged)
    Q_PROPERTY(bool leftRearWindow READ leftRearWindow WRITE setleftRearWindow NOTIFY leftRearWindowChanged)
    Q_PROPERTY(bool rightRearWindow READ rightRearWindow WRITE setrightRearWindow NOTIFY rightRearWindowChanged)
    Q_PROPERTY(bool AC READ AC WRITE setAC NOTIFY ACChanged)
    Q_PROPERTY(int ACTemp READ ACTemp WRITE setACTemp NOTIFY ACTempChanged)
    Q_PROPERTY(QString shutdownPhoto READ shutdownPhoto WRITE setshutdownPhoto NOTIFY shutdownPhotoChanged)
    Q_PROPERTY(bool driving READ driving WRITE setdriving NOTIFY drivingChanged)

    void setavailableFuel(float f);
    float availableFuel() const;

    void setaverageFuel(float f);
    float averageFuel() const;

    void settotalKm(float f);
    float totalKm() const;

    void setsubKmA(float f);
    float subKmA() const;

    void setsubKmB(float f);
    float subKmB() const;

    void setleftFrontDoor(bool b);
    bool leftFrontDoor() const;

    void setrightFrontDoor(bool b);
    bool rightFrontDoor() const;

    void setleftRearDoor(bool b);
    bool leftRearDoor() const;

    void setrightRearDoor(bool b);
    bool rightRearDoor() const;

    void setleftFrontWindow(bool b);
    bool leftFrontWindow() const;

    void setrightFrontWindow(bool b);
    bool rightFrontWindow() const;

    void setleftRearWindow(bool b);
    bool leftRearWindow() const;

    void setrightRearWindow(bool b);
    bool rightRearWindow() const;

    void setAC(bool b);
    bool AC() const;

    void setACTemp(int temp);
    int ACTemp() const;

    void setshutdownPhoto(QString photo);
    QString shutdownPhoto() const;

    void setdriving(bool b);
    bool driving() const;

    void onCarChanged(const CarInfo &info);

signals:
    void availableFuelChanged();
    void averageFuelChanged();
    void totalKmChanged();
    void subKmAChanged();
    void subKmBChanged();
    void leftFrontDoorChanged();
    void rightFrontDoorChanged();
    void leftRearDoorChanged();
    void rightRearDoorChanged();
    void leftFrontWindowChanged();
    void rightFrontWindowChanged();
    void leftRearWindowChanged();
    void rightRearWindowChanged();
    void ACChanged();
    void ACTempChanged();
    void shutdownPhotoChanged();
    void drivingChanged();

    void signalUpdate();

public slots:
    void update();
    void switchLeftFrontDoor(bool b);
    void switchRightFrontDoor(bool b);
    void switchLeftRearDoor(bool b);
    void switchRightRearDoor(bool b);
    void switchLeftFrontWindow(bool b);
    void switchRightFrontWindow(bool b);
    void switchLeftRearWindow(bool b);
    void switchRightRearWindow(bool b);
    void switchAC(bool b);
    void switchACTemp(int v);
    void switchDriving(bool b);

private:
    Car();

    float m_availableFuel{0.0};
    float m_averageFuel{0.0};
    float m_totalKm{0.0};
    float m_subKmA{0.0};
    float m_subKmB{0.0};
    bool m_leftFrontDoor{false};
    bool m_rightFrontDoor{false};
    bool m_leftRearDoor{false};
    bool m_rightRearDoor{false};
    bool m_leftFrontWindow{false};
    bool m_rightFrontWindow{false};
    bool m_leftRearWindow{false};
    bool m_rightRearWindow{false};
    bool m_AC{false};
    int m_ACTemp{20};
    QString m_shutdownPhoto;
    bool m_driving{false};
};

#endif // CAR_H
