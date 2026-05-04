/*
 * SPDX-FileCopyrightText: 2020 Nick Korotysh <nick.korotysh@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#pragma once

#include <QWidget>

class GradientEdit : public QWidget
{
  Q_OBJECT

  Q_PROPERTY(QGradient gradient READ gradient WRITE setGradient
             NOTIFY gradientChanged)

public:
  explicit GradientEdit(QWidget* parent = nullptr)
    : GradientEdit(QLinearGradient(), parent) {}
  explicit GradientEdit(const QGradient& gradient, QWidget* parent = nullptr);

  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;

  bool hasHeightForWidth() const override { return true; }
  int heightForWidth(int w) const override { return w; }

  inline const QGradient& gradient() const noexcept { return m_gradient; }

public slots:
  void setGradient(const QGradient& gradient);

  void setGradientType(QGradient::Type type);
  void setGradientSpread(QGradient::Spread spread);
  void setGradientStops(const QGradientStops& stops);

signals:
  void gradientChanged(const QGradient& gradient);

protected:
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;

  void paintEvent(QPaintEvent* event) override;

private:
  void updatePoints();
  void updateGradient();

private:
  QBrush m_background;
  QGradient m_gradient;

  QVector<QPointF> m_points;
  int m_selected_point = -1;
};
