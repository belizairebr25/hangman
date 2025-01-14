#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>  // Include MySQL header

int main() {
    // MySQL connection and result variables
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    // Database connection details
    const char *server = "localhost";       // Change to your server address
    const char *user = "root";              // Change to your username
    const char *password = "your_password"; // Change to your password
    const char *database = "your_database"; // Change to your database name

    // Initialize MySQL
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    // Connect to database
    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Execute a simple query
    if (mysql_query(conn, "SELECT * FROM your_table LIMIT 5")) {
        fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Store result
    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Print query result
    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // Clean up
    mysql_free_result(res);
    mysql_close(conn);

    printf("Database query executed successfully.\n");
    return EXIT_SUCCESS;
}
