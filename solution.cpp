#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "base64.h"

// Namespace alias for convenience
using json = nlohmann::json;
using namespace std;

string uuid_extraction(string info){
    int start = info.find("uuid:");
    if (start == string::npos){
        return "";
    }
    int end = info.find(",");
    return info.substr(start+5,end-start-5);    // pos shift for 5 char ("uuid:")
}

int main() {
    // Task 1: Parse the data
    ifstream input_json("data/data.json");
    json json_data = json::parse(input_json);

    // Task 2: Discard devices based on timestamp values
    time_t current_t = time(nullptr);
    json filtered_json;
    for (auto& device: json_data["Devices"]){
        string timestamp_str = device["timestamp"];
        int timestamp = stoi(timestamp_str);
        if (timestamp >= current_t){
            filtered_json.push_back(device);
        }
    }

    // Task3: Decode base64 string to int, and get the total
    int total_value = 0;
    for (auto& device: filtered_json) {
        int decoded = stoi(base64_decode(device["value"]));
        total_value += decoded;
    }

    // Task4: extract uuid from info
    vector<string> uuid_list;
    for (auto& device: filtered_json) {
        string temp = uuid_extraction(device["Info"]);
        uuid_list.push_back(temp);
    }

    // Task 5: output result
    ifstream schema("output-schema/schema.json");
    json schema_json = json::parse(schema);
    json output_json_data;
    output_json_data["$schema"] = schema_json["$schema"];
    output_json_data["type"] = schema_json["type"];

    json output_prop;
    output_prop["ValueTotal"] = total_value;
    output_prop["UUIDS"] = uuid_list;
    output_json_data["properties"] = output_prop;
    ofstream  output_json ("output.json");
    output_json << output_json_data.dump(4);
    output_json.close();
    return 0;
}