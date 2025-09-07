Version: 1.0
Date: 25-08-2025
Author: Xavier Berthiaume

# Introduction

## Purpose
This document describes the functional and non-functional requirements for Lot Manager. The purpose of this software is to provide factory supervisors with a centralized, reliable, and intuitive tool to manage the location, inventory, and specific settings (e.g., reefer temperature) of all vehicles (cars, trucks, semi-trailers) within a storage lot. This SRS serves as a agreement between the developers and the stakeholders on the system's capabilities.


## Project Scope
Lot Manager will be a desktop application developed in C++ using the Qt framework. It will allow users to:
- Digitally map the physical lot layout.

- Create and delete lot positions.

- Create, read, update, and delete records of vehicles and their positions.

- Manage detailed inventories for each vehicle.

- Control and monitor specific settings for specialized vehicles (e.g., reefer temperature).

- Ensure high data integrity to prevent operational errors.

- Keep a record of individual vehicle moves.

- User authentication and role-based access control.

- Networked access to the application and its data.

The following are out of project scope:
- Real-time GPS tracking of vehicles (positioning is manually updated by users/staff).

- Integration with physical sensors or IoT devices (initial version).

- Financial accounting or billing modules.

- Data backups or data redundancy.


## Definitions, Acronyms, and Abbreviations
- *Vehicle*: A general term for any unit on the lot (Car, Truck, Semi-Trailer).

- *Reefer*: A refrigerated semi-trailer with temperature control capabilities.

- *Lot*: The physical yard area where vehicles are stored.

- *Supervisor*: The primary user of the system (e.g., Factory Supervisor).

- *Staff*: Personnel who execute moves on the lot based on instructions from the supervisor using the Lot Manager software.

- *Qt*: A cross-platform application framework used for GUI development.


## References
Qt Framework Documentation: https://www.qt.io/


# Overview

## User Needs
Factory supervisors need to quickly locate specific vehicles, verify their contents and settings (like temperature), and instruct staff to move them without physically inspecting each one, saving time and reducing errors in a high-volume environment.


## User Characteristics
Primary User (Supervisor): Technically proficient, needs a highly reliable and accurate system. Their primary goal is efficiency and data integrity. They are not software developers but are comfortable with complex operational software.


## Operating Environment
- Software: Microsoft Windows 10/11

- Hardware: Standard desktop or laptop computer.

- Framework: C++17 (or newer), Qt 6.x.


## Design and Implementation Constraints
- The application must be developed in C++ using the Qt framework.

- The data must be persisted to a local, single-user database (e.g., SQLite for simplicity in V1.0).

- The user interface must be intuitive and require minimal training


# Functional Requirements

## 1. Lot Layout Management (FR1)
    FR1.1: The system shall allow the user to define a visual representation of the physical lot.

    FR1.2: The user shall be able to manually place spots within the lot.

## 2. Vehicle Management (FR2)
    FR2.1: The system shall support one vehicle type: Semi-Trailer.

    FR2.2: For all vehicles, the system shall store:

        Unique ID (Van # for semi-trailers and plate numbers for cars and trucks)

        Type

        Current lot location (which spot)

        Creation date/time (When the vehicle entered the lot)

        Last move date/time

        Location on the lot

        General notes

    FR2.3: The user shall be able to Create, View, Edit, and Delete vehicle records.

    FR2.4: The user shall be able to Move a vehicle from one spot to another by updating its location property.

##  3. Inventory Management (FR3)
    FR3.1: The system shall allow the user to manage an inventory list for each vehicle.

    FR3.2: For each inventory item, the system shall store:

        Item name/description

        Quantity

    FR3.3: The user shall be able to Add, Edit, and Remove items from a vehicle's inventory.

## 4. Specialized Settings Management (FR4)
    FR4.1: The system shall allow the user to mark a Semi-Trailer with a Reefer.

    FR4.2: For a Reefer, the system shall store a Last Checked Temperature setting and a Target Temperature setting.

    FR4.3: The user shall be able to view and modify the Target Temperature for a Reefer.

## 5. Data Presentation and Search (FR5)
    FR5.1: The system shall provide a main view showing the lot layout with vehicles in their spots.

    FR5.2: The user shall be able to select a spot to view details of the vehicle located there.

    FR5.3: The user shall be able to search for a vehicle by its unique ID.

    FR5.4: The user shall be able to filter the lot view to show only Reefers.

## 6. History Log (FR6)
    FR6.1: The system shall maintain a persistent, immutable log of all vehicle move operations.

    FR6.2: These log files shall be readable by the application, the functionality accessed through a sub-menu.

    FR6.3: The data from the log should be human readable, preferably translatable.

## 7. Internationalization (I18n) and Localization (L10n) (FR7)
    FR7.1: All user-facing text strings in the GUI shall be externalized to resource files.

    FR7.2: The application shall dynamically load the appropriate language (English or French) based on the system locale or a user preference setting at startup.

## 8. Network accessibility (FR8)
    FR8.1: The software can be either in network mode or in local mode, which refers to where the data will be fetched from.

    FR8.2: Locks will prevent the same vehicle from being modified by two users at the same time.

    FR8.3: All network communications must be encrypted.

## 9. Multi-user functionality (FR9)
    FR9.1: All users will have a username, user code and pin code to access their profile.

    FR9.2: 2 user roles exist, one with edit privileges, one without (observer role).


# Non-Functional Requirements

## Multilingual Support
    The software, as well as any accompanying documentation, will be freely available in both the English and French languages.

## Reliability
    The system shall be highly stable with no unplanned crashes during standard operation.

    Data corruption must be prevented. The application shall handle file I/O and database errors gracefully.

## Data Integrity
    This is of utmost importance.

    The system shall not allow two vehicles to be placed in the same spot simultaneously.

    All critical actions (Delete, Move) shall require user confirmation.

    Data shall be auto-saved frequently to prevent loss.

## Usability
    The GUI shall be designed using Qt's standard widgets for a familiar look and feel.

    Common tasks (e.g., moving a vehicle) shall be achievable in 3 clicks or less.

    The lot view shall be clear and uncluttered, using color-coding (e.g., for Reefer status).

## Performance
    The interface shall remain responsive when managing a lot of 200+ vehicles.

    Loading the main lot view and searching for a vehicle shall be near-instantaneous.

    The software will be capable of handling at least 20 concurrent users.

## Supportability
    The code shall be well-commented and adhere to modern C++ best practices.

    The database schema shall be versioned and documented to allow for future migrations.

