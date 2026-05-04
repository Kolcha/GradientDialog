/*
 * SPDX-FileCopyrightText: 2020 Nick Korotysh <nick.korotysh@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#pragma once

#include <QWidget>

class GradientStopsEdit : public QWidget
{
  Q_OBJECT

  Q_PROPERTY(QGradientStops stops READ stops WRITE setStops
             NOTIFY stopsChanged)

public:
  explicit GradientStopsEdit(QWidget* parent = nullptr)
    : GradientStopsEdit(QGradientStops(), parent) {}
  explicit GradientStopsEdit(const QGradientStops& stops,
                             QWidget* parent = nullptr);

  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;

  inline const QGradientStops& stops() const noexcept { return m_stops; }

public slots:
  void setStops(const QGradientStops& stops);

signals:
  void stopsChanged(const QGradientStops& stops);

protected:
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseDoubleClickEvent(QMouseEvent* event) override;

  void paintEvent(QPaintEvent* event) override;

private:
  int findStopIndex(qreal xpos) const;

  void addStop(qreal pos);
  void removeStop(int idx);

  QColor pickColor(qreal pos) const;

  void updateImage();

private:
  QBrush m_background;
  QGradientStops m_stops;

  int m_stop_index = -1;
  QImage m_gradient;
};
