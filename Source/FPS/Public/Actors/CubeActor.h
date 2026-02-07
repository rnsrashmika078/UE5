// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeActor.generated.h"


class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UPointLightComponent;

UCLASS()
class FPS_API ACubeActor : public AActor
{
	GENERATED_BODY()
	
public:
   	ACubeActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


    UFUNCTION(BlueprintCallable)
    void PrintToScreen(const  FString& message);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    UStaticMeshComponent* CubeMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    UCameraComponent* Camera;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    UPointLightComponent* PointLight;
};
