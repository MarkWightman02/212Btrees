#include <iostream>

//-------------------BASE VERSION FROM ESTEVES---------------------------------

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

//----------------------V0.1-------------------------

void WriteDOTFile(std::string file_name, std::vector<std::vector<double>> * const readData){
    // Opens the outfile file, prepares it for writing
    std::ofstream output_file(file_name);
    
    // Loop rows
    for(unsigned int i = 0; i < readData->size(); i++){
        // Loop columns
        for(unsigned int j = 0; j < readData[i]->size(); j++){
            /*
            loop Node until empty
                output key
                output " ,"
            output " -> "
            output or return child node
            */
        }
        // Output a newline character after every row
        output_file << "\n";
    }
}

/*---V0.1 NOTES---

- CHANGES MADE: changed image_data to readData for context, changed fxn name to WriteDOTFile, changed code in nested loop, added pseudocode for an additional loop and outputs
- might need a helper fxn to run through the nodes recursively
- will need tweaking to fulfill the needs of the DOT viewer

//-