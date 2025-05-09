/**
 * @file ChatBot_essentials.h
 * @brief This header file contains essential data and configurations for the Chatbot project.
 * 
 * It includes necessary libraries, defines a namespace `Chatbot_data` which contains:
 * - A map of chatbot responses categorized by keywords.
 * - A set of common stop words to be filtered out during text processing.
 * 
 * The responses map provides predefined responses for various user inputs such as greetings, jokes, assistance requests, and more.
 * The stopWords set contains words that are typically filtered out in natural language processing to improve response accuracy.
 * 
 * @namespace Chatbot_data
 * @var std::map<std::string, std::vector<std::string>> responses
 * A map containing predefined responses for various user inputs.
 * 
 * @var std::set<std::string> stopWords
 * A set of common stop words to be filtered out during text processing.
 */

#ifndef CHATBOT_ESSENTIALS_H
#define CHATBOT_ESSENTIALS_H


// myHeaders.h
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <ctime>
#include <thread>     // For std::this_thread::sleep_for
#include <chrono>     // For std::chrono::milliseconds

using namespace std;

namespace Chatbot_data
{
    // Chatbot responses
    map<std::string, vector<std::string> > responses = {
        // Greetings
        {"hello", {"Hi there!", "Hello! How can I assist you today?", "Hey! Nice to see you."}},
        {"hi", {"Hello!", "Hi! How can I help you?", "Greetings!"}},
        {"hey", {"Hey! What's up?", "Hello! How can I assist?", "Hi there!"}},

        // How are you
        {"how you", {"I'm just a bot, but I'm doing great! How about you?", "I'm functioning as expected! How can I help?", "Feeling chatty today. What's on your mind?"}},

        // Name or identity
        {"your name", {"I'm ChatGPT, your friendly assistant.", "You can call me Chatbot.", "I don't have a name, but I'm here to help!"}},
        {"who you", {"I'm a chatbot here to assist you.", "Your friendly virtual assistant.", "I'm just a helpful program."}},

        // Jokes
        {"tell joke", {"Why don't scientists trust atoms? Because they make up everything!", "Why did the scarecrow win an award? Because he was outstanding in his field!", "I would tell you a construction joke, but I'm still working on it."}},
        {"make laugh", {"Why do programmers prefer dark mode? Because light attracts bugs!", "Why was the math book sad? It had too many problems.", "Parallel lines have so much in common… it’s a shame they’ll never meet."}},

        // Help or assistance
        {"help", {"Sure! How can I assist you?", "I'm here to help. What do you need?", "Let me know what you're looking for, and I'll do my best to assist."}},
        {"assist", {"Happy to assist! What can I do for you?", "I can help with anything you need, just ask!", "Your assistant is ready. How can I help?"}},

        // Purpose or capabilities
        {"your purpose", {"I'm here to assist, chat, and make your life easier!", "My purpose is to help you with tasks, answer questions, and keep you company.", "To assist you with anything you need (within reason)!"}},
        {"what can", {"I can chat, tell jokes, and help you with various tasks. What do you need?", "I'm here to assist with information, calculations, and more. Just ask!", "I can do a lot! Try me."}},

        // Gratitude
        {"thank", {"You're welcome!", "No problem! Let me know if there's anything else.", "Happy to help!"}},
        {"thanks", {"No worries!", "You're very welcome!", "Glad I could assist!"}},

        // Goodbye
        {"goodbye", {"Goodbye! Have a great day!", "See you later!", "Take care and come back anytime."}},
        {"bye", {"Bye! Take care!", "See you soon!", "Goodbye and have a wonderful day!"}},

        // Random Facts
        {"tell fact", {"Did you know that honey never spoils? Archaeologists found pots in Egyptian tombs still edible after 3,000 years.", "Octopuses have three hearts! Two pump blood to the gills, and one pumps it to the body.", "Bananas are berries, but strawberries aren't!"}},
        {"interesting", {"Did you know that there are more stars in the universe than grains of sand on Earth?", "Sloths can hold their breath longer than dolphins—up to 40 minutes!", "Sharks existed before trees—they’ve been around for over 400 million years!"}},

        // Weather
        {"weather", {"It's sunny today. Perfect for a walk!", "Looks like it's going to rain. Don't forget your umbrella!", "The weather is chilly. Stay warm!"}},
        {"temperature", {"It's currently 25°C. A lovely day!", "It's 15°C and cloudy. You might need a jacket.", "It's a hot 32°C. Stay hydrated!"}},

        // Time and Date
        {"current time", {"The current time is 3:45 PM.", "It's 10:15 AM. Do you have plans for the morning?", "It's 7:30 PM. Time to relax!"}},
        {"current date", {"Today's date is January 12, 2025.", "It's January 12, 2025. Hope you're having a good day!", "The date today is 12/01/2025."}},

        // Random Questions
        {"who created", {"I was created by OpenAI.", "I'm a product of OpenAI's innovative team.", "OpenAI built me to assist people like you!"}},
        {"are you real", {"I'm as real as the code that runs me!", "I'm a virtual assistant, not a physical being.", "I exist in the digital world, here to help you."}},

        // Motivation
        {"motivate", {"Believe in yourself! You can achieve great things.", "Every step you take gets you closer to your goal.", "Keep going! The best is yet to come."}},
        {"inspire", {"Dream big and work hard to make it happen.", "Success is the result of small efforts repeated daily.", "Every accomplishment starts with the decision to try."}}};

    set<std::string> stopWords = {
        "a", "about", "above", "after", "again", "against", "all", "am", "an", "and", "any", "are", "aren't", "as", "at",
        "be", "because", "been", "before", "being", "below", "between", "both", "but", "by",
        "can", "can't", "cannot", "could", "couldn't",
        "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during",
        "each",
        "few", "for", "from", "further",
        "had", "hadn't", "has", "hasn't", "have", "haven't", "having", "he", "he'd", "he'll", "he's", "her", "here", "here's", "hers", "herself", "him", "himself", "his", "how", "how's",
        "i", "i'd", "i'll", "i'm", "i've", "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself",
        "let's",
        "me", "more", "most", "mustn't", "my", "myself",
        "no", "nor", "not", "of", "off", "on", "once", "only", "or", "other", "ought", "our", "ours", "ourselves", "out", "over", "own",
        "same", "shan't", "she", "she'd", "she'll", "she's", "should", "shouldn't", "so", "some", "such",
        "than", "that", "that's", "the", "their", "theirs", "them", "themselves", "then", "there", "there's", "these", "they", "they'd", "they'll", "they're", "they've", "this", "those", "through", "to", "too",
        "under", "until", "up",
        "very",
        "was", "wasn't", "we", "we'd", "we'll", "we're", "we've", "were", "weren't", "what", "what's", "when", "when's", "where", "where's", "which", "while", "who's", "whom", "why", "why's", "with", "won't", "would", "wouldn't",
        "you'd", "you'll", "you're", "you've", "your", "yours", "yourself", "yourselves"};

} // namespace Chatbot_data


#endif