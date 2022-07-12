
drop table if exists users;
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name TEXT
);

drop table if exists profiles;
CREATE TABLE profiles (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    bio TEXT
);

drop table if exists posts;
CREATE TABLE posts (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    content TEXT
);

drop table if exists clans;
CREATE TABLE clans (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name TEXT
);

drop table if exists clans_users;
CREATE TABLE clans_users (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    clan_id INT
);

