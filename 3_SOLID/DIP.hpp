//This is low level class
class MessggeService {
public:
  void sendNotification(const std::string& message) {
    // Code to send notification
    std::cout << "Notification sent: " << message << std::endl;
  }
};
// this is high level class
// it is directly dependent on low level class which voilates the Dependency Inversion Principle (DIP)
// shows the tight coupling between high level and low level class
class NoficationService {
   MessggeService* messageService;
public:
    NoficationService(MessggeService* service) : messageService(service) {}

    void notify(const std::string& message) {
        messageService->sendNotification(message);
    }
};


int main() {
    MessggeService messageService;
    NoficationService notificationService(&messageService);

    notificationService.notify("Hello, World!");

    return 0;
}

// To fix this, we can use an interface or abstract class to decouple the high-level and low-level classes.
// This way, the high-level class depends on an abstraction rather than a concrete implementation.
// This allows us to change the low-level class without affecting the high-level class.


class IMessageService {
public:
    virtual void sendNotification(const std::string& message) = 0;
    virtual ~IMessageService() {}
};
class MessageService : public IMessageService {
public:
    void sendNotification(const std::string& message) override {
        // Code to send notification
        std::cout << "Notification sent: " << message << std::endl;
    }
};
class NotificationService {
    IMessageService* messageService;
public: 
    NotificationService(IMessageService* service) : messageService(service) {}

    void notify(const std::string& message) {
        messageService->sendNotification(message);
    }
};
int main() {
    MessageService messageService;
    NotificationService notificationService(&messageService);

    notificationService.notify("Hello, World!");

    return 0;
}