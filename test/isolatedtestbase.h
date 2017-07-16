/*  This file is part of Akonadi EWS Resource
    Copyright (C) 2017 Krzysztof Nowicki <krissn@op.pl>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef TEST_ISOLATEDTESTBASE_H_
#define TEST_ISOLATEDTESTBASE_H_

#include <QObject>

namespace Akonadi {
class AgentInstance;
}
class FakeEwsServerThread;
class OrgKdeAkonadiEwsSettingsInterface;
class OrgKdeAkonadiEwsWalletInterface;

class IsolatedTestBase : public QObject
{
    Q_OBJECT
public:
    IsolatedTestBase(QObject *parent = 0);
    virtual ~IsolatedTestBase();

    static QString loadResourceAsString(const QString &path);
protected:
    virtual void init();
    virtual void cleanup();

    bool setEwsResOnline(bool online, bool wait);
protected:
    QString mEwsResIdentifier;
    QString mAkonadiInstanceIdentifier;
    QScopedPointer<FakeEwsServerThread> mFakeServerThread;
    QScopedPointer<Akonadi::AgentInstance> mEwsInstance;
    QScopedPointer<OrgKdeAkonadiEwsSettingsInterface> mEwsSettingsInterface;
    QScopedPointer<OrgKdeAkonadiEwsWalletInterface> mEwsWalletInterface;
};

#endif
