#include <iostream>

class GasolineSource
{
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default;
};

class GasStation : public GasolineSource
{
public:
    virtual void FuelUp()
    {
        std::cout << "Pumping gas at gas station" << std::endl;
    }
};

class FuelCan : public GasolineSource
{
public:
    virtual void FuelUp()
    {
        std::cout << "Pumping gas from fuel can" << std::endl;
    }
};

class Car
{
    GasolineSource *gasolineService = NULL;

public:
    Car(GasolineSource *service) : gasolineService(service)
    {
        // If no dependecy defined, throw exception
        if (gasolineService == nullptr)
        {
            throw std::invalid_argument("service must not be null");
        }
    }
    void getGasoline()
    {
        std::cout << "Car needs more gasoline!" << std::endl;
        // Abstract away the dependency implementation with polymorphism.
        gasolineService->FuelUp();
    }
};

int main()
{
    GasolineSource *stationService = new GasStation();
    GasolineSource *canService = new FuelCan();

    // racecar is independent from the implementation of the fuel service.
    // a gas station service is injected.
    Car racecar(stationService);
    racecar.getGasoline();

    // dune buggy is independent from the implementation of the fuel service.
    // a fuel can service is injected.
    Car duneBuggy(canService);
    duneBuggy.getGasoline();

    delete stationService;
    delete canService;
    return 0;
}