C:\tools\mysql\bin\mysql.exe -uroot -e 'create database owl_test charset=utf8 collate=utf8_unicode_ci;'
C:\tools\mysql\bin\mysql.exe -uroot owl_test < ./tests/schemas/mysql/dump.sql
