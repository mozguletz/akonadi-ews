/*  This file is part of Akonadi EWS Resource
    Copyright (C) 2015-2016 Krzysztof Nowicki <krissn@op.pl>

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


#ifndef AKONADI_EWS_EWSGETPASSWORDEXPIRATIONDATE_H
#define AKONADI_EWS_EWSGETPASSWORDEXPIRATIONDATE_H

#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#include <QtCore/QTimer>

#include "ewsid.h"
#include "ewseventrequestbase.h"
#include "ewstypes.h"

class QXmlStreamReader;
class QXmlStreamWriter;


class EwsGetPasswordExpirationDateRequest : public EwsRequest
{
    Q_OBJECT
public:
    EwsGetPasswordExpirationDateRequest(QString email, EwsClient &client, QObject *parent);
    virtual ~EwsGetPasswordExpirationDateRequest();

    QDateTime getPasswordExpirationDate(){ return passwdExpiationDate; }

    virtual void start();
protected Q_SLOTS:
    virtual bool parseResult(QXmlStreamReader &reader);

private:
    QDateTime passwdExpiationDate;
    QString userEmail;
};

#endif //AKONADI_EWS_EWSGETPASSWORDEXPIRATIONDATE_H
