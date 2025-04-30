
#pragma once

class User
{
private:
    std::string mName;
    std::string mEmail;
public:
    User(const std::string& name, const std::string& email);
    void savetoDatabase() const;
    void sendEmailNotification() const;
};
// above is the User class definition which voilates the Single Responsibility Principle (SRP)
// because it has two reasons to change: if the database changes or if the email service changes.
// The User class should only be responsible for user-related data and behavior.
// To fix this, we can create separate classes for database and email notification.
// The User class should only be responsible for user-related data and behavior.
// The Database class should be responsible for saving user data to the database.
// The EmailNotification class should be responsible for sending email notifications.

// code after refactoring

class User_SRP
{
private:
    std::string mName;
    std::string mEmail;
public:
    User(const std::string& name, const std::string& email)
        : mName(name), mEmail(email) {}
};

class Database
{
public:
    void saveUser(const User& user) const
    
};

class EmailNotification
{   
public:
    void sendEmail(const User& user) const
    {
        // code to send email notification
    }
};
