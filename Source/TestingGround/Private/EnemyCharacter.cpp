// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "EnemyCharacter.h"


AEnemyCharacter::AEnemyCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	this->AggroTrigger = PCIP.CreateDefaultSubobject<USphereComponent>(this, FName(TEXT("AggroTrigger")));
	this->AggroTrigger->AttachTo(this->RootComponent);

	this->AggroTrigger->InitSphereRadius(1500.0f); // By default the aggro trigger has a radius of 15 meters
}

