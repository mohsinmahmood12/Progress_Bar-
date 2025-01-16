# C++ Progress Bar

A lightweight, customizable command-line progress bar implementation in C++. This library provides a simple way to add visual progress indicators to your command-line applications with minimal setup.

## Features

- Customizable progress bar appearance
- Support for custom messages
- Configurable update intervals
- Adjustable bar width
- Error handling and input validation
- Cross-platform compatibility
- Header-only implementation

## Demo

```plaintext
Loading... [45% ] ##################
Processing [80% ] ================================
```

## Requirements

- C++11 or later
- Standard Template Library (STL)
- CMake 3.10 or later (for building with CMake)

## Installation

### Option 1: Header-only Include

Simply copy `progress_bar.hpp` to your project and include it:

```cpp
#include "progress_bar.hpp"
```

### Option 2: Using Git

```bash
git clone https://github.com/yourusername/cpp-progress-bar.git
cd cpp-progress-bar
```

## Building and Running

### Using G++

```bash
# Build
g++ -std=c++11 main.cpp -o progress_bar

# Run
./progress_bar
```

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
./progress_bar
```

## Usage Examples

### Basic Usage

```cpp
#include <iostream>
#include "progress_bar.hpp"

int main() {
    // Simple progress bar with default settings
    show_progress_bar(std::cout, 100, "Loading...");
    return 0;
}
```

### Custom Configuration

```cpp
// Custom width and fill character
show_progress_bar(std::cout, 50, "Processing", 50, '#');

// Custom output stream
show_progress_bar(std::clog, 100, "Downloading", 70, '=');
```

## API Reference

### Function Signature

```cpp
void show_progress_bar(
    std::ostream& os,              // Output stream
    int update_interval_ms,        // Update interval in milliseconds
    const std::string& message,    // Display message
    size_t bar_width = 70,         // Total bar width (optional)
    char fill_char = '*'           // Fill character (optional)
);
```

### Parameters

| Parameter | Type | Description | Default |
|-----------|------|-------------|---------|
| os | std::ostream& | Output stream for the progress bar | Required |
| update_interval_ms | int | Time between updates in milliseconds | Required |
| message | const std::string& | Message to display before the bar | Required |
| bar_width | size_t | Total width of the progress bar | 70 |
| fill_char | char | Character used to fill the bar | '*' |

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Code Style Guidelines

- Use consistent indentation (4 spaces)
- Follow C++ best practices
- Add comments for complex logic
- Include unit tests for new features
- Update documentation as needed

## Changelog

### Version 1.0.0 (2025-01-16)
- Initial release
- Basic progress bar functionality
- Customizable appearance
- Error handling
- Cross-platform support