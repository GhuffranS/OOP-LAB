#include "iostream"
using namespace std;

int tracker(int arr[][28]){
    int index = 0;
    float avg[4][4];
    float highest = 0.0;
    for (int i = 0; i < 4; i++)
    {
        cout<<"Air Quality Index for City Number "<<i+1<<endl;
        for (int x = 0; x < 28; x++)
        {
            cout<<"Enter Air Quality Index for day "<<x+1<<endl;
            cin>>arr[i][x];
        }
        
    }

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int z = 0; z < 7; z++)
            {
                avg[j][i] += arr[i][z];
            }
            avg[j][i] = avg[j][i]/7;
            if (highest < avg[j][i])
            {
                highest = avg[j][i];
                index = i;
            }
        
        }
    }
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<"Average AQI For city "<<i+1<<", Week "<<j+1<<": "<<avg[i][j]<<endl;
        }
    }
    
    

    cout << "Highest AQI is for city number : "<<index+1<<endl;
    return 0;    

}

int critical(int arr[][7]){
    for (int i = 0; i < 4; i++)
    {
        for (int z = 0; z < 7; z++)
        {
            if(arr[i][z] > 150)
            {
                cout<<"CRITICAL! AQI For city "<<i+1<<", Day "<<z+1<<" exceeds 150"<<endl;
            }
        }
        
    }

    return 0;
    
}

int visualize(int arr[][7]){
    for (int i = 0; i < 4; i++)
    {
        cout<<"City Number "<<i+1<<endl;
        for (int j = 0; j < 7; j++)
        {
            cout<<"Day "<<j+1<<": ";
            int val = arr[i][j]/10;
            for (int k = 0; k < val; k++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        cout<<endl;
        
        
    }
    return 0;
    
}

int monthly(int arr[][28]){
    float avg[4][4] = {0};
    float highest = 0;
    int city;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float sum = 0;
            for (int k = 0; k < 7; k++)
            {
                sum += arr[i][7*j + k];
            }
            avg[i][j] = sum/7;
            cout<<"Average for City "<<i+1<<", Week "<<j+1<<": "<<avg[i][j]<<endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        float temp = 0;
        temp = avg[i][0] - avg[i][3];
        if (temp > highest)
        {
            highest = temp;
            city = i;
        } 
    }
    cout<<"City "<<city+1<<" has the highest improved air quality. Difference: "<<highest<<endl;
    return 0;
}

int report(int arr[][28]){
    float avg[4][4] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float sum = 0;
            for (int k = 0; k < 7; k++)
            {
                sum += arr[i][j*7 + k];
            }
            avg[i][j] = sum/7;
            cout<<"Average for City "<<i+1<<", Week "<<j+1<<": "<<avg[i][j]<<endl;
        }
    }
    cout<<endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {   
            if (arr[i][j] > 150)
            {
                cout<<"Critical! City "<<i+1<<" Day "<<j+1<<" exceed 150"<<endl;
            }
            
        }
        
    }
    cout<<endl;

    for (int i = 0; i < 4; i++)
    {
        int lowest = arr[i][0];
        int highest = arr[i][0];
        for (int j = 0; j < 28; j++)
        {
            if (arr[i][j] > highest)
            {
                highest = arr[i][j];

            }
            if (arr[i][j] < lowest)
            {
                lowest = arr[i][j];
            }
        }
        cout<<"The highest AQI for city "<<i+1<<" is "<<highest<<", Lowest is "<<lowest<<endl;
    }
    return 0;
    


    
}



int main(){
    int AQI[4][28];
    tracker(AQI);
    monthly(AQI);
    report(AQI);
}