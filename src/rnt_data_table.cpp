#include <vector>
#include <cmath>
#include <string>
#include <iostream>

class data
{
public:
    char get_Nrnt_grp(int depth, int time);

    std::vector<std::vector<int>> get_data()
    {
        return Nrnt_grp;
    }

private:
    std::vector<std::vector<int>> Nrnt_grp = {{57, 101, 158, 245, 426}, {36, 60, 88, 121, 163, 217, 297, 449}, {26, 43, 61, 82, 106, 133, 165, 205, 256, 330, 461}, 
    {20, 33, 47, 62, 78, 97, 117, 140, 166, 198, 236, 285, 354, 469, 962, 1102}, {17, 27, 38, 50, 62, 76, 91, 107, 125, 145, 167, 193, 223, 260, 307, 371}, 
    {14, 23, 32, 42, 52, 63, 74, 87, 100, 115, 131, 148, 168, 190, 215, 232}, {12, 20, 27, 36, 44, 53, 63, 73, 84, 95, 108, 121, 135, 151, 163}, 
    {11, 17, 24, 31, 39, 46, 55, 63, 72, 82, 92, 102, 114, 125}, {9, 15, 21, 28, 34, 41, 48, 56, 63, 71, 80, 89, 92}, {8, 14, 19, 25, 31, 37, 43, 50, 56, 63, 71, 74}, 
    {7, 12, 17, 22, 28, 33, 39, 45, 51, 57, 63}, {6, 10, 14, 19, 23, 28, 32, 37, 42, 47, 48}, {5, 9, 12, 16, 20, 24, 28, 32, 36, 39}, {4, 7, 11, 14, 17, 21, 24, 28, 31, 33}, 
    {4, 6, 9, 12, 15, 18, 21, 25}, {3, 6, 8, 11, 14, 16, 19, 20}, {3, 5, 7, 10, 12, 15}, {2, 4, 6, 9, 11, 12}, {2, 4, 6, 8, 10} ,{-1, 3, 5, 7, 8}, {-1, 3, 5, 6, 7}, {-2, -1, 4, 6}, 
    {-2, -1, 4, 5, 6}, {-2, -1, 3, 5}};

    std::vector<char> Grps = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    std::vector<int> depths = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
};

char data::get_Nrnt_grp(int depth, int time)
{
    bool warning = false;
    std::string Uwarning = "DECOMP";
    //round depth to nearest multiple of 5
    if (depth < 10)
    {
        depth = 10;
    }
    // round to nearest multiple of 5 for depths less than 60
    if ((depth < 60) && (depth >= 10)){
        while (depth % 5 != 0)
        {
            depth += 1;
        } 
    }
    // round to the nearest multiple of 10 for numbers greater than 60
    if (depth >= 60){
        while (depth % 10 != 0)
        {
            depth += 1;
        }
    }
    // convert depth to index
    for (unsigned int i=0; i < depths.size(); i++)
    {
        if ((depths.at(i)) == depth)
        {
            depth = i;
            break;
        }
    }

    
    int grp = 0;
    bool cont = true;
    // find group time - round to next if greater
    for (int i = 0; i < Nrnt_grp.at(depth).size(); i++)
    {
        //check if time is already in list
        if (Nrnt_grp.at(depth).at(i) == time)
        {   
            grp = i;
            cont = false;
            break;
        }
    }
    for (int i = 0; i < Nrnt_grp.at(depth).size() - 1; i++)
    {
        // find times that input is between and round greater
        if ((Nrnt_grp.at(depth).at(i) < time) && (time < Nrnt_grp.at(depth).at(i + 1)))
        {
            grp = i + 1;
            cont = false;
            break;
        }
    }
    if (cont)
    {
        //account for time lower than 'A' group
        if (time < Nrnt_grp.at(depth).at(0))
        {
            grp = 0;
        }
        // round depths after first 3 marked with "*"
        if ((time > Nrnt_grp.at(depth).at(Nrnt_grp.at(depth).size()-1)) && (depth > 2))
        {
            return 0;
        }
        // round times marked with "*"
        if ((time > Nrnt_grp.at(depth).at(Nrnt_grp.at(depth).size()-1)) && (depth <= 2))
        {
            //ask ethan about "*" rounding
            grp = Nrnt_grp.at(depth).size();
        } 
    }
    return Grps.at(grp);
}

