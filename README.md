# Solution to Exercise 02

### Prerequisites
- C++ compiler (e.g., g++)
- JSON library (https://github.com/nlohmann/json)
- Base64 library (https://github.com/ReneNyffenegger/cpp-base64)

### Building the program
- Clone / download the source code from repository
- Change directory to directory containing source code
`cd <path>`
- Compile the program using C++ compiler to generate executable file named "solution"
`g++ -std=c++17 -o solution solution.cpp`

### Running the program
- Checking exists of required input file
    - `data/data.json`: input JSON file
    - `output-schema/schema.json`: output JSON schema
- Running this command to execute the program
`./solution`
- Result is in `output.json` in the same directory