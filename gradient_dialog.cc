/*
 * SPDX-FileCopyrightText: 2020 Nick Korotysh <nick.korotysh@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include "gradient_dialog.h"
#include "ui_gradient_dialog.h"

QGradient GradientDialog::getGradient(bool* ok, const QGradient& gradient,
                                      QWidget* parent, const QString& title)
{
  GradientDialog dlg(gradient, parent);
  if (!title.isEmpty())
    dlg.setWindowTitle(title);
  dlg.exec();
  if (ok)
    *ok = dlg.result() == QDialog::Accepted;
  return dlg.gradient();
}

GradientDialog::GradientDialog(const QGradient& gradient, QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::GradientDialog)
{
  ui->setupUi(this);

  setGradient(gradient);

  connect(ui->stops_edit, &GradientStopsEdit::stopsChanged,
          ui->gradient_edit, &GradientEdit::setGradientStops);
  connect(ui->gradient_edit, &GradientEdit::gradientChanged,
          this, &GradientDialog::gradientChanged);
}

GradientDialog::~GradientDialog()
{
  delete ui;
}

QGradient GradientDialog::gradient() const
{
  return ui->gradient_edit->gradient();
}

void GradientDialog::setGradient(const QGradient& gr)
{
  ui->gradient_edit->setGradient(gr);
  ui->stops_edit->setStops(gr.stops());

  ui->type_linear_rbtn->setChecked(gr.type() == QGradient::LinearGradient);
  ui->type_radial_rbtn->setChecked(gr.type() == QGradient::RadialGradient);
  ui->type_conical_rbtn->setChecked(gr.type() == QGradient::ConicalGradient);

  ui->spread_pad_rbtn->setChecked(gr.spread() == QGradient::PadSpread);
  ui->spread_repeat_rbtn->setChecked(gr.spread() == QGradient::RepeatSpread);
  ui->spread_reflect_rbtn->setChecked(gr.spread() == QGradient::ReflectSpread);
}

void GradientDialog::on_type_linear_rbtn_clicked()
{
  ui->gradient_edit->setGradientType(QGradient::LinearGradient);
}

void GradientDialog::on_type_radial_rbtn_clicked()
{
  ui->gradient_edit->setGradientType(QGradient::RadialGradient);
}

void GradientDialog::on_type_conical_rbtn_clicked()
{
  ui->gradient_edit->setGradientType(QGradient::ConicalGradient);
}

void GradientDialog::on_spread_pad_rbtn_clicked()
{
  ui->gradient_edit->setGradientSpread(QGradient::PadSpread);
}

void GradientDialog::on_spread_repeat_rbtn_clicked()
{
  ui->gradient_edit->setGradientSpread(QGradient::RepeatSpread);
}

void GradientDialog::on_spread_reflect_rbtn_clicked()
{
  ui->gradient_edit->setGradientSpread(QGradient::ReflectSpread);
}
