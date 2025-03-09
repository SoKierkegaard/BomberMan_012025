// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Muro.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberMan_012025GameMode::BeginPlay()
{
	// Create a new Enemigo
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Muro Spawning"));

	MurosCreados = 0;
	for (int i = 0; i < 8; i++)
	{
		//crea los muros
		AMuro* muro01 = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), FVector(500.0f + i * 100, 300.0f + i * 100, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
	}

}