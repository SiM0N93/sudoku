-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Erstellungszeit: 10. Mai 2014 um 12:36
-- Server Version: 5.6.16
-- PHP-Version: 5.5.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `sudoku`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `accounts`
--

CREATE TABLE IF NOT EXISTS `accounts` (
  `id` smallint(4) unsigned NOT NULL AUTO_INCREMENT,
  `first_name` varchar(25) COLLATE utf8_unicode_ci NOT NULL,
  `last_name` varchar(25) COLLATE utf8_unicode_ci NOT NULL,
  `username` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `window_width` smallint(5) unsigned DEFAULT 0,
  `window_height` smallint(5) unsigned DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=3 ;

--
-- Daten für Tabelle `accounts`
--

INSERT INTO `accounts` (`id`, `first_name`, `last_name`, `username`, `password`) VALUES
(1, 'Michael', 'Schneider', 'ms', '098f6bcd4621d373cade4e832627b4f6'),
(2, 'Dario', 'Tilgner', 'dario', '827ccb0eea8a706c4c34a16891f84e7b');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `points`
--

CREATE TABLE IF NOT EXISTS `points` (
  `id` mediumint(8) unsigned NOT NULL AUTO_INCREMENT,
  `userid` mediumint(8) unsigned NOT NULL,
  `points` mediumint(8) unsigned NOT NULL,
  `time` smallint(5) unsigned NOT NULL,
  `difficulty` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `userid` (`userid`,`points`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

--
-- Daten für Tabelle `points`
--

INSERT INTO `points` (`id`, `userid`, `points`, `time`, `difficulty`) VALUES
(1, 2, 300, 50, NULL),
(2, 1, 500, 100, NULL),
(3, 2, 1000, 150, NULL),
(4, 1, 1337, 42, NULL);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
