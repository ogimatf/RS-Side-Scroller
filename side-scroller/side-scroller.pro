QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    Bullet.cpp \
    Button.cpp \
    Enemy.cpp \
    EnemyPickman.cpp \
    EnemySniperJoe.cpp \
    Entity.cpp \
    Game.cpp \
    Inert.cpp \
    LevelManager.cpp \
    Object.cpp \
    Pickaxe.cpp \
    Player.cpp \
    Projectile.cpp \
    Rocket.cpp \
    SniperJoeBullet.cpp \
    main.cpp

HEADERS += \
    Block.h \
    Bullet.h \
    Button.h \
    Enemy.h \
    EnemyPickman.h \
    EnemySniperJoe.h \
    Entity.h \
    Game.h \
    Inert.h \
    LevelManager.h \
    Object.h \
    Pickaxe.h \
    Player.h \
    Projectile.h \
    Rocket.h \
    SniperJoeBullet.h \
    Utils.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
