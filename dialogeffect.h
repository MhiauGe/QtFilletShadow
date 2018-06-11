#ifndef DIALOGEFFECT_H
#define DIALOGEFFECT_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsEffect>

/**
 * @brief The DialogEffect class
 * 功能：用于实现所有弹窗的圆角和阴影效果
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
