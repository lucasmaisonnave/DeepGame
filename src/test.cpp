#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("../level/level1.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    const Json::Value& joueur = obj["Joueur"]; // array of characters
    
    std::cout << " x: " << joueur["x"].asInt();
    std::cout << " y: " << joueur["y"].asInt();
    std::cout << std::endl;
    
    return 0;
}
