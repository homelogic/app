#ifndef DEFAULTS_H
#define DEFAULTS_H

#define DB_HOST     "192.168.1.150"
#define DB_PORT 3306
#define DB_DBNAME   "homelogic"
#define DB_USER     "homelogic"
#define DB_PASSWD   "homelogic"
#define DB_DRIVER "QMYSQL"

/* Define QTimer in ms before interrupt signal */
#define DEVICE_QUERY_WAIT   1500
#define CHECK_UPDATED_WAIT  4000

#define DEVICE_QUERY_EXECUTE    true
#define POLL_STATUS_EXECUTE   true

#endif // DEFAULTS_H
