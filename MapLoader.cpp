#include "MapLoader.hpp"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename, MapData& mapData)
{
    std::string line; //przechowuje linijki podane z pliku
    std::ifstream file(filename); //tworzy obiekt plikowy
    bool isMapValid = false;

    if(file.is_open())
    {
        while(std::getline(file, line)) //ładuje z dane z pliku po kolei do zmiennej
        {

            if(!isMapValid)
            {
                if(line == "[Map]")
                {
                    isMapValid = true;
                    continue;
                }

                else
                {
                    std::cout<<"Map file is not valid"<<std::endl;
                    break;
                }
            }

            if(isMapValid)
            {

            try 
            {    
                int count = line.find('='); //oddziela nazwę zmiennej od zmiennej w pliku znajdując znak '='
                std::string variable = line.substr(0, count);
                std::string value = line.substr(count + 1, line.length() - count);

                if(variable == "version")
                {
                    mapData.version = std::stoi(value);
                }

                else if(variable == "tilesheet")
                {
                    mapData.tilesheet = value; 
                }
                else if(variable == "name")
                {
                    mapData.name = value;
                }

                else if(variable == "mapWidth")
                {
                    mapData.mapWidth = std::stoi(value);
                }

                else if(variable == "mapHeight")
                {
                    mapData.mapHeight = std::stoi(value);
                }

                else if(variable == "tileWidth")
                {
                    mapData.tileWidth = std::stoi(value);
                }

                else if(variable == "tileHeight")
                {
                    mapData.tileHeight = std::stoi(value);
                }

                else if(variable == "scaleX")
                {
                    mapData.scaleX = std::stoi(value);
                }

                else if(variable == "scaleY")
                {
                    mapData.scaleY = std::stoi(value);
                }

                else if(variable == "dataLength")
                {
                    mapData.dataLength = std::stoi(value);

                }

                else if(variable == "data")
                {
                    //usunac to kiedys z heapu, bo core dumped
                    mapData.data = new int[mapData.dataLength];

                    int offset = 0;
                    int i = 0;

                    while(true)
                    {
                        int count = value.find(',', offset);
                        std::string mapIndex = value.substr(offset, count - offset);

                        if(mapIndex == ";")
                        {
                            break;
                        }

                        mapData.data[i] = std::stoi(mapIndex);

                        offset = count + 1;
                        i++;
                    }
                }
            }

            catch(const std::exception&)
            {
                std::cout<<"Something went wrong"<<std::endl;
            }

        }

    }

        file.close(); //pamiętać o zamknięciu pliku
        }


    else
    {
        std::cout<<"Unable to open the file "<<filename<<std::endl;
    }
}

