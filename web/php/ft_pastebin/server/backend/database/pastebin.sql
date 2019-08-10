SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

--
-- Databatse: `pastebin`
--

-- --------------------------------------------------------

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

COMMIT;
