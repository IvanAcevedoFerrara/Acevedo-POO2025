    #ifndef ADMINDB_H
    #define ADMINDB_H

    #include <QString>
    #include <QSqlDatabase>

    class AdminDB {
    private:
        static AdminDB *instancia;
        QSqlDatabase db;

        AdminDB();

    public:
        static AdminDB *getInstancia();
        void conectar();
        bool validarUsuario(const QString &nombre, const QString &password, QString &ultimoIngreso);
        void actualizarUltimoIngreso(const QString &nombre);
    };

    #endif // ADMINDB_H
