// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CubeActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"

ACubeActor::ACubeActor()
{
    PrimaryActorTick.bCanEverTick = true;

    //root component ( cube mesh )
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    SetRootComponent(CubeMesh);


    //Spring arm component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 200.f;

    //Camera component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    SpringArm->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
    PointLight->SetupAttachment(Camera);
}



void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
}
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ACubeActor::PrintToScreen(const  FString& message) {
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, message);
}
