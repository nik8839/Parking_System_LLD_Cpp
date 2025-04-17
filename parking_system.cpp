#include <bits/stdc++.h>
using namespace std;
class Vehicle
{
private:
    int row_num, spot_num;
    chrono::time_point<chrono::system_clock> start_time; // parking start time
public:
    Vehicle()
    {
        row_num = -1;
        spot_num = -1;
    }
    void occupySpot(int r, int c)
    {
        row_num = r;
        spot_num = c;
        start_time = chrono::system_clock::now(); // Initialize start_time when parked
    }
    void vacate_spot()
    {
        row_num = -1;
        spot_num = -1;
    }
    int calculateParkingDuration()
    {
        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::minutes>(now - start_time); // Use minutes instead of hours
        return duration.count(); // Convert to minutes
    } // calculate parking duration in hours

    virtual int calculateParkingFee() = 0;
    virtual string getType() = 0;
};

class Car : public Vehicle
{
public:
    string getType()
    {
        return "Car";
    }
    int calculateParkingFee()
    {
        return 5 * calculateParkingDuration(); // Placeholder for start and end time
    }
};

class Bike : public Vehicle
{
public:
    string getType()
    {
        return "Bike";
    }
    int calculateParkingFee()
    {
        return 2 * calculateParkingDuration(); // Placeholder for start and end time
    }
};
class Parking
{
private:
    int rows, cols;
    vector<vector<Vehicle *>> grid;

public:
    void create(int r, int c)
    {
        rows = r, cols = c;
        grid.resize(r);
        for (int i = 0; i < r; i++)
        {
            grid[i].resize(c);
        }
    }
    pair<int, int> findSpot()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == NULL)
                {
                    pair<int, int> res = {i, j};
                    return res;
                }
            }
        }
        return pair<int, int>(-1, -1);
    }
    pair<int, int> park(Vehicle *v)
    {
        pair<int, int> spot = findSpot();
        if (spot.first == -1)
        {
            return {-1, -1};
        }
        grid[spot.first][spot.second] = v;
        v->occupySpot(spot.first, spot.second);
       
        return spot;
    }

    void leave(Vehicle *v)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == v)
                {
                    grid[i][j] = NULL;
                    v->vacate_spot();
                    return;
                }
            }
        }
    }
    void printParking()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == NULL)
                    cout << "0 ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Parking Obj;
    int r, c;
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;
    Obj.create(r,c);
    Car c1,c2,c3;

    auto spot1 = Obj.park(&c1);
    if (spot1.first != -1)
    {
        cout << "Car 1 parked at: (" << spot1.first << ", " << spot1.second << ")" << endl;
        cout << "Car 1 parking fee: " << c1.calculateParkingFee() << endl;
    }

    auto spot2 = Obj.park(&c2);
    if (spot2.first != -1)
        cout << "Car 2 parked at: (" << spot2.first << ", " << spot2.second << ")" << endl;

    auto spot3 = Obj.park(&c3);
    if (spot3.first == -1)
        cout << "Car 3 could not be parked. No spot available." << endl;

    Obj.printParking();
}