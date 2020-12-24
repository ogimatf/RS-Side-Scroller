#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QPixmap>

#include "Object.h"

class HealthBar : public Object
{
public:
    HealthBar();
    QPixmap texture_health_bar[11];

    virtual std::string name() { return "HealthBar";}


    virtual void animate();

    virtual void advance();

    virtual void solveCollisions();
};

#endif // HEALTHBAR_H
