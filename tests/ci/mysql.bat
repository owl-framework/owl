mysqladmin --host=localhost --user=root create owl_test
mysql -uroot owl_test < ./tests/schemas/mysql/dump.sql
