#include <stdio.h>
#include "Table.h"
#include "Measurement.h"
#include "MemoryNFilling.h"

void Table() //Функція для формування та виводу таблиці результатів виміру.
{
    float ordered, random, backordered;
    printf("Vector\n");
    printf("Size M*N:%d\n", M*N);
    printf("\t\t Ordered \t Random \t BackOrdered \n");
    Select6_SortMeasurementVector(1);
    ordered = MeasurementProcessing();
    Select6_SortMeasurementVector(2);
    random = MeasurementProcessing();
    Select6_SortMeasurementVector(3);
    backordered = MeasurementProcessing();
    printf("Select6\t\t %f\t %f\t %f\n", ordered, random, backordered);
    InsertExchange_SortMeasurementVector(1);
    ordered = MeasurementProcessing();
    InsertExchange_SortMeasurementVector(2);
    random = MeasurementProcessing();
    InsertExchange_SortMeasurementVector(3);
    backordered = MeasurementProcessing();
    printf("InsertExchange\t %f\t %f\t %f\n",ordered, random, backordered);
    Select3Exchange_SortMeasurementVector(1);
    ordered = MeasurementProcessing();
    Select3Exchange_SortMeasurementVector(2);
    random = MeasurementProcessing();
    Select3Exchange_SortMeasurementVector(3);
    backordered = MeasurementProcessing();
    printf("Select3Exchange\t %f\t %f\t %f\n",ordered, random, backordered);

    printf("\nArray\n");
    printf("Size P:%d M:%d N:%d\n", P, M, N);
    printf("\t\t Ordered \t Random \t BackOrdered \n");
    Select6_SortMeasurementArray(1);
    ordered = MeasurementProcessing();
    Select6_SortMeasurementArray(2);
    random = MeasurementProcessing();
    Select6_SortMeasurementArray(3);
    backordered = MeasurementProcessing();
    printf("Select6\t\t %f\t %f\t %f\n", ordered, random, backordered);
    InsertExchange_SortMeasurementArray(1);
    ordered = MeasurementProcessing();
    InsertExchange_SortMeasurementArray(2);
    random = MeasurementProcessing();
    InsertExchange_SortMeasurementArray(3);
    backordered = MeasurementProcessing();
    printf("InsertExchange\t %f\t %f\t %f\n",ordered, random, backordered);
    Select3Exchange_SortMeasurementArray(1);
    ordered = MeasurementProcessing();
    Select3Exchange_SortMeasurementArray(2);
    random = MeasurementProcessing();
    Select3Exchange_SortMeasurementArray(3);
    backordered = MeasurementProcessing();
    printf("Select3Exchange\t %f\t %f\t %f\n",ordered, random, backordered);
    getchar();
}
