//Isaac Opata
//June 26, 2024
//Structred Data
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_OF_SPEAKERS = 10; // Define the number of speakers

// Define a structure to hold speaker information
struct Speaker
{
    string name, phone, topic;
    double fee;
};

// Function prototypes
void getInfo(Speaker&);
void showInfo(const Speaker&);
void changeInfo(Speaker&);
void displayAll(const Speaker[], int);

int main()
{
    Speaker speakers[NUM_OF_SPEAKERS]; // Array to store speaker information
    int choice; // Variable to store user menu choice
    int speakerIndex; // Variable to store the index of the speaker

    // Loop to display the menu and get user input
    do
    {
        // Display menu options
        cout << "\n1. Enter new speaker information\n";
        cout << "2. Change the information for a speaker\n";
        cout << "3. Display all speaker information\n";
        cout << "4. Exit\n\n";

        // Get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate user choice
        while (choice < 1 || choice > 4)
        {
            cout << "Invalid choice. Check and reenter.\n";
            cin >> choice;
        }

        // Switch statement to handle user choice
        switch (choice)
        {
        case 1:
            // Add new speaker information
            cout << "Enter the index of the speaker to add (0-" << NUM_OF_SPEAKERS - 1 << "): ";
            cin >> speakerIndex;
            if (speakerIndex >= 0 && speakerIndex < NUM_OF_SPEAKERS)
            {
                getInfo(speakers[speakerIndex]);
            }
            else
            {
                cout << "Invalid index.\n";
            }
            break;

        case 2:
            // Change existing speaker information
            cout << "Enter the index of the speaker to change (0-" << NUM_OF_SPEAKERS - 1 << "): ";
            cin >> speakerIndex;
            if (speakerIndex >= 0 && speakerIndex < NUM_OF_SPEAKERS)
            {
                changeInfo(speakers[speakerIndex]);
            }
            else
            {
                cout << "Invalid index.\n";
            }
            break;

        case 3:
            // Display all speaker information
            displayAll(speakers, NUM_OF_SPEAKERS);
            break;

        case 4:
            // Exit the program
            cout << "Exiting the program.\n";
            break;
        }
    } while (choice != 4); // Continue until user chooses to exit

    return 0;
}

// Function to get speaker information from user
void getInfo(Speaker& s)
{
    cout << "Enter speaker's name: ";
    cin.ignore(); // Ignore leftover newline character
    getline(cin, s.name);
    cout << "Enter speaker's phone number: ";
    getline(cin, s.phone);
    cout << "Enter speaking topic: ";
    getline(cin, s.topic);
    do {
        cout << "Enter fee required: ";
        cin >> s.fee;
        if (s.fee < 0)
        {
            cout << "Fee cannot be negative. Please reenter.\n";
        }
    } while (s.fee < 0); // Validate fee to ensure it's not negative
}

// Function to display a single speaker's information
void showInfo(const Speaker& s)
{
    cout << "Name: " << s.name << endl;
    cout << "Phone: " << s.phone << endl;
    cout << "Topic: " << s.topic << endl;
    cout << "Fee: $" << fixed << setprecision(2) << s.fee << endl;
}

// Function to change existing speaker information
void changeInfo(Speaker& s)
{
    cout << "Enter new information for the speaker:\n";
    getInfo(s); // Reuse getInfo to update the speaker's information
}

// Function to display information for all speakers
void displayAll(const Speaker speakers[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (!speakers[i].name.empty()) // Only display filled entries
        {
            cout << "\nSpeaker " << i + 1 << " information:\n";
            showInfo(speakers[i]);
        }
    }
}
