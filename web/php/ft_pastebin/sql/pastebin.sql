SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

--
-- Databatse: `pastebin`
--

-- --------------------------------------------------------

DROP DATABASE IF EXISTS `pastebin`;
CREATE DATABASE `pastebin`;
USE `pastebin`;

--
-- Table structure for table `links`
--

DROP TABLE IF EXISTS `links`;

CREATE TABLE `links` (
    `id` INT(11) AUTO_INCREMENT PRIMARY KEY,
    `title` VARCHAR(255) NOT NULL,
    `author` VARCHAR(255) NOT NULL,
    `language` VARCHAR(255) NOT NULL,
    `count` INT(11) DEFAULT 10,
    `expire` DATETIME DEFAULT NOW(),
    `private` TINYINT(1) DEFAULT 0,
    `text` TEXT NOT NULL,
	`date` DATETIME DEFAULT NOW()
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `admins`
--

DROP TABLE IF EXISTS `admins`;

CREATE TABLE `admins` (
    `id` INT(11) AUTO_INCREMENT PRIMARY KEY,
    `login` VARCHAR(255) NOT NULL,
    `pass` VARCHAR(255) NOT NULL,
	`date` DATETIME DEFAULT NOW(),
    UNIQUE (id,login)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `admins` (login, pass) VALUES ('admin', 'admintest');

COMMIT;
