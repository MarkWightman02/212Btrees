void ReadFile(std::string file_name, std::vector<std::vector<double>> * image_data){
    // Create the input filestream - opens the file & prepares it for reading
    std::ifstream file(file_name);

    // Temporary string to hold a single line of the file
    std::string str;

    // Reads all lines in the file, 1 at at time
    while (std::getline(file, str)) {
        // Creates a temporary vector to represent one row
       std::vector<double> new_row;
       // Converts our string into a stringstream
       std::istringstream ss(str);
       // Temp double to store a converted value from a line
       double token;

        // Reads all values from the stringstream (current row), converts to double
        while(ss >> token){
            // Adds the converted value to the row
            new_row.push_back(token);
        }
        // Pushes our constructed vector of doubles to the 2D vector
        image_data->push_back(new_row);
    }
}
