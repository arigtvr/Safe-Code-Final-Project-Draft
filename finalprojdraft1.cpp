#include <iostream>
#include <map>
#include <string>

class EmergencyService {
public:
    void addAction(int number, const std::string& action) {
        actions[number] = action;
    }

    void displayChoices() {
        std::cout << "1. Physical Abuse\n"
                  << "2. Hate Speech\n"
                  << "3. Bullying/Stalking\n"
                  << "4. Threatening/Blockmails\n"
                  << "Enter your choice: ";
    }

    void callAction(int number) {
        if (actions.find(number) != actions.end()) {
            std::cout << "Redirecting: " << actions[number] << std::endl;

            displaySeverityLevels();

            // Get user input for severity level
            int severity;
            std::cin >> severity;

            // Handle severity level
            handleSeverity(severity);
        } else {
            std::cout << "Invalid choice: " << number << ". Please try again.\n";
            displayChoices();
            std::cin >> number;
            callAction(number);
        }
    }

    void displaySeverityLevels() {
        std::cout << "1. Low\n"
                  << "2. Moderate\n"
                  << "3. Critical\n"
                  << "Enter your choice: ";
    }

    void handleSeverity(int number) {
        if (number >= 1 && number <= 3) {
            std::cout << "Reporting severity level: " << number << std::endl;
        } else {
            std::cout << "Invalid severity level: " << number << ". Please try again.\n";
            displaySeverityLevels();
            std::cin >> number;
            handleSeverity(number);
        }
    }

private:
    std::map<int, std::string> actions;
};

int main() {
    EmergencyService emergencyService;

    // Add actions
    emergencyService.addAction(1, "Contacting WVSU-CICT Women's Desk for physical abuse");
    emergencyService.addAction(2, "Contacting WVSU-CICT Women's Desk for hate speech");
    emergencyService.addAction(3, "Contacting WVSU-CICT Women's Desk for bullying/stalking");
    emergencyService.addAction(4, "Contacting WVSU-CICT Women's Desk for threatening/blockmails");

    // Display choices
    emergencyService.displayChoices();

    // Get user input
    int choice;
    std::cin >> choice;

    // Call the corresponding action
    emergencyService.callAction(choice);

    return 0;
}
