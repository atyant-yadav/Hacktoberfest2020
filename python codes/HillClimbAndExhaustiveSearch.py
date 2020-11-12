import random
import numpy as np
import math
import time


def makeTSP(nCities):
    positions = 2*np.random.rand(nCities, 2)-1
    distance = np.zeros((nCities, nCities))

    for i in range(nCities):
        for j in range(nCities):
            distance[i, j] = math.sqrt(
                (positions[i, 0] - positions[j, 0])**2 + (positions[i, 1] - positions[j, 1])**2)
            distance[j, i] = distance[i, j]
        return distance


def permutation(order):
    order = tuple(order)
    if len(order) == 1:
        yield order
    else:
        for i in range(len(order)):
            rest = order[:i] + order[i+1:]
            move = (order[i],)
            for smaller in permutation(rest):
                yield move + smaller


def exhaustive(distance):
    nCities = np.shape(distance)[0]

    cityOrder = np.arange(nCities)

    distanceTravelled = 0
    for i in range(nCities-1):
        distanceTravelled += distance[cityOrder[i], cityOrder[i+1]]
    distanceTravelled += distance[cityOrder[nCities-1], 0]

    for newOrder in permutation(range(nCities)):
        possibleDistanceTravelled = 0
        for i in range(nCities-1):
            possibleDistanceTravelled += distance[newOrder[i], newOrder[i+1]]
        possibleDistanceTravelled += distance[newOrder[nCities-1], 0]

        if possibleDistanceTravelled < distanceTravelled:
            distanceTravelled = possibleDistanceTravelled
            cityOrder = newOrder
    return cityOrder, distanceTravelled


def hillClimbing(distance):

    nCities = np.shape(distance)[0]

    cityOrder = np.arange(nCities)
    random.shuffle(cityOrder)

    distanceTravelled = 0
    for i in range(nCities-1):
        distanceTravelled += distance[cityOrder[i], cityOrder[i+1]]
    distanceTravelled += distance[cityOrder[nCities-1], 0]

    for i in range(1000):
        # Choose cities to swap
        city1 = np.random.randint(nCities)
        city2 = np.random.randint(nCities)

        if city1 != city2:
            # Reorder the set of cities
            possibleCityOrder = cityOrder.copy()
            possibleCityOrder = np.where(
                possibleCityOrder == city1, -1, possibleCityOrder)
            possibleCityOrder = np.where(
                possibleCityOrder == city2, city1, possibleCityOrder)
            possibleCityOrder = np.where(
                possibleCityOrder == 1, city2, possibleCityOrder)

            # Work out the new distance
            # This can be done more efficiently
            newDistanceTravelled = 0
            for j in range(nCities-1):
                newDistanceTravelled += distance[possibleCityOrder[j],
                                                 possibleCityOrder[j+1]]
            distanceTravelled += distance[cityOrder[nCities-1], 0]

            if newDistanceTravelled < distanceTravelled:
                distanceTravelled = newDistanceTravelled
                cityOrder = possibleCityOrder
    return cityOrder, distanceTravelled


def runAll():
    nCities = 5
    distance = makeTSP(nCities)

    print("Exhaustive search")
    start = time.time()
    print(exhaustive(distance))
    finish = time.time()
    print(finish-start)
    print("")
    print("Hill Climbing")
    start = time.time()
    print(hillClimbing(distance))
    finish = time.time()
    print(finish-start)


runAll()
