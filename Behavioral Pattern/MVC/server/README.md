# How to run this project

# Step One
install mysql or mariadb in your OS :<br>
https://dev.mysql.com/doc/mysql-installation-excerpt/5.7/en/<br>
https://mariadb.com/downloads/<br>

example commands for UBUNTU OS:<br>
sudo apt update<br>
sudo apt install mysql-server<br>
sudo mysql_secure_installation<br>
sudo mysql<br>
mysql> SELECT user,authentication_string,plugin,host FROM mysql.user;<br>
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'enter-your-root-password';<br>
mysql> FLUSH PRIVILEGES;<br>
mysql> SELECT user,authentication_string,plugin,host FROM mysql.user;<br>
mysql> exit<br>

# Step Two
login into mysql with ypur root user and password, then create the deaf user and database with following commands:<br>
mysql -u root -p<br>
mysql> CREATE DATABASE DB;<br>
mysql> CREATE USER 'DBusername'@'localhost' IDENTIFIED BY 'copy-password-from-application.properties';<br>
mysql> GRANT ALL PRIVILEGES ON DB.* TO 'DBusername'@'localhost';<br>

# Step Three
find this line code "spring.jpa.hibernate.ddl-auto = none" from application.properties file and change none to create value<br>
spring.jpa.hibernate.ddl-auto = create<br>
then go to root of project and run following command:<br>
mvn clean package<br>
then change spring.jpa.hibernate.ddl-auto value from create to none value<br>

# Final Step
you can run application from intellij IDEA or spring boot.<br>
Intellij IDEA:<br>
find DataLoggerApplication.java and right click this file and choose Run<br>
Spring Boot:<br>
go to root of project in terminal and run mvn spring-boot:run

