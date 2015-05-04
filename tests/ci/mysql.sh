#!/bin/sh
mysql -uroot -e 'create database owl_test charset=utf8 collate=utf8_unicode_ci;'
mysql -uroot lynx_test < ./tests/schemas/mysql/dump.sql
