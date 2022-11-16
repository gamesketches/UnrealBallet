// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "BalletInputResolver.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALLET_API UBalletInputResolver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBalletInputResolver();
    

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float rightFootRotation;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    float leftFootRotation;
    
    void UpdateLeftStickX(float value);
    void UpdateLeftStickY(float value);
    void UpdateRightStickY(float value);
    
    UFUNCTION(BlueprintCallable)
    void UpdateInputValues(float leftX, float leftY, float rightY, bool leftRaise, bool rightRaise);
    
    // Initializers
    UFUNCTION(BlueprintCallable)
    void SetTenduRotationRangeRight(FVector rotationRange);
    
    UFUNCTION(BlueprintCallable)
    void SetTenduRotationRangeLeft(FVector rotationRange);
    
    UFUNCTION(BlueprintCallable)
    void SetAt90RotationRangeRight(FVector rotationRange);
    
    UFUNCTION(BlueprintCallable)
    void SetAt90RotationRangeLeft(FVector rotationRange);
    
    UFUNCTION(BlueprintCallable)
    void SetPlieRotationRight(FVector thighVector, FVector calfVector, FVector footVector);
    
    UFUNCTION(BlueprintCallable)
    void SetPlieRotationLeft(FVector thighVector, FVector calfVector, FVector footVector);
    
    // Getters
    
    UFUNCTION(BlueprintCallable)
    FVector GetRootPosition();
    
    // Thigh Rotations
    UFUNCTION(BlueprintCallable)
    FVector GetLeftThighRotation();

    UFUNCTION(BlueprintCallable)
    FVector GetRightThighRotation();

    // Calf Rotations
    UFUNCTION(BlueprintCallable)
    FVector GetLeftCalfRotation();

    UFUNCTION(BlueprintCallable)
    FVector GetRightCalfRotation();

    // Foot Rotations
    UFUNCTION(BlueprintCallable)
    FVector GetLeftFootRotation();

    UFUNCTION(BlueprintCallable)
    FVector GetRightFootRotation();
    
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    
    // Basic Input Values
    float leftStickX;
    float leftStickY;
    float rightStickY;
    bool leftRaise;
    bool rightRaise;
    
    // Rotation Ranges
    FVector at90RotationRangeRight;
    FVector at90RotationRangeLeft;
    FVector tenduRotationRangeRight;
    FVector tenduRotationRangeLeft;

    // Plie Releve vectors
    FVector plieRotationVectorsRight[3];
    FVector plieRotationVectorsLeft[3];
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
