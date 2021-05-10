#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Expresiones para validar mails
    ui->comboBox->addItem("^([\\w_]+)(\\.[\\w_]+)*@([A-Za-z]+)(\\.[A-Za-z]+)(\\.[A-Za-z]{2,})*$");
    ui->comboBox->addItem("^([A-Z0-9a-z._-]+)(\\.[A-Z0-9a-z._-]+)*@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}(\\.[A-Za-z]{2,4})*$");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QString patron = ui->comboBox->itemText(ui->comboBox->currentIndex());

    QRegularExpression regex(patron);

    QString analizar = ui->lineEdit->text();

    QRegularExpressionMatch match = regex.match(analizar);

    bool coincidencia = match.hasMatch();

    if (coincidencia) {
        ui->labelResultado->setText("EXPRESIÓN VÁLIDA");
    } else {
        ui->labelResultado->setText("EXPRESIÓN NO VÁLIDA");
    }
}
