-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 09, 2024 at 11:09 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `melodymaven`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `AdminID` int(30) NOT NULL,
  `AdminName` varchar(30) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Password` varchar(30) NOT NULL,
  `Phone` int(30) NOT NULL,
  `Avatar` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`AdminID`, `AdminName`, `Email`, `Password`, `Phone`, `Avatar`) VALUES
(2305381, 'LEE WEN BIN', 'adminlee@gmail.com', 'Adminlee123@', 128274394, '../avatars/present-continuous-tense-worksheet.jpg'),
(2305419, 'Rafael Hon Zhong Hang', 'adminrafael@gmail.com', 'Adminrafael123@', 138485303, NULL),
(2305449, 'Sin Wei Hong', 'adminsin@gmail.com', 'Adminsin123@', 12948363, NULL),
(2305514, 'Cheon Jie Han', 'admincheon@gmail.com', 'Admincheon123@', 182754422, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `booking`
--

CREATE TABLE `booking` (
  `bookingID` int(11) NOT NULL,
  `ticketID` int(10) NOT NULL,
  `bookingDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `booking`
--

INSERT INTO `booking` (`bookingID`, `ticketID`, `bookingDate`) VALUES
(1, 1, '2024-05-10'),
(2, 2, '2024-06-01'),
(3, 3, '2024-08-01'),
(4, 4, '2024-07-01'),
(36, 45, '2024-05-09');

-- --------------------------------------------------------

--
-- Table structure for table `event`
--

