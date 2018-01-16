-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Client :  127.0.0.1
-- Généré le :  Lun 15 Janvier 2018 à 21:56
-- Version du serveur :  5.7.14
-- Version de PHP :  5.6.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `application`
--

-- --------------------------------------------------------

--
-- Structure de la table `activite`
--

CREATE TABLE `activite` (
  `id` int(11) NOT NULL,
  `ville` varchar(255) NOT NULL,
  `code_postal` char(5) NOT NULL,
  `style` int(11) NOT NULL,
  `type` varchar(255) NOT NULL,
  `date` char(10) NOT NULL,
  `hour` char(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `activite`
--

INSERT INTO `activite` (`id`, `ville`, `code_postal`, `style`, `type`, `date`, `hour`) VALUES
(1, 'Paris', '75000', 1, 'cinema', '19/01/2018', '22:30'),
(2, 'Toulouse', '31000', 2, 'restaurant', '27/01/2018', '23:30'),
(3, 'Lyon', '69000', 1, 'restaurant', '25/01/2018', '14:59'),
(4, 'Cannes', '06400', 0, 'theatre', '13/02/2018', '23:59'),
(5, 'Reims', '51100', 0, 'patinoire', '05/02/2018', '13:20'),
(6, 'Lille', '59000', 0, 'cinema', '12/03/2018', '14:20'),
(7, 'Bordeaux', '33000', 2, 'theatre', '22/03/2018', '07:55'),
(8, 'Creteil', '94028', 1, 'restaurant', '26/03/2018', '14:00'),
(9, 'Marseille', '13001', 2, 'patinoire', '02/04/2018', '13:45');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `activite`
--
ALTER TABLE `activite`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `activite`
--
ALTER TABLE `activite`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
