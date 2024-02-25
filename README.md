# TheWeekendProjects
## Objective
Some projects of mine are too small to have a whole repository for each one, so I decided to put them all in one repository.

All of the projects in this repository were made in just a few hours (about 2-4 hours), usually made in one weekend.

## List of projects
So far, this repository contains the following projects:
- Password Generator: creates random password, based on a set of rules. Made in C.

## Password Generator
### Description
C program that generates random password, based on a set of rules.

The password library creates the random password. The main.c file defines the rules I wanted (you can very easily change them in this file).

### How to use
Just like most C projects, just run "make" on terminal. The binary is called "main", and you can execute it with "./main".

### Rules
These are the rules I decided (based on what I consider to be a strong password):
- Length: the password should be at least 4 characters long, with a recommended minimum length of 12;
- Characters: if the password is not completely numerical, the quantity of special, upper and numerical characters should each be between 1 and 25% of the length of the password. The exact quantity is choosen randomly. The remaining characters are lower case characters.
