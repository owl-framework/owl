#!/bin/sh
psql -U postgres -c 'create database owl_test;'
psql -U postgres -d owl_test -f tests/schemas/pgsql/dump.sql
