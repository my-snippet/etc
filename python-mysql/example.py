import pymysql.cursors
import os


PY_MYSQL_USER = os.environ.get('PY_MYSQL_USER')
PY_MYSQL_PASSWORD = os.environ.get('PY_MYSQL_PASSWORD')
PY_MYSQL_DB = 'pymysql'

connection = pymysql.connect(host='localhost',
                             user=PY_MYSQL_USER,
                             password=PY_MYSQL_PASSWORD,
                             db=PY_MYSQL_DB,
                             charset='utf8mb4',
                             cursorclass=pymysql.cursors.DictCursor)

try:
    with connection.cursor() as cursor:
        # Create a new record
        sql = "INSERT INTO `users` (`email`, `password`) VALUES (%s, %s)"
        cursor.execute(sql, ('webmaster@python.org', 'very-secret'))

    # connection is not autocommit by default. So you must commit to save
    # your changes.
    connection.commit()

    with connection.cursor() as cursor:
        # Read a single record
        sql = "SELECT `id`, `password` FROM `users` WHERE `email`=%s"
        cursor.execute(sql, ('webmaster@python.org',))
        result = cursor.fetchone()
        print(result)
finally:
    connection.close()