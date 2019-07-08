#include <iostream>
#include <windows.h>
#include <winsock.h>
#include <mysql.h>


using namespace std;

int main()
{

    MYSQL* conn; //puntero conexion
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn=mysql_init(0); //inicializar puntero
    int qstate;

    //conectar a bd
    conn=mysql_real_connect(conn,"localhost","root","","productos",3306,NULL,0);


    if(conn)
    {
        cout<<"Conectado";

        qstate=mysql_query(conn,"select * from productos");

        if(!qstate)
        {
            res=mysql_store_result(conn);

            while((row=mysql_fetch_row(res))){
                cout<<"Id: "<<row[0]<<" Descripcion: "<<row[1]<< " Pu: "<<row[2]<<endl;
            }
        }
        else
        {
        cout<<"Error de datos";
        }
    }
    else
    {
        cout<<"Error de conexion";
    }





}
