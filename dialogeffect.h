#ifndef DIALOGEFFECT_H
#define DIALOGEFFECT_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsEffect>

/**
 * @brief The DialogEffect class
 * 功能：用于实现所有弹窗的圆角和阴影效果
 * 用法：
 * 1.弹窗类构造函数中setAttribute(Qt::WA_TranslucentBackground);
 * 2.将弹窗与各控件之间增加widget层，放置所有空间到widget，设置widget父控件为弹窗类
 * 3. 在initstyle中使用下列代码：
 *    this->resize(width() + 40, height() + 40);
 *    this->layout()->setMargin(20);
 *    DialogEffect* dialogShadow = new DialogEffect;
 *    dialogShadow->setRoundedCornerAndShadow(ui->wgtContent);
 */
class DialogEffect : public QGraphicsEffect
{
    Q_OBJECT
public:
	explicit DialogEffect(QWidget* aWidget, QObject *parent = 0);

    void draw(QPainter* painter);
    QRectF boundingRectFor(const QRectF& rect) const;

    inline void setDistance(qreal distance) { m_distance = distance; updateBoundingRect(); }
    inline qreal distance() const { return m_distance; }

    inline void setBlurRadius(qreal blurRadius) { m_blurRadius = blurRadius; updateBoundingRect(); }
    inline qreal blurRadius() const { return m_blurRadius; }

    inline void setColor(const QColor& color) { m_color = color; }
    inline QColor color() const { return m_color; }

private:
	/**
	* @brief setRoundedCornerAndShadow
	* @param widget 想要设置的弹窗类对象
	*/
	void setRoundedCornerAndShadow();

private:
    qreal  m_distance;
    qreal  m_blurRadius;
    QColor m_color;
	qint32 m_corner;
	QWidget* mWidget;
};

#endif // DIALOGEFFECT_H
