#include "CoreMinimal.h"
#include "gameframework/pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TejoPawn.h"

ATejoPawn::ATejoPawn()
{
	//Activamos el Tick (Función que se ejecuta en todos los frames).
	
	PrimaryActorTick.bCanEverTick = true;
	//1. Crear y asignar la malla como componente raiz
	// El RootComponent es el componente principal del cual se desprenden los demas
	
	TejoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TejoMesh"));
	RootComponent= TejoMesh;
	TejoMesh->SetSimulatePhysics(true); //Activa las fìsicas reales (Gravedad colisiones e impulsos)
	
	//Crea el springArm
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	
	//Le decimos a la càmara que NO copie la rotaciòn del tejo
	//Asì aunque gire al chocar o moverse, la camara de mantiene
	//Siempre mirando al mismo àngulo
	
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;
	
	CameraBoom->SetWorldRotation(FRotator(-45.0f, 0.0f, 0.0f)); //Angulo Fijo en 45 Grados hacia abajo
	CameraBoom->TargetArmLength = 1200.0f; //Distancia de alejamiento de la càmara
	CameraBoom->bDoCollisionTest = false; //Desactiva el zoom automatico si choca con paredes
	
	//Crear càmara y unirla al extremo del brazo
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom;USpringArmComponent::SocketName);
	
	//Por defecto el jugador es el 0, esto se puede sobre-escribir en el game-mode
	//o el editor cunado se genera cada tejo para cada jugador
	
	IndiceJugador = 0;
};
void ATejoPawn::BeginPlay()
{

	Super::BeginPlay();

}
void AtejoPawn::Tick( float DeltaTime )

{
	Super::Tick( DeltaTime );
}	
	
void AtejoPawn::SetupPlayerInputTag(class UInputComponent* PlayerInputComponent)

{
	 Super::SetupPlayerInputTag(PlayerInputComponent);
}
//Acà vas a bindear las acciones del inputo (mover, lanzar la ficha)
// Despuès se rellena porque la mecànica de lanzamiento no està escrita


	
	
	
	
	
	
	
	
	
	
