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
#define CHECK_UPDATED_WAIT  4500
#define CHECK_LOCATION  3000
#define CHECK_TEMPERATURE 15000

#define DEVICE_QUERY_EXECUTE    true
#define POLL_STATUS_EXECUTE  true
#define CHECK_LOCATION_EXECUTE  true
#define CHECK_TEMPERATURE_EXECUTE true

#define SERIAL_TIMEOUT  500

#endif // DEFAULTS_H
