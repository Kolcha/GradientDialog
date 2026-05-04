/*
 * SPDX-FileCopyrightText: 2020 Nick Korotysh <nick.korotysh@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#pragma once

#include <QDialog>

namespace Ui {
class GradientDialog;
}

class GradientDialog : public QDialog
{
  Q_OBJECT

  Q_PROPERTY(QGradient gradient READ gradient WRITE setGradient
             NOTIFY gradientChanged)

public:
  static QGradient getGradient(bool* ok,
                               const QGradient& gradient = QLinearGradient(),
                               QWidget* parent = nullptr,
                               const QString& title = QString());

  explicit GradientDialog(QWidget* parent = nullptr)
    : GradientDialog(QLinearGradient(), parent) {}
  explicit GradientDialog(const QGradient& gradient,
                          QWidget* parent = nullptr);
  ~GradientDialog();

  QGradient gradient() const;

public slots:
  void setGradient(const QGradient& gradient);

signals:
  void gradientChanged(const QGradient& gradient);

private slots:
  void on_type_linear_rbtn_clicked();
  void on_type_radial_rbtn_clicked();
  void on_type_conical_rbtn_clicked();

  void on_spread_pad_rbtn_clicked();
  void on_spread_repeat_rbtn_clicked();
  void on_spread_reflect_rbtn_clicked();

private:
  Ui::GradientDialog* ui;
};
