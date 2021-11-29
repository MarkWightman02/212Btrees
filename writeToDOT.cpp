#include <iostream>


void WriteFile(std::string file_name, std::vector<std::vector<double>> * const image_data){
    // Opens the outfile file, prepares it for writing
    std::ofstream output_file(file_name);
    
    // Loop rows
    for(unsigned int i = 0; i < image_data->size(); i++){
        // Loop columns
        for(unsigned int j = 0; j < image_data[i]->size(); j++){
            // Output each value and a space
            output_file << (*image_data)[i][j] << " ";
        }
        // Output a newline character after every row
        output_file << "\n";
    }
}
