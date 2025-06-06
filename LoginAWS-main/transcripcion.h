#ifndef TRANSCRIPCION_H
#define TRANSCRIPCION_H

#include <QWidget>

class Transcripcion : public QWidget
{
    Q_OBJECT

public:
    explicit Transcripcion(const QString &token, QWidget *parent = nullptr);
    void enviarAudio(const QString &rutaAudio);

signals:
    void textoTranscripto(const QString &texto);

private:
    QString m_token;
};

#endif // TRANSCRIPCION_H
