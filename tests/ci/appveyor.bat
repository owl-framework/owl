mysqladmin --host=localhost --user=root --password=Password12! create owl_test
mysql -uroot --password=Password12! owl_test < ./tests/schemas/mysql/dump.sql
