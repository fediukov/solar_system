#pragma once

#include <QDate>
#include <QObject>
#include <QVariant>

#include "date.h"
#include "system.h"
#include "solar_system.h"

class SystemQtWrapper : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QVariantList list READ GetList NOTIFY dateChanged)

public:
	SystemQtWrapper(QObject* parent = nullptr) : QObject(parent), system_(std::move(CreateSolarSystem()))
	{
		QDate today = QDate::currentDate();
		date_ = Date(today.day(), today.month(), today.year());
	}

	Q_INVOKABLE QVariantList GetObjects();
	Q_INVOKABLE QVariantList GetObjects(Date& date);
	Q_INVOKABLE Date& NextDate();
	Q_INVOKABLE Date& PrevDate();

	Q_INVOKABLE QVariantList GetList();
	Q_INVOKABLE QString GetDateString() const;

signals:
	void dateChanged();

private:
	System system_;
	Date date_;
};
