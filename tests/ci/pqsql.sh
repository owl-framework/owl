#!/bin/sh
psql -U postgres -c 'create database owl_test;'
psql -U postgres -d lynx_test -f tests/schemas/pqsql/dump.sql
