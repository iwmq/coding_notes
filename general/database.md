
Let's Build a Simple Database
----
A step-by-step tutorial on how to implement a simple Sqlite-like database
system. I enjoy the data struct like B/B+ tree, and this is a very good and
practical introduction for sush an important concepts.


See https://cstack.github.io/db_tutorial/.

Returning clause
----

The following are examples of using `RETURNING` clause on some database systems.

For Postgresql:
```
create table robots (id serial primary key, name varchar(20));
insert into robots (name) values ('Big doge'), ('peppy') returning *;
```

For Sqlite3 (3.35+):
```
create table robots (id integer primary key autoincrement, name varchar(20));
insert into robots (name) values ('Big doge'), ('peppy') returning *;
```

For MariaDB (10.5+):
```
create table robots (id integer not null primary key auto_increment, name varchar(20));
insert into robots (name) values ('diego') returning *;
```

This feature is tot implemented on MySQL 8.0.

The `RETURNING` clause is important for using Django ORM's `bulk_create` method.
If the backend database system does not support it, `bulk_create` will not set `pk`
of creted objects.