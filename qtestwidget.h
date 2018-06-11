#pragma once

#include <QWidget>
#include "ui_QTestWidget.h"

class QTestWidget : public QWidget
{
	Q_OBJECT

public:
	QTestWidget(QWidget *parent = Q_NULLPTR);
	~QTestWidget();

private:
	Ui::QTestWidget ui;
};
