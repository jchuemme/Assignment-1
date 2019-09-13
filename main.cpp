#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <sstream>

using namespace std;

void print(std::vector<string> const &color_vec){
    for (auto const& i: color_vec){
        std::cout << i << " ";
    }
    cout <<"\n";
}

int main()
{
    
    std::array<std::array<string,2>,3> std_arr = 
    {{{"blue","white"},
    {"green","white"},
    {"green","white"}}};
    
    std::vector<string> color_vec1(std::begin(std_arr.at(0)), std::end(std_arr.at(0)));
    std::vector<string> color_vec2(std::begin(std_arr.at(1)), std::end(std_arr.at(1)));
    std::vector<string> color_vec3(std::begin(std_arr.at(2)), std::end(std_arr.at(2)));
 
    cout << "\nPlease Enter Missing Pegs: \n";
    std::string miss_pegs;
    getline(cin,miss_pegs);
    
    istringstream iss;
    iss.str(miss_pegs);
    
    std::vector<string>miss_color(3);
    for (int n=0; n<3; n++){
        string color;
        iss >> color;
        miss_color.push_back(color);
    
        if (n=0){
            color_vec1.insert(2,color);
        }
        
        if (n=1){
            color_vec2.insert(0,color);
        }
        
        if (n=2){
            color_vec3.insert(1,color);
        }
    }
    
    print(miss_color);
    cout << "Vector 1: ";
    print(color_vec1);
    cout << "Vector 2: ";
    print(color_vec2);
    cout << "Vector 3: ";
    print(color_vec3);

    return 0;
}
