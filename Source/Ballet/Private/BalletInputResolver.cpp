// Fill out your copyright notice in the Description page of Project Settings.

#include "BalletInputResolver.h"

// Sets default values for this component's properties
UBalletInputResolver::UBalletInputResolver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	/*InputComponent->BindAxis("LeftStickX", this, &UBalletInputResolver::UpdateLeftStickX);
	InputComponent->BindAxis("LeftStickY", this, &UBalletInputResolver::UpdateLeftStickY);
	InputComponent->BindAxis("RightStickY", this, &UBalletInputResolver::UpdateRightStickY);
    */
	// ...
}

// Called when the game starts
void UBalletInputResolver::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UBalletInputResolver::SetTenduRotationRangeRight(FVector rotationRange) {
    tenduRotationRangeRight = rotationRange;
}

void UBalletInputResolver::SetTenduRotationRangeLeft(FVector rotationRange) {
    tenduRotationRangeLeft = rotationRange;
}

void UBalletInputResolver::SetAt90RotationRangeRight(FVector rotationRange) {
    at90RotationRangeRight = rotationRange;
}

void UBalletInputResolver::SetAt90RotationRangeLeft(FVector rotationRange) {
    at90RotationRangeLeft = rotationRange;
}

void UBalletInputResolver::SetPlieRotationRight(FVector thighVector, FVector calfVector, FVector footVector) {
    plieRotationVectorsRight[0] = thighVector;
    plieRotationVectorsRight[1] = calfVector;
    plieRotationVectorsRight[2] = footVector;
}

void UBalletInputResolver::SetPlieRotationLeft(FVector thighVector, FVector calfVector, FVector footVector) {
    plieRotationVectorsLeft[0] = thighVector;
    plieRotationVectorsLeft[1] = calfVector;
    plieRotationVectorsLeft[2] = footVector;
}
FVector UBalletInputResolver::GetRootPosition() {
    float calculated = 40 * rightStickY;
    return FVector(0, 0, calculated);
}

FVector UBalletInputResolver::GetRightThighRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;
    
    if(rightStickY < 0) {
        xVal = plieRotationVectorsRight[0].X * rightStickY;
        yVal = plieRotationVectorsRight[0].Y * rightStickY;
        zVal = plieRotationVectorsRight[0].Z * rightStickY;
        //yVal = rightStickY * -10;
        //zVal = rightStickY * 90;
    }
    // I.E. if At90
    else if(rightRaise) {
        xVal = at90RotationRangeRight.X * leftStickX;
        yVal = at90RotationRangeRight.Y * leftStickY;
    }
    else {
        xVal = tenduRotationRangeRight.X * leftStickX;
        yVal = tenduRotationRangeRight.Y * leftStickY;
    }
    
    return FVector(xVal, yVal, zVal);
}

FVector UBalletInputResolver::GetLeftThighRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;

    if(rightStickY < 0) {
        xVal = plieRotationVectorsLeft[0].X * rightStickY;
        yVal = plieRotationVectorsLeft[0].Y * rightStickY;
        zVal = plieRotationVectorsLeft[0].Z * rightStickY;
        //yVal = rightStickY * 10;
        //zVal = rightStickY * 90;
    }
    
    return FVector(xVal, yVal, zVal);
}

FVector UBalletInputResolver::GetRightCalfRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;
    
    if(rightStickY < 0) {
        //zVal = 130 * rightStickY;
        xVal = plieRotationVectorsRight[0].X * rightStickY;
        yVal = plieRotationVectorsRight[0].Y * rightStickY;
        zVal = plieRotationVectorsRight[0].Z * rightStickY;
    }
    return FVector(xVal, yVal, zVal);
}

FVector UBalletInputResolver::GetLeftCalfRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;
    
    if(rightStickY < 0) {
        xVal = plieRotationVectorsLeft[0].X * rightStickY;
        yVal = plieRotationVectorsLeft[0].Y * rightStickY;
        zVal = plieRotationVectorsLeft[0].Z * rightStickY;
        //zVal = -130 * rightStickY;
    }
    return FVector(xVal, yVal, zVal);
}

FVector UBalletInputResolver::GetRightFootRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;
    
    if(rightStickY < 0) {
        xVal = plieRotationVectorsRight[0].X * rightStickY;
        yVal = plieRotationVectorsRight[0].Y * rightStickY;
        zVal = plieRotationVectorsRight[0].Z * rightStickY;
        //yVal = -40 + rightStickY;
    }
    else {
        
    }
    return FVector(xVal, yVal, zVal);
}

FVector UBalletInputResolver::GetLeftFootRotation() {
    float xVal = 0;
    float yVal = 0;
    float zVal = 0;
    
    if(rightStickY < 0) {
        xVal = plieRotationVectorsLeft[0].X * rightStickY;
        yVal = plieRotationVectorsLeft[0].Y * rightStickY;
        zVal = plieRotationVectorsLeft[0].Z * rightStickY;
        //yVal = 40 + rightStickY;
    }
    
    return FVector(xVal, yVal, zVal);
}

// Called every frame
void UBalletInputResolver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    rightFootRotation = -40 * rightStickY;
    leftFootRotation = 40 * rightStickY;
	// ...
}

void UBalletInputResolver::UpdateInputValues(float leftX, float leftY, float rightY, bool leftR, bool rightR) {
    leftStickX = leftX;
    leftStickY = leftY;
    if(rightY > 0) rightY = 0;
    rightStickY = rightY;
    leftRaise = leftR;
    rightRaise = rightR;
}

void UBalletInputResolver::UpdateLeftStickX(float value)
{
	leftStickX = value;
}

void UBalletInputResolver::UpdateLeftStickY(float value)
{
	leftStickY = value;
}

void UBalletInputResolver::UpdateRightStickY(float value)
{
	rightStickY = value;
}
