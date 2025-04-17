# Parking Lot System

This project is a simple Parking Lot System implemented in C++ to simulate parking operations. It allows vehicles to park, leave, and calculate parking fees based on the duration of their stay.

## Features

- **Dynamic Parking Grid**: The parking lot can be created with a specified number of rows and columns.
- **Vehicle Parking**: Vehicles can park in the first available spot.
- **Vehicle Leaving**: Vehicles can vacate their parking spots.
- **Parking Fee Calculation**: Calculates parking fees based on the duration of parking (in minutes).
- **Grid Visualization**: Displays the current state of the parking lot.

## Classes and Methods

### `Vehicle`
- Base class for all vehicles.
- Tracks the parking spot and start time.
- Abstract methods:
  - `calculateParkingFee()`: Calculates the parking fee.
  - `getType()`: Returns the type of the vehicle.

### `Car`
- Derived class from `Vehicle`.
- Implements `calculateParkingFee()` and `getType()`.

### `Parking`
- Manages the parking lot grid.
- Methods:
  - `create(int rows, int cols)`: Initializes the parking lot with the given dimensions.
  - `park(Vehicle *v)`: Parks a vehicle in the first available spot.
  - `leave(Vehicle *v)`: Removes a vehicle from its spot.
  - `printParking()`: Displays the current state of the parking lot.

## How to Run

1. Compile the code using a C++ compiler:
   ```
   g++ -o output/parking_system.exe parking_system.cpp
   ```
2. Run the executable:
   ```
   .\output\parking_system.exe
   ```

## Example Output

1. Create a parking lot with 1 row and 2 columns.
2. Park three cars (`c1`, `c2`, `c3`).
3. Display the parking grid and calculate fees.

Expected behavior:
- `c1` and `c2` are parked successfully.
- `c3` cannot be parked as the lot is full.
- Parking fees are calculated based on the duration of parking.

## Notes

- The parking fee is calculated as `5 units per minute`.
- The parking duration is measured in minutes from the time the vehicle is parked.

## Future Enhancements

- Add support for different vehicle types (e.g., bikes, trucks) with varying parking fees.
- Implement a graphical user interface (GUI).
- Add persistence to save and load parking lot states.