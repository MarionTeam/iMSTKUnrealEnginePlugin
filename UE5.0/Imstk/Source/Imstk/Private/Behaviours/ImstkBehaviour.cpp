// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkBehaviour.h"

// Sets default values
UImstkBehaviour::UImstkBehaviour()
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;

}

void UImstkBehaviour::InitializeComponent() {
	Super::InitializeComponent();

	// Add tag to each behaviour to find from blueprint for initialization
	if(GetWorld() && GetWorld()->GetGameInstance())
		GetOwner()->Tags.Add(FName("ImstkBehaviour"));
}

// Called when the game starts or when spawned
void UImstkBehaviour::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void UImstkBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UImstkBehaviour::IsInitialized()
{
	return bIsInitialized;
}

void UImstkBehaviour::Init() 
{

}

void UImstkBehaviour::UnInit() 
{

}