CREATE TABLE `event` (
  `EventID` int(11) NOT NULL,
  `EventName` varchar(30) NOT NULL,
  `EventDate` date NOT NULL,
  `EventLocation` varchar(255) NOT NULL,
  `EventPrice` varchar(30) NOT NULL,
  `EventCapacity` int(255) NOT NULL,
  `EventTime` varchar(255) NOT NULL,
  `status` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `event`
--

INSERT INTO `event` (`EventID`, `EventName`, `EventDate`, `EventLocation`, `EventPrice`, `EventCapacity`, `EventTime`, `status`) VALUES
(1, 'MMS CONCERT', '2024-05-09', 'Central Park,New York', 'FREE', 100, '10::00 am - 11:00 am', 'running'),
(2, 'Melody Maven Society Run (MMS)', '2024-05-16', 'Central Park,New York', 'RM40', 70, '10:00 am - 11:00 pm', 'running'),
(3, 'MMS Music Competition', '2024-05-06', 'Central Park,New York', 'FREE', 50, '12:00 PM - 4:00 PM', 'running'),
(4, 'MMS Music Lecture', '2024-05-17', 'Central Park,New York', 'RM30', 70, '7:00 pm - 9:00 pm', 'running'),
(5, '阿斯顿1', '2024-05-10', 'KEPONG', '100011', 20011, '08:00 AM - 08:00 AM', 'COMMING SOON');

-- --------------------------------------------------------

--
-- Table structure for table `ticket`
--

CREATE TABLE `ticket` (
  `ticketID` int(11) NOT NULL,
  `EventID` int(10) NOT NULL,
  `UserID` int(10) NOT NULL,
  `status` varchar(20) NOT NULL,
  `image_url` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `ticket`
--

INSERT INTO `ticket` (`ticketID`, `EventID`, `UserID`, `status`, `image_url`) VALUES
(1, 1, 1, 'Booked', NULL),
(2, 2, 2, 'Booked', '663bbad45d02a.jpg'),
(3, 3, 4, 'Booked', NULL),
(4, 3, 4, 'Booked', NULL),
(45, 2, 2, 'Booked', 'uploads/663c9159ccbdb.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `UserID` int(11) NOT NULL,
  `UserName` varchar(255) DEFAULT NULL,
  `UserIC` varchar(20) DEFAULT NULL,
  `UserPassword` varchar(255) DEFAULT NULL,
  `UserEmail` varchar(255) DEFAULT NULL,
  `UserComment` varchar(255) DEFAULT NULL,
  `UserPhone` varchar(20) DEFAULT NULL,
  `Avatar` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`UserID`, `UserName`, `UserIC`, `UserPassword`, `UserEmail`, `UserComment`, `UserPhone`, `Avatar`) VALUES
(1, 'Rafael', '050506141321', 'rafael@123', 'rafael@gmail.com', NULL, '0123457789', NULL),
(2, 'Cheon Jie Han', '0387654321', 'jiehan@456', 'jiehan@gmail.com', NULL, '0123456789', '../avatars/silver-wolf-and-kafka-honkai-star-rail-thumb.jpg'),
(3, 'Sin Wei Hong', '0598654321', 'weihong@456', 'weihong@gmail.com', NULL, '0127456789', NULL),
(4, 'Lee Wen BIn', '040801142111', 'wenbin@123', 'wenbin@gmail.com', NULL, '0128882789', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `user_event_details`
--

CREATE TABLE `user_event_details` (
  `ID` int(11) NOT NULL,
  `UserID` int(11) DEFAULT NULL,
  `EventID` int(11) DEFAULT NULL,
  `EventUserName` varchar(255) DEFAULT NULL,
  `EventUserIC` varchar(20) DEFAULT NULL,
  `EventEmail` varchar(40) NOT NULL,
  `EventPhone` varchar(40) NOT NULL,
  `ticketID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `user_event_details`
--

INSERT INTO `user_event_details` (`ID`, `UserID`, `EventID`, `EventUserName`, `EventUserIC`, `EventEmail`, `EventPhone`, `ticketID`) VALUES
(1, 1, 1, 'RAFAEL', '01230912830', 'rafael@gmail.com', '01234567890', 1),
(2, 2, 2, 'Cheon Jie Han', '0987654321', 'jiehan@gmail.com', '01233301923', 2),
(3, 3, 3, 'SIN WEI HONG', '050912309812', 'weihong@gmail.com', '01234567890', 3),
(4, 4, 4, 'LEE WEN BIN', '0987654321', 'wenbin@gmail.com', '01233301923', 4),
(48, 2, 2, 'LEE WEN BIN', '040701141321', 'hello@gmail.com', '0128022823', 45);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`AdminID`);

--
-- Indexes for table `booking`
--
ALTER TABLE `booking`
  ADD PRIMARY KEY (`bookingID`),
  ADD KEY `FK_ticketID` (`ticketID`);

--
-- Indexes for table `event`
--
ALTER TABLE `event`
  ADD PRIMARY KEY (`EventID`);

--
-- Indexes for table `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`ticketID`),
  ADD KEY `FK_EventID` (`EventID`),
  ADD KEY `FK_UserID` (`UserID`),
  ADD KEY `idx_ticketID` (`ticketID`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`UserID`);

--
-- Indexes for table `user_event_details`
--
ALTER TABLE `user_event_details`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `UserID` (`UserID`),
  ADD KEY `EventID` (`EventID`),
  ADD KEY `FK_ticketID_user_event_details` (`ticketID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `booking`
--
ALTER TABLE `booking`
  MODIFY `bookingID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT for table `event`
--
ALTER TABLE `event`
  MODIFY `EventID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=57;

--
-- AUTO_INCREMENT for table `ticket`
--
ALTER TABLE `ticket`
  MODIFY `ticketID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=46;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `UserID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `user_event_details`
--
ALTER TABLE `user_event_details`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=49;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `booking`
--
ALTER TABLE `booking`
  ADD CONSTRAINT `FK_ticketID` FOREIGN KEY (`ticketID`) REFERENCES `ticket` (`ticketID`);

--
-- Constraints for table `ticket`
--
ALTER TABLE `ticket`
  ADD CONSTRAINT `FK_EventID` FOREIGN KEY (`EventID`) REFERENCES `event` (`EventID`),
  ADD CONSTRAINT `FK_UserID` FOREIGN KEY (`UserID`) REFERENCES `user` (`UserID`);

--
-- Constraints for table `user_event_details`
--
ALTER TABLE `user_event_details`
  ADD CONSTRAINT `FK_ticketID_user_event_details` FOREIGN KEY (`ticketID`) REFERENCES `ticket` (`ticketID`),
  ADD CONSTRAINT `user_event_details_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `user` (`UserID`),
  ADD CONSTRAINT `user_event_details_ibfk_2` FOREIGN KEY (`EventID`) REFERENCES `event` (`EventID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
