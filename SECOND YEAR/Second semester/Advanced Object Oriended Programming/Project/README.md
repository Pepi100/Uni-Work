# <center> Management of an audio online store </center>

### <center> This project is an application for the management of an online store that sells audio products like headphones and microphones. </center>

#

### This application implements the following classes:

-  <b> Model classes</b>:
    
    These classes are the primary objects used in te application. They each correspond to a table in the database. 

    - <b> User </b> - <i> interface class</i>.

        - <b> Employee </b> - <i> extends<b> User </b></i>.

        - <b> Customer </b> - <i> extends<b> User </b></i>.

    - <b> Product </b> - <i> interface class</i>.

        - <b> Headphones </b> - <i> extends<b> Product </b></i>.

        - <b> Microphone </b> - <i> extends<b> Product </b></i>.

    - <b> Address </b>

    - <b> Manufacturer </b>

- <b> Service classes</b>:

    - <b> Menu </b> - displays options and menus.

    - <b> Service </b> - takes input from Menu class and send corresponding signal to <b> DatabaseConnection</b>.

    - <b> DatabaseConnection</b> - manages querys on the database.

#
### What I learned?
 
 - [x] How to build a database that matches my application`s needs.

 - [x] The importance of configuring the correct contraints when creating tables.

 - [x] Operating a database using JDBC.

 - [x] Java inheritance and composition.

 - [x] Working with interface and singleton classes. 