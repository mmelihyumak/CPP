#include "PmergeMe.hpp"


static void printMap(std::map<int, int> maps, int mode){


    if (mode == 0)
        std::cout << "Before: ";
    else if (mode == 1)
        std::cout << "After: ";

    std::map<int, int>::iterator it = maps.begin();

    while (it != maps.end()){
        std::cout << it->second << " ";
        it++;
    }
        std::cout << std::endl;
}

std::map<int, int> setMap(int argc, char **argv){

    if (argc < 2 || !argv[0][0]){
        std::cout << "Invalid argument number\n";
        exit(1);
    }

    std::map<int, int> mapValues;

    int i = -1;
    int j = 0;
    int k = -1;
    std::string temp;
    while (argv[++i]){
        std::stringstream ss(argv[i]);
        while (getline(ss, temp, ' ')){
            k = -1;
            while (temp[++k]){
                if (isdigit(temp[k]) == 0){
                    throw PmergeMe::Error();
                    std::cout << "Invalid argument\n";
                    exit(1);
                }
            }
            if (temp[0] != 0){
                int x = std::stoi(temp);
                mapValues[j] = x;
                j++;
            }
        }
    }
    return mapValues;
}

std::list<int> setList(char **argv){

    if (!argv || !argv[0]){
        std::cout << "Invalid argument number\n";
        exit(1);
    }

    std::list<int> listValues;

    int i = -1;
    int j = 0;
    int k = -1;

    std::string temp;

    while (argv[++i]){
        std::stringstream ss(argv[i]);
        while (getline(ss, temp, ' ')){
            k = -1;
            while (temp[++k]){
                if (isdigit(temp[k]) == 0){
                    throw PmergeMe::Error();
                    std::cout << "Invalid argument\n";
                    exit(1);
                }
            }
            if (temp[0] != 0){
                int x = std::stoi(temp);
                listValues.push_back(x);
                j++;
            }
        }
    }

    return listValues;
}

void printList(std::list<int> list){

    std::cout << "List: ";

    std::list<int>::iterator it = list.begin();

    while (it != list.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


int main(int argc, char **argv) {

    PmergeMe pm;

    try
    {
        std::map<int, int> mapValues;
        mapValues = setMap(argc, argv + 1);

        std::list<int> listValues;
        listValues = setList(argv + 1);
        pm.setMapValues(mapValues);
        pm.setListValues(listValues);
        printMap(mapValues, 0);
        clock_t mapStartTime = clock();
        pm.mapMergeSort(0, pm.getMapValues().size() - 1);
        clock_t mapFinishTime = clock();
        clock_t listStartTime = clock();
        pm.listMergeSort(0, listValues.size() - 1);
        clock_t listFinishTime = clock();

        mapValues = pm.getMapValues();
        //printMapV2(mapValues, 0, mapValues.size() - 1);
        listValues = pm.getListValues();

        printMap(mapValues, 1);

        double timeMap = static_cast<double>(mapFinishTime - mapStartTime);
        std::cout << "Time to process a range of " << mapValues.size() << " elements with std::map : "
            << timeMap<< " us" << std::endl;

        double timeList = static_cast<double>(listFinishTime - listStartTime);
        std::cout << "Time to process a range of " << listValues.size() << " elements with std::list : "
            << timeList << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}