#include <iostream>
#include <mysql/mysql.h>

using namespace std;

/*
 * [CLASS] Process
 */
class Proc
{
    const char *MY_HOSTNAME;
    const char *MY_DATABASE;
    const char *MY_USERNAME;
    const char *MY_PASSWORD;
    const char *MY_SOCKET;
    enum
    {
        MY_PORT_NO = 3306,
        MY_OPT = 0
    };
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

  public:
    Proc();          // Constructor
    bool execMain(); // Main Process
};

/*
 * Proc - Constructor
 */
Proc::Proc()
{
    // Initialize constants
    MY_HOSTNAME = "localhost";
    MY_DATABASE = "test";
    MY_USERNAME = "user";
    MY_PASSWORD = "pass";
    MY_SOCKET = NULL;
}

/*
 * Main Process
 */
bool Proc::execMain()
{
    try
    {
        // Format a MySQL object
        conn = mysql_init(NULL);

        // Establish a MySQL connection
        if (!mysql_real_connect(
                conn,
                MY_HOSTNAME, MY_USERNAME,
                MY_PASSWORD, MY_DATABASE,
                MY_PORT_NO, MY_SOCKET, MY_OPT))
        {
            cerr << mysql_error(conn) << endl;
            return false;
        }

        // Execute a sql statement
        if (mysql_query(conn, "SHOW TABLES"))
        {
            cerr << mysql_error(conn) << endl;
            return false;
        }

        // Get a result set
        res = mysql_use_result(conn);

        // Fetch a result set
        cout << "* MySQL - SHOW TABLES in `"
             << MY_DATABASE << "`" << endl;
        while ((row = mysql_fetch_row(res)) != NULL)
            cout << row[0] << endl;

        // Release memories
        mysql_free_result(res);

        // Close a MySQL connection
        mysql_close(conn);
    }
    catch (char *e)
    {
        cerr << "[EXCEPTION] " << e << endl;
        return false;
    }
    return true;
}

/*
 * Execution
 */
int main()
{
    try
    {
        Proc objMain;
        bool bRet = objMain.execMain();
        if (!bRet)
            cout << "ERROR!" << endl;
    }
    catch (char *e)
    {
        cerr << "[EXCEPTION] " << e << endl;
        return 1;
    }
    return 0;
}