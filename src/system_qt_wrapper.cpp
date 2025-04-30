#include "system_qt_wrapper.h"

QVariantList SystemQtWrapper::GetObjects()
{
	return GetObjects(date_);
}

QVariantList SystemQtWrapper::GetObjects(Date& date)
{
	QVariantList objects;

	for (const Object* obj : system_.GetObjects())
	{
		const Position pos = obj->GetPosition(date);
		QVariantMap m;
		m["name"] = QString::fromStdString(obj->GetName());
		m["x"] = pos.x;
		m["y"] = pos.y;
		objects.append(m);
	}

	return objects;
}

Date& SystemQtWrapper::NextDate()
{
	++date_;
	emit dateChanged();
	return date_;
}

Date& SystemQtWrapper::PrevDate()
{
	--date_;
	emit dateChanged();
	return date_;
}

QVariantList SystemQtWrapper::GetList()
{
	return GetObjects();
}

QString SystemQtWrapper::GetDateString() const
{
	return QString("%1.%2.%3")
		.arg(date_.Day(), 2, 10, QLatin1Char('0'))
		.arg(date_.Month(), 2, 10, QLatin1Char('0'))
		.arg(date_.Year());
}