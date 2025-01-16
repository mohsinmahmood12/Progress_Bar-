#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
#include <thread>
#include <stdexcept>

/**
 * @brief Displays an animated progress bar with a custom message
 * 
 * @param os Output stream to display the progress bar (e.g., std::cout, std::clog)
 * @param update_interval_ms Time in milliseconds between progress updates
 * @param message Message to display before the progress bar
 * @param bar_width Total width of the progress bar (default: 70)
 * @param fill_char Character to use for filling the progress bar (default: '*')
 * @throws std::invalid_argument if update_interval_ms is negative or bar_width is too small
 */
void show_progress_bar(
    std::ostream& os,
    int update_interval_ms,
    const std::string& message,
    size_t bar_width = 70,
    char fill_char = '*'
) {
    // Input validation
    if (update_interval_ms < 0) {
        throw std::invalid_argument("Update interval must be non-negative");
    }
    if (bar_width < 10) {
        throw std::invalid_argument("Bar width must be at least 10 characters");
    }

    // Handle case where message is too long
    std::string display_message = message;
    if (display_message.length() >= bar_width) {
        os << display_message << "\n";
        display_message.clear();
    } else {
        display_message += " ";
    }

    // Calculate available space for the progress bar
    const size_t available_width = bar_width - display_message.length();
    
    // Calculate progress increment per step
    const double progress_increment = 100.0 / available_width;

    // Display initial message
    os << display_message;

    // Display progress bar
    for (double percentage = 0; percentage <= 100; percentage += progress_increment) {
        // Format the progress bar
        display_message += fill_char;
        
        // Clear the current line and display updated progress
        os << "\r ["
           << std::setw(3) << static_cast<int>(percentage)
           << "% ] "
           << display_message
           << std::flush;

        // Wait for the specified interval
        std::this_thread::sleep_for(
            std::chrono::milliseconds(update_interval_ms)
        );
    }

    // Move to next line after completion
    os << "\n\n";
}

int main() {
    try {
        // Example usage with different configurations
        show_progress_bar(std::cout, 100, "Loading...", 50, '#');
        show_progress_bar(std::cout, 50, "Processing", 70, '=');
        
        // Example with default parameters
        show_progress_bar(std::cout, 100, "Completing");
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}