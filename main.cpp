
// * 
 * @brief Entry point for the Chatbot application.
 *
 * This file contains the main function which initializes the Chatbot,
 * takes user input, and processes it until the user types "exit".
 *
 * @details
 * The main function creates an instance of the Chatbot class and enters
 * a loop where it continuously takes user input and generates responses
 * until the user inputs "exit". Upon exiting the loop, a message is
 * printed to indicate that the chatbot is exiting.
 *
 * @return int Returns 0 upon successful execution.



#include "ChatBot_essentials.h"


/**
 * @class Chatbot
 * @brief A simple chatbot class that takes input, processes it, and responds.
 * 
 * The Chatbot class provides methods to take user input, clean the input, and generate a response.
 */

class Chatbot
{
private:
    
public:
    Chatbot();
    ~Chatbot();

    string takeInput();
    string cleanInput(string input);
    void respond(string input);
};

/**
 * @brief Prompts the user for input and returns the entered string.
 * 
 * This function displays a prompt ("You: ") to the user, waits for the user to enter a line of text,
 * and then returns the entered text as a string.
 * 
 * @return std::string The input entered by the user.
 */
string Chatbot::takeInput()
{
    string input;
    cout << "You: ";
    getline(cin, input);
    return input;
}


/**
 * @brief Cleans the input string by converting it to lowercase, removing punctuation, and removing stop words.
 *
 * This function performs the following steps:
 * 1. Converts the entire input string to lowercase.
 * 2. Removes all punctuation characters from the input string.
 * 3. Removes stop words from the input string.
 *
 * @param input The input string to be cleaned.
 * @return A cleaned version of the input string with lowercase letters, no punctuation, and no stop words.
 */
string Chatbot::cleanInput(string input)
{
    // Convert input to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Remove punctuation
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());

    // Remove stop words
    istringstream iss(input);
    string word;
    string cleanInput;
    while (iss >> word)
    {
        if (Chatbot_data::stopWords.find(word) == Chatbot_data::stopWords.end())
        {
            cleanInput += word + " ";
        }
    }

    return cleanInput;
}

/**
 * @brief Responds to user input by matching it with predefined responses or providing a default response.
 * 
 * This function takes a user input string, cleans it, and checks if it matches any predefined responses.
 * If a match is found, it outputs a corresponding response. If no match is found, it outputs a default response.
 * 
 * @param input The user input string to be processed and responded to.
 */
void Chatbot::respond(string input)
{
    string cleanInput = Chatbot::cleanInput(input);

    // Check if input matches any predefined responses
    for (auto const &response : Chatbot_data::responses)
    {
        if (cleanInput.find(response.first) != string::npos)
        {
            cout << "Chatbot: " << response.second[rand() % response.second.size()] << endl;
            return;
        }
    }

    // If no predefined response is found, provide a default response
    cout << "Chatbot: I'm not sure how to respond to that. Can you ask me something else?" << endl;
}


Chatbot::Chatbot()
{
}

Chatbot::~Chatbot()
{
}


/** 
 * @brief Entry point for the Chatbot application.
 *
 * This file contains the main function which initializes the Chatbot,
 * takes user input, and processes it until the user types "exit".
 *
 * @details
 * The main function creates an instance of the Chatbot class and enters
 * a loop where it continuously takes user input and generates responses
 * until the user inputs "exit". Upon exiting the loop, a message is
 * printed to indicate that the chatbot is exiting.
 *
 * @return int Returns 0 upon successful execution.
**/

void typewriterEffect(string message);

int main()
{
    cout<< "Welcome to Chatbot!"<< " Type 'exit' to end the chat.\n"<<endl;

    Chatbot chatbot;
    string input = chatbot.takeInput();

    while (input != "exit")
    {
        typewriterEffect("Generating reply...");
        cout<< "\r";
        chatbot.respond(input);
        cout<<endl;
        input = chatbot.takeInput();
    }

    typewriterEffect("exiting chatbot...\n\n");

    return 0;
}


void typewriterEffect(string message)
{
    int initial_delay = 120;  // Starting delay in milliseconds
    int decrement = 5;        // Reduce delay by 3ms for each character
    int min_delay = 30;       // Minimum delay for typing effect

    for (size_t i = 0; i < message.size(); ++i) {
        // Print the character and flush the output immediately
        cout << message[i] << flush;
        
        // Calculate current delay
        int current_delay = max(initial_delay - static_cast<int>(i) * decrement, min_delay);
        
        // Pause for the calculated delay
        this_thread::sleep_for(chrono::milliseconds(current_delay));
    }
    this_thread::sleep_for(chrono::milliseconds(300));
}



