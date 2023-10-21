#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<vector<string>> getData(vector<vector<string>> data, string filename){

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "Error opening the necessary file." << endl;
    }
    else{
        string line;
        getline(file, line);

        while (getline(file, line)){
            vector<string> row;
            stringstream lineStream(line);
            string cell;

            while(getline(lineStream, cell, ',')){
                row.push_back(cell);
            }
            data.push_back(row);
        }
    }

    file.close();
    return data;
}

int getRoomNum(vector<vector<string>> data, int type, string city, string hotel){

    if(type > 5 || type < 0){
        return -1;
    }
    else{
        int ma = data.size();
        for(int j = 0; j < ma; j++){
            if(data[j][1] == city && data[j][0] == hotel){
                string status = data[j][2*type];
                int l = status.length();
                int count = 0;
                for(int i = 0; i < l; i++){
                    if(status[i] == '0'){
                        count+=1;
                    }
                }
                return count;
            }
        }
    }
    return -1;
}

string getCity(vector<vector<string>> data, int ma){

    cout << "Enter location : \n" <<
            "1 : Bangalore\n" <<
            "2 : Chennai\n" <<
            "3 : Mumbai\n" << 
            "4 : Kolkata\n" << endl;

    int input;
    string city;

    while(1 == 1){
        cin >> input;
        if(input == 1){city = "Bangalore";break;}
        else if(input == 2){city = "Chennai";break;}
        else if(input == 3){city = "Mumbai";break;}
        else if(input == 4){city = "Kolkata";break;}
        else{cout << "Enter valid city: " << endl;}
    }

    cout << "\n| Hotel    | Normal Price | Suite  Price | Deluxe_Suite  Price | Deluxe  Price | Luxury  Price |" << endl;

    for(int i = 0; i < ma; i++){
        if(data[i][1] == city){
            cout << "| " << data[i][0] << " | ";
            for(int j = 1; j < 6; j++){
                int n = getRoomNum(data,j,city,data[i][0]);
                cout << n << "  " << data[i][2*j+1] << " | ";
            }
            cout << endl;
        }
    }

    return city;

}

string getHotel(vector<vector<string>> data, int ma, string city){

    cout << "\nSelect your hotel : " ;
    for(int i = 0; i < ma; i++){
        if(data[i][1] == city){
            cout << " " << data[i][0];
        }
    }
    cout << endl;
    return city;

}

int main(){

    vector<vector<string>> data;
    data = getData(data,"../Test.csv");

    //Type : 1 == normal, 2 == suite, 3 == deluxe_suite, 4 == deluxe, 5 == luxury

    int ma = data.size();
    string city = getCity(data, ma);

    string Hotel = getHotel(data, ma, city);
    
}