
#pragma once

#include "TejoPawn.generated.h"
#include "CoreMinimal.h"
#include "gameframework/pawn.h"
#include "TejoPawn.h"

// Atejopawn representa el tejo "jugador"
UCLASS ()  
class TEJOWARSTP_API ATejoPawn : public APawn
{
	GENERATED_BODY()
public:
	ATejoPawn();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// Malla 3d del Tejo
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TejoMesh;
	
	//SpringArm que mantiene la distancia y angulos del Tejo
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FollowCamera;
	
	//Indice del jugador que controla al tejo (0, 1, 2, 3)
	//Para saber quien lanza el disco y anota el punto 
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Juego")
	int32 IndiceJugador;
	};